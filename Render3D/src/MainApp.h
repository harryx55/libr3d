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
		static GLFWwindow* window;
	};
	
}