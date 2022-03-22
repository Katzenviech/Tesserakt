#include "Game.h"

void Game::run(Controller& controller, Renderer& renderer, Player& player, std::vector<Bullet>& bullets, int target_frame_duration)
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
        update(controller, player, bullets, target_frame_duration);
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
    }
}

void Game::update(Controller& controller, Player& player, std::vector<Bullet>& bullets, int target_frame_duration)
{
    // Fill vector with bullets
    if(controller.get_fire_pressed()){
        bullets.emplace_back(player.getX(), player.getY(), 0.f, 0.f, 0, 1000, 1000, 10);
    }

    // Move the player
    player.setXVel((controller.get_right_pressed() - controller.get_left_pressed()) * player.getSpeed());
    player.setYVel((controller.get_down_pressed() - controller.get_up_pressed()) * player.getSpeed());
    player.normalizeSpeed();

    player.setX(player.getX() + player.getXVel() / 60); // TODO: Must depend on FPS
    player.setY(player.getY() + player.getYVel() / 60);
    // Boundary 
    if (player.getX() <= 0)
        player.setX(0);
    if (player.getX() >= (player.getWidth() - player.getSize()))
        player.setX(player.getWidth() - player.getSize());
    if (player.getY() <= 0)
        player.setY(0);
    if (player.getY() >= (player.getHeight() - player.getSize()))
        player.setY(player.getHeight() - player.getSize());
}