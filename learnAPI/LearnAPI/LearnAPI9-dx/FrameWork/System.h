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
	// 창 끄는 함수
	void ShutdownWindows();
	// 윈도우 클래스 선언 및 창 만들어주는 함수
	void InitializeWindows(HINSTANCE hInst, bool isFull, int& screenW, int& screenH);
public:
	System();
	~System();
	// 그래픽, 키입력 함수 실행
	bool Frame();
	//메시지 루프 함수
	int Run();
	// 클래스 멤버 -할당 해제함수
	void Shutdown();
	LRESULT	 AppProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam); //실제 프로시저

	static LRESULT CALLBACK statiproc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam); //정적 프로 시저
	//사용할 객체들
	GraphicsClass* graphics;
	InputClass* InputC;
	//외부에서 윈도우클래스 초기화 함수
	bool Initialize(HINSTANCE hinstance, bool isFull = false,int =800,int =600);
};

