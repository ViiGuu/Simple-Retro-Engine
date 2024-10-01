#ifndef ABSTRACT_SCENE_H
#define ABSTRACT_SCENE_H


class AbstractScene
{
    public:
        virtual ~AbstractScene() = default;
        virtual void update() = 0;
        virtual void render() = 0;
        virtual void initialize() = 0;
    protected:
        AbstractScene() = delete;   
};

#endif