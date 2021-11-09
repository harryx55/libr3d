#ifndef _LOG_H_
#define _LOG_H_
#include <windows.h>

namespace rnd {
	void print(const char* level, const char* format, ...);
}
#endif
