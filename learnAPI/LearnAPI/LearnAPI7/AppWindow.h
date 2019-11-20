#pragma once
#include "ChildClass.h"
#include "ImageDraw.h"
class AppWindow
{
private:
	WNDCLASSEXW wcex;
	WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
	WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.
	HINSTANCE _Inst;
	HWND _childWnd1;													//자식 윈도우 핸들.
	HWND _PopupWnd1;													//팝업 윈도우 핸들.
	ImageDraw imgDraw;

public:
	AppWindow();
	~AppWindow();
	ChildClass child;
	ChildClass popup;
	void SetRegistClass(HINSTANCE inst);
	BOOL CreateAppWindow(int nCmdShow);
	int MessageLoop();
	LRESULT	 AppProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	
	BOOL InitializeWnd(HINSTANCE hinstance, int ncmdshow);
	static AppWindow* proc;
	
	
	BOOL CreatchildWindow(int nCmdShow);
	
};

