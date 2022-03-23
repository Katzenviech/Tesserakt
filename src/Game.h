#pragma once

#include <vector>
#include "SDL.h"
#include "Controller.h"
#include "Renderer.h"
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"

class Game {

public:
    Game(int bulletspeed, int time_between_shots_ms, int enemy_move_speed_percent, int stun_time_ms);
    void run(Controller& controller, Renderer& renderer, Player& player, std::vector<Bullet>& bullets, std::vector<Enemy> enemies, int target_frame_duration);

private:
    void update(Controller& controller, Player& player, std::vector<Bullet>& bullets, std::vector<Enemy>& enemies);
    bool m_running = true;
    int m_bulletspeed;
    float m_timeSinceLastFrame = 0.f;
    float m_timeBetweenShots;
    void destroyBulletsOutOfScreen(std::vector<Bullet>& bullets);
    float m_enemy_move_speed;
    int m_score = 0;
};