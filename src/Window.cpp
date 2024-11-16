#include "Window.h"



Window::Window(int width, int height, std::string title) : _width(width), _height(height), _title(title) {
	
	glfwInit();
	_windowID = glfwCreateWindow(_width, _height, _title.c_str(), NULL, NULL);
	glfwMakeContextCurrent(_windowID);
	gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
}

Window::Window() {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	_windowID = glfwCreateWindow(800, 800, "Test", NULL, NULL);
	glfwMakeContextCurrent(_windowID);
	gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
}

Window::~Window() {
	glfwDestroyWindow(_windowID);
	glfwTerminate();
}

bool Window::running() {
	if (!glfwWindowShouldClose(_windowID))
		return true;
	else
		return false;
} 

void Window::update() {
	glfwSwapBuffers(_windowID);
	glfwPollEvents();
	glClear(GL_COLOR_BUFFER_BIT);

}