#ifndef OBSERVER_H
#define OBSERVER_H

namespace sre
{
    class Observer
    {
        public:
        virtual void update() = 0;
        protected:
        private:
    };
}

#endif