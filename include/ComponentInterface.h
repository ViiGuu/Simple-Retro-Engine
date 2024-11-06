#ifndef COMPONENT_INTERFACE_H
#define COMPONENT_INTERFACE_H

namespace sre
{
    class ComponentInterface
    {
        public:
            virtual ~ComponentInterface() = default;
        private:
            virtual void pureVirtual() = 0;
    };
}

#endif