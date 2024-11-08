#ifndef SUBJECT_H
#define SUBJECT_H
/// \cond
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <any>
/// \endcond
#include "Observer.h"

namespace sre
{
    class Observable
    {
        
       public:
            Observable(const Observable& other) = delete;
            Observable& operator=(const Observable& other) = delete;
            const std::vector<Observer*>& getObservers();
            virtual void add(Observer* obs);
            virtual void remove(Observer* obs);
            //make pure virtual, pass Event as param. or overload for concrete implementations......
            virtual void notify();
            virtual void notify(const std::any& data) = 0;
        protected:
            Observable() : observers() {};
            std::vector<Observer*> observers;
        private:
    };
}

#endif