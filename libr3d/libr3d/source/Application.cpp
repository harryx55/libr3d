#include "pch.h"
#include "Application.h"

using namespace rnd;
Application *Application::s_instance;

/*Application::Application(uint32_t width, uint32_t height, const char* title,
			 bool resizable) : m_deltaTime(0.0), m_lastTime(0.0f) {
        s_instnace = this;
	if(s_instnce) {
	      print("Error", "%s\n", "[ERROR] multiple instances of application");
	      __debugbreak();
	      }

	window = new Window(width, height, title, resizable);
	if(!gladLoadGL()) {
		printf("failed not initialize glad \n"); __debugbreak();
	}

	input = (Input*)malloc(sizeof(Input));
}*/
bool Application::Create(uint32_t width, uint32_t height, const char* windowCaption, bool resizable) {
	window = new Window(width, height, windowCaption, resizable);
	
	// @TODO: if using opengl renderer then initialize glad
	if(!gladLoadGL()) {
	      print("Error", "%s", "[ERROR] failed to initialize glad");
	      __debugbreak();
	}

	// @Refactor:
	input = (Input*)malloc(sizeof(Input));
	return true;
}


void Application::Update() {
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.2f, 0.2f, 0.2f, 1.0f);

	if(input->IsKeyPressed(GLFW_KEY_A)) {
		printf("%s%f\n", "Mouse position Y : ", input->GetMousePosYImpl());
	}
	
	if(input->IsKeyPressed(GLFW_KEY_W)) {
		  printf("%s\n", input->GetKeyName(GLFW_KEY_W));
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

