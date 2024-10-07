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


namespace sre
{
    /**
     * The main engine responsible for running the game.
     * Creation, access and cleanup of the engine is handled by the EngineManager, which must first be created by the user.
     * See the documentation for the EngineManager class for more details.
     * Before calling the run() function to start the game loop, the engine must be initialized using the initialize() function.
     * 
     * While single-object creation is not strictly enforced, 
     * creating more than one Engine object is redundant and can lead to undefined behaviour.
     * 
     * @author Viggo Gustafsson
     */
    class Engine
    {
        public:
            ~Engine();
            SDL_Window& getWindow();
            SDL_Renderer& getRenderer();
            bool isInitialized() { return initialized; }
            void initialize(const std::string windowName);
            void run();
            Engine(const Engine&) = delete; 
            Engine operator= (const Engine&) = delete;
        protected:
            void setRenderer(RendererInterface& ren);
        private:
            //ensure that a Scene is present before run() is called
            std::unique_ptr<SceneNavigatorInterface> scenes;
            SDL_Window* window;
            //remove once Renderer class has been implemented
            // or set to ren.get() ?
            // probably remove and keep renderer hidden from engine
            SDL_Renderer* renderer;
            RendererInterface& ren;
            Engine(RendererInterface* rend) : window(nullptr), renderer(nullptr), initialized(false), ren(*rend) {}
            bool initialized;
            void update(); //calls scene.update();
            void render();

            friend class EngineManager;
    };
}



#endif