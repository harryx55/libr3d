#include "pch.h"
#include "log.h"

enum CONSOLE_COLOR {
      BLACK       = 0,
      BLUE        = FOREGROUND_BLUE,
      GREEN       = FOREGROUND_GREEN,
      RED         = FOREGROUND_RED,
      YELLOW      = FOREGROUND_RED | FOREGROUND_GREEN,
      DEFAULT     = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE
};

using namespace rnd;
// the first argument is the severity of the message
void print(const char* level, const char* format, ...) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	
	if(strcmp(level, "error")) {
	      SetConsoleTextAttribute(hConsole, CONSOLE_COLOR::RED);
	}
	else if (strcmp(level, "warn")) {
	      SetConsoleTextAttribute(hConsole, CONSOLE_COLOR::YELLOW);	      
	}
        else if (strcmp(level, "info")) {
	      SetConsoleTextAttribute(hConsole, CONSOLE_COLOR::GREEN);
	}
	else if (strcmp(level, "debug")) {
	      SetConsoleTextAttribute(hConsole, CONSOLE_COLOR::BLUE);
	}

	va_list arg;
	va_start(arg, 0);
        vprintf(format, arg); 
	va_end(arg);
	
	SetConsoleTextAttribute(hConsole, CONSOLE_COLOR::DEFAULT);
}

