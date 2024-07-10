#ifndef SCENE_H
#define SCENE_H

#include <vector>
template <typename T>
class Scene
{
    public:
    int getID() const { return sceneID; }
    protected:
    Scene() = delete;
    Scene(int id) : sceneID(id), sceneContent() {}
    std::vector<T> sceneContent;
    int sceneID;
};

#endif