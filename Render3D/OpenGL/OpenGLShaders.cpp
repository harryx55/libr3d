#include "pch.h"
#include "OpenGLShaders.h"


void Shaders::AttachShader(const char* vertex_source, const char* fragment_source)
{
	m_shaderProgram = glCreateProgram();
	m_vertexShader = glCreateShader(GL_VERTEX_SHADER);
	m_fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

	const char* v_src = ReadFile(vertex_source);
	const char* source = v_src;
	glShaderSource(m_vertexShader, 1, &source, nullptr);
	glCompileShader(m_vertexShader);

	// check for compilation errors
	int vert_result;
	glGetShaderiv(m_vertexShader, GL_COMPILE_STATUS, &vert_result);
	if (vert_result == GL_FALSE)
		R3D_ERROR("SHADERS| vertex shader compilation error");
  
	const char* f_src = ReadFile(fragment_source);
	source = f_src;
	glShaderSource(m_fragmentShader, 1, &source, nullptr);
	glCompileShader(m_fragmentShader);

	int frag_result;
	glGetShaderiv(m_fragmentShader, GL_COMPILE_STATUS, &frag_result);
	if (frag_result == GL_FALSE)
		R3D_ERROR("SHADERS| fragment shader compilation error");

	glAttachShader(m_shaderProgram, m_vertexShader);
	glAttachShader(m_shaderProgram, m_fragmentShader);

	glLinkProgram(m_shaderProgram);
	glValidateProgram(m_shaderProgram);

	int link_result;
	glGetProgramiv(m_shaderProgram, GL_LINK_STATUS, &link_result);
	if (link_result == GL_FALSE)
		R3D_ERROR("SHADERS| Shader program linking error");
  
	glUseProgram(m_shaderProgram);
}

const char* Shaders::ReadFile(const char* filename)
{
	std::fstream file_stream;
	std::stringstream string_stream;

	file_stream.open(filename);
	if (!file_stream.is_open())
	{
		R3D_WARN("SHADERS| could not open shader source file");
		return "Error";
	}

	R3D_INFO(filename, " shader loaded successfully");
	string_stream << file_stream.rdbuf();
	file_stream.close();

	return string_stream.str().c_str();
}

int Shaders::GetUniformLocation(const std::string& name)
{
	int location = glGetUniformLocation(m_shaderProgram, name.c_str());

	std::string error_message = "uniform " + name + " does not exist";
	if (location == -1)
		R3D_WARN(error_message.c_str());
	return location;
}

void Shaders::SetTexture(const char* name, int i)
{
	glUniform1i(GetUniformLocation(name), i);
}

void Shaders::bind() const
{
	glUseProgram(m_shaderProgram);
}

void Shaders::unbind() const
{
	glUseProgram(0);
}

void Shaders::DetachShader()
{
  
}
