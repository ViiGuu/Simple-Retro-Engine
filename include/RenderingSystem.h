#ifndef RENDERING_SYSTEM_H
#define RENDERING_SYSTEM_H

#include "SystemInterface.h"
#include <queue>

namespace sre
{
    /**
     * The RenderingSystem is basically a queue wrapper class. RenderingObservers communicates with RenderingSystem
     * and pushes Entities/Renderables into its queue. The Renderer then pops the Entities/Renderables and renders them
     * during the rendering stage of the game loop.
     */
    class RenderingSystem : public SystemInterface
    {
        //TODO: let the renderingsystem handle RenderableComponents instead of entire entities.
        //(once they are implemented that is)
        public:
            RenderingSystem() : entities() {};
            ~RenderingSystem() = default;
            void update() override {}
            /* Returns the Entity in front of the queue and removes it, or nullptr if the queue is empty*/
            Entity* pop() override;
            void push(Entity* entity) override;
        private:
            std::queue<Entity*> entities;
    };
}

#endif