#include <libr3d.h>
#include <renderer/opengl/OpenGLRenderer.h>

#include <stdio.h>

struct SandboxApp : public Application
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
	
	while(app->Running()) {
		app->Update();
		app->Render();
	}
	delete app;
}
