#include "pch.h"
#include "GLFW_window.h"
#include <glad.h>

using namespace rnd;
GLFWwindow *Window::m_window;
Window::Window(uint32_t width, uint32_t height, const char* title)
  : m_width(width), m_height(height), m_title(title) {
	if (!glfwInit()) {
	      __debugbreak();
	      printf("glfw not initialized\n");
	}
      
	m_window = glfwCreateWindow(width, height, title, NULL, NULL);
	glfwMakeContextCurrent(m_window);
	
	glfwSetWindowSizeCallback(m_window, [](GLFWwindow* w, int width,
					       int height) {
		glViewport(0, 0, width, height);
	});
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


void Window::setVSync(bool set) {
	if(set) {
	      glfwSwapInterval(1);
	}
}

void Window::setFullscreen(bool set) {
	if (set) {
	      /*
	      m_window = glfwCreateWindow(m_width, m_height, m_title,
					  glfwGetPrimaryMonitor(), NULL);
	      */
	}
}

void Window::setWindowed(bool set) {
	if(set) {
	}
}

void Window::setResizable(bool set) {
}

void Window::closeWindow() {
	glfwDestroyWindow(m_window);
	glfwTerminate();
}
