#include "Renderer.h"


Renderer::Renderer() 
{
	float vertices[] = 
	{
		 0.5f,  0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f,
	     0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,
		-0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
		-0.5f,  0.5f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f
	 	 
	};

	unsigned int indices[] = 
	{
		0, 1, 2,
		0, 2, 3
	};   
	
	unsigned int vao;
	unsigned int vbo;
	unsigned int ebo;
	
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	
	glGenBuffers(1, &ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*) 0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*) (3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*) (6 * sizeof(float)));
	glEnableVertexAttribArray(2);

	_shaders.push_back(Shader("../shaders/vertexShader.vs", "../shaders/fragmentShader.fs"));
	_textures.push_back(Texture("../assets/brickwall.jpg", Texture::JPG));
	_textures.push_back(Texture("../assets/guts.png", Texture::PNG));
	
}

Renderer::~Renderer() {
	
}

void Renderer::draw() {
	_shaders[0].use();
	_textures[0].use();
	_textures[1].use();
	glUniform1i(glGetUniformLocation(_shaders[0].getShaderID(), "texture1"), 0);
	glUniform1i(glGetUniformLocation(_shaders[0].getShaderID(), "texture2"), 1);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}
