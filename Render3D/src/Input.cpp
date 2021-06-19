#include "pch.h"
#include "Input.h"


namespace R3D
{
	bool R3D::Input::m_Keys[MAX_KEY_COUNT];

	void Input::InitInput()
	{
		for (int i = 0; i < MAX_KEY_COUNT; i++)
		{
			m_Keys[i] = false;
		}
	}

	bool Input::isPressed(unsigned int keycode)
	{
		if (keycode >= MAX_KEY_COUNT)
			return true;
		return false;
	}

	void Input::KeyInput(GLFWwindow* window, int key, int keycode, int action, int mods)
	{
		m_Keys[key] = keycode != GLFW_RELEASE;
	}

	void Input::MouseCallBack(GLFWwindow* window, double xpos, double ypos)
	{

	}
}

