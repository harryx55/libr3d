#pragma once

#include "OpenGL/OpenGLBuffers.h"
#include "OpenGL/OpenGLShaders.h"
#include "OpenGL/OpenGLTextures.h"

namespace R3D
{
	enum class RENDERER
	{
		OPENGL   = 0,
		DIRECT3D = 1
	};


	class Application
	{
	public:
		Application(RENDERER renderer, bool, int WIDTH = 1280, int HEIGHT = 720);

		static void window_resize_callback(GLFWwindow*, int, int);
		void OnUpdate();
		void onShutDown();
		bool WindowIsOpen();

	private:
		GLFWwindow* window;
	};
}