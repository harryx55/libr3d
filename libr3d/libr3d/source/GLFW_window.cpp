#include "GLFW_window.h"
#include <stdio.h>

GLFWwindow *Window::m_window;
Window::Window(uint32_t width, uint32_t height, const char* title) {
	if (!glfwInit()) {
		__debugbreak();
		printf("glfw not initialized\n");
	}
	
	m_window = glfwCreateWindow(width, height, title, NULL, NULL);
	glfwMakeContextCurrent(m_window);
	glfwSwapInterval(1);
}

bool Window::Running() {
	return !glfwWindowShouldClose(m_window);
}

void Window::Update() {
	glfwPollEvents();
	glfwSwapBuffers(m_window);
}

Window::~Window() {
	glfwTerminate();
}
