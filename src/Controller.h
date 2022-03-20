#pragma once
#include "SDL.h"
#include "Player.h"

class Controller{

public:

    void HandleInput(bool& running, Player& player);

    // Setter
    void set_right_pressed(bool set);
    void set_left_pressed(bool set);
    void set_jump_pressed(bool set);

    // Getter
    bool get_right_pressed() const;
    bool get_left_pressed() const;
    bool get_jump_pressed() const;

private:
    SDL_Event m_event;

    bool m_right_pressed = false;
    bool m_left_pressed = false;
    bool m_jump_pressed = false;

};