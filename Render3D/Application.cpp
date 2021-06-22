#include "pch.h"
#include "Application.h"

#include "OpenGL/OpenGLBuffers.h"

namespace R3D
{
	// Runs on startup
	void Application::Init()
	{
		Log::Init();
		R3D_INFO("Initialized...!");

		// initialize opengl
		gladLoadGL();
	}

	// Runs before render
	void Application::Prepare()
	{
		R3D_WARN("Preparing render...");
		float vertices[] =
		{
			-0.5f, -0.5f,
			 0.0f,  0.5f,
			 0.5f, -0.5f
		};

		VertexArray vao;
		vao.CreateVertexArray();

		VertexBuffer* vbo = new VertexBuffer;
		vbo->AttachBuffer(vertices, 6, 2);
		vao.AddBuffer(vbo, 0);
	}

	// Runs every frame, rendering is done here
	void Application::Update()
	{
		glDrawArrays(GL_TRIANGLES, 0, 3);
	}

	// Run after rendering is done
	void Application::Close()
	{
	}
}