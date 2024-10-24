#ifndef SCENE_H
#define SCENE_H

#include "SceneInterface.h"
#include "Entity.h"

namespace sre
{
    class Scene : public SceneInterface<Entity> //is Entity the right call?
    {
        //TODO:
        //this might need a bit of a revamp:
        //have the Scene be responsible for attaching Observers into the Engine's Observables
        //this would mean that scene-related entities can be thrown in and removed,
        //but "global" entities like UI and player stuff can still be handled outside of it
        public:
            Scene() = default;
            //have a function setUp that attaches all the observers to their observables
            //have a function tearDown that detaches all the observers from their observables
            void update() override; //updates all entities
            void render() override; //this is redundant, since the rendering is handled by the RenderingSystem
            void add(Entity entity) override;
            void remove(Entity entity) override;

            //these two probably redundant
            void makeActive(Entity entity) override;
            void makeInactive(Entity entity) override;
        protected:
            ~Scene() = default;
        private:
            std::vector<Entity> entities;
            //maybe instead of vector of entities, maybe Observers?
            //OR a map of Observer : Observable.
            //this way you can easily activate the scene by setting the observer key to its observable value.
    };
}
#endif