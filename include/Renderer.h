#ifndef RENDERER_H
#define RENDERER_H

#include "RendererInterface.h"
#include "SystemInterface.h"
#include <iostream>
#include <SDL2/SDL.h>

namespace sre
{
    /**
     * The Renderer is initialized during Engine creation. It is responsible for rendering the screen
     * and communicating with specific Entities that need to be rendered.
     */
    class Renderer : public RendererInterface
    {
        //order of rendering:
        //all entities are updated which is follow by Renderer.update()
        //all entities are drawn one by one with Renderer.drawEntity()
        //finally draw() is called which updates the screen.
        //or i guess draw() will call RenderPresent after calling drawEntity for all Entities in the RenderingSystem queue
        public:
            Renderer() = default;
            ~Renderer();
            inline SDL_Renderer& getRenderer() {return *renderer;}
            void update() override;
            void draw() override;
            //this can probably be private and called from draw which goes through the renderingSystem queue?
            //can pass something like while queue not empty, pop Entity and pass to drawEntity
            void drawEntity(void* texture, void* rect) override;
            void initialize(SDL_Window* window, SystemInterface* renderingSys);
        protected:
        private:
            SystemInterface* renderingSystem;
            SDL_Renderer* renderer;
    };
}


#endif