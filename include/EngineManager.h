#ifndef ENGINEMANAGER_H
#define ENGINEMANAGER_H

#include "Engine.h"
#include "Manager.h"
#include "Renderer.h"
#include "RenderingSystem.h"
#include "Window.h"
#include <memory>

namespace sre
{
    /**
     * The EngineManager serves as a pipeline for creating, accessing and destroying the game engine, as well as relevant external parts.
     * To create a new Engine, first create an EngineManager object and then call the create() function
     * to create a reference to a new Engine object. To destroy the Engine, call the destroy() function.
     * 
     * @author Viggo Gustafsson
     */
    //TODO maybe use builder pattern to create the engine, allow user to specify Window, Renderer details etc. just a thought
    class EngineManager : public Manager<Engine>
    {
        public:
            EngineManager() = default;
            ~EngineManager() = default;
            Engine& create() override;
            void destroy() override;
        private:
            std::unique_ptr<Renderer> renderer;
            std::unique_ptr<Window> window;
            std::unique_ptr<RenderingSystem> renderSys;

    };
}

#endif