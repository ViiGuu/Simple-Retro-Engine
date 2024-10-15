#ifndef ENTITY_H
#define ENTITY_H

#include <vector>
#include "ComponentInterface.h"

namespace sre
{
    class Entity
    {
        public:
            //set to protected default so subclasses can use.
           Entity() = delete;
           Entity(const Entity&) = delete;
           Entity& operator=(const Entity& other) = delete;
        protected:
        private:
            const int id;
            std::vector<ComponentInterface> components;
    };
}

#endif