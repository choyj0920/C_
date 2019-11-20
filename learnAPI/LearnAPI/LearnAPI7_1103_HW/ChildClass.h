#pragma once
#include "framework.h"

class ChildClass
{
private:

	WNDCLASSEXW wcex;
	HWND super_hwnd;
	HWND Ihwnd;
	HINSTANCE _Inst;

public:
	ChildClass();
	~ChildClass();
	int MessageLoop();
	static LRESULT CALLBACK staticpro_ch(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	static LRESULT CALLBACK staticpro_po(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	static ChildClass* childwindow;
	static ChildClass* popupwindow;
	
	LRESULT	 childProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	LRESULT	 popProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	HWND setchild(HWND shwnd,HINSTANCE _hins, HCURSOR cursorset, HBRUSH brushset, LPCWSTR szname, bool popup);
	HWND createchlidwindow(HWND shwnd, bool popup,LPCWSTR szname,const WCHAR *(menu),HINSTANCE _hInst,const RECT& pos);
};

