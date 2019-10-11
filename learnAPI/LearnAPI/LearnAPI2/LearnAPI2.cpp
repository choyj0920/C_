// LearnAPI2.cpp : 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "LearnAPI2.h"

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE _hInst;														//어플리케이션 핸들.
HWND _hWnd;																//메인 윈도우 핸들.
LPCWSTR _szWinClassName = L"MAKE_WINDOW2";
SortAlgorithmClass sort;

WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.
TCHAR str[MAX_PATH] = { 0, };

WNDCLASS wndClass;											//커스텀할 윈도우 구조체 변수.
MSG msg;															//메시지 루프에서 사용할 변수

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
//윈도우 프로 시져 함수 CALLBACK 은 계속 실행 하게 하는 ~
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
// 클래스 등록 , 클래스 변수 초기화 함수
void myRegisterClass(HINSTANCE hInstance);
// 창 만드는 함수
BOOL CreateShowWindow(HINSTANCE hInstance, int nCmdShow);
//메시지 루프 함수
int MessageLoop(HINSTANCE hInstace);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.
	srand(time(0));
	_hInst = hInstance;												//어플리케이션의 핸들을 저장.
	sort.InitArrrayData();

  
	//윈도우 구조체의 내용을 저장.
	myRegisterClass(hInstance);
	if (!CreateShowWindow(hInstance, nCmdShow)) {
		return 0;
	}

	MessageBox(NULL, L"윈도우 창 생성.", L"알림", MB_YESNO);   //윈도우 시작시 실행

	SetTimer(_hWnd, TIMER_TEST1, 250, NULL);




	return MessageLoop(hInstance);
}
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM IParam) {

	switch (uMsg)
	{
	case WM_TIMER:
		switch (wParam)
		{
		default:
			break;
		}
		break;
	case WM_COMMAND: {
		int id = LOWORD(wParam);
		switch (id)
		{
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			break;
		}
		break;

	}

	case WM_PAINT: {
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		sort.SelectedSort(hdc, RECT{ 500,120,100,100 });
		break;
	}
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	}
	return (DefWindowProc(hWnd, uMsg, wParam, IParam));
}


//클래스 레지스터 등록 
void myRegisterClass(HINSTANCE hInstance)
{
	wndClass.cbClsExtra = 0;
	wndClass.cbWndExtra = 0;
	wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); //하얀색
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndClass.hIcon = LoadIcon(NULL, MAKEINTRESOURCE(IDI_LEARNAPI2));
	wndClass.hInstance = _hInst; //hinstance;
	wndClass.lpfnWndProc = WndProc;
	wndClass.lpszClassName = _szWinClassName;
	wndClass.lpszMenuName = MAKEINTRESOURCEW(IDC_LEARNAPI2);
	wndClass.style = CS_HREDRAW | CS_VREDRAW;

	RegisterClass(&wndClass);
}

//창 만들기, 
BOOL CreateShowWindow(HINSTANCE hInstance, int nCmdShow)
{
	_hWnd = CreateWindow(_szWinClassName, _szWinClassName, WS_OVERLAPPEDWINDOW
		, CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, (HMENU)NULL, _hInst, NULL);
	if (_hWnd == NULL)
		return 0;
	ShowWindow(_hWnd, nCmdShow);
	return 1;


}

//메시지 루프
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