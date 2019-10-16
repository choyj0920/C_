// LearnAPI3.cpp : 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "LearnAPI3.h"
#include "resource.h"

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE _hInst;														//어플리케이션 핸들.
HWND _hWnd;																//메인 윈도우 핸들.
LPCWSTR _szWinClassName = L"DRAW";

bool _isShow = false;

WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.
TCHAR str[MAX_PATH] = { 0, };

bool mounseMOVE = false;
int figure = 0;  // 0 직선, 1직사각형,2 원
RECT pos = { 0,0,0,0 };
COLORREF linecolor, brushcolor;

//0: solid 1:DOT 2:DASH 3:NULL
int lineshape = 0;
//0: 채우기 1:격자 2:수직  3:투명
int brushshape = 0;
COLORREF color[4] = { RGB(0, 0, 0),RGB(255, 0, 0),RGB(0, 0, 255),RGB(0, 255, 0) };
int penstyle[4] = { PS_SOLID,PS_DOT,PS_DASH,PS_NULL };
int brushstyle[4] = { BS_SOLID,HS_DIAGCROSS,HS_VERTICAL,BS_HOLLOW};

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

//함수 정의
void ConvertUnicodeToMultibyte(TCHAR *pUnicode, char *pMultybyte);
void ConvertMultibyteToUnicode(char* pMultybyte, TCHAR *pUnicode);

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
		case ID_32808:
			figure = 0;
			break;
		case ID_32809:
			figure = 1;
			break;
		case ID_32810:
			figure = 2;
			break;
		case ID_32807:
			linecolor = 0;
			break;
		case ID_32776:
			linecolor = 1;
			break;
		case ID_32777:
			linecolor = 2;
			break;
		case ID_32778:
			linecolor = 3;
			break;
		case ID_32779:
			lineshape = 0;
			break;
		case ID_32780:
			lineshape = 1;
			break;
		case ID_32781:
			lineshape = 2;
			break;
		case ID_32811:
			lineshape = 3;
			break;
		case ID_32814:
			brushcolor = 0;
			break;
		case ID_32803:
			brushcolor = 1;
			break;
		case ID_32805:
			brushcolor = 2;
			break;
		case ID_32804:
			brushcolor = 3;
			break;
		case ID_32800:
			brushshape = 0;
			break;
		case ID_32801:
			brushshape = 1;
			break;
		case ID_32815:
			brushshape = 2;
			break;
		case ID_32813:
			brushshape = 3;
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			break;
		}
		InvalidateRect(hWnd, NULL, true);
		break;

	}

	case WM_LBUTTONDOWN:
		pos.left = LOWORD(IParam);
		pos.top = HIWORD(IParam);
		InvalidateRect(hWnd, NULL, TRUE);   // 다지우기 true 
		pos.bottom = pos.top, pos.right = pos.left;
		mounseMOVE = true;
		break;
	case WM_MOUSEMOVE:
		if (mounseMOVE) {
			pos.right = LOWORD(IParam);
			pos.bottom= HIWORD(IParam);
			InvalidateRect(hWnd, NULL, TRUE);   // 다지우기 true 
		}
		break;
	case WM_LBUTTONUP:
		mounseMOVE = false;
		InvalidateRect(hWnd, NULL, TRUE);   // 다지우기 true 
		break;

	case WM_PAINT: {
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		
		HPEN pen = CreatePen(penstyle[lineshape], 1,color[linecolor]);
		LOGBRUSH lplb;
		HBRUSH brush;
		if (brushshape == 0 || brushshape == 3) {
			lplb.lbStyle = brushstyle[brushshape];
			lplb.lbHatch = 0;
			lplb.lbColor = color[brushcolor];
			brush = CreateBrushIndirect(&lplb);
		}
		else
			brush= CreateHatchBrush(brushstyle[brushshape], color[brushcolor]);
		HGDIOBJ obrush = (HBRUSH)SelectObject(hdc, brush);
		HPEN open = (HPEN)SelectObject(hdc, pen);
		switch (figure)
		{
		case 0: {
			MoveToEx(hdc, pos.left, pos.top, NULL);
			LineTo(hdc, pos.right, pos.bottom);
			break;
		}
		case 1: {
			Rectangle(hdc, pos.left, pos.top, pos.right, pos.bottom); //그래서 원 먼저 그리면 사각형 그리면서 사라짐
			break;
		}
		case 2: {
			Ellipse(hdc, pos.left, pos.top, pos.right, pos.bottom); //그래서 원 먼저 그리면 사각형 그리면서 사라짐
			break;
		}

		};

		EndPaint(hWnd, &ps);
		SelectObject(hdc, obrush);
		SelectObject(hdc, open);
		DeleteObject(pen);
		DeleteObject(brush);
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
	wndClass.hIcon = LoadIcon(NULL, MAKEINTRESOURCE(IDI_LEARNAPI3));
	wndClass.hInstance = _hInst; //hinstance;
	wndClass.lpfnWndProc = WndProc;
	wndClass.lpszClassName = _szWinClassName;
	wndClass.lpszMenuName = MAKEINTRESOURCEW(IDC_LEARNAPI3);
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


void ConvertUnicodeToMultibyte(TCHAR *pUnicode, char *pMultybyte) {
	WideCharToMultiByte(CP_ACP, 0, pUnicode, lstrlen(pUnicode), pMultybyte, sizeof(pMultybyte), NULL, NULL);
}
void ConvertMultibyteToUnicode(char* pMultybyte, TCHAR *pUnicode) {
	MultiByteToWideChar(CP_ACP, NULL, pMultybyte, -1, pUnicode, sizeof(pUnicode) / sizeof(TCHAR));

}