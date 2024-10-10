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
            //TODO: Implement observer that calls drawEntity, or some other sleek pattern
            //OR just dependency injection. ECS - RenderingSystem implements System, has a reference to SpriteComponent/Component.
            //RenderingSystem is injected into Renderer which renders the Sprite. Yes?
            void drawEntity(void* texture, void* rect) override;
            void initialize(SDL_Window* window);
        protected:
        private:
            SDL_Renderer* renderer;
    };
}


#endif