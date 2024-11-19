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
        while(RenderableComponent* component = renderingSystem->pop())
        {
            //swap out texture and rect with ent.getRen.texture() etc.

            // if(renderer == nullptr)
            //     throw std::runtime_error("Renderer has not been initialized");

            // if(texture == nullptr)
            //     throw std::runtime_error("Texture has not been initialized");

            // if(rect == nullptr)
            //     throw std::runtime_error("Rect has not been initialized");
            
            // SDL_Texture* texturePtr = static_cast<SDL_Texture*>(texture);
            // if(texturePtr == nullptr)
            //     throw std::runtime_error("SDL_Texture expected");

            // SDL_Rect* rectPtr = static_cast<SDL_Rect*>(rect);
            // if(rectPtr == nullptr)
            //     throw std::runtime_error("SDL_Rect expected");

            // SDL_RenderCopy(renderer, static_cast<SDL_Texture*>(texture), NULL, static_cast<SDL_Rect*>(rect));
        }
        
        SDL_RenderPresent(renderer);
    }

    void Renderer::initialize(SDL_Window* window, RenderingSystem* renderingSys)
    {
        renderer = (SDL_CreateRenderer(window, SDL_RENDERER_ACCELERATED, 0));
        if (!renderer)
        {
            std::cerr << "Renderer could not be created! SDL Error: " << SDL_GetError() << std::endl;
            exit(-1);
        }
    }
}