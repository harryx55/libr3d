#include <glad/glad.h>
#include "R3DAssert.h"
#include "Log.h"

class Shaders
{
public:
	void AttachShader(const char*, const char*);
	void DetachShader();
	void bind() const;
	void unbind() const;
  
private:
	unsigned int m_shaderProgram;
	unsigned int m_vertexShader;
	unsigned int m_fragmentShader;

	int GetUniformLocation(const char*);
	const char* ReadFile(const char*);
};
