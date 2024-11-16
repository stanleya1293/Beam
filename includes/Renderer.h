#ifndef RENDERER_H
#define RENDERER_H
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
#include "Shader.h"

class Renderer {
public:
	Renderer();
	~Renderer();
	void draw();
private:
	std::vector<Shader> shaders;
};

#endif
