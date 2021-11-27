#ifndef __BASE_H_
#define __BASE_H_


namespace rnd {
      typedef char               int8;
      typedef short              int16;
      typedef int                int32;
      typedef long long          int64;

      typedef unsigned char      uint8;
      typedef unsigned short     uint16;
      typedef unsigned int       uint32;
      typedef unsigned long long uint64;

      enum class ERR {
	  PRINT_ERROR = 0,
	  PRINT_INFO  = 1,
	  PRINT_WARN  = 2,
	  PRINT_DEBUG = 3
      };
      void print(ERR level, const char* format, ...);
};


#ifdef _DEBUG
#define Assert(x, error) {if((!x)) { rnd::print(ERR::PRINT_ERROR, "%s", error); __debugbreak(); }}
#elif
    #define Assert(x, error)
#endif

#endif
