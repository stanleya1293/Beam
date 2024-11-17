#ifndef TEXTURE_H
#define TEXTURE_H
#include <glad/glad.h>
#include "stb_image.h"


class Texture {
public:
    enum TextureType {
        PNG,
        JPG,
        JPEG
    };
    Texture(const char* texturePath, TextureType type);
    ~Texture();
    void use();
private:
    unsigned int _textureID;
    int _width;
    int _height;
    int _nrChannels;
    int _count;
};

#endif