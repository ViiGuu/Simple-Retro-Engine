#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>
#include <string>
#include <SDL.h>
#include <atomic>
#include <stdexcept>
#include <memory>
#include <vector>
#include "Manager.h"

namespace sre
{
    /**
     * The main engine responsible for running the game.
     * Creation, access and cleanup of the engine is handled by the EngineManager, which must first be created by the user.
     * See the documentation for the EngineManager class for more details.
     * Before calling the run() function to start the game loop, the engine must be initialized using the initialize() function.
     * 
     * While single-object creation is not strictly enforced, 
     * creating more than one Engine object can lead to undefined behaviour and should be reserved for testing purposes.
     * 
     * @author Viggo Gustafsson
     */
    class Engine
    {
        public:
            ~Engine();
            /** Initializes the engine with the given window name.
             * 
             * @param windowName The name of the window.
             */
            void initialize(std::string windowName);

            /** Function responsible for running the main game loop. */
            void run();
            Engine(const Engine&) = delete; 
            Engine operator= (const Engine&) = delete;
        protected:
        private:
            friend class EngineManager;
            Engine() {}
             /** Updates the various behaviours in the game. */
            void update();
    };

}



#endif