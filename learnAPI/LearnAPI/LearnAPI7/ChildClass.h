#pragma once
#include "framework.h"

class ChildClass
{
private:

	WNDCLASSEXW wcex;
	
	HINSTANCE _Inst;

public:
	ChildClass();
	~ChildClass();
	WNDCLASSEXW*  getRegistClass();
	int MessageLoop();
	LRESULT	 childProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	LRESULT	 popProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

};
