#ifndef RENDERER_H
#define RENDERER_H

#include "RendererInterface.h"
#include "RenderingSystem.h"
#include "RenderableComponent.h"
/// \cond
#include <iostream>
#include <SDL2/SDL.h>
/// \endcond

namespace sre
{
    /**
     * The Renderer is initialized during Engine creation. It is responsible for rendering the screen
     * and communicating with specific Entities that need to be rendered.
     */
    class Renderer : public RendererInterface
    {
        public:
            Renderer() = default;
            ~Renderer();
            inline SDL_Renderer& getRenderer() {return *renderer;}
            void update() override;
            void draw() override;
            void initialize(SDL_Window* window, RenderingSystem* renderingSys);
        protected:
        private:
            RenderingSystem* renderingSystem;
            SDL_Renderer* renderer;
    };
}


#endif