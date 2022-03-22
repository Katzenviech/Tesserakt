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
            case SDL_SCANCODE_UP:
            case SDL_SCANCODE_W:
                m_up_pressed = true;
                break;
            case SDL_SCANCODE_DOWN:
            case SDL_SCANCODE_S:
                m_down_pressed = true;
                break;
            case SDL_SCANCODE_A:
            case SDL_SCANCODE_LEFT:
                m_left_pressed = true;
                break;
            case SDL_SCANCODE_D:
            case SDL_SCANCODE_RIGHT:
                m_right_pressed = true;
                break;
            case SDL_SCANCODE_SPACE:
                m_fire_pressed = true;
                break;
            default:
                break;
            }
            break;
        case SDL_KEYUP:
            switch (m_event.key.keysym.scancode)
            {
            case SDL_SCANCODE_UP:
            case SDL_SCANCODE_W:
                m_up_pressed = false;
                break;
            case SDL_SCANCODE_DOWN:
            case SDL_SCANCODE_S:
                m_down_pressed = false;
                break;
            case SDL_SCANCODE_A:
            case SDL_SCANCODE_LEFT:
                m_left_pressed = false;
                break;
            case SDL_SCANCODE_D:
            case SDL_SCANCODE_RIGHT:
                m_right_pressed = false;
                break;
            case SDL_SCANCODE_SPACE:
                m_fire_pressed = false;
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



bool Controller::get_right_pressed() const
{
    return m_right_pressed;
}

bool Controller::get_left_pressed() const
{
    return m_left_pressed;
}

bool Controller::get_up_pressed() const
{
    return m_up_pressed;
}

bool Controller::get_down_pressed() const
{
    return m_down_pressed;
}

bool Controller::get_fire_pressed() const
{
    return m_fire_pressed;
}