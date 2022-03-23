#pragma once
#include <vector>
#include "Asset.h"
#include "Bullet.h"


class Enemy : public Asset
{

public:
    Enemy(float x_pos, float y_pos, float x_vel, float y_vel, int speed, int width, int height, int size);
    virtual ~Enemy() = default;

    void update(const Asset& target, float timeSinceLastFrame);
    bool stun(std::vector<Bullet>& bullets);

    float getTimeSinceStunned() const;
    void setTimeSinceStunned(float time);

    static float m_stunTime_s;

    int getColorA() const;
    bool isStunned() const;

private:
    float m_timeSinceStunned = 0.f;
    bool m_stunned = true;
    float m_Alive_s = 0.f;


};
