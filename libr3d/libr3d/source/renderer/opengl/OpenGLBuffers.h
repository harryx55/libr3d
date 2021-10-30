#pragma once
#include <glad.h>

struct VertexArray {
  GLuint vao;

  void CreateVertexArray();
  void BindVertexArray();
  void UnbindVertexArray();
  void DestroyVertexArray();

  void AttachAttributes(GLuint index, GLuint size, GLuint stride, GLuint offset);
};

struct VertexBuffer {
  GLuint vbo;

  void CreateBuffer(void* data, GLuint size);
  void BindBuffer();
  void UnbindBuffer();
  void DestroyBuffer();
};

struct IndexBuffer {
  GLuint ibo;
  GLuint count;
  
  void CreateBuffer(void* data, GLuint size);
  void BindBuffer();
  void UnbindBuffer();
  void DestroyBuffer();
};

