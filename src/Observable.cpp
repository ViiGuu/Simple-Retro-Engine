#include "Observable.h"

namespace sre
{

    const std::vector<Observer*>& Observable::getObservers() 
    {
        return observers;
    }
    void Observable::remove(Observer* obs)
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

    void Observable::notify(const std::any& event)
    {
        for (auto obs : observers)
        {
            obs->update(event);
        }
    }
}
