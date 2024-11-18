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
		bool isRunning();
		void update();
		inline GLFWwindow* getWindowID() { return windowID; };
	private:
		GLFWwindow* windowID;
		int winHeight;
		int winWidth;
		std::string winTitle;
};

#endif
