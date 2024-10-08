#ifndef ENGINEMANAGER_H
#define ENGINEMANAGER_H

#include "Engine.h"
#include "Manager.h"
#include "Renderer.h"
#include "Window.h"
#include <memory>

//TODO: break out Render and Window creation into their own functions, document the intended order of creation.
namespace sre
{
    /**
     * The EngineManager serves as a pipeline for creating, accessing and destroying the game engine.
     * To create a new Engine, first create an EngineManager object and then call the create() function
     * to create a reference to a new Engine object. To destroy the Engine, call the destroy() function.
     * 
     * @author Viggo Gustafsson
     */
    class EngineManager : public Manager<Engine>
    {
        public:
            EngineManager() = default;
            ~EngineManager() = default;
            Engine& create() override;
            void destroy() override;
        private:
        //smart pointer to Window or similar
        std::unique_ptr<Renderer> renderer;
        std::unique_ptr<Window> window;

    };
}

#endif