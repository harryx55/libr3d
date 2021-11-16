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

    void print(const char* level, const char* format, ...);
};


#ifdef _DEBUG
    #define ASSERT(x, error) {if((!x)) { rnd::print("Error", "%s", error); __debugbreak(); }}
#elif
    #define ASSERT(x, error)
#endif

#endif
