#pragma once
#include <glad.h>

struct OpenGLShaders {
  GLuint m_shaderProgram;
  GLuint m_vertexShader;
  GLuint m_fragmentShader;

  void LoadShaders(const char*, const char*);
  void DestroyShaders();

  void BindShader();
  void UnbindShader();

  void SetTexture(const char*, GLint i = 0);

  /*
  void SetUnifromVector3(const char*, const glm::vec3&);
  void SetUnifromMatrix4(const char*, const glm::mat4&);
  */
  
  int GetUniformLocation(const char* name);
};


