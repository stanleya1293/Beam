#ifndef APPLICATION_H
#define APPLICATION_H
#include "Window.h"
#include "Renderer.h"


class Application {
public:
    Application();
    ~Application();
    void start();
private:
    Window _window;
    Renderer _renderer;
};

#endif