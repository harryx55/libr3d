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

	void Generate(const char*, int width = 320, int height = 240);
	void setActiveTexture(int);
	void bind() const;
	void unbind() const;

private:
	bool fileExists(const char*);
};