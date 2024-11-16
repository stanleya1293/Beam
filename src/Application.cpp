#include "Application.h"

Application::Application() {

}

Application::~Application() {

}

void Application::start() {
    while (_window.running()) 
	{
        _renderer.draw();
        _window.update();
	}
}