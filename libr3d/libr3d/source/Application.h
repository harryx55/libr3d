#pragma once
#include "GLFW_window.h"
#include "GLFW_input.h"
#include "renderer/opengl/OpenGLBuffers.h"
#include "renderer/opengl/OpenGLShaders.h"

#include "core/base.h"
namespace rnd {
    struct Application {

        Application() { }
        ~Application();
      
        //@Refactor: remove Update funcion
        void Update();

        // Initializes Application context and subsystems including input and windowing.
        bool Create(uint32_t width = 1280, uint32_t height = 720, const char* windowCaption = "libr3d", bool resizable = true);

        // Retrieves the current window.
        Window* GetWindow() { return window; }

        // Retrieves singleton application instance.
        static Application *Get() { s_instance =  new Application(); return s_instance; }

        // Calculate timestep.
        double calcDeltaTime();
      
        // Calculate current framerate.
        float  GetFPS() const { return (float)(1000 / (m_deltaTime * 1000)); }

        // get elapsed time
        double getElapsedTime() const { return m_lastTime; }

        // get elapsed time between frames in seconds
        double getDeltaTimeSeconds() const { return m_deltaTime; }
      
        // get elapsed time between frames in milliseconds
        double getDeltaTimeMilliSeconds() const { return m_deltaTime * 1000; }
      
    private:
        static Application *s_instance;
        Window *window;
        Input *input;

        double m_deltaTime = 0.0;
        float m_lastTime   = 0.0f;
    };
}
