#pragma once
#include "framework.h"

class ModalClass
{
private:

	HWND super_hwnd;
	HWND m_hWnd;
	HWND x_Scrolbar=NULL;
	HWND y_Scrolbar= NULL;
	HINSTANCE _Inst;
	LPCWSTR _szModalName;  //������Ʈ���� ����� �ڽ� �������� ����ü �̸�

public:
	ModalClass();
	~ModalClass();
	int MessageLoop();
	static ModalClass* modalwindow;

	LRESULT	 ModalProc(HWND mhWnd, UINT message, WPARAM wParam, LPARAM lParam);
	static LRESULT statiproc(HWND hWnd, UINT iMsg,
		WPARAM wParam, LPARAM lParam);
	void createModalwindow(HWND shwnd, LPCTSTR resource, HINSTANCE _hInst);
};
