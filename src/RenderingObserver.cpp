#include "RenderingObserver.h"

namespace sre
{
    void RenderingObserver::update(const std::any& data)
    {
        try
        {
            ComponentInterface* component = std::any_cast<ComponentInterface*>(data);
            if(component != nullptr)
                renderingSystem->push(component);
            else
                throw std::invalid_argument("null pointer passed in RenderingObserver::update");
        }

        catch(const std::bad_any_cast& e)
        {
            std::cerr << e.what() << "needs to be a ComponentInterface pointer \n";
        }
        
    }
    
}