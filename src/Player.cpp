#include "Player.h"

Player::Player(float x_pos, float y_pos, float x_vel, float y_vel, int speed, int jump, int width, int height, int size) : m_x_pos{x_pos},
                                                                                                                           m_y_pos{y_pos},
                                                                                                                           m_x_vel{x_vel},
                                                                                                                           m_y_vel{y_vel},
                                                                                                                           m_speed{speed},
                                                                                                                           m_jump{jump},
                                                                                                                           m_width{width},
                                                                                                                           m_height{height},
                                                                                                                           m_size{size} {}

float Player::getX() const
{
    return m_x_pos;
}

float Player::getY() const
{
    return m_y_pos;
}

float Player::getXVel() const
{
    return m_x_vel;
}

float Player::getYVel() const
{
    return m_y_vel;
}

int Player::getSpeed() const
{
    return m_speed;
}

int Player::getJump() const
{
    return m_jump;
}

bool Player::canJump() const
{
    return m_can_jump;
}

int Player::getWidth() const
{
    return m_width;
}

int Player::getHeight() const
{
    return m_height;
}

int Player::getSize() const
{
    return m_size;
}

void Player::setX(float x)
{
    m_x_pos = x;
}

void Player::setY(float y)
{
    m_y_pos = y;
}

void Player::setXVel(float x_vel)
{
    m_x_vel = x_vel;
}

void Player::setYVel(float y_vel)
{
    m_y_vel = y_vel;
}

void Player::setCanJump(bool set)
{
    m_can_jump = set;
}

int Player::getColorR() const
{
    return m_colorR;
}

int Player::getColorG() const
{
    return m_colorG;
}

int Player::getColorB() const
{
    return m_colorB;
}

int Player::getColorA() const
{
    return m_colorA;
}
