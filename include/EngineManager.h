#ifndef ENGINEMANAGER_H
#define ENGINEMANAGER_H

#include "Engine.h"
#include "Manager.h"
#include <memory>

namespace sre
{
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

            Engine& get() const override
            {
                if (!managed) 
                {
                    throw std::runtime_error("Object not created");
                }

                return *managed;
            }
    };
}

#endif