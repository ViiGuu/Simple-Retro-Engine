#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <atomic>
#include <stdexcept>
#include <memory>
#include <vector>
#include "Manager.h"
#include "SceneNavigatorInterface.h"
#include "RendererInterface.h"
#include "WindowInterface.h"


namespace sre
{
    /**
     * The main engine responsible for running the game.
     * Creation, access and cleanup of the engine is handled by the EngineManager, which must first be created by the user.
     * See the documentation for the EngineManager class for more details.
     * Before calling the run() function to start the game loop, the engine must be initialized using the initialize() function.
     * 
     * While single-object creation is not strictly enforced, 
     * creating more than one Engine object is redundant and will lead to undefined behaviour.
     * 
     * @author Viggo Gustafsson
     */
    class Engine
    {
        public:
            ~Engine();
            WindowInterface& getWindow();
            RendererInterface& getRenderer();
            bool isInitialized();
            void run();
            Engine(const Engine&) = delete; 
            Engine operator= (const Engine&) = delete;
        protected:
            void setRenderer(RendererInterface& ren);
            void setWindow(WindowInterface& win);
            void initialize();
        private:
            //ensure that a Scene is present before run() is called
            std::unique_ptr<SceneNavigatorInterface> scenes; // will it need this pointer? if the scene communicates with the observer/observable...z
            //vector of observables for different systems?
            //if so a lot of different systems can be handled in a decoupled way.
            WindowInterface* window; //these 2 might be redundant to keep in Engine
            RendererInterface* renderer;
            Engine() : window(nullptr), renderer(nullptr), initialized(false) {}
            bool initialized;
            //TODO look over how the different parts should interact in general...
            //TODO scenes.getActive().update(); or something
            void update();
            void render();

            friend class EngineManager;
    };
}



#endif