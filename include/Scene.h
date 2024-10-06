#ifndef SCENE_H
#define SCENE_H

#include "SceneI.h"

class Scene : public SceneI<int> //placeholder data type
{
    public:
    void update() override; //updates all entities
    void render() override; //renders all entities
    void add(int entity) override;
    void remove(int entity) override;
    void makeActive(int entity) override;
    void makeInactive(int entity) override;
    protected:
    Scene() {}
    private:
    std::vector<int> entities; //placeholder data type
};

#endif