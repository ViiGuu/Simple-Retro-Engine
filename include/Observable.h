#ifndef SUBJECT_H
#define SUBJECT_H
/// \cond
#include <vector>
#include <algorithm>
#include <stdexcept>
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
            //should this just be pure virtual? let implementations
            //handle how they want to deal with the notifying?
            //probably, since different implementations will want to
            //pass along different info to observers
            virtual void notify();
        protected:
            Observable() : observers() {};
            std::vector<Observer*> observers;
        private:
    };
}

#endif