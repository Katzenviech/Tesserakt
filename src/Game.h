#pragma once

#include <vector>
#include <random>
#include "SDL.h"
#include "Controller.h"
#include "Renderer.h"
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"

class Game
{

public:
    Game(int bulletspeed, int time_between_shots_ms, int enemy_move_speed_percent, int stun_time_ms, int spawn_time_ms, int speed_inc_perc, int width, int height, int size);
    void run(Controller &controller, Renderer &renderer, Player &player, std::vector<Bullet> &bullets, std::vector<Enemy> enemies, int target_frame_duration);
    int GetScore() const;

private:
    void update(Controller &controller, Player &player, std::vector<Bullet> &bullets, std::vector<Enemy> &enemies);
    bool m_running = true;
    int m_bulletspeed;
    float m_timeSinceLastFrame = 0.f;
    float m_timeBetweenShots;
    float m_timeSinceLastSpawn = 0.f;
    void destroyBulletsOutOfScreen(std::vector<Bullet> &bullets);
    float m_enemy_move_speed;
    int m_score = 0;
    float m_spawn_time_s;

    std::random_device m_dev;
    std::mt19937 m_engine;
    std::uniform_int_distribution<int> m_random_w;
    std::uniform_int_distribution<int> m_random_h;

};