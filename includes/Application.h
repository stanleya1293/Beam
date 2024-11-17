#ifndef APPLICATION_H
#define APPLICATION_H
#include "Window.h"
#include "Renderer.h"
#include "Camera.h"


class Application {
public:
    Application();
    ~Application();
    void start();
    void handleInput();
private:
    Window window;
    Renderer renderer;
    Camera camera;
};

#endif