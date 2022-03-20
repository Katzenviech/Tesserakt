#include "Controller.h"

void Controller::HandleInput(bool &running, Player &player)
{

    while (SDL_PollEvent(&m_event))
    {
        switch (m_event.type)
        {
        case SDL_QUIT:
            running = false;
            break;
        case SDL_KEYDOWN:
            switch (m_event.key.keysym.scancode)
            {
            case SDL_SCANCODE_SPACE:
            case SDL_SCANCODE_UP:
            case SDL_SCANCODE_W:
                m_jump_pressed = true;
                break;
            case SDL_SCANCODE_A:
            case SDL_SCANCODE_LEFT:
                m_left_pressed = true;
                break;
            case SDL_SCANCODE_D:
            case SDL_SCANCODE_RIGHT:
                m_right_pressed = true;
                break;
            default:
                break;
            }
            break;
        case SDL_KEYUP:
            switch (m_event.key.keysym.scancode)
            {
            case SDL_SCANCODE_SPACE:
            case SDL_SCANCODE_UP:
            case SDL_SCANCODE_W:
                m_jump_pressed = false;
                break;
            case SDL_SCANCODE_A:
            case SDL_SCANCODE_LEFT:
                m_left_pressed = false;
                break;
            case SDL_SCANCODE_D:
            case SDL_SCANCODE_RIGHT:
                m_right_pressed = false;
                break;
            default:
                break;
            }
            break;
        default:
            break;
        }
    }
}

void Controller::set_right_pressed(bool set)
{
    m_right_pressed = set;
}

void Controller::set_left_pressed(bool set)
{
    m_left_pressed = set;
}

void Controller::set_jump_pressed(bool set)
{
    m_jump_pressed = true;
}

bool Controller::get_right_pressed() const
{
    return m_right_pressed;
}

bool Controller::get_left_pressed() const
{
    return m_left_pressed;
}

bool Controller::get_jump_pressed() const
{
    return m_jump_pressed;
}