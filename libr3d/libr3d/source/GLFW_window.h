#pragma once
#include <glfw3.h>
#include <stdint.h>

namespace rnd {
    struct Window {
        Window(uint32_t, uint32_t, const char*, bool resizable);
        bool Running();
        void Update();
        ~Window();

        void setVSync(bool set);
        void setFullscreen(bool set);
        void setWindowed(bool set);
        void setResizable(bool set);
        void closeWindow();
        void setAspectRatio(uint32_t x, uint32_t y);
      
        int32_t getWindowWidth();
        int32_t getWindowHeight();
        void setWindowSize(uint32_t x, uint32_t y);
        void setWindowMaxlimits(uint32_t x, uint32_t y);
        void setWindowMinlimits(uint32_t x, uint32_t y);
        void setWindowPosition(uint32_t x, uint32_t y);
      
        static GLFWwindow* GetWindow() { return m_window; }

    private:
        GLFWmonitor *m_monitor;
        static GLFWwindow *m_window;
        uint32_t m_width;
        uint32_t m_height;
        const char* m_title;
    };
}
