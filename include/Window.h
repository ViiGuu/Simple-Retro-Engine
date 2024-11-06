#ifndef WINDOW_H
#define WINDOW_H

#include "WindowInterface.h"
/// \cond
#include <SDL2/SDL.h>
/// \endcond

namespace sre
{
    /**
     * Used to create a window for the game. Call initialize() to create a window, which must be called
     * before initializing the Renderer.
     */
    class Window : public WindowInterface
    {
        public:
        Window() : window(nullptr) {}
        ~Window();
        void initialize(std::string windowName) override;
        SDL_Window& getWindow();
        protected:
        private:
        SDL_Window* window;
    };
}

#endif