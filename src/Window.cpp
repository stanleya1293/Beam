#include "Window.h"



Window::Window(int width, int height, std::string title) {
	m_title = title;
	m_width = width;
	m_height = height;
	glfwInit();
	m_windowID = glfwCreateWindow(m_width, m_height, m_title.c_str(), glfwGetPrimaryMonitor(), NULL);
	glfwMakeContextCurrent(m_windowID);
	gladLoadGL();
}

Window::Window() {
	m_title = "";
	glfwInit();
	m_windowID = glfwCreateWindow(0, 0, "", glfwGetPrimaryMonitor(), NULL);
	glfwMakeContextCurrent(m_windowID)
	gladLoadGL();
	glfwGetWindowSize(m_window, &m_width, &m_height);
}

Window::~Window() {
	glfwDestroyWindow(p_window);
	glfwTerminate();
}

bool Window::running() {
	if (!glfwWindowShouldClose)
		return true;
	else
		return false;
} 

void Window::update() {
	glClear(GL_COLOR_BUFFER_BIT);
	glfwSwapBuffers(p_window);
	glfwPollEvents();
}