#pragma once
#include "../framework.h"
class System: public Singleton<System>
{
private:

	MSG msg;
	LPCWSTR _ApplicationName;

	HINSTANCE _Inst;
	HWND m_hWnd;

	bool isFullScreen;
	void ShutdownWindows();
	void InitializeWindows(HINSTANCE hInst, bool isFull, int& screenW, int& screenH);
public:
	System();
	~System();
	static TCHAR _szFullPathName[MAX_PATH];
	bool Frame();

	int Run();
	void Shutdown();
	LRESULT	 AppProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam); //���� ���ν���

	static LRESULT CALLBACK statiproc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam); //���� ���� ����
	//����� ��ü��
	GraphicsClass* graphics;
	InputClass* InputC;
	bool Initialize(HINSTANCE hinstance, bool isFull = true,int =800,int =600);
};

