#ifndef TEXTURE_H
#define TEXTURE_H
#include <glad/glad.h>
#include "stb_image.h"


class Texture 
{
public:
    enum TextureType 
    {
        PNG,
        JPG,
        JPEG
    };
    Texture(const char* texturePath, TextureType type);
    ~Texture();
    void use();
private:
    unsigned int textureID;
    int textureWidth;
    int textureHeight;
    int textureNrChannels;
    int textureCount;
};

#endif