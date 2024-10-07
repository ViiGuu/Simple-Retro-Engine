#ifndef RENDERER_H
#define RENDERER_H

#include "RendererInterface.h"
#include <SDL2/SDL.h>

namespace sre
{
    class Renderer : public RendererInterface
    {
        public:
        Renderer() = default;
        ~Renderer() = default;
        void update() override;
        void draw() override;
        void renderPresent() override;
        void renderClear() override;
        //needs reference to Window, call from EngineManager AFTER creating window
        //alternatively pass Window through constructor and skip initialize
        void initialize() override;
        protected:
        private:
    };
}


#endif