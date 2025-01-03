#include "EngineManager.h"

namespace sre
{
    Engine& EngineManager::create()
    {
        if (managed)
        {
            throw std::runtime_error("Object already created");
        }

        managed = std::unique_ptr<Engine>(new Engine());
        managed->initialize();

        window = std::unique_ptr<Window>(new Window());
        window->initialize("Game"); //fix custom names in the future

        renderSys = std::unique_ptr<RenderingSystem>(new RenderingSystem());
        renderer = std::unique_ptr<Renderer>(new Renderer());
        renderer->initialize(&window->getWindow(), renderSys.get());
        
        managed->setRenderer(*renderer);
        managed->setWindow(*window);
        return *managed; 
    }

    void EngineManager::destroy()
    {
        if (!managed) 
            throw std::runtime_error("Engine not created");
        managed.reset();

        if (!window)
            throw std::runtime_error("Window not created");
        window.reset();

        if (!renderSys)
            throw std::runtime_error("Rendering System not created");
        renderSys.reset();
    
        if (!renderer)
            throw std::runtime_error("Window not created");
        renderer.reset();
    }


}