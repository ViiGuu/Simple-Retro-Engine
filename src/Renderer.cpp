#include "Renderer.h"

namespace sre
{
    Renderer::~Renderer()
    {
        SDL_DestroyRenderer(renderer);
        renderer = nullptr;
    }

    void Renderer::update()
    {
        SDL_RenderClear(renderer);
    }

    void Renderer::draw()
    {
        SDL_RenderPresent(renderer);
    }

    void Renderer::drawEntity(SDL_Texture* texture, SDL_Rect* rect)
    {
        SDL_RenderCopy(renderer, texture, NULL, rect);
    }

    void Renderer::initialize(SDL_Window* window)
    {
        renderer = (SDL_CreateRenderer(window, SDL_RENDERER_ACCELERATED, 0));
        if (!renderer)
        {
            std::cerr << "Renderer could not be created! SDL Error: " << SDL_GetError() << std::endl;
            exit(-1);
        }
    }
}