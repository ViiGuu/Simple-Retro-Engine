#include "Subject.h"

namespace sre
{
    void Subject::remove(const Observer& obs)
    {
        observers.erase(
            std::remove(observers.begin(), observers.end(), obs), 
            observers.end());
    }

    void Subject::add(Observer* obs)
    {
        observers.push_back(obs);
    }

    void Subject::notify()
    {
       std::for_each(observers.begin(), observers.end(),
       [](Observer* obs)
       {
        obs->update();
       });
    }
}
