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
            Subject() = delete;
            Subject(const Subject& other) = delete;
            Subject operator=(const Subject& other) = delete;
            virtual void add(Observer* obs);
            virtual void remove(const Observer& obs);
            virtual void notify();
        protected:
        private:
            std::vector<Observer*> observers;

    };
}

#endif