#ifndef RENDERABLE_COMPONENT_H
#define RENDERABLE_COMPONENT_H

#include "ComponentInterface.h"

namespace sre
{
 class RenderableComponent : public ComponentInterface
 {
    //TODO: add sdl_rect, sdl_texture, x, y ? 
    public:
        RenderableComponent() = default;
        ~RenderableComponent() = default;
    private:
 };
    
}


#endif