#include "Bullet.h"

Bullet::Bullet(float x_pos, float y_pos, float x_vel, float y_vel, int speed, int width, int height, int size) : 
Asset(x_pos - size /2, y_pos - size/2, x_vel, y_vel, speed, width, height, size)
{
    m_colorR = 214;
    m_colorG =  92;
    m_colorB = 172;
    m_colorA = 222;
}

void Bullet::setHit(){
   m_hit = true; 
}

bool Bullet::isHit() const {
    return m_hit;
}