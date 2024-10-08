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

    }

    void Renderer::draw()
    {

    }

    void Renderer::renderPresent()
    {

    }

    void Renderer::renderClear()
    {
        
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