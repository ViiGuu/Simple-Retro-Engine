#ifndef ENTITY_H
#define ENTITY_H
/// \cond
#include <vector>
/// \endcond
#include "ComponentInterface.h"

namespace sre
{
    class Entity
    {
        public:
            //set to protected default so subclasses can use.
           Entity(const Entity&) = delete;
           Entity& operator=(const Entity& other) = delete;
        protected:
            Entity() = default;
        private:
            const int id;
            std::vector<ComponentInterface> components;
    };
}

#endif