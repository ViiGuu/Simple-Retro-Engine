#ifndef SCENE_NAVIGATOR_INTERFACE_H
#define SCENE_NAVIGATOR_INTERFACE_H
/// \cond
#include <map>
#include <memory>
/// \endcond

namespace sre
{
    /**
     * Interface for holding a collection of scenes as well as holding a pointer to the active scene.
     */
    class SceneNavigatorInterface
    {
        //TODO so what's the plan with SceneNavigator? Basically SceneNavigator holds Scenes, each Scene attaches/detaches Observers to the Observables?
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