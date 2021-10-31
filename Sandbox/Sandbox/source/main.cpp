#include <libr3d.h>
#include <renderer/opengl/OpenGLRenderer.h>

#include <stdio.h>

struct SandboxApp : public rnd::Application
{
  void Setup(){
	  printf("Hello World! \n");
  }

  void Render(){
  }
};

int main()
{
	SandboxApp *app = new SandboxApp();
	app->Setup();
	app->setVSync(true);
	app->setResizable(false);
	
	while(app->Running()) {
		app->Update();
		app->Render();
	}
	delete app;
}
