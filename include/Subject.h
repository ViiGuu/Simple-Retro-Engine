#ifndef SUBJECT_H
#define SUBJECT_H

#include "Observer.h"
#include <vector>
#include <algorithm>

namespace sre
{
    //TODO: test Subject functionality
    class Subject
    {
        public:
            Subject(const Subject& other) = delete;
            Subject& operator=(const Subject& other) = delete;
            const std::vector<Observer*>& getObservers();
            virtual void add(Observer* obs);
            virtual void remove(Observer* obs);
            virtual void notify();
        protected:
            Subject() : observers() {};
            std::vector<Observer*> observers;
        private:
    };
}

#endif