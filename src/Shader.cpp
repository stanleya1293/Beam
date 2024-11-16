#include "Shader.h"

Shader::Shader(const char* vertexShaderPath, const char* fragmentShaderPath) {
    std::string vertexShaderCode;
    std::string fragmentShaderCode;
    std::ifstream vertexShaderFile;
    std::ifstream fragmentShaderFile;

    std::stringstream vertexShaderStream;
    std::stringstream fragmentShaderStream;

    vertexShaderFile.open(vertexShaderPath);
    fragmentShaderFile.open(fragmentShaderPath);
    if (vertexShaderFile.fail()) {
        std::cout << "Something went wrong with the fragment shader loading!\n";
    }
    vertexShaderStream << vertexShaderFile.rdbuf();
    if (vertexShaderFile.fail()) {
        std::cout << "Something went wrong with the vertex shader loading!\n";
    }
    fragmentShaderStream << fragmentShaderFile.rdbuf();

    vertexShaderFile.close();
    fragmentShaderFile.close();

    vertexShaderCode = vertexShaderStream.str();
    fragmentShaderCode = fragmentShaderStream.str();

    const char* vertexShaderSource = vertexShaderCode.c_str();
    const char* fragmentShaderSource = fragmentShaderCode.c_str();

    unsigned int fragmentShader;
	unsigned int vertexShader;
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
		

	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);

	int v_success;
	char v_infolog[512];
	glCompileShader(vertexShader);
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &v_success);
	if (!v_success) {
		glGetShaderInfoLog(vertexShader, 512, NULL, v_infolog);
		std::cout << "ERROR: VERTEX SHADER COMPILATION: \n" << v_infolog << std::endl;
	}

	int f_success;
	char f_infolog[512];
	glCompileShader(fragmentShader);
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &f_success);
	if (!v_success) {
		glGetShaderInfoLog(fragmentShader, 512, NULL, f_infolog);
		std::cout << "ERROR: FRAGMENT SHADER COMPILATION: \n" << f_infolog << std::endl;
	}


	_shaderID = glCreateProgram();

	glAttachShader(_shaderID, vertexShader);
	glAttachShader(_shaderID, fragmentShader);
	glLinkProgram(_shaderID);

	glDeleteShader(fragmentShader);
	glDeleteShader(vertexShader);

}

void Shader::use() {
    glUseProgram(_shaderID);
}

unsigned int Shader::getShaderID() {
	return _shaderID;
}

Shader::~Shader() {

}