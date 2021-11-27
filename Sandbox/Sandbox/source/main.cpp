#include <libr3d.h>
#include <renderer/opengl/OpenGLRenderer.h>

int main() {
	rnd::print("Debug", "%s\n", "Test print");
	rnd::Application *app = rnd::Application::Get();
	if(!app->Create()) {
	      rnd::print("Error", "%s\n", "failed to create application instance ");
	}
	app->GetWindow()->setVSync(true);
	
	while(app->GetWindow()->Running()) {
		app->calcDeltaTime();
		app->Update();
	}
	delete app;
}
