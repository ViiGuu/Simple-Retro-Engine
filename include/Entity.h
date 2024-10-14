#ifndef ENTITY_H
#define ENTITY_H

#include <vector>
#include "ComponentInterface.h"

namespace sre
{
    class Entity
    {
        public:
            //maybe not delete on these or maybe yes? i mean it should be an interface-ish
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