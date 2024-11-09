#ifndef SHADER_H
#define SHADER_H
#include <glad/glad.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>


class Shader {
public:
    Shader(const char* vertexShaderPath, const char* fragmentShaderPath);
    ~Shader();
    void use();
    unsigned int getShaderID();
private:
    unsigned int m_shaderID;
};

#endif