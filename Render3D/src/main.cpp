#include "pch.h"
#include "Application.h"

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720
#define VSYNC		 true


int main()
{
	R3D::Log::Init();
	R3D::Application* game = new R3D::Application(R3D::RENDERER::OPENGL, VSYNC, SCREEN_WIDTH, SCREEN_HEIGHT);

	R3D_INFO("Application Initialized!");
	
	if (!gladLoadGL())
	{
		R3D_ERROR("GLAD| glad initialization error");
	}

	R3D_INFO("Preparing render...");
	float vertices[] =
	{
		-0.5f, -0.5f,     1.0f, 0.0f, 0.0f,
		-0.5f,  0.5f,     0.0f, 1.0f, 0.0f,
		 0.5f,  0.5f,     0.0f, 0.0f, 1.0f,
		 0.5f, -0.5f,     0.0f, 0.0f, 1.0f
	};

	unsigned int indices[] =
	{
		0, 1, 2, 2, 3, 0
	};

	R3D::VertexArray vao = R3D::VertexArray();
	vao.CreateVertexArray();

	R3D::VertexBuffer* vbo = new R3D::VertexBuffer;
	vbo->AttachBuffer(vertices, 20, 2);

	R3D::IndexBuffer ibo = R3D::IndexBuffer();
	ibo.AttachBuffer(indices, 6);

	vao.AddBuffer(0, 2, 5);		// positions
	vao.AddBuffer(1, 3, 5);		// colors

	Shaders shader;
	shader.AttachShader("C:/Solutions/Render3D/Render3D/OpenGL/shaders/vertex.glsl",
		"C:/Solutions/Render3D/Render3D/OpenGL/shaders/fragment.glsl");

	while (game->WindowIsOpen())
	{
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
		game->OnUpdate();
	}
	game->onShutDown();
}




