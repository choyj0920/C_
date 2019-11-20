// LearnAPI4.cpp : 애플리케이션에 대한 진입점을 정의합니다.

#include "framework.h"
#include "LearnAPI4.h"
#include "DrawImage.h"
#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE _hInst;														//어플리케이션 핸들.
HWND _hWnd;																//메인 윈도우 핸들.
LPCWSTR _szWinClassName = L"MAKE_WINDOW4";
int modeset = 0;


//tagPOINT set[4][4] = { 0, };
//int mo_x = 1, mo_y = 1;
//tagPOINT* move = &set[mo_x][mo_y];
//
//tagPOINT mode[] = { {2,2},{3,3},{3,4},{4,3},{4,4} };
//tagPOINT* modes = &mode[0];
//void set__() {
//	mo_x = modes->x -1;
//	mo_y	= modes->y-1;
//	for (int i = 0; i < 4; i++) {
//		for (int j = 0; j < 4; j++) {
//			set[i][j] = { i,j };
//		}
//	}
//	move = &set[mo_x][mo_y];
//}
//


DrawImage draw;

WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.
TCHAR str[MAX_PATH] = { 0, };

RECT pos = { 100,0,400,0 };
WNDCLASS wndClass;											//커스텀할 윈도우 구조체 변수.
MSG msg;															//메시지 루프에서 사용할 변수




void DrawImageToBMP(HDC hdc, int sx, int sy, int fx, int fy, RECT copy, HBITMAP hbit);

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:

LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
void myRegisterClass(HINSTANCE hInstance);
BOOL CreateShowWindow(HINSTANCE hInstance, int nCmdShow);
int MessageLoop(HINSTANCE hInstace);

void DrawImageToBMP(HDC hdc, int sx, int xy, TCHAR* lpmbpName);

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
	
	case WM_KEYDOWN: //키보드 다운 
		switch (wParam) {
		/*case VK_LEFT:
			pos.right -= 3;
			break;
		case 'A':
		case 'a':
			pos.left -= 8;
			break;
		case VK_RIGHT:
			pos.right += 3;
			break;
		case 'D':
		case 'd':
			pos.left += 3;
			break;
		case VK_UP:
			pos.bottom -= 3;
			break;
		case 'W':
		case 'w':
			pos.top -= 3;
			break;
		case VK_DOWN:
			pos.bottom += 3;
			break;
		case 'S':
		case 's':
			pos.top += 3;
			break;*/
		case VK_LEFT:
			/*if (mo_x > 0) {
				tagPOINT temp = set[mo_x][mo_y];
				set[mo_x][mo_y] = set[mo_x - 1][mo_y];
				set[mo_x - 1][mo_y] = temp;
				mo_x--;

			}*/
			break;
		}
		/*
		if (pos.left < 0)	pos.left = 0;
		else if (pos.left > 300) pos.left = 300;
		if (pos.right < 300)  pos.right = 300;
		else if (pos.right > 600) pos.right = 600;
		if (pos.top < 0) pos.top = 0;
		else if (pos.top > 600) pos.top = 600;
		if (pos.bottom < 0) pos.bottom = 0;
		else if (pos.bottom > 600) pos.bottom = 600;*/
		InvalidateRect(hWnd, NULL, true); //wm_paint발생을 위해 사용 다 안지우는 거 false

		break;

	case WM_COMMAND: {
		int id = LOWORD(wParam);
		switch (id)
		{
		case ID_32771:
			modeset = 0;
			InvalidateRect(hWnd, NULL, true); //wm_paint발생을 위해 사용 다 안지우는 거 false

			break;
		case ID_32772:
			modeset = 1;
			InvalidateRect(hWnd, NULL, true); //wm_paint발생을 위해 사용 다 안지우는 거 false

			break;
		case ID_32773:
			modeset = 2;
			InvalidateRect(hWnd, NULL, true); //wm_paint발생을 위해 사용 다 안지우는 거 false
			break;
		case ID_32774:
			modeset = 3;
			InvalidateRect(hWnd, NULL, true); //wm_paint발생을 위해 사용 다 안지우는 거 false
			break;
		case ID_32775:
			modeset = 4;
			InvalidateRect(hWnd, NULL, true); //wm_paint발생을 위해 사용 다 안지우는 거 false
			break;

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
		/*HDC memdc = CreateCompatibleDC(hdc);
		HBITMAP hbit = LoadBitmap(_hInst, MAKEINTRESOURCE(IDB_BITMAP5));
		HBITMAP oldbit = (HBITMAP)SelectObject(memdc, hbit);
		GetObject(hbit, sizeof(BITMAP), &bit);
		BitBlt(hdc, pos.left- bit.bmWidth / 2, pos.top, bit.bmWidth/2, bit.bmHeight, memdc, 0, 0, SRCCOPY);
		BitBlt(hdc, pos.right, pos.bottom, bit.bmWidth/2, bit.bmHeight, memdc, bit.bmWidth / 2, 0, SRCCOPY);
		SelectObject(hdc, oldbit);
		DeleteObject(hbit);
		DeleteObject(memdc);
		*/
		/*
		HBITMAP hbit = LoadBitmap(_hInst, MAKEINTRESOURCE(IDB_BITMAP5));
		GetObject(hbit, sizeof(BITMAP), &bit);
		int perw = bit.bmWidth / mode[modeset][0];
		int perw_s = perw + 3;
		int perh = bit.bmHeight / mode[modeset][1];
		int perh_s = perh + 3;
		for (int i = 0; i < mode[modeset][0]; i++) {
			for (int j = 0; j < mode[modeset][1]; j++) {
				DrawImageToBMP(hdc, perw_s* i, perh_s* j, perw, perh, { perw * i,perh * j,perw,perh }, hbit);
			}
		}

		DeleteObject(hbit);
		*/
		HDC memdc = CreateCompatibleDC(hdc);
		/*draw.set_initial(_hInst, hWnd, hdc, memdc);
		draw.draw_bitblt(0, 0, MAKEINTRESOURCE(IDB_BITMAP5));
		draw.draw_strecthblt(400, 0, 200, 200, MAKEINTRESOURCE(IDB_BITMAP5));
		draw.draw_divied_strech(600, 0, mode[modeset][0], mode[modeset][1], MAKEINTRESOURCE(IDB_BITMAP5));
		TCHAR str[MAX_PATH]={L"bitmap.bmp"};*/
		//draw.image_draw(900, 0, 200, 200,str);
		
		draw.set_initial(_hInst, hWnd, hdc, memdc);
		draw.image_draw(0, 0, 200, 200, L"test.bmp");
		draw.image_draw2(0, 0, 400, 400,L"bitmap.bmp");
		DeleteObject(memdc);

		EndPaint(hWnd, &ps);
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
	wndClass.hIcon = LoadIcon(NULL, MAKEINTRESOURCE(IDI_LEARNAPI4));
	wndClass.hInstance = _hInst; //hinstance;
	wndClass.lpfnWndProc = WndProc;
	wndClass.lpszClassName = _szWinClassName;
	wndClass.lpszMenuName = MAKEINTRESOURCEW(IDC_LEARNAPI4);
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

void DrawImageToBMP(HDC hdc, int sx, int sy, TCHAR* lpmbpName)
{
	BITMAP bit;
	HDC memdc = CreateCompatibleDC(hdc);
	HBITMAP hbit = LoadBitmap(_hInst,lpmbpName);
	//HBITMAP hbit = (HBITMAP)LoadImage(_hInst,L"test.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE);
	HBITMAP oldbit = (HBITMAP)SelectObject(memdc, hbit);
	GetObject(hbit, sizeof(BITMAP), &bit);
	//BitBlt(hdc, sx,sy, bit.bmWidth , bit.bmHeight, memdc, 0, 0, SRCCOPY);
	StretchBlt(hdc, sx, sy, bit.bmWidth, bit.bmHeight, memdc, 0, 0, 100,100, SRCCOPY);

	SelectObject(memdc, oldbit);
	DeleteObject(hbit);
}
void DrawImageToBMP(HDC hdc, int sx, int sy,int fx,int fy,RECT copy, HBITMAP hbit)
{
	HDC memdc = CreateCompatibleDC(hdc);
	HBITMAP oldbit = (HBITMAP)SelectObject(memdc, hbit);
	//BitBlt(hdc, sx,sy, bit.bmWidth , bit.bmHeight, memdc, 0, 0, SRCCOPY);
	StretchBlt(hdc, sx, sy, fx, fy, memdc, copy.left, copy.top, copy.right, copy.bottom, SRCCOPY);

	SelectObject(memdc, oldbit);
	DeleteObject(memdc);

}


void paintprint(HWND hWnd, int n)
{

}