#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>
#include <string>
#include <SDL.h>
#include <atomic>
#include <stdexcept>
#include <memory>

//TODO: sort memory management in destructor
//TODO: Create unit tests for Engine class.

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
        /** Creates a new Engine instance. */
        static std::unique_ptr<Engine> create();

        Engine(const Engine&) = delete; 

        Engine operator= (const Engine&) = delete;

        /** Initializes the engine. */
        void initialize();

        /** Runs the game loop. */
        void run();

        /** Handles cleaning up of resources and quits the game. */
        void quit();
    protected:
    private:
        ~Engine(){}
        Engine(){}
        void destroy();
        friend std::unique_ptr<Engine> create();
};
}



#endif