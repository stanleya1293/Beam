#include "Application.h"

Application::Application() {}

Application::~Application() {}

void Application::handleInput() {
    static bool keyHeldW = false;
    static bool keyHeldA = false;
    static bool keyHeldS = false;
    static bool keyHeldD = false;

    if (glfwGetKey(window.getWindowID(), GLFW_KEY_W) == GLFW_PRESS || keyHeldW == true) {
        camera.move(Camera::Forward);
    }
    if (glfwGetKey(window.getWindowID(), GLFW_KEY_A) == GLFW_PRESS || keyHeldA == true) {
        camera.move(Camera::Left);
    }
    if (glfwGetKey(window.getWindowID(), GLFW_KEY_S) == GLFW_PRESS || keyHeldS == true) {
        camera.move(Camera::Backward);
    }
    if (glfwGetKey(window.getWindowID(), GLFW_KEY_D) == GLFW_PRESS || keyHeldD == true) {
        camera.move(Camera::Right);
    }
    if (glfwGetKey(window.getWindowID(), GLFW_KEY_W) == GLFW_RELEASE) {
        keyHeldW = false;
    }
    if (glfwGetKey(window.getWindowID(), GLFW_KEY_A) == GLFW_RELEASE) {
        keyHeldA = false;
    }
    if (glfwGetKey(window.getWindowID(), GLFW_KEY_S) == GLFW_RELEASE) {
        keyHeldS = false;
    }
    if (glfwGetKey(window.getWindowID(), GLFW_KEY_D) == GLFW_RELEASE) {
        keyHeldD = false;
    }
}

void Application::start() {
    while (window.isRunning()) 
    {
        handleInput();
        camera.update();
        renderer.draw();
        window.update();
	}
}