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
        //MAYBE it makes more sense to not have this observer attached to the RenderingSystem,
        //instead use Observable which pushes the Observer into the RenderingSystem queue
        public:
            RenderingObserver(SystemInterface* renderSys) : renderingSystem(renderSys) {}
            void update() override;
            void update(Entity* entity);
        private:
            SystemInterface* renderingSystem;
    };
}

#endif