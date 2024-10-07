#ifndef RENDERER_INTERFACE_H
#define RENDERER_INTERFACE_H

namespace sre
{
    //TODO: create getter and use in EngineManager
    class RendererInterface
    {
        public:
            RendererInterface() = default;
            ~RendererInterface() = default;
            virtual void update() = 0;
            virtual void draw() = 0;
            virtual void renderPresent() = 0;
            virtual void renderClear() = 0;
            virtual void initialize() = 0;
        protected:
        private:
    };
}
#endif