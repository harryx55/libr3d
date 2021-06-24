#include "pch.h"
#include "Application.h"


namespace R3D
{
	Application::Application(RENDERER render, bool VSync, int WIDTH, int HEIGHT)
	{
		if (!glfwInit())
		{
			R3D_ERROR("GLFW| glfw initialization error");
		}

		window = glfwCreateWindow(WIDTH, HEIGHT, "Window", NULL, NULL);
		glfwMakeContextCurrent(window);

		if (VSync)
			glfwSwapInterval(1);
		glfwSetFramebufferSizeCallback(window, Application::window_resize_callback);
	}

	void Application::window_resize_callback(GLFWwindow* window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}

	void Application::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(window);
	}

	bool Application::WindowIsOpen()
	{
		return !glfwWindowShouldClose(window);
	}

	void Application::onShutDown()
	{
		glfwDestroyWindow(window);
		glfwTerminate();
	}
}
