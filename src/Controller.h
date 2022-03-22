#pragma once
#include "SDL.h"
#include "Player.h"

class Controller{

public:

    void HandleInput(bool& running, Player& player);

    // Getter
    bool get_right_pressed() const;
    bool get_left_pressed() const;
    bool get_up_pressed() const;
    bool get_down_pressed() const;
    bool get_fire_left_pressed() const;
    bool get_fire_right_pressed() const;
    bool get_fire_up_pressed() const;
    bool get_fire_down_pressed() const;

private:
    SDL_Event m_event;

    bool m_right_pressed = false;
    bool m_left_pressed = false;
    bool m_up_pressed = false;
    bool m_down_pressed = false;
    bool m_fire_left_pressed = false;
    bool m_fire_right_pressed = false;
    bool m_fire_up_pressed = false;
    bool m_fire_down_pressed = false;

};