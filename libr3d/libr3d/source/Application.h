#pragma once
#include "GLFW_window.h"
#include "GLFW_input.h"
#include "renderer/opengl/OpenGLBuffers.h"
#include "renderer/opengl/OpenGLShaders.h"

#include "core/log.h"
namespace rnd {
    struct Application {

        Application(uint32_t width, uint32_t height, const char* title, bool resizable);
        void Update();
        ~Application();

        bool Running();
        void Setup();
        void Render();
        Window* GetWindow() { return window; }

        double calcDeltaTime();
        double getTime() const { return m_lastTime; }
        double getDeltaTimeSeconds() const { return m_deltaTime; }
        double getDeltaTimeMilliSeconds() const { return m_deltaTime * 1000; }

        void setVSync(bool set);
        void setFullscreen(bool set);
        void setWindowed(bool set);
        void setAspectRatio(uint32_t x, uint32_t y);
      
        int32_t getWindowWidth();
        int32_t getWindowHeight();
        void setWindowSize(uint32_t x, uint32_t y);
        void setWindowMaxLimits(uint32_t x, uint32_t y);
        void setWindowMinLimits(uint32_t x, uint32_t y);
        void setWindowPosition(uint32_t x,  uint32_t y);
    private:
        Window *window;
        double m_deltaTime;      
        float m_lastTime;
      
        OpenGLShaders *shader;
        VertexArray   *vertexArray;
        VertexBuffer  *vertexBuffer;
        IndexBuffer   *indexBuffer;
        Input *input;
    };
}
