#include "Enemy.h"
#include <cmath>

Enemy::Enemy(float x_pos, float y_pos, float x_vel, float y_vel, int speed, int width, int height, int size) : 
Asset(x_pos, y_pos, 0.f, 0.f, speed, width, height, size)
{
    m_colorR = 0;
    m_colorG = 255;
    m_colorB = 0;
    m_colorA = 255;
}

void Enemy::seekTarget(const Asset& target){
    // normalize vector
    float delta_x = target.getX() - m_x_pos;
    float delta_y = target.getY() - m_y_pos;
    float help = delta_x*delta_x + delta_y*delta_y;
    float norm = 1.f;
    if(help > 0.f)
        norm = sqrt(1.f / help);
    delta_x *= norm;
    delta_y *= norm;

    m_x_vel = m_speed * delta_x;
    m_y_vel = m_speed * delta_y;

}