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

    bool Engine::isInitialized()
    {
        if (initialized == true && window != nullptr && renderer != nullptr)
        {
            return true;
        }
        return false;
    }

    void Engine::setRenderer(RendererInterface& ren)
    {
        renderer = &ren;
    }

    void Engine::setWindow(WindowInterface& win)
    {
        window = &win;
    }

    void Engine::initialize()
    {
        if(isInitialized())
            return;

        //TODO: initialize all the Observables. potentially refactor into some kind of Builder and let user decide which observables to initialize with (or just straight up let them add them before calling init)

        if (SDL_Init(SDL_INIT_EVERYTHING) < 0) 
        {
            std::cerr << "Failed to initialize SDL! SDL error: " << SDL_GetError() << std::endl;
            exit(-1);
        }

        if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
        {
            std::cerr << "SDL_mixer could not be initialized! SDL_mixer Error: " << Mix_GetError() << std::endl;
            exit(-1);
        }
        
        initialized = true;
    }

    void Engine::run()
    {
        //TODO: add quitting logic.
        while(true)
        {
            update();
            render();
        }
    }

    void Engine::update()
    {
        //check for empty sys?

        std::for_each(systems.begin(), systems.end(),
        [](SystemInterface* sys)
        {
            sys->update();
        });

        renderer->update();
    }

    void Engine::render()
    {
        //render scene
        renderer->draw();
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
