#ifndef SYSTEM_INTERFACE_H
#define SYSTEM_INTERFACE_H

namespace sre
{
    class SystemInterface
    {
        public:
            virtual ~SystemInterface() = default;
            //look over args
            virtual void update() = 0;
    };
}

#endif