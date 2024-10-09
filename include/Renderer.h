#ifndef RENDERER_H
#define RENDERER_H

#include "RendererInterface.h"
#include <iostream>
#include <SDL2/SDL.h>

namespace sre
{
    class Renderer : public RendererInterface
    {
        public:
        Renderer() = default;
        ~Renderer();
        SDL_Renderer& getRenderer() {return *renderer;}
        void update() override;
        void draw() override;
        //TODO: Implement observer that calls drawEntity
        void drawEntity(SDL_Texture* texture, SDL_Rect* rect);
        void initialize(SDL_Window* window);
        protected:
        private:
        SDL_Renderer* renderer;
    };
}


#endif