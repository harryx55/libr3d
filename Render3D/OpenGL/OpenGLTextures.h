#pragma once
#include <glad/glad.h>


class Texture2D
{
private:
	int m_width, m_height;
	unsigned int TextureID;
	unsigned char* Buffer;
	int channels;

public:
	Texture2D();
	~Texture2D();

	void Generate(const char*, int, int);
	void setActiveTexture(int);
	void bind() const;
	void unbind() const;
};