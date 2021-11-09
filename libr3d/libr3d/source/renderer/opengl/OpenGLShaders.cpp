#include "pch.h"
#include "OpenGLShaders.h"

void OpenGLShaders::LoadShaders(const char* vertexSrc, const char* fragmentSrc) {
	m_shaderProgram  = glCreateProgram();
	m_vertexShader   = glCreateShader(GL_VERTEX_SHADER);
	m_fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(m_vertexShader, 1, &vertexSrc, nullptr);
	glCompileShader(m_vertexShader);

	GLint compileResult = 0;
	glGetShaderiv(m_vertexShader, GL_COMPILE_STATUS, &compileResult);
	
	//
	// TODO: change opengl error logging code below
	//
	if(compileResult == GL_FALSE) {
		int maxLength = 0;
		glGetShaderiv(m_vertexShader, GL_INFO_LOG_LENGTH, &maxLength);

		char infoLog[25];	
		glGetShaderInfoLog(m_vertexShader, maxLength, &maxLength, &infoLog[0]);
		printf("%s%s\n", "vertex shader compilation failed", infoLog);
      
		glDeleteShader(m_vertexShader);
		return;
	}

	glShaderSource(m_fragmentShader, 1, &fragmentSrc, nullptr);
	glCompileShader(m_fragmentShader);

	compileResult = 0;
	glGetShaderiv(m_fragmentShader, GL_COMPILE_STATUS, &compileResult);
	if(compileResult == GL_FALSE) {
		int maxLength = 0;
		glGetShaderiv(m_fragmentShader, GL_INFO_LOG_LENGTH, &maxLength);

		char infoLog[25];
		glGetShaderInfoLog(m_fragmentShader, maxLength, &maxLength, &infoLog[0]);
		printf("%s%s\n", "fragment shader compilation failed", infoLog);
		    
		glDeleteShader(m_fragmentShader);
		return;
	}

	glAttachShader(m_shaderProgram, m_vertexShader);
	glAttachShader(m_shaderProgram, m_fragmentShader);
	glLinkProgram(m_shaderProgram);

	int linkResult = 0;
	glGetProgramiv(m_shaderProgram, GL_LINK_STATUS, &linkResult);
	if(linkResult == GL_FALSE) {
		int maxLength = 0;
		glGetShaderiv(m_shaderProgram, GL_INFO_LOG_LENGTH, &maxLength);
      
		char infoLog[25];
		printf("%s%s\n", "shader linking failed", infoLog);
		glGetShaderInfoLog(m_shaderProgram, maxLength, &maxLength, &infoLog[0]);

		glDeleteShader(m_shaderProgram);
		return;
	}

	glValidateProgram(m_shaderProgram);

	glDetachShader(m_shaderProgram, m_vertexShader);
	glDetachShader(m_shaderProgram, m_fragmentShader);
}

int OpenGLShaders::GetUniformLocation(const char* name) {
	GLint location = glGetUniformLocation(m_shaderProgram, name);

	if (location == -1) {
		printf("%s%s%s\n", "Uniform ", name, "does not exist"); __debugbreak();
	}
	return location;
}

void OpenGLShaders::SetTexture(const char* name, GLint i) {
	glUniform1i(GetUniformLocation(name), i);
}

/*
void OpenGLShaders::SetUnifromVector3(const char* name, const glm::vec3& vector) {
	glUniform3fv(GetUniformLocation(name), 1, glm::value_ptr(vector));
}

void OpenGLShaders::SetUnifromMatrix4(const char* name, const glm::mat4& matrix) {
	glUniformMatrix4fv(GetUniformLocation(name), 1, GL_FALSE, glm::value_ptr(matrix));
}
*/
void OpenGLShaders::BindShader() {
	glUseProgram(m_shaderProgram);
}

void OpenGLShaders::UnbindShader() {
	glUseProgram(0);
}

void OpenGLShaders::DestroyShaders() {
	glDeleteShader(m_vertexShader);
	glDeleteShader(m_fragmentShader);
	glDeleteShader(m_shaderProgram);
}
