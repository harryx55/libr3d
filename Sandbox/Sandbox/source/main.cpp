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
	
	while(app->Running()) {
		app->calcDeltaTime();
		app->Update();
		app->Render();
		rnd::print("Error", "%f%s\n", app->getTime(), " ms");
	}
	delete app;
}
