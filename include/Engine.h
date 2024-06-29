#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>
#include <string>
#include <SDL.h>
#include <atomic>
#include <stdexcept>
#include <memory>

//TODO: Set up debugging for Google Test
namespace sre
{
    /**
     * The main engine responsible for running the game. Engine creation uses the factory method pattern using the create() function.
     * Before calling the run() function to start the game loop, the engine must be initialized using the initialize() function.
     * 
     * While single-object creation is not strictly enforced, 
     * creating more than one Engine object will result in undefined behaviour.
     * 
     * @author Viggo Gustafsson
     */
    class Engine
    {
        public:
            ~Engine(){}
            /** Creates a new Engine instance. */
            static Engine* create() { return new Engine(); }

            /** Initializes the engine with the given window name.
             * 
             * @param windowName The name of the window.
             */
            void initialize(std::string windowName);

            /** Function responsible for running the main game loop. */
            void run();

            /** Handles cleaning up of resources and quits the game. */
            void quit();
            Engine(const Engine&) = delete; 
            Engine operator= (const Engine&) = delete;
        protected:
        private:
            Engine(){}
             /** Updates the various behaviours in the game. */
            void update();
    };
}



#endif