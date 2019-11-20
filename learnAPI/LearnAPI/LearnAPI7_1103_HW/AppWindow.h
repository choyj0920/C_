#pragma once
#include "ChildClass.h"
class AppWindow
{
private:
	WNDCLASSEXW wcex;
	WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
	WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.
	HINSTANCE _Inst;
	HWND _childWnd1;													//자식 윈도우 핸들.
	HWND _PopupWnd1;													//팝업 윈도우 핸들.
	HWND m_hWnd;

public:
	AppWindow();
	~AppWindow();
	static POINT set[8][8];
	static TCHAR _szFullPathName[MAX_PATH];
	ChildClass child;
	ChildClass popup;
	ModalClass modal;
	static int div_x, div_y;
	static POINT* findcell(int x, int y);
	void SetRegistClass(HINSTANCE inst);
	BOOL CreateAppWindow(int nCmdShow);
	int MessageLoop();
	LRESULT	 AppProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam); //실제 프로시저
	static LRESULT CALLBACK statiproc(HWND hWnd, UINT iMsg,WPARAM wParam, LPARAM lParam); //정적 프로 시저
	static AppWindow* mainWindow; //프로시저 실행을 위해 윈도우 객체 주소 변수
	
	BOOL InitializeWnd(HINSTANCE hinstance, int ncmdshow);


};

