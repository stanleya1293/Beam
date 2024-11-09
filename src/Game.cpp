#include "Game.h"

Game::Game() {

};

Game::~Game() {

}

void Game::start() {
    while (m_window.running()) 
	{
        m_renderer.draw();
        m_window.update();
	}
}