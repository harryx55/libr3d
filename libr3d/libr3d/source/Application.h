#pragma once
#include "GLFW_window.h"
#include "GLFW_input.h"
#include "renderer/opengl/OpenGLBuffers.h"
#include "renderer/opengl/OpenGLShaders.h"

#include "core/base.h"
namespace rnd {
    struct Application {

        Application() { }
        void Update();
        ~Application();

        bool Create(uint32_t width = 1280, uint32_t height = 720, const char* windowCaption = "libr3d", bool resizable = true);
        void Setup();
        void Render();
        Window* GetWindow() { return window; }
        static Application *Get() { s_instance =  new Application(); return s_instance; }

        double calcDeltaTime();
        double getTime() const { return m_lastTime; }
        double getDeltaTimeSeconds() const { return m_deltaTime; }
        double getDeltaTimeMilliSeconds() const { return m_deltaTime * 1000; }
    private:
        static Application *s_instance;
        Window *window;
        double m_deltaTime = 0.0;
        float m_lastTime   = 0.0f;

        Input *input;
    };
}
