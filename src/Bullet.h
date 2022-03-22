#pragma once
#include "Asset.h"

class Bullet : public Asset {

public:
    Bullet(float x_pos, float y_pos, float x_vel, float y_vel, int speed, int width, int height, int size);
    virtual ~Bullet() = default;
    
private:


};