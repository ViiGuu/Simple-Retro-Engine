#include "RenderingSystem.h"
namespace sre
{
    RenderableComponent* RenderingSystem::pop()
    {
        if(renderables.empty())
            return nullptr;
        
        RenderableComponent* ren = renderables.front();
        renderables.pop();
        return ren;
    }

    void RenderingSystem::push(ComponentInterface* component)
    {
        if(component != nullptr)
        {   
            RenderableComponent* ren = dynamic_cast<RenderableComponent*>(component);
            if(ren != nullptr)
                renderables.push(ren);
        }
    }
}
