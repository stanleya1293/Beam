#include "Window.h"



Window::Window(int width, int height, std::string title) {
	m_title = title;
	m_width = width;
	m_height = height;
	glfwInit();
	m_windowID = glfwCreateWindow(m_width, m_height, m_title.c_str(), NULL, NULL);
	glfwMakeContextCurrent(m_windowID);
	gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
}

Window::Window() {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	m_windowID = glfwCreateWindow(800, 800, "Test", NULL, NULL);
	glfwMakeContextCurrent(m_windowID);
	gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
}

Window::~Window() {
	glfwDestroyWindow(m_windowID);
	glfwTerminate();
}

bool Window::running() {
	if (!glfwWindowShouldClose(m_windowID))
		return true;
	else
		return false;
} 

void Window::update() {
	glfwSwapBuffers(m_windowID);
	glfwPollEvents();
	glClear(GL_COLOR_BUFFER_BIT);

}