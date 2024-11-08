#ifndef INPUT_SYSTEM_H
#define INPUT_SYSTEM_H

#include "SystemInterface.h"
#include "Observable.h"

namespace sre
{
    class InputSystem : public SystemInterface, public Observable
    {
        public:
            InputSystem() = default;
            void update() override;
            
        protected:
        private:
            void push(Entity* entity) {}
            Entity* pop() {}

    };
}

#endif