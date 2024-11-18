#include "Window.h"



Window::Window(int width, int height, std::string title) : winWidth(width), winHeight(height), winTitle(title) 
{
	
	glfwInit();
	windowID = glfwCreateWindow(winWidth, winHeight, winTitle.c_str(), NULL, NULL);
	glfwMakeContextCurrent(windowID);
	gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
	
}

Window::Window() 
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	windowID = glfwCreateWindow(800, 800, "Test", NULL, NULL);
	glfwMakeContextCurrent(windowID);
	gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
}

Window::~Window() 
{
	glfwDestroyWindow(windowID);
	glfwTerminate();
}

bool Window::isRunning() 
{
	if (!glfwWindowShouldClose(windowID))
		return true;
	else
		return false;
} 

void Window::update() 
{
	glfwSwapBuffers(windowID);
	glfwPollEvents();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

}