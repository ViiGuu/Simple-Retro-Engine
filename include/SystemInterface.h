#ifndef SYSTEM_INTERFACE_H
#define SYSTEM_INTERFACE_H

#include "Entity.h"

namespace sre
{
    class SystemInterface
    {
        public:
            SystemInterface() = default;
            virtual ~SystemInterface() = default;
            virtual void update() = 0;
            virtual void push(Entity* entity) = 0;
            virtual Entity* pop() = 0;
        private:
            //implement queue for implementation

            //TODO implement CollisionHandlerSystem?

    };
}

#endif