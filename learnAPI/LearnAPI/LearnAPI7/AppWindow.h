#pragma once
#include "ChildClass.h"
#include "ImageDraw.h"
class AppWindow
{
private:
	WNDCLASSEXW wcex;
	WCHAR szTitle[MAX_LOADSTRING];                  // ���� ǥ���� �ؽ�Ʈ�Դϴ�.
	WCHAR szWindowClass[MAX_LOADSTRING];            // �⺻ â Ŭ���� �̸��Դϴ�.
	HINSTANCE _Inst;
	HWND _childWnd1;													//�ڽ� ������ �ڵ�.
	HWND _PopupWnd1;													//�˾� ������ �ڵ�.
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

