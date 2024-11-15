#include "RenderingSystem.h"
namespace sre
{
    ComponentInterface* RenderingSystem::pop()
    {
        if(components.empty())
            return nullptr;
        
        ComponentInterface* ent = components.front();
        components.pop();
        return ent;
    }

    void RenderingSystem::push(ComponentInterface* component)
    {
        if(component != nullptr)
        {   
            RenderableComponent* ren = dynamic_cast<RenderableComponent*>(component);
            if(ren != nullptr)
                components.push(component);
        }
    }
}
