#pragma once
#include "pch.h"
#include <glfw3.h>

namespace R3D
{
	class MainApp
	{
	public:
		static void Run();
		static void onCreate();
		static void onClose();
		
	private:
		static void window_resize_callback(GLFWwindow*, int, int);
		static void mouse_cursor_callback(GLFWwindow*);

	private:
		static GLFWwindow* window;
	};
	
}