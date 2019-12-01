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
	// â ���� �Լ�
	void ShutdownWindows();
	// ������ Ŭ���� ���� �� â ������ִ� �Լ�
	void InitializeWindows(HINSTANCE hInst, bool isFull, int& screenW, int& screenH);
public:
	System();
	~System();
	// �׷���, Ű�Է� �Լ� ����
	bool Frame();
	//�޽��� ���� �Լ�
	int Run();
	// Ŭ���� ��� -�Ҵ� �����Լ�
	void Shutdown();
	LRESULT	 AppProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam); //���� ���ν���

	static LRESULT CALLBACK statiproc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam); //���� ���� ����
	//����� ��ü��
	GraphicsClass* graphics;
	InputClass* InputC;
	//�ܺο��� ������Ŭ���� �ʱ�ȭ �Լ�
	bool Initialize(HINSTANCE hinstance, bool isFull = false,int =800,int =600);
};

