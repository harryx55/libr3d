#pragma once
#include "GLFW_window.h"

struct Input {
  bool IsKeyPressedImpl(int keyCode);
  bool IsMouseButtonPressedImpl(int button);

  float GetMousePosXImpl();
  float GetMousePosYImpl();

  struct MousePos { float x, y; };
  MousePos GetMousePosImpl();
};
