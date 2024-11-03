#ifndef WINDOW_H
#define WINDOW_H
#include <GLFW/glfw3.h>

class Window {
	public:
		Window(int width, int height, int title);
		~Window();
		void Start();
	private:
		GLFWwindow* window;
		int height;
		int width;
		char* title;
}

#endif
