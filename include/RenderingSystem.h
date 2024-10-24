#ifndef RENDERING_SYSTEM_H
#define RENDERING_SYSTEM_H

#include "SystemInterface.h"
#include <queue>

namespace sre
{
    class RenderingSystem : public SystemInterface
    {
        //TODO:
        //What if Engine has a ref to RenderingSystem?
        //if so then all Observables (even RenderingObservables)
        //can be bunched up and called during update
        //RenderingObservable then pushes Entities for rendering onto the RenderingSys queue
        //which then gets rendered during Engine's render() call
        public:
            RenderingSystem() : entities() {};
            ~RenderingSystem() = default; //will the pointers in queue need to be managed?
            void update() override {}
            /* Returns the Entity in front of the queue and removes it. Can return nullptr. */
            Entity* pop() override;
            void push(Entity* entity) override;
        private:
            std::queue<Entity*> entities;
    };
}

#endif