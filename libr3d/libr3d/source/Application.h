#pragma once
#include "GLFW_window.h"
#include "GLFW_input.h"
#include "renderer/opengl/OpenGLBuffers.h"
#include "renderer/opengl/OpenGLShaders.h"

struct Application {

  Application();
  void Update();
  ~Application();

  bool Running();
  void Setup();
  void Render();
  Window* GetWindow() { return window; }
  
private:
  Window *window;

  OpenGLShaders *shader;
  VertexArray   *vertexArray;
  VertexBuffer  *vertexBuffer;
  IndexBuffer   *indexBuffer;
  Input *input;
};
