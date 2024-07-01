#ifndef MANAGER_H
#define MANAGER_H

#include <memory>
#include <stdexcept>

template <typename T>
class Manager
{
    public:
        Manager() = default;
        ~Manager() = default;
        virtual T& create() 
        { 
            if (managed) 
            {
                throw std::runtime_error("Object already created");
            }
            //consider make_unique if compilation allows
            managed = std::unique_ptr<T>(new T());
            return *managed; 
        }
        virtual void destroy() 
        { 
            if (!managed) 
            {
                throw std::runtime_error("Object not created");
            }

            managed.reset();
        }
        virtual T& get () const 
        { 
            if (!managed) 
            {
                throw std::runtime_error("Object not created");
            }

            return *managed;    
        }
        Manager(const Manager&) = delete;
        Manager& operator=(const Manager&) = delete;
        
    protected:
        Manager() = default;
        virtual ~Manager() = default;

    private:
        std::unique_ptr<T> managed;
};

#endif