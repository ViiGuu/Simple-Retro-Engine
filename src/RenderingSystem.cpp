#include "RenderingSystem.h"
namespace sre
{
    Entity* RenderingSystem::pop()
    {
        if(entities.empty())
            return nullptr;
        
        Entity* ent = entities.front();
        entities.pop();
        return ent;
    }

    void RenderingSystem::push(Entity* entity)
    {
        if(entity != nullptr)
            entities.push(entity);
    }
}
