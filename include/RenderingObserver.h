#ifndef RENDERING_OBSERVER_H
#define RENDERING_OBSERVER_H
#include "Observer.h"
#include "Entity.h"
#include "SystemInterface.h"
#include <iostream>
#include <stdexcept>

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
            /** Should pass a RenderableComponent, otherwise an exception will be thrown. An exception will also be thrown if data is a null pointer */
            void update(const std::any& data) override;
        private:
            SystemInterface* renderingSystem;
    };
}

#endif