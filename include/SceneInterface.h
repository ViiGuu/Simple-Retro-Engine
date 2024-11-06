#ifndef SCENE_INTERFACE_H
#define SCENE_INTERFACE_H
/// \cond
#include <vector>
/// \endcond
namespace sre
{
    template <typename T>
    class SceneInterface
    {
        public:
            //maybe protected so only the scenenavigator can access?
            virtual void update() = 0;
            virtual void render() = 0;
            virtual void add(T entity) = 0;
            virtual void remove(T entity) = 0;
            virtual void initialize() = 0; //or initialize in constructor?
            virtual void makeActive(T entity) = 0;
            virtual void makeInactive(T entity) = 0;
        protected:
            SceneInterface() = default;
            virtual ~SceneInterface() = default;
        private:
        std::vector<T> entities;
    };
}
#endif