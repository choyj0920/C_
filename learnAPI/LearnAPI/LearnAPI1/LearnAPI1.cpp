// LearnAPI1.cpp : 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "LearnAPI1.h"

//윈도우 구조체를 레지스트에 등록
//윈도우를 만들고 show
//메시지 루프 구현
//윈도우 프로 시져 구현.

//전역변수,
HINSTANCE _hInst;														//어플리케이션 핸들.
HWND _hWnd;																//메인 윈도우 핸들.
LPCWSTR _szWinClassName = L"MakeWindow";		
WNDCLASS wndClass;											//커스텀할 윈도우 구조체 변수.
MSG msg;															//메시지 루프에서 사용할 변수
void paintprint(HWND hWnd, int n);
//레지스트리에 등록할 윈도우 구조체 이름.
// LPWSTR ,LPCWSTR const 차이
//윈도우 메인 프로시져
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM IParam);
void myRegisterClass(HINSTANCE hInstance);
BOOL CreateShowWindow(HINSTANCE hInstance, int nCmdShow);
int MessageLoop(HINSTANCE hInstace);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	srand(time(0));


	_hInst = hInstance;												//어플리케이션의 핸들을 저장.

	//윈도우 구조체의 내용을 저장.
	myRegisterClass(hInstance);
	if (!CreateShowWindow(hInstance, nCmdShow)) {
		return 0;
	}
	MessageBox(NULL, L"윈도우 창 생성.", L"알림", MB_YESNO);



	return MessageLoop(hInstance);
	
}
//초기화 되지않기 위해 전역으로 
int n = 0;
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM IParam) {
	
	switch (uMsg)
	{
	case WM_COMMAND: {
			int id = LOWORD(wParam);
			switch (id)
			{
			case IDM_EXIT:
				DestroyWindow(hWnd);
				break;
			case IDM_MESSAGE:
				MessageBox(NULL, L"바보.", L"알림", MB_YESNO);
				break;
			case ID_32773:
				n = 1;
				InvalidateRect(hWnd, NULL, false);
				break;
			case ID_32774:
				n = 2;
				InvalidateRect(hWnd, NULL, false);
				break;
			case ID_32775:
				n = 3;
				InvalidateRect(hWnd, NULL, false);
				break;
			}
			break;

		}
	case WM_PAINT: {
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		int x = rand() % 800;
		int y = rand() % 500;
		int x_len = rand() % 500;
		int y_len = rand() % 500;
		switch (n)
		{
		case 1: {
			MoveToEx(hdc, x, y, NULL);
			LineTo(hdc, x +x_len, y+ y_len);
			break;
		}
		case 2: {
			Rectangle(hdc, x, y, x+x_len, y + y_len); //그래서 원 먼저 그리면 사각형 그리면서 사라짐
			break;
		}
		case 3: {
			Ellipse(hdc, x, y, x + x_len, y + y_len); //그래서 원 먼저 그리면 사각형 그리면서 사라짐
			break;
			}

		}
		break;
	}
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	}



	return (DefWindowProc(hWnd, uMsg, wParam, IParam));
}

void myRegisterClass(HINSTANCE hInstance)
{
	wndClass.cbClsExtra = 0;
	wndClass.cbWndExtra = 0;
	wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); //검은색
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndClass.hIcon = LoadIcon(NULL, MAKEINTRESOURCE(IDI_LEARNAPI1));
	wndClass.hInstance = _hInst; //hinstance;
	wndClass.lpfnWndProc = WndProc;
	wndClass.lpszClassName = _szWinClassName;
	wndClass.lpszMenuName = MAKEINTRESOURCEW(IDC_LEARNAPI1);
	wndClass.style = CS_HREDRAW | CS_VREDRAW;

	RegisterClass(&wndClass);
}

BOOL CreateShowWindow(HINSTANCE hInstance, int nCmdShow)
{
	_hWnd = CreateWindow(_szWinClassName, _szWinClassName, WS_OVERLAPPEDWINDOW
		, CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, (HMENU)NULL, _hInst, NULL);
	if (_hWnd == NULL)
		return 0;
	ShowWindow(_hWnd, nCmdShow);
	return 1;

	
}

int MessageLoop(HINSTANCE hInstace)
{
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (int)msg.wParam;
}

void paintprint(HWND hWnd, int n) 
{

}