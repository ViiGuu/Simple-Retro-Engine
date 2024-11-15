#ifndef OBSERVER_H
#define OBSERVER_H
#include "ComponentInterface.h"
#include <any>

namespace sre
{
    /** Concrete observers need to override update(), and should hold a reference to a Component or other object it needs to interact with. */
    class Observer
    {
        public:
            /** This method passes an std::any, and should use std::any_cast to cast it to the appropriate type */
            virtual void update(const std::any& event) = 0;
        private:
            //reference to the component, so that update can pass data to it?
    };
}

#endif