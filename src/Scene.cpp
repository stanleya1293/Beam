#include "Scene.h"

Scene::Scene() {
    window = Window();
    renderer = Renderer();
}

Scene::~Scene() {

}

Scene::start() {
    while (window.windowRunning()) 
	{
        window.update();
	}
}