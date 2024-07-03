#include "Engine.h"

namespace sre
{
    void Engine::initialize(std::string windowName)
    {
        SDL_Init(SDL_INIT_EVERYTHING);
        if (SDL_Init(SDL_INIT_EVERYTHING) < 0) 
        {
            std::cerr << "Failed to initialize SDL. SDL error: " << SDL_GetError() << std::endl;
            exit(-1);
        }
        
        initialized = true;
    }

    void Engine::run()
    {

    }

    Engine::~Engine()
    {
        SDL_Quit();
    }

}
