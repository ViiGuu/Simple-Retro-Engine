#ifndef ENGINEMANAGER_H
#define ENGINEMANAGER_H

#include "Engine.h"
#include "Manager.h"
#include <memory>

namespace sre
{
    /**
     * The EngineManager serves as a pipeline for creating, accessing and destroying the game engine.
     * To create a new Engine, first create an EngineManager object and then call the create() function
     * to create a reference to a new Engine object. To destroy the Engine, call the destroy() function.
     * 
     * @author Viggo Gustafsson
     */
    class EngineManager : public Manager<Engine>
    {
        public:
            EngineManager() = default;
            ~EngineManager() = default;
            Engine& create() override
            {
                if (managed)
                {
                    throw std::runtime_error("Object already created");
                }
                //consider make_unique if compilation allows
                managed = std::unique_ptr<Engine>(new Engine());
                return *managed; 
            }

            void destroy() override
            {
                if (!managed) 
                {
                    throw std::runtime_error("Object not created");
                }

                managed.reset();
            }
    };
}

#endif