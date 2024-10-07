#include "EngineManager.h"

namespace sre
{
    Engine& EngineManager::create()
    {
        if (managed)
        {
            throw std::runtime_error("Object already created");
        }
        //create window and then pass to renderer
        renderer = std::unique_ptr<Renderer>(new Renderer());
        managed = std::unique_ptr<Engine>(new Engine(&(*renderer)));
        managed->setRenderer(*renderer);
        return *managed; 
    }

    void EngineManager::destroy()
    {
        if (!managed) 
        {
            throw std::runtime_error("Object not created");
        }

        managed.reset();
    }


}