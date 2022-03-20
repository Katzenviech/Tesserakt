#pragma once

#include "SDL.h"
#include "Player.h"

class Renderer {

public:

    Renderer(int screen_width, int screen_height, int rect_size);
    virtual ~Renderer();

    void render(const Player& player);
    void updateWindowTitle();

private:
  SDL_Window* sdl_window;
  SDL_Renderer* sdl_renderer;
  SDL_Rect sdl_rect;

  int m_screen_width;
  int m_screen_height;
  int m_rect_size;
  
};