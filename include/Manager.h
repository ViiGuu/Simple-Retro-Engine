#ifndef MANAGER_H
#define MANAGER_H
/// \cond
#include <memory>
#include <stdexcept>
/// \endcond

/**
 * Interface for managing the creation and destruction of an object, with an internal smart pointer
 * for automatic memory management.
 */
template <typename T>
class Manager
{
    public:
        virtual T& create() = 0;
        virtual void destroy() = 0;
        virtual T& get () const {throw std::runtime_error("get() not implemented for this Manager");}
        Manager(const Manager&) = delete;
        Manager& operator=(const Manager&) = delete;
        
    protected:
        Manager() = default;
        virtual ~Manager() = default;
        std::unique_ptr<T> managed;
        
};

#endif