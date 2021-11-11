#include <libr3d.h>
#include <renderer/opengl/OpenGLRenderer.h>

struct SandboxApp : public rnd::Application
{
    using Application::Application;
    void Setup() {
    }

    void Render() {
    }
};

int main()
{
	SandboxApp *app = new SandboxApp(900, 600, "libr3d", false);
	app->Setup();
	app->setVSync(true);
	
	while(app->Running()) {
		app->calcDeltaTime();
		app->Update();
		app->Render();
	}
	delete app;
}
