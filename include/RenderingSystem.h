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
     * and pushes components/Renderables into its queue. The Renderer then pops the components/Renderables and renders them
     * during the rendering stage of the game loop.
     */
    class RenderingSystem : public SystemInterface
    {
        //TODO: Refactor, merge with Renderer (make Renderer implement System) and implement Observable.
            //Should handle Components (RenderableComponents) instead of components
        public:
            RenderingSystem() : components() {};
            ~RenderingSystem() = default;
            void update() override {}
            /* Returns the ComponentInterface in front of the queue and removes it, or nullptr if the queue is empty*/
            ComponentInterface* pop() override;
            void push(ComponentInterface* component) override;
        private:
            std::queue<ComponentInterface*> components;
    };
}

#endif