#ifndef WINDOW_H
#define WINDOW_H
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

class Window 
{
	public:
		Window(int width, int height, std::string title);
		~Window();
	private:
		GLFWwindow* p_window;
		int p_height;
		int p_width;
		std::string p_title;
};

#endif
