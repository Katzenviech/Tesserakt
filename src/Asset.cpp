#include "Asset.h"
#include <cmath>

Asset::Asset(float x_pos, float y_pos, float x_vel, float y_vel, int speed, int width, int height, int size) : m_x_pos{x_pos},
                                                                                                                 m_y_pos{y_pos},
                                                                                                                 m_x_vel{x_vel},
                                                                                                                 m_y_vel{y_vel},
                                                                                                                 m_speed{speed},
                                                                                                                 m_width{width},
                                                                                                                 m_height{height},
                                                                                                                 m_size{size}{}

float Asset::getX() const
{
    return m_x_pos;
}

float Asset::getY() const
{
    return m_y_pos;
}

float Asset::getXVel() const
{
    return m_x_vel;
}

float Asset::getYVel() const
{
    return m_y_vel;
}

int Asset::getSpeed() const
{
    return m_speed;
}

int Asset::getWidth() const
{
    return m_width;
}

int Asset::getHeight() const
{
    return m_height;
}

int Asset::getSize() const
{
    return m_size;
}

void Asset::setX(float x)
{
    m_x_pos = x;
}

void Asset::setY(float y)
{
    m_y_pos = y;
}

void Asset::setXVel(float x_vel)
{
    m_x_vel = x_vel;
}

void Asset::setYVel(float y_vel)
{
    m_y_vel = y_vel;
}

int Asset::getColorR() const
{
    return m_colorR;
}

int Asset::getColorG() const
{
    return m_colorG;
}

int Asset::getColorB() const
{
    return m_colorB;
}

int Asset::getColorA() const
{
    return m_colorA;
}

void Asset::normalizeSpeed()
{
    if ((fabs(m_x_vel) + fabs(m_y_vel)) > m_speed)
    {
        m_x_vel *= 0.71; // 1/sqrt(2)
        m_y_vel *= 0.71;
    }
}
