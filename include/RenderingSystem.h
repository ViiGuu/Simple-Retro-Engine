#ifndef RENDERING_SYSTEM_H
#define RENDERING_SYSTEM_H

#include "SystemInterface.h"
#include "RenderableComponent.h"
/// \cond
#include <queue>
/// \endcond

namespace sre
{
    /**
     * The RenderingSystem is basically a queue wrapper class. RenderingObservers communicates with RenderingSystem
     * and pushes renderables into its queue. The Renderer then pops the renderables and renders them
     * during the rendering stage of the game loop.
     */
    class RenderingSystem : public SystemInterface
    {
        public:
            RenderingSystem() : renderables() {};
            ~RenderingSystem() = default;
            void update() override {}
            /* Returns the renderable in front of the queue and removes it, or nullptr if the queue is empty */
            RenderableComponent* pop() override;
            void push(ComponentInterface* component) override;
        private:
            std::queue<RenderableComponent*> renderables;
    };
}

#endif