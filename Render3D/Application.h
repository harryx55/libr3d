#pragma once


#define  SCREEN_WIDTH		1280
#define  SCREEN_HEIGHT		1280
#define  WINDOW_TITLE		"Window"
#define  VSYNC				true

namespace R3D
{
	class Application
	{
	public:
		static void Init();
		static void Prepare();
		static void Update();
		static void Close();
	};
}