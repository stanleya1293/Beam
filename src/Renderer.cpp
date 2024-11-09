#include "Renderer.h"


Renderer::Renderer() 
{
	float vertices[] = 
	{
		 0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
	    -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
		 0.0f,  0.5f, 0.0f, 0.0f, 0.0f, 1.0f
	 	 
	};

	unsigned int indices[] = 
	{
		0, 1, 2,
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

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*) 0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (float*) (3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	shader = new Shader("shaders/vertexShader.vs", "shaders/fragmentShader.fs");
}

Renderer::~Renderer() {
	delete shader;
}

void Renderer::draw() {
	shader->use();
	float time = glfwGetTime();
	float greenValue = sin(time) / 2.0f + 0.0f;
	int vertexLocation = glGetUniformLocation(shader->getShaderID(), "fadeScalar");
	glUniform1f(vertexLocation, greenValue);
	glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);
}
