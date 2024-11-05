#ifndef RENDERER_H
#define RENDERER_H
#include <glad/glad.h>
#include <iostream>


class Renderer {
public:
	Renderer();
	~Renderer();
private:
	unsigned int shaderID;
};

#endif
