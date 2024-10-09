#ifndef RENDERER_INTERFACE_H
#define RENDERER_INTERFACE_H


namespace sre
{
    class RendererInterface
    {
        public:
            RendererInterface() = default;
            ~RendererInterface() = default;
            virtual void update() = 0;
            virtual void draw() = 0;
        protected:
        private:
    };
}
#endif