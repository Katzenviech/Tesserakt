#pragma once
#include "Asset.h"

class Player : public Asset {

public:
    Player(float x_pos, float y_pos, float x_vel, float y_vel, int speed, int width, int height, int size);
    virtual ~Player() = default;

    float getTimeSinceLastShot() const;
    void setTimeSinceLastShot(float time);

private:
    float m_timeSinceLastShot = 0.f;
};
