#include "ChildClass.h"
#include "ModalClass.h"

#include "AppWindow.h"
ChildClass* ChildClass::childwindow = NULL;
ChildClass* ChildClass::popupwindow = NULL;

ChildClass::ChildClass()
{

}

ChildClass::~ChildClass()
{
}



int ChildClass::MessageLoop()
{
	HACCEL hAccelTable = LoadAccelerators(_Inst, MAKEINTRESOURCE(IDC_LEARNAPI71103HW));
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

LRESULT ChildClass::staticpro_ch(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	return childwindow->childProc(hWnd, message, wParam, lParam);
}

LRESULT ChildClass::staticpro_po(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	return popupwindow->popProc(hWnd, message, wParam, lParam);
}



LRESULT ChildClass::childProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_CREATE: {
		CreateWindow(L"Button", L"◀", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, //자식으로(같이 움직이게), 보이게, 푸시느낌나는형식으로
			0, 100, 100, 100, hWnd, (HMENU)ID_CON_BUTTON_1, _Inst, NULL);
		CreateWindow(L"Button", L"▶", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  //자식으로(같이 움직이게), 보이게, 푸시느낌나는형식으로
			200, 100, 100, 100, hWnd, (HMENU)ID_CON_BUTTON_2, _Inst, NULL);
		CreateWindow(L"Button", L"▲", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, //자식으로(같이 움직이게), 보이게, 푸시느낌나는형식으로
			100, 0, 100, 100, hWnd, (HMENU)ID_CON_BUTTON_3, _Inst, NULL);
		CreateWindow(L"Button", L"▼", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, //자식으로(같이 움직이게), 보이게, 푸시느낌나는형식으로
			100, 200, 100, 100, hWnd, (HMENU)ID_CON_BUTTON_4, _Inst, NULL);

	}
		
	case WM_COMMAND:
	{
		int wmId = LOWORD(wParam);
		// 메뉴 선택을 구문 분석합니다:
		switch (wmId)
		{
	
		case ID_CON_BUTTON_1:
		case ID_CON_BUTTON_2:
		case ID_CON_BUTTON_3:
		case ID_CON_BUTTON_4:
			SendMessageW(super_hwnd, WM_COMMAND, wParam, lParam);
			break;
		case IDM_EXIT:
			PostQuitMessage(0);
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
LRESULT ChildClass::popProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_COMMAND:
	{
		int wmId = LOWORD(wParam);
		// 메뉴 선택을 구문 분석합니다:
		switch (wmId)
		{

		case IDM_EXIT:
			PostQuitMessage(0);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
	}
	break;
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		DrawImage draw;
		HDC hdc = BeginPaint(hWnd, &ps);
		HDC memdc = CreateCompatibleDC(hdc);
		//base출력
		draw.set_initial(_Inst, hWnd, hdc, memdc);
		draw.draw_divied_strech_(10,10,350,350, 1, 1,AppWindow::_szFullPathName);

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

HWND ChildClass::setchild(HWND shwnd, HINSTANCE _hInst, HCURSOR cursorset, HBRUSH brushset, LPCWSTR szname, bool popup)
{
	super_hwnd = shwnd;
	_Inst = _hInst;
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = _Inst;
	wcex.hIcon = LoadIcon(_Inst, MAKEINTRESOURCE(IDI_LEARNAPI71103HW));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_LEARNAPI71103HW);
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));
	
	//자식 윈도우의 구조체를 작성한다 .
	wcex.hCursor = cursorset;
	wcex.hbrBackground = brushset;
	wcex.lpszClassName = szname;
	if (popup) {
		popupwindow = this;
		wcex.lpfnWndProc = staticpro_po;
		wcex.lpszMenuName = NULL;
	}
	else {
		childwindow = this;
		wcex.lpfnWndProc = staticpro_ch;
	}
	
	RegisterClassExW(&wcex);

	return HWND();
}

HWND ChildClass::createchlidwindow(HWND shwnd, bool popup, LPCWSTR szname, const WCHAR* (menu), HINSTANCE _hInst, const RECT& pos)
{
	Ihwnd = CreateWindow(szname, menu, (popup ? 0 : WS_CHILD) | WS_VISIBLE | WS_BORDER | WS_CAPTION, pos.left, pos.top, pos.right, pos.bottom, shwnd, NULL, _hInst, NULL);
	return Ihwnd;

	
}

