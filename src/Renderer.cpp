#include <iostream>
#include "Renderer.h"

Renderer::Renderer(int screen_width, int screen_height, int rect_size)
    : m_screen_width{screen_width}, m_screen_height{screen_height}, m_rect_size{rect_size}
{
    /* Initializes the timer, audio, video, joystick,
    haptic, gamecontroller and events subsystems */
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        std::cerr << "SDL could not be initialized.\n";
        std::cerr << "Error initializing SDL: " << SDL_GetError() << "\n";
        SDL_Quit();
    }

    /* Create a window */
    sdl_window = SDL_CreateWindow("TESSERAKT",
                                              SDL_WINDOWPOS_CENTERED,
                                              SDL_WINDOWPOS_CENTERED,
                                              m_screen_width, m_screen_height,
                                              SDL_WINDOW_SHOWN);

    if (nullptr == sdl_window)
    {
        std::cerr << "Error creating window: " << SDL_GetError() << "\n";
        SDL_Quit();
    }

    /* Create a renderer */
    int32_t render_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
    sdl_renderer = SDL_CreateRenderer(sdl_window, -1, render_flags);
    if (nullptr == sdl_renderer)
    {
        std::cerr << "Error creating renderer: " << SDL_GetError() << "\n";
        SDL_DestroyWindow(sdl_window);
        SDL_Quit();
    }
    SDL_SetRenderDrawBlendMode(sdl_renderer, SDL_BLENDMODE_BLEND);

}

Renderer::~Renderer()
{
    /* Release resources */
    SDL_DestroyRenderer(sdl_renderer);
    SDL_DestroyWindow(sdl_window);
    SDL_Quit();
}

void Renderer::render(const Player& player, const std::vector<Bullet>& bullets, const std::vector<Enemy>& enemies)
{
    SDL_Rect sdl_rect;

    /* Clear screen */
    SDL_SetRenderDrawColor(sdl_renderer, 0, 0, 0, 255);
    SDL_RenderClear(sdl_renderer);

    /* Draw the bullets */
    for(const Bullet& b : bullets){
        SDL_SetRenderDrawColor(sdl_renderer, b.getColorR(), b.getColorG(), b.getColorB(), b.getColorA());
        sdl_rect = {(int)b.getX(), (int)b.getY(), b.getSize(), b.getSize()};
        SDL_RenderFillRect(sdl_renderer, &sdl_rect);
    }


    /* Draw the player */
    sdl_rect = {(int)player.getX(), (int)player.getY(), player.getSize(), player.getSize()};
    SDL_SetRenderDrawColor(sdl_renderer, player.getColorR(), player.getColorG(), player.getColorB(), player.getColorA());
    SDL_RenderFillRect(sdl_renderer, &sdl_rect);
    
    /* Draw the enemies */
    for(const Enemy& e : enemies){
        sdl_rect = {(int)e.getX(), (int)e.getY(), e.getSize(), e.getSize()};
        SDL_SetRenderDrawColor(sdl_renderer, e.getColorR(), e.getColorG(), e.getColorB(), e.getColorA());
        SDL_RenderFillRect(sdl_renderer, &sdl_rect);
    }

    /* Draw to window and loop */
    SDL_RenderPresent(sdl_renderer);

}

void Renderer::updateWindowTitle(){
    return;
}