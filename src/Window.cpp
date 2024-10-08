#include "Window.h"

namespace sre
{
    Window::~Window()
    {
        SDL_DestroyWindow(window);
        window = nullptr;
    }

    void Window::initialize(std::string windowName)
    {

        SDL_DisplayMode displayMode;

        if (SDL_GetCurrentDisplayMode(0, &displayMode) != 0) 
        {
            std::cout << "SDL_GetCurrentDisplayMode failed: " << SDL_GetError() << std::endl;
            exit(-1);
        }

        int height = displayMode.h;
        int width = displayMode.w;

        window = SDL_CreateWindow(windowName.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_MAXIMIZED);

        if (!window) 
        {
            std::cerr << "Window could not be created! SDL Error: " << SDL_GetError() << std::endl;
            exit(-1);
        }
    }

    SDL_Window& Window::getWindow()
    {
        if(window == nullptr)
        {
            throw std::runtime_error("Window has not been initialized");
        }
        return *window;
    }
}