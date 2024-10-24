#include "Observable.h"

namespace sre
{

    const std::vector<Observer*>& Observable::getObservers() 
    {
        return observers;
    }
    void Observable::remove(Observer* obs) //do i also need to clean up the removed observer itself?
    {
        observers.erase(
            std::remove(observers.begin(), observers.end(), obs), 
            observers.end());
    }

    void Observable::add(Observer* obs)
    {
        if(obs != nullptr)
        {
            int find = std::count(observers.begin(), observers.end(), obs);
            if(find == 0)
                observers.push_back(obs);
        }
    }

    void Observable::notify()
    {
       std::for_each(observers.begin(), observers.end(),
       [](Observer* obs)
       {
        obs->update(); //this should have different args based on implementation
       });
    }
}
