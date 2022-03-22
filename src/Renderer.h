#pragma once

#include <vector>
#include "SDL.h"
#include "Player.h"
#include "Bullet.h"

class Renderer {

public:

    Renderer(int screen_width, int screen_height, int rect_size);
    virtual ~Renderer();

    void render(const Player& player, const std::vector<Bullet>& bullets);
    void updateWindowTitle();

private:
  SDL_Window* sdl_window;
  SDL_Renderer* sdl_renderer;

  int m_screen_width;
  int m_screen_height;
  int m_rect_size;
  
};