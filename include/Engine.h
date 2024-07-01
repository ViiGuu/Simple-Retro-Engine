#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>
#include <string>
#include <SDL.h>
#include <atomic>
#include <stdexcept>
#include <memory>
#include <vector>

//TODO: Create EngineManager implementation of Manager and replace Engines.
//TODO: Set up debugging for Google Test
namespace sre
{
    /**
     * The main engine responsible for running the game.
     * The engine is created using the free function createEngine(). Once the Engine should shut down,
     * call the free function destroyEngine() to ensure proper cleanup of resources. Do not delete the Engine manually.
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
            friend Engine* createEngine();
            friend void destroyEngine();
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
            
            Engine() {}
             /** Updates the various behaviours in the game. */
            void update();
    };
   
   /** Holds a collection of smart pointers to Engine objects, allowing automatic memory cleanup. */
    class Engines
    {
        public:
        friend Engine* createEngine();
        friend void destroyEngine();
            
        private:
        static std::vector<std::unique_ptr<Engine>> engines;
    };

    std::vector<std::unique_ptr<Engine>> Engines::engines;

    /** Creates a new Engine object associated with a smart pointer and returns it */
    extern Engine* createEngine() 
    {
        Engines::engines.emplace_back(std::unique_ptr<Engine>(new Engine()));
        return Engines::engines.back().get();
    }

    /** Destroys the Engine. Call when the game should shut down. */
    extern void destroyEngine()
    {
        //The function logic allows more than one engine to be destroyed,
        //note that this is for testing purposes. See Engine class documentation.
        Engines::engines.clear();
    }

}



#endif