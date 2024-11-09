#ifndef SCENE_H
#define SCENE_H
#include "Renderer.h"
#include "Window.h"


class Scene {
public:
    Scene();
    ~Scene();
    void start();
private:
    Renderer renderer;
    Window window;
};

#endif