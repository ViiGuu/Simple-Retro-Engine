#ifndef EVENT_HANDLER_H
#define EVENT_HANDLER_H

/// \cond
#include <memory>
#include <queue>
/// \endcond

namespace sre
{
    //** The EventHandler is responsible for creating specific Events that the Engine can process and pass along. */
    class EventHandler
    {

        //PROBABLY REDUNDANT - if the Engine iterates through Systems, and Systems can implement Observable,
        //then using an EventHandler is probably redundant.
        //for example an InputSystem can keep track of keyboard input, notify observers (which would probably be player)

        //what does EventHandler need to do?
            //update() - check if the EventHandler needs to create an event
            //createEvent() - create new event.
                //"construct" the Event (set appropriate values)
                //place the Event on the EventQueue
        public:
            virtual void update() = 0;
        protected:
            virtual void createEvent() = 0;
            EventHandler() = default;
        private:
            std::unique_ptr<int> event; //placeholder value
            std::queue<int> eventQueue; //placeholder value
    };
}

#endif