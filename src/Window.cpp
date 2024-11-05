#include "Window.h"



Window::Window(int width, int height, std::string title) 
{
	glfwInit();
	p_window = glfwCreateWindow(width, height, title.c_str(), glfwGetPrimaryMonitor(), NULL);
	glfwMakeContextCurrent(p_window);
	gladLoadGL();
	glfwGetWindowSize(p_window, &p_width, &p_height);
	p_title = title;
	while (!glfwWindowShouldClose(p_window)) 
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(p_window);
		glfwPollEvents();
	}
}

Window::~Window() 
{
	glfwDestroyWindow(p_window);
	glfwTerminate();
}
