#pragma once

#include "SDL.h"
#include "Controller.h"
#include "Renderer.h"
#include "Player.h"

class Game {

public:

    Game(int gravity);

    void run(Controller& controller, Renderer& renderer, Player& player, int target_frame_duration);


private:
    void update(Controller& controller, Player& player, int target_frame_duration);
    bool m_running = true;
    int m_gravity;

};