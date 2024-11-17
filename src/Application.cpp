#include "Application.h"

Application::Application() {

}

Application::~Application() {

}

void Application::start() {
    while (_window.isRunning()) 
	{
        _renderer.draw();
        _window.update();
	}
}