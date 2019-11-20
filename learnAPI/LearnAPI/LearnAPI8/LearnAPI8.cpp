// LearnAPI7.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "AppWindow.h"



int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	srand((unsigned)time(0));
	AppWindow app;

	if (!app.InitializeWnd(hInstance, nCmdShow)) {
		return 0;
	}

	app.MessageLoop();

	return 0;
}


