#ifndef WINDOW_INTERFACE_H
#define WINDOW_INTERFACE_H
/// \cond
#include <iostream>
/// \endcond
namespace sre
{
    class WindowInterface
    {
        public:
        WindowInterface() = default;
        ~WindowInterface() = default;
        virtual void initialize(std::string windowName) = 0;
        protected:
        private:
    };
}

#endif