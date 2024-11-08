#ifndef RENDERING_OBSERVER_H
#define RENDERING_OBSERVER_H
#include "Observer.h"
#include "Entity.h"
#include "SystemInterface.h"

namespace sre
{
    /**
     * Add a RenderingObserver to Entities that need to interact with the Renderer through the RenderingSystem.
     * A prerequisite is that the Entity has a RenderableComponent
     */
    class RenderingObserver : public Observer
    {
        //TODO create some unit tests once a RenderableComponent has been implemented
        public:
            RenderingObserver(SystemInterface* renderSys) : renderingSystem(renderSys) {}
            void update() override;
            void update(Entity* entity); //component instead of entity
        private:
            SystemInterface* renderingSystem;
    };
}

#endif