#ifndef SCENE_NAVIGATOR_INTERFACE_H
#define SCENE_NAVIGATOR_INTERFACE_H

#include <map>
#include <memory>

namespace sre
{
    /**
     * Interface for holding a collection of scenes as well as holding a pointer to the active scene.
     */
    //TODO fix this up
    class SceneNavigatorInterface
    {
        public:
            virtual void setActive(int key) = 0;
            virtual int getActive() = 0;
            virtual ~SceneNavigatorInterface() = default;
        protected:
            SceneNavigatorInterface() = default;
        private:
            std::shared_ptr<int> active;
            std::map<int, int> collection;
    };
}
#endif