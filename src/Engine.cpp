#include "Engine.h"

namespace sre
{
    std::unique_ptr<Engine> Engine::create()
    {
        return std::unique_ptr<Engine>(new Engine());
    }

    void Engine::initialize(std::string windowName)
    {
        SDL_Init(SDL_INIT_EVERYTHING);
        if (SDL_Init(SDL_INIT_EVERYTHING) < 0) 
        {
            std::cerr << "Failed to initialize SDL. SDL error: " << SDL_GetError() << std::endl;
            exit(-1);
        }
    }

    void Engine::run()
    {

    }

    void Engine::quit()
    {

    }
    

}
