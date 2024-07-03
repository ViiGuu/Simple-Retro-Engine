#ifndef MANAGER_H
#define MANAGER_H

#include <memory>
#include <stdexcept>

template <typename T>
class Manager
{
    public:
        virtual T& create() = 0;
        virtual void destroy() = 0;
        virtual T& get () const = 0;
        Manager(const Manager&) = delete;
        Manager& operator=(const Manager&) = delete;
        
    protected:
        Manager() = default;
        virtual ~Manager() = default;
        std::unique_ptr<T> managed;
        
};

#endif