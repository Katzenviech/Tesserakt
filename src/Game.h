#pragma once

#include <vector>
#include "SDL.h"
#include "Controller.h"
#include "Renderer.h"
#include "Player.h"
#include "Bullet.h"

class Game {

public:

    void run(Controller& controller, Renderer& renderer, Player& player, std::vector<Bullet>& bullets, int target_frame_duration);

private:
    void update(Controller& controller, Player& player, std::vector<Bullet>& bullets, int target_frame_duration);
    bool m_running = true;
    int m_gravity;

};