#include "Engine.h"

Engine* Engine::create()
    {
        try 
    {
        bool expected = false;

        if (!engineCreated.compare_exchange_strong(expected, true))
        {
            throw std::runtime_error("Only one Engine can be created.");
        }

        engineCreated.store(true);
        return new Engine();
    } catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
        return nullptr;
    }
    }

void Engine::run()
{

}

void Engine::initialize()
{

}

void Engine::destroy()
{

}
