#pragma once

class Asset{
public:
    Asset(  float x_pos,
            float y_pos,
            float x_vel,
            float y_vel,
            int speed,
            int width,
            int height,
            int size
        );

    virtual ~Asset() = default;

    // Getter
    float getX() const;
    float getY() const;
    float getXVel() const;
    float getYVel() const;
    int getSpeed() const;

    int getWidth() const;
    int getHeight() const;
    int getSize() const;
    int getColorR() const;
    int getColorG() const;
    int getColorB() const;
    int getColorA() const;

    // Setter
    void setX(float x);
    void setY(float y);
    void setXVel(float x_vel);
    void setYVel(float y_vel);

    void normalizeSpeed();

    bool checkCollision(const Asset& other);
    
protected:
    float m_x_pos;
    float m_y_pos;
    float m_x_vel;
    float m_y_vel;
    int m_speed;
   
    int m_width;
    int m_height;
    int m_size;

    int m_colorR = 0;
    int m_colorG = 0;
    int m_colorB = 0;
    int m_colorA = 255;


};