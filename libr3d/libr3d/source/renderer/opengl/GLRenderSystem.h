#ifndef _GL_RENDER_SYSTEM_H_
#define _GL_RENDER_SYSTEM_H_

#include <glad.h>

namespace rnd {
	void GL_Clear(float r = 0.0f, float g = 0.0f, float b = 0.0f, bool backBuffer = true, bool DepthTest = false, bool stencilTest = false);
	void GL_init();
	      
	struct Renderable2D {
		Renderable2D(/*math::vec3 position, math::vec4 color, math::vec2 size */);
	private:
		GLuint vertexArray;
		GLuint vertexBuffer;
		GLuint indexBuffer;
	};
}

#endif
