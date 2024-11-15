#ifndef SYSTEM_INTERFACE_H
#define SYSTEM_INTERFACE_H

#include "ComponentInterface.h"

namespace sre
{
    class SystemInterface
    {
        public:
            SystemInterface() = default;
            virtual ~SystemInterface() = default;
            virtual void update() = 0;
            virtual void push(ComponentInterface* component) = 0;
            virtual ComponentInterface* pop() = 0;
        private:
            //implement queue for implementation

    };
}

#endif