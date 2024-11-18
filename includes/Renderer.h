#ifndef RENDERER_H
#define RENDERER_H
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
#include "Shader.h"
#include "Texture.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


class Renderer 
{
public:
	Renderer();
	~Renderer();
	void draw();
	void draw(unsigned int shaderIndex, glm::mat4 modelMatrix);
	void setActiveShader(int index);
	inline static Shader getActiveShader() { return activeShader; };
private:
	std::vector<Shader> rendererShaders;
	std::vector<Texture> rendererTextures;
	std::vector<unsigned int> rendererVAOs;
	static Shader activeShader;
};


#endif
