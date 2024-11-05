#include "Renderer.h"

Renderer::Renderer() 
{
	float quad[] = 
	{
		-1.0f, -1.0f, 0.0f,
	       	-1.0f,  1.0f, 0.0f,
		 1.0f,  1.0f, 0.0f,
	 	 1.0f, -1.0f, 0.0f	 
	};

	int indices[] = 
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
	glBufferData(GL_ARRAY_BUFFER, sizeof(quad), quad, GL_STATIC_DRAW);
	
	glGenBuffers(1, &ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*) 0);
	glEnableVertexAttribArray(0);
	
	unsigned int fshader;
	unsigned int vshader;
	fshader = glCreateShader(GL_FRAGMENT_SHADER);
	vshader = glCreateShader(GL_VERTEX_SHADER);

	const std::string fshader_src = 
		"#version 330 core\n"
		"out vec4 color;"
		"\n"
		"void main()\n"
		"{\n"
		"color = vec4 (0.0, 1.0, 0.0, 1.0);\n"
		"}\0";

	const std::string vshader_src = 
		"#version 330 core\n"
		"layout (location = 0) in vec3 aPos;\n"
		"\n"
		"void main()\n"
		"{\n"
		"gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
		"}\0";

	glShaderSource(vshader, 1, vshader_src.c_str(), NULL);
	glShaderSource(fshader, 1, fshader_src.c_str(), NULL);

	glCompileShader(vshader);
	glCompileShader(fshader);

	shaderID = glCreateProgram();

	glAttachShader(shaderID, vshader);
	glAttachShader(shaderID, fshader);
	glLinkProgram(shaderID);

	glDeleteShader(fshader);
	glDeleteShader(vshader);

	glUseProgram(shaderID);


}

Renderer::~Renderer() {
	
}
