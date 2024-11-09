#ifndef WINDOW_H
#define WINDOW_H
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

class Window 
{
	public:
		Window(int width, int height, std::string title);
		Window();
		~Window();
		bool running();
		void update();
	private:
		GLFWwindow* m_windowID;
		int m_height;
		int m_width;
		std::string m_title;
};

#endif
