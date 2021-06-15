#include "pch.h"
#include "MainApp.h"

#ifdef R3D_WINDOWS


int main(int argc, char** argv)
{
	R3D::MainApp::onCreate();
	R3D::MainApp::Run();
	R3D::MainApp::onClose();
}

#endif