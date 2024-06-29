#include "Engine.h"

namespace sre
{
    std::unique_ptr<Engine> Engine::create()
    {
        return std::unique_ptr<Engine>(new Engine());
    }

    void Engine::run()
    {

    }

    void Engine::initialize()
    {

    }

    void Engine::destroy()
    {

}
}
