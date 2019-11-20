#include "AppWindow.h"
AppWindow* AppWindow::mainWindow = NULL;

TCHAR AppWindow::_szFullPathName[MAX_PATH] = { 0, };

int AppWindow::div_x = 0;
int AppWindow::div_y = 0;

POINT AppWindow::set[8][8] = { 0, };


LPCWSTR _szChildWndClassName = L"ChildTestWnd1";  //레지스트리에 등록할 자식 윈도우의 구조체 이름
LPCWSTR _szPopupWndClassName = L"PopupTestWnd";  //레지스트리에 등록할 자식 윈도우(팝업)의 구조체 이름

//=================================================================================================

AppWindow::AppWindow()
{
	LoadStringW(_Inst, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadStringW(_Inst, IDC_LEARNAPI71103HW, szWindowClass, MAX_LOADSTRING);
}

AppWindow::~AppWindow()
{
}

POINT* AppWindow::findcell(int x, int y)
{
	for (int i = 0; i < div_y; i++) {
		for (int j = 0; j < div_x; j++) {
			if (set[i][j].x == x && set[i][j].y == y) {
				return &set[i][j];
			}

		}
	}
	return nullptr;
}

void AppWindow::SetRegistClass(HINSTANCE hInstance)
{
	_Inst = hInstance;
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = statiproc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = _Inst;
	mainWindow = this;
	wcex.hIcon = LoadIcon(_Inst, MAKEINTRESOURCE(IDI_LEARNAPI71103HW));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_LEARNAPI71103HW);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	RegisterClassExW(&wcex);
	

}

BOOL AppWindow::CreateAppWindow(int nCmdShow)
{
	m_hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, _Inst, nullptr);

	if (!m_hWnd)
	{
		return FALSE;
	}

	ShowWindow(m_hWnd, nCmdShow);
	UpdateWindow(m_hWnd);

	return TRUE;
}

int AppWindow::MessageLoop()
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


LRESULT AppWindow::AppProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_CREATE:
		m_hWnd = hWnd;
		child.setchild(m_hWnd, _Inst, LoadCursor(nullptr, IDC_HAND), (HBRUSH)GetStockObject(GRAY_BRUSH), _szChildWndClassName, false);
		popup.setchild(m_hWnd, _Inst, LoadCursor(nullptr, IDC_HELP), (HBRUSH)GetStockObject(WHITE_BRUSH), _szPopupWndClassName, true);
		break;
	case WM_COMMAND:
	{
		int wmId = LOWORD(wParam);
		// 메뉴 선택을 구문 분석합니다:
		switch (wmId)
		{
		case IDM_FILE_OPEN: {

			TCHAR dir[MAX_PATH] = { 0, };
			_tgetcwd(dir, MAX_PATH);
			OPENFILENAME ofn;
			memset(&ofn, 0, sizeof(OPENFILENAME));
			ofn.lStructSize = sizeof(OPENFILENAME);
			ofn.hwndOwner = hWnd;
			ofn.lpstrFilter = L"BMP 파일\0*.bmp;*.BMP\0모든파일\0*.*"; //필터
			ofn.lpstrFile = _szFullPathName;
			ofn.nMaxFile = MAX_PATH;
			ofn.lpstrInitialDir = dir;
			if (GetOpenFileName(&ofn) != FALSE) {
				_szFullPathName;
				div_x = div_y = 0;  //초기화
				modal.createModalwindow(hWnd, MAKEINTRESOURCE(IDD_LEARNAPI71103HW_DIALOG), _Inst);
				if (div_x != 0) {
					InvalidateRect(_PopupWnd1, NULL, true); //wm_paint발생을 위해 사용 다 안지우는 거 false
					_childWnd1 = child.createchlidwindow(hWnd, false, _szChildWndClassName, L"퍼즐 방향키", _Inst, { 900,10,350,400 });
					_PopupWnd1 = popup.createchlidwindow(hWnd, true, _szPopupWndClassName, L"원래 그림", _Inst, { 1200,200,400,400 });
					for (int i = 0; i < 8; i ++) {
						for (int j = 0; j < 8; j++) {
							set[i][j] = { j,i };
						}
					}
					InvalidateRect(hWnd, NULL, true); //wm_paint발생을 위해 사용 다 안지우는 거 false

				}

			}
			break;
		
		}
						  
		case ID_CON_BUTTON_1: {
			POINT* move = &set[div_y - 1][div_x - 1];
			if (move->x > 0) {
				POINT* change = findcell(move->x - 1, move->y );
				POINT temp = *change;
				*change = *move;
				*move = temp;
				InvalidateRect(hWnd, NULL, true); //wm_paint발생을 위해 사용 다 안지우는 거 false

			}
			break;
		}
			
		case ID_CON_BUTTON_2: {
			POINT* move = &set[div_y - 1][div_x - 1];
			if (move->x <div_x-1) {
				POINT* change = findcell(move->x + 1, move->y );
				POINT temp = *change;
				*change = *move;
				*move = temp;
				InvalidateRect(hWnd, NULL, true); //wm_paint발생을 위해 사용 다 안지우는 거 false

			}
			break;
		}
		case ID_CON_BUTTON_3: {
			POINT* move = &set[div_y - 1][div_x - 1];
			if (move->y > 0) {
				POINT* change = findcell(move->x , move->y - 1);
				POINT temp = *change;
				*change = *move;
				*move = temp;
				InvalidateRect(hWnd, NULL, true); //wm_paint발생을 위해 사용 다 안지우는 거 false

			}
			break;
		}
		case ID_CON_BUTTON_4: {
			POINT* move = &set[div_y - 1][div_x - 1];
			if (move->y<div_y-1) {
				POINT* change = findcell(move->x, move->y +1);
				POINT temp = *change;
				*change = *move;
				*move = temp;
				InvalidateRect(hWnd, NULL, true); //wm_paint발생을 위해 사용 다 안지우는 거 false

			}
			break;
		}
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
		DrawImage draw;
		HDC memdc = CreateCompatibleDC(hdc);
		//base출력
		draw.set_initial(_Inst, hWnd, hdc, memdc);
		if (div_x != 0) {
			draw.draw_divied_strech_puzzle(10, 10, 600, 600, div_x, div_y, _szFullPathName, set);

		}

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

LRESULT AppWindow::statiproc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{

	return mainWindow->AppProc(hWnd, iMsg, wParam, lParam);
}


BOOL AppWindow::InitializeWnd(HINSTANCE hinstance, int ncmdshow)
{
	SetRegistClass(hinstance);
	return CreateAppWindow(ncmdshow);
}

