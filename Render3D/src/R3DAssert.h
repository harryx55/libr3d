#pragma once


#ifdef ENABLE_ASSERTS
	#define R3D_ASSERT(x, ...) { if((!x)) { ASSERT(x, __VA_ARGS__); __debugbreak(); } }
#else
	#define R3D_ASSERT(x, ...)
#endif