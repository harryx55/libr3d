#include "pch.h"
#include "OpenGLTextures.h"
#include "stb_image/stb_image.h"


Texture2D::Texture2D() 
		: m_width(0), m_height(0), Buffer(0), channels(0), TextureID(0)
{
	glGenTextures(1, &TextureID);
	glBindTexture(GL_TEXTURE_2D, TextureID);
}

Texture2D::~Texture2D()
{
	glDeleteTextures(1, &TextureID);
}

void Texture2D::Generate(const char* fileName, int width = 320, int height = 240)
{
	m_width = width;
	m_height = height;

	Buffer = stbi_load(fileName, &m_width, &m_height, &channels, 4);
	stbi_set_flip_vertically_on_load(1);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, Buffer);
	stbi_image_free(Buffer);
}

void Texture2D::bind() const
{
	glBindTexture(GL_TEXTURE_2D, TextureID);
}

void Texture2D::unbind() const
{
	glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture2D::setActiveTexture(int textureIndex)
{
	glActiveTexture(GL_TEXTURE0 + textureIndex);
}