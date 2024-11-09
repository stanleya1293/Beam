#ifndef GAME_H
#define GAME_H
#include "Window.h"
#include "Renderer.h"


class Game {
public:
    Game();
    ~Game();
    void start();
private:
    Window m_window;
    Renderer m_renderer;
};

#endif