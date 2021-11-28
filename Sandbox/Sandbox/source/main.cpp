#include <libr3d.h>
#include <renderer/opengl/OpenGLRenderer.h>

int main() {
	rnd::print(rnd::ERR::PRINT_DEBUG, "%s\n", "Test print");
	rnd::Application *app = rnd::Application::Get();
	if(!app->Create()) {
	      rnd::print(rnd::ERR::PRINT_ERROR, "%s\n", "failed to create application instance ");
	}
	app->GetWindow()->setVSync(true);
	
	while(app->GetWindow()->Running()) {
		app->calcDeltaTime();
		rnd::print(rnd::ERR::PRINT_DEBUG, "%f\n", app->GetFPS());
		app->Update();
	}
	delete app;
}
