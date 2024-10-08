#include "Engine.h"

namespace sre
{

    WindowInterface& Engine::getWindow()
    {
        if (window == nullptr)
        {
            throw std::runtime_error("Window has not been initialized");
        }
        return *window;
    }

    RendererInterface& Engine::getRenderer()
    {
        if (renderer == nullptr)
        {
            throw std::runtime_error("Renderer has not been initialized");
        }
        return *renderer;
    }

    void Engine::setRenderer(RendererInterface& ren)
    {
        renderer = &ren;
    }

    void Engine::initialize()
    {
        if (SDL_Init(SDL_INIT_EVERYTHING) < 0) 
        {
            std::cerr << "Failed to initialize SDL! SDL error: " << SDL_GetError() << std::endl;
            exit(-1);
        }

        // window = SDL_CreateWindow(windowName.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1920, 1080, SDL_WINDOW_MAXIMIZED);
        // if (!window) 
        // {
        //     std::cerr << "Window could not be created! SDL Error: " << SDL_GetError() << std::endl;
        //     exit(-1);
        // }

        // renderer = (SDL_CreateRenderer(window, SDL_RENDERER_ACCELERATED, 0));
        // if (!renderer)
        // {
        //     std::cerr << "Renderer could not be created! SDL Error: " << SDL_GetError() << std::endl;
        //     exit(-1);
        // }

        if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
        {
            std::cerr << "SDL_mixer could not be initialized! SDL_mixer Error: " << Mix_GetError() << std::endl;
            exit(-1);
        }
        
        initialized = true;
    }

    void Engine::run()
    {

    }

    Engine::~Engine()
    {
        if(isInitialized())
        {
            // SDL_DestroyRenderer(renderer);
            renderer = nullptr;
            // SDL_DestroyWindow(window);
            window = nullptr;
            Mix_CloseAudio();
            TTF_Quit();
        }
        
        SDL_Quit();
    }

}
