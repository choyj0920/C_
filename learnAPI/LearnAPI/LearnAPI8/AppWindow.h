#pragma once
#include "ChildClass.h"
#include "ModalClass.h"
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
	ImageDraw imgdraw;
	bool gameStart = false;
	Ch_Manager manager;
public:
	AppWindow();
	~AppWindow();
	static POINT set[8][8];
	static TCHAR _szFullPathName[MAX_PATH];
	ChildClass child;
	int ninja_set = 0;
	POINT ninja = { 10,10 };
	ChildClass popup;
	HWND m_hWnd;

	ModalClass modal;
	static int div_x, div_y;
	static POINT* findcell(int x, int y);
	void SetRegistClass(HINSTANCE inst);
	BOOL CreateAppWindow(int nCmdShow);
	int MessageLoop();
	LRESULT	 AppProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam); //���� ���ν���
	static LRESULT CALLBACK statiproc(HWND hWnd, UINT iMsg,WPARAM wParam, LPARAM lParam); //���� ���� ����
	static AppWindow* mainWindow; //���ν��� ������ ���� ������ ��ü �ּ� ����
	
	BOOL InitializeWnd(HINSTANCE hinstance, int ncmdshow);


};

