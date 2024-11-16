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
		GLFWwindow* _windowID;
		int _height;
		int _width;
		std::string _title;
};

#endif
