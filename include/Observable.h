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
        //TODO: Implement EventInterface that can be passed as param for notify
        // this way specific observers can decide themselves what the event should be, and I don't have to deal with generic types.
        public:
            Observable(const Observable& other) = delete;
            Observable& operator=(const Observable& other) = delete;
            const std::vector<Observer*>& getObservers();
            virtual void add(Observer* obs);
            virtual void remove(Observer* obs);
            //make pure virtual, pass EventInterface as param
            virtual void notify();
        protected:
            Observable() : observers() {};
            std::vector<Observer*> observers;
        private:
    };
}

#endif