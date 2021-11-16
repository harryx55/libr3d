#include "pch.h"
#include "base.h"

void rnd::print(const char* level, const char* format, ...) {
#ifdef _DEBUG
#ifdef _WIN32
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
  
#endif
  va_list args;
  va_start(args, format);
  vprintf(format, args);
  va_end(args);

#ifdef _WIN32
  // restore defualt foreground console color(grey)
  SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
#endif
#endif
}
