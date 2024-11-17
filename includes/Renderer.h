#ifndef RENDERER_H
#define RENDERER_H
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
#include "Shader.h"
#include "Texture.h"

class Renderer {
public:
	Renderer();
	~Renderer();
	void draw();
private:
	std::vector<Shader> _shaders;
	std::vector<Texture> _textures;
};

#endif
