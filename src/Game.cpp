#include <algorithm>
#include <cmath>
#include "Game.h"
#include "Enemy.h"

Game::Game(int bulletspeed, int time_between_shots_ms, int enemy_move_speed_percent, int stun_time_ms, int width, int height, int size) 
: m_bulletspeed{bulletspeed}, m_timeBetweenShots{time_between_shots_ms * 0.001f}, m_enemy_move_speed{enemy_move_speed_percent * 0.01f},
      m_engine{ m_dev() }, m_random_w {0, width - size - 1}, m_random_h {0, height - size -1}
{
    Enemy::m_stunTime_s = stun_time_ms * 0.001;
}

void Game::run(Controller &controller, Renderer &renderer, Player &player, std::vector<Bullet> &bullets, std::vector<Enemy> enemies, int target_frame_duration)
{
    int title_timestamp = SDL_GetTicks();
    int frame_start;
    int frame_end;
    int frame_duration;
    int frame_count = 0;

    enemies.emplace_back(200.f, 150.f, 0.f, 0.f, player.getSpeed() * m_enemy_move_speed, player.getWidth(), player.getHeight(), player.getSize());
    enemies.emplace_back(500.f, 450.f, 0.f, 0.f, player.getSpeed() * m_enemy_move_speed, player.getWidth(), player.getHeight(), player.getSize());

    while (m_running)
    {
        frame_start = SDL_GetTicks();

        // Input, Update, Render - the main game loop.
        controller.HandleInput(m_running, player);
        update(controller, player, bullets, enemies);
        renderer.render(player, bullets, enemies);

        frame_end = SDL_GetTicks();

        // Keep track of how long each loop through the input/update/render cycle
        // takes.
        frame_count++;
        frame_duration = frame_end - frame_start;

        // After every second, update the window title.
        if (frame_end - title_timestamp >= 1000)
        {
            renderer.updateWindowTitle(m_score);
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

void Game::destroyBulletsOutOfScreen(std::vector<Bullet> &bullets)
{
    // remove bullets if they are OUTOFBOUNDS
    auto new_end = std::remove_if(bullets.begin(), bullets.end(), [](const Bullet &b) {
        return (int)b.getX() > b.getWidth() ||
               (int)b.getY() > b.getHeight() ||
               (int)b.getX() < -b.getWidth() ||
               (int)b.getY() < -b.getHeight() ||
               b.isHit();
    });
    bullets.erase(new_end, bullets.end());
}

void Game::update(Controller &controller, Player &player, std::vector<Bullet> &bullets, std::vector<Enemy> &enemies)
{
    // Shoot - Fill vector with bullets
    constexpr int OUTOFBOUNDS = 10000; // pixels
    constexpr int BULLETSIZE = 8;
    // TODO: Make SPAWNTIME constexpr in main
    constexpr float SPAWNTIME = 1.f;

    player.setTimeSinceLastShot(player.getTimeSinceLastShot() + m_timeSinceLastFrame);
    if (player.isAlive())
    {
        if (player.getTimeSinceLastShot() >= m_timeBetweenShots)
        {
            player.setTimeSinceLastShot(0.f);
            if (controller.get_fire_left_pressed())
            {
                bullets.emplace_back(player.getX() + player.getSize() / 2, player.getY() + player.getSize() / 2, -1.f * m_bulletspeed + player.getXVel(), player.getYVel(), 0, OUTOFBOUNDS, OUTOFBOUNDS, BULLETSIZE);
            }
            else if (controller.get_fire_right_pressed())
            {
                bullets.emplace_back(player.getX() + player.getSize() / 2, player.getY() + player.getSize() / 2, 1.f * m_bulletspeed + player.getXVel(), player.getYVel(), 0, OUTOFBOUNDS, OUTOFBOUNDS, BULLETSIZE);
            }
            else if (controller.get_fire_up_pressed())
            {
                bullets.emplace_back(player.getX() + player.getSize() / 2, player.getY() + player.getSize() / 2, player.getXVel(), -1.f * m_bulletspeed + player.getYVel(), 0, OUTOFBOUNDS, OUTOFBOUNDS, BULLETSIZE);
            }
            else if (controller.get_fire_down_pressed())
            {
                bullets.emplace_back(player.getX() + player.getSize() / 2, player.getY() + player.getSize() / 2, player.getXVel(), 1.f * m_bulletspeed + player.getYVel(), 0, OUTOFBOUNDS, OUTOFBOUNDS, BULLETSIZE);
            }
        }

        // Move the player
        player.setXVel((controller.get_right_pressed() - controller.get_left_pressed()) * player.getSpeed());
        player.setYVel((controller.get_down_pressed() - controller.get_up_pressed()) * player.getSpeed());
        player.normalizeSpeed();

        player.setX(player.getX() + player.getXVel() * m_timeSinceLastFrame);
        player.setY(player.getY() + player.getYVel() * m_timeSinceLastFrame);
    }

    // Boundary
    if (player.getX() <= 0)
        player.setX(0);
    if (player.getX() >= (player.getWidth() - player.getSize()))
        player.setX(player.getWidth() - player.getSize());
    if (player.getY() <= 0)
        player.setY(0);
    if (player.getY() >= (player.getHeight() - player.getSize()))
        player.setY(player.getHeight() - player.getSize());

    // Move bullets
    for (Bullet &b : bullets)
    {
        b.setX(b.getX() + b.getXVel() * m_timeSinceLastFrame);
        b.setY(b.getY() + b.getYVel() * m_timeSinceLastFrame);
    }

    // Move enemies
    for (Enemy &e : enemies)
    {
        // move
        e.update(player, m_timeSinceLastFrame);
        e.setX(e.getX() + e.getXVel() * m_timeSinceLastFrame);
        e.setY(e.getY() + e.getYVel() * m_timeSinceLastFrame);
        // hit
        if (e.stun(bullets))
        {
            // remove bullet if enemy was hit
            destroyBulletsOutOfScreen(bullets);
            m_score++;
        }

        if (!e.isStunned() && e.checkCollision(player))
            player.setDead();
    }
    // remove bullet out of window
    destroyBulletsOutOfScreen(bullets);

    // spawn new enemies
    m_timeSinceLastSpawn += m_timeSinceLastFrame;
    if(m_timeSinceLastSpawn > SPAWNTIME && player.isAlive()){
        m_timeSinceLastSpawn = 0.f;
        int x = m_random_w(m_engine);
        int y = m_random_h(m_engine);
        enemies.emplace_back(x, y, 0.f, 0.f, player.getSpeed() * m_enemy_move_speed, player.getWidth(), player.getHeight(), player.getSize());
        m_score += 10;
    }
    
}

int Game::GetScore() const { 
    return m_score; 
}