#include "AppWindow.h"
AppWindow* AppWindow::proc = NULL;

LRESULT CALLBACK MsgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	return AppWindow::proc->AppProc(hWnd,message,wParam,lParam);
}
LRESULT CALLBACK MsgProc_child(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	return AppWindow::proc->child.childProc(hWnd, message, wParam, lParam);
}
LRESULT CALLBACK MsgProc_pop(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	return AppWindow::proc->popup.popProc(hWnd,message,wParam,lParam);
}


LPCWSTR _szChildWndClassName = L"ChildTestWnd1";  //레지스트리에 등록할 자식 윈도우의 구조체 이름
LPCWSTR _szPopupWndClassName = L"PopupTestWnd";  //레지스트리에 등록할 자식 윈도우(팝업)의 구조체 이름


//=================================================================================================

AppWindow::AppWindow()
{
	LoadStringW(_Inst, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadStringW(_Inst, IDC_LEARNAPI7, szWindowClass, MAX_LOADSTRING);
}

AppWindow::~AppWindow()
{
}

void AppWindow::SetRegistClass(HINSTANCE hInstance)
{
	_Inst = hInstance;
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = MsgProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = _Inst;
	proc = this;
	wcex.hIcon = LoadIcon(_Inst, MAKEINTRESOURCE(IDI_LEARNAPI7));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_LEARNAPI7);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	RegisterClassExW(&wcex);
	//자식 윈도우의 구조체를 작성한다 .
	wcex.hCursor = LoadCursor(NULL, IDC_HELP);
	wcex.hbrBackground = (HBRUSH)GetStockObject(GRAY_BRUSH);
	wcex.lpszClassName = _szChildWndClassName;
	wcex.lpfnWndProc = MsgProc_child;
	RegisterClassExW(&wcex);

	//팝업 윈도우 구조체 작성
	wcex.hCursor = LoadCursor(NULL, IDC_HAND);

	wcex.hbrBackground = (HBRUSH)GetStockObject(GRAY_BRUSH);
	wcex.lpszClassName = _szPopupWndClassName;
	wcex.lpfnWndProc = MsgProc_pop;
	wcex.lpszMenuName = NULL;
	RegisterClassExW(&wcex);

}

BOOL AppWindow::CreateAppWindow(int nCmdShow)
{
	HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, _Inst, nullptr);

	if (!hWnd)
	{
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return TRUE;
}

int AppWindow::MessageLoop()
{
	HACCEL hAccelTable = LoadAccelerators(_Inst, MAKEINTRESOURCE(IDC_LEARNAPI7));
	MSG msg;

	// 기본 메시지 루프입니다:
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
	return (int)msg.wParam;

}

LRESULT AppWindow::AppProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_CREATE:
		_childWnd1 = CreateWindow(_szChildWndClassName, L"자식 창1", WS_CHILD | WS_VISIBLE | WS_BORDER | WS_CAPTION,
			10, 10, 200, 500, hWnd, NULL, _Inst, NULL);
		_PopupWnd1 = CreateWindow(_szPopupWndClassName, L"팝업창1", WS_VISIBLE | WS_BORDER | WS_CAPTION,
			10, 10, 200, 500, hWnd, NULL, _Inst, NULL);
		break;
	case WM_COMMAND:
	{
		int wmId = LOWORD(wParam);
		// 메뉴 선택을 구문 분석합니다:
		switch (wmId)
		{
		
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
	}
	break;
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		// TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
		imgDraw.TestDrawImage(hdc, L"주석 2019-10-19 143117.png", 50, 100);
		EndPaint(hWnd, &ps);
	}
	break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}


BOOL AppWindow::InitializeWnd(HINSTANCE hinstance, int ncmdshow)
{
	SetRegistClass(hinstance);
	return CreateAppWindow(ncmdshow);
}

BOOL AppWindow::CreatchildWindow(int nCmdShow)
{
	
	return 0;
}
