#include "pch.h"
#include "Application.h"

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
		std::array<float, 6> vertices =
		{
			-0.5f, -0.5f,
			 0.0f,  0.5f,
			 0.5f, -0.5f
		};
		unsigned int vao;
		glGenVertexArrays(1, &vao);
		glBindVertexArray(vao);

		unsigned int vbo;
		glGenBuffers(1, &vbo);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferData(GL_ARRAY_BUFFER, sizeof(float) * vertices.size(), vertices.data(), GL_STATIC_DRAW);

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * 4, (void*)0);
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