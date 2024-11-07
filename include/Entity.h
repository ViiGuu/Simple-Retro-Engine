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
           Entity(const Entity&) = delete;
           Entity& operator=(const Entity& other) = delete;
        protected:
            Entity() = default;
        private:
            const int id; //relevant?
            std::vector<ComponentInterface> components;
    };
}

#endif