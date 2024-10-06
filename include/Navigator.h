#ifndef NAVIGATOR_H
#define NAVIGATOR

#include <map>
#include <memory>

/**
 * Interface for holding a collection of elements as well as holding a pointer to the active element,
 * for example the SceneNavigator implementation which holds a collection of scenes and has an active scene
 * that gets rendered by the engine.
 */
template<typename T, typename Y>
class Navigator
{
    public:
        virtual void setActive(T key) = 0;
        virtual Y getActive() = 0;
        virtual ~Navigator() = default;
    protected:
        Navigator() = 0;
    private:
        virtual std::shared_ptr<Y> active;
        virtual std::map<T, Y> collection;
};

#endif