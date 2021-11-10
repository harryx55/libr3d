#include "pch.h"
#include "log.h"

// the first argument is the severity of the message
#ifdef _WIN32 && _DEBUG
void rnd::print(const char* level, const char* format, ...) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	switch(level[0]) {
	case 'E':
	      SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
	      break;
	case 'D':
	      SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
	      break;
	case 'I':
	      SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	  break;
	case 'W':
	      SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
	      break;
	      }

	va_list args;
	va_start(args, format);
	vprintf(format, args);
	va_end(args);
	
	// restore defualt foreground console color(grey)
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

#elif
void rnd::print(const char* level, const char* format, ...) {
	va_list args;
	va_start(args, format);
	vprintf(format, args);
	va_end(args);
}
#endif
