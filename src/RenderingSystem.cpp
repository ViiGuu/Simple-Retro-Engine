#include "RenderingSystem.h"
namespace sre
{
    Entity& RenderingSystem::getEntity()
    {
        Entity* ent = entities.front();
        entities.pop();
        return *ent;
    }

    void RenderingSystem::push(Entity* entity)
    {
        if(entity != nullptr)
            entities.push(entity);
    }
}
