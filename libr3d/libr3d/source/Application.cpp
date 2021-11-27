#include "pch.h"
#include "Application.h"

using namespace rnd;
Application *Application::s_instance;
bool Application::Create(uint32_t width, uint32_t height, const char* windowCaption, bool resizable) {
	window = new Window(width, height, windowCaption, resizable);
	
	// @TODO: if using opengl renderer then initialize glad

	Assert(gladLoadGL(), "Failed to initialize glad \n");
	rnd::print("Info", "%s\n", glGetString(GL_VENDOR));
	rnd::print("Info", "%s\n", glGetString(GL_VERSION));
	rnd::print("Info", "%s\n", glGetString(GL_RENDERER));
	
	// @Refactor:
	input = (Input*)malloc(sizeof(Input));
	return true;
}


void Application::Update() {
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.2f, 0.2f, 0.2f, 1.0f);

	if(input->IsKeyPressed(GLFW_KEY_A)) {
	      rnd::print("Info", "%s\n", "Mouse position Y : ", input->GetMousePosYImpl());
	}
	
	if(input->IsKeyPressed(GLFW_KEY_W)) {
	      rnd::print("Info", "%s\n", input->GetKeyName(GLFW_KEY_W));
	}
	window->Update();
}

Application::~Application() {
	delete window;
}

double Application::calcDeltaTime() {
      float time  = (float)glfwGetTime();
      m_deltaTime = time - m_lastTime;
      m_lastTime  = time;

      return m_lastTime;
}

