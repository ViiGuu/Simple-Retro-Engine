#ifndef ENGINE_H
#define ENGINE_H

#include "Sprite.h"
#include <iostream>
#include <string>
#include <SDL.h>

class Engine
{
public:
    void run();
protected:
private:
    Engine(){}
    ~Engine(){}
    void initialize();
    void destroy();
};

static bool engineCreated = false;

#endif