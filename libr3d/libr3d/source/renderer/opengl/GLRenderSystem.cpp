#include "pch.h"
#include "GLRenderSystem.h"

using namespace rnd;

static const char* GL_errorsMessage(GLenum err) {
      switch(err) {
	  case GL_INVALID_ENUM:
	      return "GL_INVALID_ENUM";

	  case GL_INVALID_VALUE:
	      return "GL_INVALID_VALUE";

	  case GL_INVALID_OPERATION:
	      return "GL_INVALID_OPERATION";
			
	  case GL_OUT_OF_MEMORY:
	      return "GL_OUT_OF_MEMORY";

	  case GL_INVALID_FRAMEBUFFER_OPERATION:
	      return "GL_INVALID_FRAMEBUFFER_OPERATION";
      }
      return "GL_NO_ERROR";
}

bool GL_logCall(const GLchar* function, const GLchar* file, GLuint line) {
      if (auto error = glGetError()) {
	    rnd::print("Error", "%s%s%s%s%s%d\n", "OpenGL Error: ", GL_errorsMessage(error), " in function ", function, file, line );
	    return false;
      }
      return true;
}

#ifdef _DEBUG
      #define GL_ERR(x) while(glGetError() !=  GL_NO_ERROR); x; if(!(GL_logCall(#x, __FILE__, __LINE__))) { __debugbreak(); }
#else
      #define GL_ERR(x) x
#endif

void GL_Clear(float r = 0.0f, float g = 0.0f, float b = 0.0f, bool DepthTest = false, bool stencilTest = false) {
      GLenum mask = GL_COLOR_BUFFER_BIT;
	      
      if(DepthTest) {
	    mask |= GL_DEPTH_BUFFER_BIT;
      }
  
      if(stencilTest) {
	    mask |= GL_STENCIL_BUFFER_BIT;
      }

      GL_ERR(glClear(mask));
      glClearColor(r, g, b, 1.0f);
}

void GL_init() {
      //
      // initialize opengl functions
      Assert(gladLoadGL(), "Failed to initialize GLAD \n");
      
      rnd::print("Info", "%s\n", glGetString(GL_VENDOR));
      rnd::print("Info", "%s\n", glGetString(GL_VERSION));
      rnd::print("Info", "%s\n", glGetString(GL_RENDERER));
      rnd::print("Info", "%s\n", glGetString(GL_EXTENSIONS));


      
}
