#ifndef ENGINE_H
#define ENGINE_H

#include "Sprite.h"
#include <iostream>
#include <string>
#include <SDL.h>
#include <atomic>
#include <stdexcept>
#include <memory>

//TODO: sort memory management in destructor
//TODO: Create unit tests for Engine class.
class Engine
{
public:
    static Engine* create();
    ~Engine()
    {
        
        engineCreated.store(false);
    }
    Engine(const Engine&) = delete; 
    Engine operator= (const Engine&) = delete;
    void run();
    void quit();
protected:
private:
    static std::atomic<bool> engineCreated;
    Engine(){}
    void initialize();
    void destroy();
    friend Engine* create();
};

std::atomic<bool> Engine::engineCreated{false};


#endif