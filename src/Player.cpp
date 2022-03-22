#include <cmath>
#include "Player.h"

Player::Player(float x_pos, float y_pos, float x_vel, float y_vel, int speed, int width, int height, int size) : 
Asset(x_pos, y_pos, x_vel, y_vel, speed, width, height, size)
{
    m_colorR = 255;
    m_colorG = 0;
    m_colorB = 0;
    m_colorA = 255;
}
