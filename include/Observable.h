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
    /** Observable interface to handle one to many event/data passing. Concrete observers need to implement their own notify() */
    class Observable
    {
       public:
            Observable(const Observable& other) = delete;
            Observable& operator=(const Observable& other) = delete;
            const std::vector<Observer*>& getObservers(); //might be necessary for Scenes?
            virtual void add(Observer* obs);
            virtual void remove(Observer* obs);
            //Concrete implementations should cast the Observer to the appropriate type, i.e RenderableObserver
            virtual void notify(const std::any& event);
        protected:
            Observable() : observers() {};
            std::vector<Observer*> observers;
        private:
    };
}

#endif