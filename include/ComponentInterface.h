#ifndef COMPONENT_INTERFACE_H
#define COMPONENT_INTERFACE_H

namespace sre
{
    class ComponentInterface
    {
        public:
            virtual ~ComponentInterface() = default;
        protected:
            ComponentInterface() = default;
        private:
    };
}

#endif