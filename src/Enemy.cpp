#include "Enemy.h"
#include <cmath>

Enemy::Enemy(float x_pos, float y_pos, float x_vel, float y_vel, int speed, int width, int height, int size) : Asset(x_pos, y_pos, 0.f, 0.f, speed, width, height, size)
{
    m_colorR = 0;
    m_colorG = 255;
    m_colorB = 0;
    m_colorA = 255;
}

void Enemy::update(const Asset &target, float timeSinceLastFrame)
{

    m_timeSinceStunned += timeSinceLastFrame;

    if (m_timeSinceStunned < m_stunTime_s)
    {
        m_x_vel = 0.f;
        m_y_vel = 0.f;
        return; // still stunned
    }

    m_new_spawend = false;
    m_Alive_s += timeSinceLastFrame;
    m_stunned = false; // wake up

    // seek target -> normalize vector
    float delta_x = target.getX() - m_x_pos;
    float delta_y = target.getY() - m_y_pos;
    float help = delta_x * delta_x + delta_y * delta_y;
    float norm = 1.f;
    if (help > 0.f)
        norm = sqrt(1.f / help);
    delta_x *= norm;
    delta_y *= norm;

    m_x_vel = m_speed * delta_x;
    m_y_vel = m_speed * delta_y;

    // increase speed
    m_speed = m_speed + (int)(m_speed_incr_perc * 0.01 * m_Alive_s);
}

float Enemy::getTimeSinceStunned() const
{
    return m_timeSinceStunned;
}

void Enemy::setTimeSinceStunned(float time)
{
    m_timeSinceStunned = time;
}

bool Enemy::stun(std::vector<Bullet> &bullets)
{
    if (m_stunned)
    {
        return false;
    }
    bool hitted = false;
    for (int i = 0; i < bullets.size(); ++i)
    {
        if (this->checkCollision(bullets[i]))
        {
            this->m_timeSinceStunned = 0.f;
            m_stunned = true;
            bullets[i].setHit();
            hitted = true;
        }
    }
    return hitted;
}

float Enemy::m_stunTime_s = 2.0;
float Enemy::m_speed_incr_perc = 1.0;

int Enemy::getColorA() const
{
    int blend = (int)((m_timeSinceStunned) / m_stunTime_s * 150.0) - 150 + 255;
    if (m_stunned)
        return blend > 255 ? 255 : blend;
    return 255;
}

int Enemy::getColorR() const
{
    if (m_new_spawend)
    {
        return 255;
    }
    return m_colorR;
}

int Enemy::getColorG() const
{
    if (m_new_spawend)
    {
        return 255;
    }
    return m_colorG;
}

int Enemy::getColorB() const
{
    if (m_new_spawend)
    {
        return 255;
    }
    return m_colorB;
}

bool Enemy::isStunned() const
{
    return m_stunned;
}