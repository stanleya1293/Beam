#include "Renderer.h"
#include "Camera.h"

Shader Renderer::activeShader = Shader();

Renderer::Renderer()
{
	float vertices[] =
	{
		-0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 
		 0.5f, -0.5f, -0.5f, 1.0f, 0.0f,
		 0.5f,  0.5f, -0.5f, 1.0f, 1.0f,
		 0.5f,  0.5f, -0.5f, 1.0f, 1.0f,
		-0.5f,  0.5f, -0.5f, 0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f, 0.0f, 0.0f,

		-0.5f, -0.5f,  0.5f, 0.0f, 0.0f,
		 0.5f, -0.5f,  0.5f, 1.0f, 0.0f, 
		 0.5f,  0.5f,  0.5f, 1.0f, 1.0f,
		 0.5f,  0.5f,  0.5f, 1.0f, 1.0f,
		-0.5f,  0.5f,  0.5f, 0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f, 0.0f, 0.0f,

		-0.5f,  0.5f,  0.5f, 1.0f, 0.0f,
		-0.5f,  0.5f, -0.5f, 1.0f, 1.0f,
		-0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f, 0.0f, 0.0f,
		-0.5f,  0.5f,  0.5f, 1.0f, 0.0f,

		 0.5f,  0.5f,  0.5f, 1.0f, 0.0f,
		 0.5f,  0.5f, -0.5f, 1.0f, 1.0f,
		 0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
		 0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
		 0.5f, -0.5f,  0.5f, 0.0f, 0.0f,
		 0.5f,  0.5f,  0.5f, 1.0f, 0.0f,

		-0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
		 0.5f, -0.5f, -0.5f, 1.0f, 1.0f,
		 0.5f, -0.5f,  0.5f, 1.0f, 0.0f,
		 0.5f, -0.5f,  0.5f, 1.0f, 0.0f,
		-0.5f, -0.5f,  0.5f, 0.0f, 0.0f,
		-0.5f, -0.5f, -0.5f, 0.0f, 1.0f,

		-0.5f,  0.5f, -0.5f, 0.0f, 1.0f,
		 0.5f,  0.5f, -0.5f, 1.0f, 1.0f,
		 0.5f,  0.5f,  0.5f, 1.0f, 0.0f,
		 0.5f,  0.5f,  0.5f, 1.0f, 0.0f,
		-0.5f,  0.5f,  0.5f, 0.0f, 0.0f,
		-0.5f,  0.5f, -0.5f, 0.0f, 1.0f

	};

	unsigned int indices[] =
	{
		0, 1, 2,
		0, 2, 3
	};
	//general
	unsigned int vao;
	unsigned int vbo;
	unsigned int ebo;

	//glGenVertexArrays(1, &vao);
	//glBindVertexArray(vao);

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	//glGenBuffers(1, &ebo);
	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	//glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	//glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	//glEnableVertexAttribArray(0);
	//glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	//glEnableVertexAttribArray(1);

	//light based

	unsigned int lightVAO;
	glGenVertexArrays(1, &lightVAO);
	glBindVertexArray(lightVAO);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*) 0);
	glEnableVertexAttribArray(0);

	rendererVAOs.push_back(lightVAO); //lightcube VAO index 0

	rendererShaders.push_back(Shader("../shaders/vertexShader.vs", "../shaders/fragmentShader.fs")); //regular cube index 0
	rendererShaders.push_back(Shader("../shaders/lightCubeShader.vs", "../shaders/lightCubeShader.fs")); //light cube index 1
	rendererShaders.push_back(Shader("../shaders/gutsShader.vs", "../shaders/gutsShader.fs")); //guts cube index 2

	rendererTextures.push_back(Texture("../assets/brickwall.jpg", Texture::JPG)); //brick wall index 0
	rendererTextures.push_back(Texture("../assets/guts.png", Texture::PNG)); //guts index 1

	glViewport(0, 0, 800, 800);

	glEnable(GL_DEPTH_TEST);

	setActiveShader(0);

}

Renderer::~Renderer() {}

void Renderer::draw() 
{
	/*glm::vec3 cubePositions[] =
	{
		glm::vec3(0.0f, 0.0f, 0.0f),
		glm::vec3(2.0f, 5.0f, -15.0f),
		glm::vec3(-1.5f, -2.2f, -2.5f),
		glm::vec3(-3.8f, -2.0f, -12.3f),
		glm::vec3(2.4f, -0.4f, -3.5f),
		glm::vec3(-1.7f, 3.0f, -7.5f),
		glm::vec3(1.3f, -2.0f, -2.5f),
		glm::vec3(1.5f, 2.0f, -2.5f),
		glm::vec3(1.5f, 0.2f, -1.5f),
		glm::vec3(-1.3f, 1.0f, -1.5f)
	};
	rendererTextures[0].use();
	rendererTextures[1].use();

	for (int i = 0; i < 10; i++) {
		glm::mat4 model = glm::mat4(1.0f);
		model = glm::translate(model, cubePositions[i]);
		float angle = 20.0f * i;
		model = glm::rotate(model, (float)glfwGetTime() + glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
		
		int modelLocation = glGetUniformLocation(getActiveShader().getShaderID(), "model");
		glUniformMatrix4fv(modelLocation, 1, GL_FALSE, glm::value_ptr(model));
		
		glUniform1i(glGetUniformLocation(rendererShaders[0].getShaderID(), "texture1"), 0);
		glUniform1i(glGetUniformLocation(rendererShaders[0].getShaderID(), "texture2"), 1);
		
		glDrawArrays(GL_TRIANGLES, 0, 36);
	}
	*/
}

void Renderer::draw(unsigned int shaderIndex, glm::mat4 modelMatrix) 
{
	setActiveShader(shaderIndex);
	glBindVertexArray(rendererVAOs[0]);

	int modelLocation = glGetUniformLocation(getActiveShader().getShaderID(), "model");
	glUniformMatrix4fv(modelLocation, 1, GL_FALSE, glm::value_ptr(modelMatrix));

	glDrawArrays(GL_TRIANGLES, 0, 36);
}

void Renderer::setActiveShader(int index) 
{
	rendererShaders[index].use();
	Renderer::activeShader = rendererShaders[index];
}