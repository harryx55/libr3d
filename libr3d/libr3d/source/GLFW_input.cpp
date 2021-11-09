#include "pch.h"
#include "GLFW_input.h"

using namespace rnd;
bool Input::IsKeyPressedImpl(int keyCode){
	int state = glfwGetKey(Window::m_window, keyCode);
	return state == GLFW_PRESS || state == GLFW_RELEASE;
}

bool Input::IsKeyPressed(int keyCode) {
	return glfwGetKey(Window::m_window, keyCode) == GLFW_PRESS;
}

bool Input::IsKeyReleased(int keyCode) {
	return glfwGetKey(Window::m_window, keyCode) == GLFW_RELEASE;
}

bool Input::IsMouseButtonPressedImpl(int button) {
	int state = glfwGetMouseButton(Window::m_window, button);
	return state == GLFW_PRESS;
}

Input::MousePos Input::GetMousePosImpl() {
	double xPos, yPos;
	glfwGetCursorPos(Window::m_window, &xPos, &yPos);
	return { (float)xPos, (float)yPos };
}

float Input::GetMousePosXImpl()
{
	return GetMousePosImpl().x;
}

float Input::GetMousePosYImpl()
{
	return GetMousePosImpl().y;
}

const char* Input::GetKeyName(int key) {
	return glfwGetKeyName(key, 0);
}
