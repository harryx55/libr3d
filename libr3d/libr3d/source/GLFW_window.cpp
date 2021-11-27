#include "pch.h"
#include "GLFW_window.h"
#include <glad.h>

using namespace rnd;
GLFWwindow *Window::m_window;

Window::Window(uint32_t width, uint32_t height, const char* title, bool resizable)
                    : m_width(width), m_height(height), m_title(title), m_monitor(NULL) {
        Assert(glfwInit(), "Failed to initialized \n");

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);

	if(resizable) {
	      glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
	}
	else {
	      glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
	}
	
	m_window = glfwCreateWindow(width, height, title, NULL, NULL);
	glfwMakeContextCurrent(m_window);
	glfwSetWindowSizeCallback(m_window, [](GLFWwindow* w, int width,
					       int height) {
		glViewport(0, 0, width, height);
	});

	m_monitor = glfwGetPrimaryMonitor();
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
	      const GLFWvidmode *mode = glfwGetVideoMode(m_monitor);
	      glfwSetWindowMonitor(m_window, m_monitor, 0, 0, mode->width, mode->height, 0);
	}
}

void Window::setWindowed(bool set) {
	if(set) {
	}
}

void Window::closeWindow() {
	glfwDestroyWindow(m_window);
	glfwTerminate();
}

void Window::setAspectRatio(uint32_t x, uint32_t y) {
	// Todo: check if the ratio specified doesn't equal any of
	// the standard aspect ratios
	glfwSetWindowAspectRatio(m_window, x, y);
}

int32_t Window::getWindowWidth() {
	int32_t width, height;
	glfwGetWindowSize(m_window, &width, &height);
	return width;
}

int32_t Window::getWindowHeight() {
	int32_t width, height;
	glfwGetWindowSize(m_window, &width, &height);
	return height;
}

void Window::setWindowSize(uint32_t x, uint32_t y) {
	glfwSetWindowSize(m_window, x, y);
}

void Window::setWindowMaxlimits(uint32_t x, uint32_t y) {
	// window limits only apply in windowed mode
	if(glfwGetWindowMonitor(m_window) == nullptr) {
	      glfwSetWindowSizeLimits(m_window, GLFW_DONT_CARE, GLFW_DONT_CARE, x, y);
	}
}

void Window::setWindowMinlimits(uint32_t x, uint32_t y) {
	// window limits only apply in windowed mode
	if(glfwGetWindowMonitor(m_window) == nullptr) {
	      glfwSetWindowSizeLimits(m_window, x, y, GLFW_DONT_CARE, GLFW_DONT_CARE);
	}
}

void Window::setWindowPosition(uint32_t x, uint32_t y) {
	glfwSetWindowPos(m_window, x, y);
}
