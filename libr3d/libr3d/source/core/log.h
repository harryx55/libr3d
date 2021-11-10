#ifndef _LOG_H_
#define _LOG_H_

#ifdef _WIN32 && _DEBUG
#include <windows.h>
namespace rnd {
	void print(const char* level, const char* format, ...);
}
#elif
namespace rnd {
	void print(const char* level, const char* format, ...);
}
#endif
#endif
