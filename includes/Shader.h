#ifndef SHADER_H
#define SHADER_H
#include <glad/glad.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>


class Shader 
{
public:
    Shader();
    Shader(const char* vertexShaderPath, const char* fragmentShaderPath);
    ~Shader();
    void use();
    inline unsigned int getShaderID() { return shaderID; };
private:
    unsigned int shaderID;
};

#endif