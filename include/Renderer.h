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
        void update() override;
        void draw() override;
        void renderPresent() override;
        void renderClear() override;
        //needs reference to Window, call from EngineManager AFTER creating window
        //alternatively pass Window through constructor and skip initialize
        void initialize(SDL_Window* window);
        protected:
        private:
        SDL_Renderer* renderer;
    };
}


#endif