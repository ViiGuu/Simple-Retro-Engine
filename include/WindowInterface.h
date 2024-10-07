#ifndef WINDOW_INTERFACE_H
#define WINDOW_INTERFACE_H

#include <SDL2/SDL.h>

namespace sre
{
    class WindowInterface
    {
        public:
        WindowInterface() = default;
        ~WindowInterface() = default;
        virtual void initialize() = 0;
        protected:
        private:
    };
}

#endif