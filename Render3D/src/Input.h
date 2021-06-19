#pragma once
#include "pch.h"
#include <glfw3.h>

#define MAX_KEY_COUNT 124

namespace R3D
{
	class Input
	{
	private:
		static bool m_Keys[MAX_KEY_COUNT];
	public:
		static void InitInput();
		static bool isPressed(unsigned int keycode);
		static void KeyInput(GLFWwindow*, int, int, int, int);
		static void MouseCallBack(GLFWwindow*, double, double);

		enum KEY
		{
			W = GLFW_KEY_W,
			A = GLFW_KEY_A,
			S = GLFW_KEY_S,
			D = GLFW_KEY_D,

			SPACE = GLFW_KEY_SPACE,
			E = GLFW_KEY_E,
			F = GLFW_KEY_F,
			R = GLFW_KEY_R,

			I = GLFW_KEY_I,
			J = GLFW_KEY_J,
			K = GLFW_KEY_K,
			L = GLFW_KEY_L,

			ENTER = GLFW_KEY_ENTER,
			RSHIFT = GLFW_KEY_RIGHT_SHIFT,
			LSHIFT = GLFW_KEY_LEFT_SHIFT,
			ESCAPE = GLFW_KEY_ESCAPE
		};
	};
}