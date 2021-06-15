#include "pch.h"
#include "MainApp.h"
#include "Application.h"


GLFWwindow* R3D::MainApp::window;

namespace R3D
{
	void MainApp::onCreate()
	{
		if (!glfwInit())
			R3D_ERROR("[ERROR]: glfw not initialized");
		
		window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE, NULL, NULL);
		glfwMakeContextCurrent(window);

		if (VSYNC)
			glfwSwapInterval(1);

		Application::Init();
	}

	void MainApp::Run()
	{
		Application::Prepare();

		while(!glfwWindowShouldClose(window))
		{
			Application::Update();

			glfwPollEvents();
			glfwSwapBuffers(window);
		}
	}

	void MainApp::onClose()
	{
		glfwDestroyWindow(window);
		glfwTerminate();

		Application::Close();
	}
}