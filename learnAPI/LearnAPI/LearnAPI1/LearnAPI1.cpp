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
TCHAR str[MAX_PATH] = { 0, };
TCHAR str2[MAX_PATH] = { 0, };
WNDCLASS wndClass;											//커스텀할 윈도우 구조체 변수.
MSG msg;															//메시지 루프에서 사용할 변수
void paintprint(HWND hWnd, int n);
int X = 300, Y = 300;
bool isDraw = false;
bool mounseMOVE = false;
int pX = 0, pY = 0;
int pX2 = 0, pY2 = 0;
TCHAR _szMounsePosition[MAX_PATH] = { 0, };
RECT _rt = { 100,50,700,500 }; //그림 그릴때 점 4개 구조체 
int _sec = 0;
int count_ = 0;

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

	//MessageBox(NULL, L"윈도우 창 생성.", L"알림", MB_YESNO);   //윈도우 시작시 실행

	SetTimer(_hWnd, TIMER_TEST1, 250, NULL);




	return MessageLoop(hInstance);
	
}
//초기화 되지않기 위해 전역으로 
int n = 0;
int len;
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM IParam) {
	
	switch (uMsg)
	{
	case WM_TIMER:
		switch (wParam)
		{
		case TIMER_TEST1:
			n = 2;
			count_++;
			_rt.left +=10, _rt.top += 10;
			_rt.bottom -=10, _rt.right -= 10;
			if (count_ >= 20) {
				SetTimer(_hWnd, TIMER_TEST2, 250, NULL);
				KillTimer(hWnd, TIMER_TEST1);
				_rt = RECT{ 800,100,1200,500 };
				break;
			}
			InvalidateRect(hWnd, NULL, false);
			break;
		case TIMER_TEST2:
			n = 3;
			count_--;
			_rt.left += 10, _rt.top += 10;
			_rt.bottom -= 10, _rt.right -= 10;
			if (count_ <= 0) {
				KillTimer(hWnd, TIMER_TEST2);
				SetTimer(_hWnd, TIMER_TEST1, 250, NULL);
				_rt = { 100,50,700,500 }; //그림 그릴때 점 4개 구조체 
				break;
			}
			InvalidateRect(hWnd, NULL, false);

			break;
		}
		

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
					
	//case wm_char:
	//	len = lstrlen(str);
	//	isdraw = true;
	//	if(wparam != vk_escape)   str[len] = (tchar)wparam;// 문자열 끝에 저장
	//	str[len + 1] = 0; //문자열 끝 뒤에 null지정
	//	invalidaterect(hwnd, null, true); //wm_paint발생을 위해 사용 다 안지우는 거 false
	//	return 0;
	case WM_KEYDOWN: //키보드 다운 
		isDraw = true;
		switch(wParam) {
		case VK_LEFT:
		case 'A':
		case 'a':
			X -= 8;
			break;
		case VK_RIGHT:
		case 'D':
		case 'd':
			X += 8;
			break;
		case VK_UP:
		case 'W':
		case 'w':
			Y -= 8;
			break;
		case VK_DOWN:
		case 'S':
		case 's':
			Y += 8;
			break;
	case '1':
		if (n != 1) {
			n = 1;
			pX = pY = pX2 = pY2 = 0;
		}
		break;
	case '2':
		if (n != 2) {
			n = 2;
			pX = pY = pX2 = pY2 = 0;
		}
		break;
	case '3':
		if (n != 3) {
			n = 3;
			pX = pY = pX2 = pY2 = 0;
		}
		break;
	case VK_ESCAPE:
		str[0] = 0;
		isDraw = false;
		n = 4;
		InvalidateRect(hWnd, NULL, TRUE);   // 다지우기 true 

		break;
		}
		InvalidateRect(hWnd, NULL, TRUE);   // 다지우기 true 
		break;
	case WM_LBUTTONDOWN:
		pX = LOWORD(IParam);
		pY = HIWORD(IParam);
		InvalidateRect(hWnd, NULL, TRUE);   // 다지우기 true 
		pX2 = pX, pY2 = pY;
		mounseMOVE = true;
		break;
	case WM_MOUSEMOVE:
		if (mounseMOVE) {
			pX2 = LOWORD(IParam);
			pY2 = HIWORD(IParam);
			isDraw = true;
			swprintf_s(_szMounsePosition, sizeof(_szMounsePosition), L"X : %d, Y : %d", pX2, pY2);  //프린트에 저장
			if (wParam&MK_CONTROL)
				swprintf_s(_szMounsePosition, sizeof(_szMounsePosition), L"%s :: [CONTROL]", _szMounsePosition);
			if (wParam&MK_SHIFT)
				swprintf_s(_szMounsePosition, sizeof(_szMounsePosition), L"%s :: [SHIFT]", _szMounsePosition);
			InvalidateRect(hWnd, NULL, TRUE);   // 다지우기 true 
		}
		break;
	case WM_LBUTTONUP:
		pX2 = LOWORD(IParam);
		pY2 = HIWORD(IParam);
		isDraw = true;
		mounseMOVE = false;
		InvalidateRect(hWnd, NULL, TRUE);   // 다지우기 true 
		break;

	case WM_PAINT: {
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		
		/*int x = rand() % 800;
		int y = rand() % 500;
		int x_len = rand() % 500;
		int y_len = rand() % 500;*/
		
		switch (n)
		{
		case 1: {
			MoveToEx(hdc, pX, pY, NULL);
			LineTo(hdc, pX2, pY2);
			break;
		}
		case 2: {
			Rectangle(hdc, _rt.left, _rt.top, _rt.right, _rt.bottom); //그래서 원 먼저 그리면 사각형 그리면서 사라짐
			break;
		}
		case 3: {
			Ellipse(hdc, _rt.left, _rt.top, _rt.right, _rt.bottom); //그래서 원 먼저 그리면 사각형 그리면서 사라짐
			break;
		}
		case 4:
			Rectangle(hdc, -2, -4, 1200, 1200);
			pX = pY = pX2 = pY2 = 0;
			n = 1;
		}
		TextOut(hdc, 100, 100, str, lstrlen(str));
		TextOut(hdc, X, Y, L"A", 1);
		TextOut(hdc, 0, 0, _szMounsePosition, lstrlen(_szMounsePosition));
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