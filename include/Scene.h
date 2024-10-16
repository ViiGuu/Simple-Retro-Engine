#ifndef SCENE_H
#define SCENE_H

#include "SceneInterface.h"
#include "Entity.h"

namespace sre
{
    class Scene : public SceneInterface<Entity> //is Entity the right call?
    {
        //Maybe Scene should just have a run, gets called by Engine through the Navigator,
        //calls update then render in order. render() could then interact with the Renderer / RenderingSystem
        public:
            Scene() = default;
            void update() override; //updates all entities
            void render() override; //renders all entities
            void add(Entity entity) override;
            void remove(Entity entity) override;
            void makeActive(Entity entity) override;
            void makeInactive(Entity entity) override;
        protected:
            ~Scene() = default;
        private:
            std::vector<Entity> entities;
    };
}
#endif