#include "pch.h"
#include "Application.h"

using namespace rnd;
Application *Application::s_instance;
bool Application::Create(uint32_t width, uint32_t height, const char* windowCaption, bool resizable) {
	window = new Window(width, height, windowCaption, resizable);
	
	// @TODO: if using opengl renderer then initialize glad

	Assert(gladLoadGL(), "Failed to initialize glad \n");
	rnd::print(rnd::ERR::PRINT_INFO, "%s\n", glGetString(GL_VENDOR));
	rnd::print(rnd::ERR::PRINT_INFO, "%s\n", glGetString(GL_VERSION));
	rnd::print(rnd::ERR::PRINT_INFO, "%s\n", glGetString(GL_RENDERER));
	rnd::print(rnd::ERR::PRINT_INFO, "%s\n", glGetString(GL_EXTENSIONS));
	
	// @Refactor:
	input = (Input*)malloc(sizeof(Input));
	return true;
}


void Application::Update() {
	//@Temp
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.2f, 0.2f, 0.2f, 1.0f);

	if(input->IsKeyPressed(GLFW_KEY_A)) {
	      rnd::print(rnd::ERR::PRINT_INFO, "%s\n", "Mouse position Y : ", input->GetMousePosYImpl());
	}
	
	if(input->IsKeyPressed(GLFW_KEY_W)) {
	      rnd::print(rnd::ERR::PRINT_INFO, "%s\n", input->GetKeyName(GLFW_KEY_W));
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

