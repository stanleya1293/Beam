#include "Texture.h"

Texture::Texture(const char* texturePath, TextureType type) : textureCount(0) 
{
	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_2D, textureID);
	stbi_set_flip_vertically_on_load(true);
	unsigned char* data = stbi_load(texturePath, &textureWidth, &textureHeight, &textureNrChannels, STBI_rgb_alpha);
	switch (type) {
	case JPG:
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, textureWidth, textureHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		break;
	case PNG:
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, textureWidth, textureHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		break;
	}
	glGenerateMipmap(GL_TEXTURE_2D);

	static int count = 0;
	count++;
	textureCount = count;

	stbi_image_free(data);
}

Texture::~Texture() {}

void Texture::use() 
{
	switch (textureCount) 
	{
	case 0:
		glActiveTexture(GL_TEXTURE0);
		break;
	case 1:
		glActiveTexture(GL_TEXTURE1);
		break;
	case 2:
		glActiveTexture(GL_TEXTURE2);
		break;
	case 3:
		glActiveTexture(GL_TEXTURE3);
		break;
	case 4:
		glActiveTexture(GL_TEXTURE4);
		break;
	}
	
	glBindTexture(GL_TEXTURE_2D, textureID);
}