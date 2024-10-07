#ifndef SCENE_H
#define SCENE_H

#include "SceneInterface.h"
namespace sre
{
    class Scene : public SceneInterface<int> //placeholder data type
    {
        public:
            Scene() = default;
            void update() override; //updates all entities
            void render() override; //renders all entities
            void add(int entity) override;
            void remove(int entity) override;
            void makeActive(int entity) override;
            void makeInactive(int entity) override;
        protected:
            ~Scene() = default;
        private:
            std::vector<int> entities; //placeholder data type
    };
}
#endif