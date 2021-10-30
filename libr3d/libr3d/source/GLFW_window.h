#pragma once
#include <glfw3.h>
#include <stdint.h>

struct Window {
  Window(uint32_t, uint32_t, const char*);
  bool Running();
  void Update();
  ~Window();

  static GLFWwindow* GetWindow() { return m_window; }
  static GLFWwindow* m_window;
};
