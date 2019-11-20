// LearnAPI2.cpp : 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "LearnAPI6.h"

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE _hInst;														//어플리케이션 핸들.
HWND _hWnd;																//메인 윈도우 핸들.
HWND _childWnd1;													//자식 윈도우 핸들.
HWND _PopupWnd1;													//자식 윈도우 핸들.
INT_PTR WINAPI _Dialogbox;													//다이얼 로그 박스
HWND WINAPI _Dialogbox2;													//다이얼 로그 박스

LPCWSTR _szWinClassName = L"MultyWindow";			//레지스트리에 등록할 자식 윈도우의 구조체 이름
LPCWSTR _szChildWndClassName = L"ChildTestWnd1";  //레지스트리에 등록할 자식 윈도우의 구조체 이름
LPCWSTR _szPopupWndClassName = L"PopupTestWnd";  //레지스트리에 등록할 자식 윈도우(팝업)의 구조체 이름

//컨트롤 핸들 선언


//const TCHAR* _szStdNames[] = { L"bitmap.bmp",L"test.bmp",L"온조",L"박혁거세",L"김수로" };
TCHAR _szBuffer[MAX_PATH] = { 0, };
TCHAR _szFullPathName[MAX_PATH] = { 0, };
TCHAR _szbmpfile[MAX_PATH] = { 0, };
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.
TCHAR str[MAX_PATH] = { 0, };

WNDCLASS wndClass;											//커스텀할 윈도우 구조체 변수.
MSG msg;															//메시지 루프에서 사용할 변수


int set = 1;
int shapeset = 2;
bool isshow = false;
int tempPos = 1;
bool mounseMOVE = false;
RECT pos = { 0, };
// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:


LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK    ChildProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM IParam);
LRESULT CALLBACK    PopupProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM IParam);

LRESULT CALLBACK DialogProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM IParam);
LRESULT CALLBACK modalessDialogProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM IParam);

void myRegisterClass(HINSTANCE hInstance);
BOOL CreateShowWindow(HINSTANCE hInstance, int nCmdShow);
int MessageLoop(HINSTANCE hInstace);


INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

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


	//윈도우 구조체의 내용을 저장.
	myRegisterClass(hInstance);
	if (!CreateShowWindow(hInstance, nCmdShow)) {
		return 0;
	}

	//MessageBox(NULL, L"윈도우 창 생성.", L"알림", MB_YESNO);   //윈도우 시작시 실행

	//SetTimer(_hWnd, TIMER_TEST1, 250, NULL);




	return MessageLoop(hInstance);
}
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM IParam) {

	switch (uMsg)
	{
	case WM_CREATE:
		_childWnd1 = CreateWindow(_szChildWndClassName, L"자식 창1", WS_CHILD | WS_VISIBLE | WS_BORDER | WS_CAPTION,
			10, 10, 200, 500, hWnd, NULL, _hInst, NULL);
		_PopupWnd1 = CreateWindow(_szPopupWndClassName, L"팝업창1",  WS_VISIBLE | WS_BORDER | WS_CAPTION,
			10, 10, 200, 500, hWnd,NULL, _hInst, NULL);

		break;

	case WM_COMMAND: {
		int id = LOWORD(wParam);
		switch (id)
		{
		case ID_32777:
			_Dialogbox2 = CreateDialog(_hInst, MAKEINTRESOURCE(IDD_DIALOG1), _hWnd, modalessDialogProc);
			ShowWindow(_Dialogbox2, SW_SHOW);
			break;
		case ID_CON_BUTTON_1: set = 1; InvalidateRect(hWnd, NULL, true); break;
		case ID_CON_BUTTON_2: set = 2; InvalidateRect(hWnd, NULL, true); break;
		case ID_CON_BUTTON_3: set = 3; InvalidateRect(hWnd, NULL, true); break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;

		}
		break;
	}
	case WM_LBUTTONDOWN:
		pos.left = LOWORD(IParam);
		pos.top = HIWORD(IParam);
		pos.bottom = pos.top, pos.right = pos.left;
		mounseMOVE = true;
		InvalidateRect(hWnd, NULL, true);   // 다지우기 true 

		break;
	case WM_MOUSEMOVE:
		if (mounseMOVE) {
			pos.right = LOWORD(IParam);
			pos.bottom = HIWORD(IParam);
			InvalidateRect(hWnd, NULL, true);   // 다지우기 true 
		}
		break;
	case WM_LBUTTONUP:
		if (mounseMOVE) {
			mounseMOVE = false;
			InvalidateRect(hWnd, NULL, true);   // 다지우기 true 
		}
		break;
	case WM_PAINT: {
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		HDC memdc = CreateCompatibleDC(hdc);
		HBRUSH brush;
		switch (set)
		{
		case 1:
			brush = CreateSolidBrush(RGB(255, 0, 0));
			break;
		case 2:
			brush = CreateSolidBrush(RGB(0, 0, 255));

			break;
		default:
			brush = CreateSolidBrush(RGB(0, 255, 0));
			break;
		}
		HGDIOBJ obrush = (HBRUSH)SelectObject(hdc, brush);
		switch (shapeset)
		{
		case 1: 
			MoveToEx(hdc, pos.left, pos.top, NULL);
			LineTo(hdc, pos.right, pos.bottom);
			break;
		case 2: 
			Ellipse(hdc, pos.left, pos.top, pos.right, pos.bottom); //그래서 원 먼저 그리면 사각형 그리면서 사라짐
			break;
		case 3: 
			Rectangle(hdc, pos.left, pos.top, pos.right, pos.bottom); 
			break;
		}
		
		SelectObject(hdc, obrush);
		DeleteObject(brush);
		DeleteObject(obrush);
		break;
	}
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	}
	return (DefWindowProc(hWnd, uMsg, wParam, IParam));
}

LRESULT ChildProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM IParam)
{
	switch (uMsg)
	{
	
	case WM_LBUTTONDOWN:
		MessageBox(hWnd, L"자식 윈도우에 마우스 버튼을 눌렀습니다.",L"알림",MB_OK);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		break;
	}
	return (DefWindowProc(hWnd, uMsg, wParam, IParam));
}

LRESULT PopupProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM IParam) {
	switch (uMsg)
	{
	case WM_CREATE: {
		CreateWindow(L"Button", L"빨강", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, //자식으로(같이 움직이게), 보이게, 푸시느낌나는형식으로
			10, 210, 50, 25, hWnd, (HMENU)ID_CON_BUTTON_1, _hInst, NULL);
		CreateWindow(L"Button", L"파랑", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, //자식으로(같이 움직이게), 보이게, 푸시느낌나는형식으로
			60, 210, 50, 25, hWnd, (HMENU)ID_CON_BUTTON_2, _hInst, NULL);
		CreateWindow(L"Button", L"초록", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, //자식으로(같이 움직이게), 보이게, 푸시느낌나는형식으로
			110, 210, 80, 25, hWnd, (HMENU)ID_CON_BUTTON_3, _hInst, NULL);
		
		break;
	}
	case WM_COMMAND: {
		int id = LOWORD(wParam);
		switch (id)
		{
		case ID_CON_BUTTON_1:
		case ID_CON_BUTTON_2:
		case ID_CON_BUTTON_3:
			SendMessage(_hWnd, WM_COMMAND, id, NULL);
			break;

		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;

		}
		break;
	}
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		break;
	}
	return (DefWindowProc(hWnd, uMsg, wParam, IParam));
}

LRESULT CALLBACK DialogProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM IParam) {

	switch (uMsg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	
	}
	return (DefWindowProc(hWnd, uMsg, wParam, IParam));
}

LRESULT modalessDialogProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM IParam)
{
	switch (uMsg)
	{
	case WM_COMMAND: {
		int id = LOWORD(wParam);
		switch (id)
		{
		case IDC_BUTTON1:
			MessageBox(NULL, L"버튼 클릭!.", L"알림", MB_YESNO);
			break;
		}
		break;
	}
	case WM_DESTROY:
		DestroyWindow(hWnd);
		_Dialogbox2 = NULL;
		break;

	}
	return (DefWindowProc(hWnd, uMsg, wParam, IParam));
}

//클래스 레지스터 등록 
void myRegisterClass(HINSTANCE hInstance)
{
	//메인 윈도우 구조체 작성
	wndClass.cbClsExtra = 0;
	wndClass.cbWndExtra = 0;
	wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); //하얀색
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndClass.hIcon = LoadIcon(NULL, MAKEINTRESOURCE(IDI_LEARNAPI6));
	wndClass.hInstance = _hInst; //hinstance;
	wndClass.lpfnWndProc = WndProc;
	wndClass.lpszClassName = _szWinClassName;
	wndClass.lpszMenuName = MAKEINTRESOURCEW(IDC_LEARNAPI6);
	wndClass.style = CS_HREDRAW | CS_VREDRAW;

	RegisterClass(&wndClass);
	
	//자식 윈도우의 구조체를 작성한다 .
	wndClass.hCursor = LoadCursor(NULL,IDC_HELP);
	wndClass.hbrBackground = (HBRUSH)GetStockObject(GRAY_BRUSH);
	wndClass.lpszClassName = _szChildWndClassName;
	wndClass.lpfnWndProc = ChildProc;
	RegisterClass(&wndClass); //자식 윈도우 구조체 등록

	//팝업 윈도우 구조체 작성
	wndClass.hCursor = LoadCursor(NULL, IDC_ICON);
	wndClass.hbrBackground = (HBRUSH)GetStockObject(GRAY_BRUSH);
	wndClass.lpszClassName = _szPopupWndClassName;
	wndClass.lpfnWndProc = PopupProc;
	wndClass.lpszMenuName = NULL;
	RegisterClass(&wndClass); //팝업 윈도우 구조체 등록

}

//창 만들기, 
BOOL CreateShowWindow(HINSTANCE hInstance, int nCmdShow)
{
	_hWnd = CreateWindow(_szWinClassName, _szWinClassName, WS_OVERLAPPEDWINDOW
		, CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, (HMENU)NULL, _hInst, NULL);
	if (_hWnd == NULL)
		return 0;
	ShowWindow(_hWnd, nCmdShow);
	//DialogBox(_hInst, MAKEINTRESOURCE(IDD_DIALOG1), _hWnd, DialogProc);

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