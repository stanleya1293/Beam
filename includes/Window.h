#ifndef WINDOW_H
#define WINDOW_H
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

class Window 
{
	public:
		Window(int width, int height, std::string title) : width_(width) height_(height) title_(title);
		Window();
		~Window();
		bool running();
		void update();
	private:
		GLFWwindow* m_windowID;
		int height_;
		int width_;
		std::string title_;
};

#endif
