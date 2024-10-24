#include "RenderingObserver.h"

namespace sre
{
    void RenderingObserver::update()
    {

    }
    void RenderingObserver::update(Entity* entity)
    {
        //make a check for if the Entity has a RenderableComponent or whatever
        renderingSystem->push(entity);
    }
    
}