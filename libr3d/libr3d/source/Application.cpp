#include "Application.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

using namespace rnd;
Application::Application() {
	window = new Window(1280, 720, "libr3d");
	if(!gladLoadGL()) {
		printf("failed not initialize glad \n"); __debugbreak();
	}

	shader       = (OpenGLShaders*)malloc(sizeof(OpenGLShaders));
	vertexArray  = (VertexArray*)malloc(sizeof(VertexArray));
	vertexBuffer = (VertexBuffer*)malloc(sizeof(VertexBuffer));
	indexBuffer  = (IndexBuffer*)malloc(sizeof(IndexBuffer));

	input = (Input*)malloc(sizeof(Input));

	vertexArray->CreateVertexArray();
	float vertices[] =
	  {
	    -0.5f, -0.5f,
	    -0.5f,  0.5f,
	    0.5f,  0.5f,
	    0.5f, -0.5f
	  };
	
	vertexBuffer->CreateBuffer(vertices, 8);

	uint32_t indices[] =
	  {
	    0, 1, 2, 2, 3, 0
	  };
	indexBuffer->CreateBuffer(indices, 6);
	vertexArray->AttachAttributes(0, 2, 2, 0);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);

	const char* vertexSrc     =
	  R"(#version 140
	  in vec3 aPos;
	  void main()
	  {
	          gl_Position = vec4(aPos, 1.0);
	  })";

	const char* fragmentSrc =
	  R"(#version 140
	  out vec4 fragColor;	  
	  void main()
	  {
	  fragColor = vec4(0.4, 0.4, 0.4, 1.0);
	  })";

	shader->LoadShaders(vertexSrc, fragmentSrc);
}

bool Application::Running() {
	return window->Running();
}

void Application::Update() {
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
		
	vertexArray->BindVertexArray();
	shader->BindShader();

	if(input->IsKeyPressed(GLFW_KEY_A)) {
		printf("%s%f\n", "Mouse position Y : ", input->GetMousePosYImpl());
	}
	
	if(input->IsKeyPressed(GLFW_KEY_W)) {
		  printf("%s\n", input->GetKeyName(GLFW_KEY_W));
	}
	glDrawElements(GL_TRIANGLES, indexBuffer->count, GL_UNSIGNED_INT, nullptr);
	window->Update();
}

Application::~Application() {
	free(vertexArray);
	free(vertexBuffer);
	free(indexBuffer);

	delete window;
}

void Application::setVSync(bool set) {
	window->setVSync(set);
}

void Application::setFullscreen(bool set) {
	window->setFullscreen(set);
}

void Application::setResizable(bool set) {
	window->setResizable(set);
}
