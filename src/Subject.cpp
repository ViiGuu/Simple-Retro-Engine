#include "Subject.h"

namespace sre
{

    const std::vector<Observer*>& Subject::getObservers() 
    {
        return observers;
    }
    void Subject::remove(Observer* obs) //do i also need to clean up the removed observer itself?
    {
        observers.erase(
            std::remove(observers.begin(), observers.end(), obs), 
            observers.end());
    }

    void Subject::add(Observer* obs)
    {
        if(obs != nullptr)
        {
            int find = std::count(observers.begin(), observers.end(), obs);
            if(find == 0)
                observers.push_back(obs);
        }
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
