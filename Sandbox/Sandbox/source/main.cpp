#include <libr3d.h>
#include <renderer/opengl/OpenGLRenderer.h>

struct SandboxApp : public rnd::Application
{
  void Setup() {
  }

  void Render() {
  }
};

int main()
{
	SandboxApp *app = new SandboxApp();
	app->Setup();
	app->setVSync(true);
	app->setResizable(true);

	// 	app->setFullscreen(true);
	rnd::print("Error", "%d\n", app->getWindowWidth());
	rnd::print("Error", "%d\n", app->getWindowHeight());
	
	while(app->Running()) {
		app->Update();
		app->Render();
	}
	delete app;
}
