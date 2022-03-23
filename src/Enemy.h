#pragma once
#include <vector>
#include "Asset.h"
#include "Bullet.h"


class Enemy : public Asset
{

public:
    Enemy(float x_pos, float y_pos, float x_vel, float y_vel, int speed, int width, int height, int size);
    virtual ~Enemy() = default;

    void seekTarget(const Asset& target, float timeSinceLastFrame);
    bool stun(std::vector<Bullet>& bullets);

    float getTimeSinceStunned() const;
    void setTimeSinceStunnde(float time);

    static float m_stunTime_s;

private:
    float m_timeSinceStunned = 0.f;


};
