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
#include "SceneInterface.h"


//TODO: Implement a Scene class
//TODO: Implement an Entity Component System
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
            /** Initializes the engine with the given window name.
             * 
             * @param windowName The name of the window.
             */
            void initialize(const std::string windowName);

            /** Function responsible for running the main game loop. */
            void run();
            Engine(const Engine&) = delete; 
            Engine operator= (const Engine&) = delete;
        protected:
        private:
            //ensure that a Scene is present before run() is called
            std::unique_ptr<int> scenes; //placeholder value
            SDL_Window* window;
            SDL_Renderer* renderer;
            friend class EngineManager;
            Engine() : window(nullptr), renderer(nullptr), initialized(false) {}
            bool initialized;
             /** Updates the various behaviours in the game. */
            void update(); //calls scene.update();
            void render();
    };
}



#endif