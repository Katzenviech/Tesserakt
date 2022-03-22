#include <algorithm>
#include <cmath>
#include "Game.h"

Game::Game(int bulletspeed, int time_between_shots_ms) : m_bulletspeed{bulletspeed}, m_timeBetweenShots{time_between_shots_ms*0.001f} {}

void Game::run(Controller &controller, Renderer &renderer, Player &player, std::vector<Bullet> &bullets, int target_frame_duration)
{
    int title_timestamp = SDL_GetTicks();
    int frame_start;
    int frame_end;
    int frame_duration;
    int frame_count = 0;

    while (m_running)
    {
        frame_start = SDL_GetTicks();

        // Input, Update, Render - the main game loop.
        controller.HandleInput(m_running, player);
        update(controller, player, bullets);
        renderer.render(player, bullets);

        frame_end = SDL_GetTicks();

        // Keep track of how long each loop through the input/update/render cycle
        // takes.
        frame_count++;
        frame_duration = frame_end - frame_start;

        // After every second, update the window title.
        if (frame_end - title_timestamp >= 1000)
        {
            frame_count = 0;
            title_timestamp = frame_end;
        }

        // If the time for this frame is too small (i.e. frame_duration is
        // smaller than the target ms_per_frame), delay the loop to
        // achieve the correct frame rate.
        if (frame_duration < target_frame_duration)
        {
            SDL_Delay(target_frame_duration - frame_duration);
        }

        m_timeSinceLastFrame = float(SDL_GetTicks() - frame_start) * 0.001; //s
    }
}

void Game::destroyBulletsOutOfScreen(std::vector<Bullet>& bullets){
    bullets.erase(std::remove_if(bullets.begin(), bullets.end(), [](const Bullet& b){
        return (int)fabs(b.getX()) > b.getWidth() || (int)fabs(b.getY()) > b.getHeight();
    }));
}

void Game::update(Controller &controller, Player &player, std::vector<Bullet> &bullets)
{

    player.setTimeSinceLastShot(player.getTimeSinceLastShot() + m_timeSinceLastFrame);

    if (player.getTimeSinceLastShot() >= m_timeBetweenShots)
    {
        player.setTimeSinceLastShot(0.f);
        // Fill vector with bullets
        if (controller.get_fire_left_pressed())
        {
            bullets.emplace_back(player.getX() + player.getSize() / 2, player.getY() + player.getSize() / 2, -1.f * m_bulletspeed + player.getXVel(), player.getYVel(), 0, 10000, 10000, 5);
        }
        if (controller.get_fire_right_pressed())
        {
            bullets.emplace_back(player.getX() + player.getSize() / 2, player.getY() + player.getSize() / 2, 1.f * m_bulletspeed + player.getXVel(), player.getYVel(), 0, 10000, 10000, 5);
        }
        if (controller.get_fire_up_pressed())
        {
            bullets.emplace_back(player.getX() + player.getSize() / 2, player.getY() + player.getSize() / 2, player.getXVel(), -1.f * m_bulletspeed + player.getYVel(), 0, 10000, 10000, 5);
        }
        if (controller.get_fire_down_pressed())
        {
            bullets.emplace_back(player.getX() + player.getSize() / 2, player.getY() + player.getSize() / 2, player.getXVel(), 1.f * m_bulletspeed + player.getYVel(), 0, 10000, 10000, 5);
        }

    }

    // Move bullets
    for (Bullet &b : bullets)
    {
        b.setX(b.getX() + b.getXVel() * m_timeSinceLastFrame);
        b.setY(b.getY() + b.getYVel() * m_timeSinceLastFrame);
    }

    // Move the player
    player.setXVel((controller.get_right_pressed() - controller.get_left_pressed()) * player.getSpeed());
    player.setYVel((controller.get_down_pressed() - controller.get_up_pressed()) * player.getSpeed());
    player.normalizeSpeed();

    player.setX(player.getX() + player.getXVel() * m_timeSinceLastFrame); // TODO: Must depend on FPS
    player.setY(player.getY() + player.getYVel() * m_timeSinceLastFrame);
    // Boundary
    if (player.getX() <= 0)
        player.setX(0);
    if (player.getX() >= (player.getWidth() - player.getSize()))
        player.setX(player.getWidth() - player.getSize());
    if (player.getY() <= 0)
        player.setY(0);
    if (player.getY() >= (player.getHeight() - player.getSize()))
        player.setY(player.getHeight() - player.getSize());

    if(bullets.size() > 0)
        destroyBulletsOutOfScreen(bullets);
}