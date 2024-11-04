#ifndef WINDOW_H
#define WINDOW_H
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Window 
{
	public:
		Window(int width, int height, char* title);
		~Window();
	private:
		GLFWwindow* p_window;
		int p_height;
		int p_width;
		char* p_title;
};

#endif
