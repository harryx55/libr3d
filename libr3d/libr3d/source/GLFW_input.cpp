#include "pch.h"
#include "GLFW_input.h"

using namespace rnd;
bool Input::IsKeyPressedImpl(int keyCode){
	int state = glfwGetKey(Window::GetWindow(), keyCode);
	return state == GLFW_PRESS || state == GLFW_RELEASE;
}

bool Input::IsKeyPressed(int keyCode) {
	return glfwGetKey(Window::GetWindow(), keyCode) == GLFW_PRESS;
}

bool Input::IsKeyReleased(int keyCode) {
	return glfwGetKey(Window::GetWindow(), keyCode) == GLFW_RELEASE;
}

bool Input::IsMouseButtonPressedImpl(int button) {
	int state = glfwGetMouseButton(Window::GetWindow(), button);
	return state == GLFW_PRESS;
}

Input::MousePos Input::GetMousePosImpl() {
	double xPos, yPos;
	glfwGetCursorPos(Window::GetWindow(), &xPos, &yPos);
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
