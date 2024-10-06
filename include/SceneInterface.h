#ifndef SCENE_INTERFACE_H
#define SCENE_INTERFACE_H

#include <vector>
template <typename T>
class SceneInterface
{
    public:
        virtual ~SceneInterface() {}
        //maybe protected so only the scenenavigator can access?
        virtual void update() = 0;
        virtual void render() = 0;
        virtual void add(T entity) = 0;
        virtual void remove(T entity) = 0;
        virtual void initialize() = 0; //or initialize in constructor?
        virtual void makeActive(T entity) = 0;
        virtual void makeInactive(T entity) = 0;
    protected:
        SceneInterface() {}
    private:
    std::vector<T> entities;
};

#endif