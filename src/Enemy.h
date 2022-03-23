#pragma once
#include "Asset.h"

class Enemy : public Asset
{

public:
    Enemy(float x_pos, float y_pos, float x_vel, float y_vel, int speed, int width, int height, int size);
    virtual ~Enemy() = default;

    void seekTarget(const Asset& target);

private:

};
