#pragma once
#include "GLFW_window.h"

namespace rnd {
    struct Input {
      bool IsKeyPressedImpl(int keyCode);
      bool IsMouseButtonPressedImpl(int button);

      bool IsKeyPressed(int keyCode);
      bool IsKeyReleased(int keyCode);
  
      float GetMousePosXImpl();
      float GetMousePosYImpl();

      const char* GetKeyName(int key);
      
      struct MousePos { float x, y; };
      MousePos GetMousePosImpl();

    };
}
