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
	LoadStringW(_Inst, IDC_LEARNAPI8, szWindowClass, MAX_LOADSTRING);
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
	wcex.hIcon = LoadIcon(_Inst, MAKEINTRESOURCE(IDI_LEARNAPI8));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_LEARNAPI8);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	RegisterClassExW(&wcex);
	

}

BOOL AppWindow::CreateAppWindow(int nCmdShow)
{
	m_hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
		10, 20, 1000, 700, nullptr, nullptr, _Inst, nullptr);

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
	HACCEL hAccelTable = LoadAccelerators(_Inst, MAKEINTRESOURCE(IDC_LEARNAPI8));
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
	case WM_CREATE: {
		for (int i = 0; i < 7; i++) {
			manager.add(new Character(L"마알.png", RECT{ firstline - 100, i * 100,100,100 }, 135, 99, 16));

		}

		m_hWnd = hWnd;
		child.setchild(m_hWnd, _Inst, LoadCursor(nullptr, IDC_HAND), (HBRUSH)GetStockObject(GRAY_BRUSH), _szChildWndClassName, false);
		popup.setchild(m_hWnd, _Inst, LoadCursor(nullptr, IDC_HELP), (HBRUSH)GetStockObject(WHITE_BRUSH), _szPopupWndClassName, true);
		break; 
	}
	case WM_TIMER:
		switch (wParam)
		{
		case RAND_SPEED_TIMER:
			manager.randspeed();
			//InvalidateRect(hWnd, NULL, false);
			break;
		case RUN_TIMER:
			manager.run();
			InvalidateRect(hWnd, NULL, FALSE);

			break;
		case DELETE_TIMER:
			KillTimer(hWnd,RAND_SPEED_TIMER);
			KillTimer(hWnd, RUN_TIMER);
			gameStart = false;
		}
		break;
	case WM_KEYDOWN: //키보드 다운 
		switch (wParam) {
		case VK_SPACE: {
			if (!gameStart) {
				gameStart = true;
				manager.empty();
				for (int i = 0; i < 7; i++) {
					manager.add(new Character(L"마알.png", RECT{ firstline - 100, i * 100,100,100 }, 135, 99, 16));

				}
				SetTimer(hWnd, RUN_TIMER, 10, NULL);
				SetTimer(hWnd, RAND_SPEED_TIMER, 450, NULL);
				manager.s_start();
				KillTimer(hWnd, DELETE_TIMER);
			}
			break;

		}
		case VK_LEFT:
		case 'A':
		case 'a':
			ninja.x -= 10;
			ninja_set++;
			if (ninja_set > 4) {
				ninja_set = 0;
			}
			break;
		case VK_RIGHT:
		case 'D':
		case 'd':
			ninja.x += 10;
			ninja_set++;
			if (ninja_set > 4) {
				ninja_set = 0;
			}
			break;
		case VK_UP:
		case 'W':
		case 'w':
			ninja.y -= 10;
			ninja_set++;
			if (ninja_set > 4) {
				ninja_set = 0;
			}
			break;
		case VK_DOWN:
		case 'S':
		case 's':
			ninja.y += 10;
			ninja_set++;
			if (ninja_set > 4) {
				ninja_set = 0;
			}
			break;
		};
		InvalidateRect(hWnd, NULL, false);
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
					InvalidateRect(_PopupWnd1, NULL, false); //wm_paint발생을 위해 사용 다 안지우는 거 false
					_childWnd1 = child.createchlidwindow(hWnd, false, _szChildWndClassName, L"퍼즐 방향키", _Inst, { 900,10,350,400 });
					_PopupWnd1 = popup.createchlidwindow(hWnd, true, _szPopupWndClassName, L"원래 그림", _Inst, { 1200,200,400,400 });
					for (int i = 0; i < 8; i ++) {
						for (int j = 0; j < 8; j++) {
							set[i][j] = { j,i };
						}
					}
					InvalidateRect(hWnd, NULL, false); //wm_paint발생을 위해 사용 다 안지우는 거 false

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
				InvalidateRect(hWnd, NULL, FALSE); //wm_paint발생을 위해 사용 다 안지우는 거 false

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
				InvalidateRect(hWnd, NULL, FALSE); //wm_paint발생을 위해 사용 다 안지우는 거 false

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
				InvalidateRect(hWnd, NULL, FALSE); //wm_paint발생을 위해 사용 다 안지우는 거 false

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
				InvalidateRect(hWnd, NULL, FALSE); //wm_paint발생을 위해 사용 다 안지우는 거 false

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
		/*
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		
		if (!gameStart) {
			TextOut(hdc, 400, 200, L"경마", lstrlenW(L"경마"));
			TextOut(hdc, 400, 230, L"시작하시려면 space", lstrlenW(L"시작하시려면 space"));
		}
		MoveToEx(hdc, firstline,0, NULL);
		LineTo(hdc, firstline,700);
		MoveToEx(hdc, finishline, 0, NULL);
		LineTo(hdc, finishline, 700);
		for (int i = 0; i < 7; i++) {
			MoveToEx(hdc,0 , i*100, NULL);
			LineTo(hdc, 1000, i*100);

		}

		manager.draw(hdc);
		//imgdraw.DrawImageToSlice(hdc, L"냐옹이.jpg", 20, 100,2,4);
		if (div_x != 0) {
			//draw.draw_divied_strech_puzzle(10, 10, 600, 600, div_x, div_y, _szFullPathName, set);
			imgdraw.DrawPuzzle(hdc,10, 10, 600, 600, div_x, div_y, _szFullPathName, set);

		}

		EndPaint(hWnd, &ps);
		*/


		PAINTSTRUCT ps;

		/** 더블버퍼링 시작처리입니다. **/
		static HDC hdc, MemDC;
		static HBITMAP BackBit, oldBackBit;
		static RECT bufferRT;
		MemDC = BeginPaint(hWnd, &ps);

		GetClientRect(hWnd, &bufferRT);
		hdc = CreateCompatibleDC(MemDC);
		BackBit = CreateCompatibleBitmap(MemDC, bufferRT.right, bufferRT.bottom);
		oldBackBit = (HBITMAP)SelectObject(hdc, BackBit);
		PatBlt(hdc, 0, 0, bufferRT.right, bufferRT.bottom, WHITENESS);

		// TODO: 여기에 그리기 코드를 추가합니다.
		if (!gameStart) {
			TextOut(hdc, 400, 200, L"경마", lstrlenW(L"경마"));
			TextOut(hdc, 400, 230, L"시작하시려면 space", lstrlenW(L"시작하시려면 space"));
		}
		MoveToEx(hdc, firstline, 0, NULL);
		LineTo(hdc, firstline, 700);
		MoveToEx(hdc, finishline, 0, NULL);
		LineTo(hdc, finishline, 700);
		for (int i = 0; i < 7; i++) {
			MoveToEx(hdc, 0, i * 100, NULL);
			LineTo(hdc, 1000, i * 100);

		}

		manager.draw(hdc);
		//imgdraw.DrawImageToSlice(hdc, L"냐옹이.jpg", 20, 100,2,4);
		if (div_x != 0) {
			//draw.draw_divied_strech_puzzle(10, 10, 600, 600, div_x, div_y, _szFullPathName, set);
			imgdraw.DrawPuzzle(hdc, 10, 10, 600, 600, div_x, div_y, _szFullPathName, set);

		}

		/** 더블버퍼링 끝처리 입니다. **/
		GetClientRect(hWnd, &bufferRT);
		BitBlt(MemDC, 0, 0, bufferRT.right, bufferRT.bottom, hdc, 0, 0, SRCCOPY);
		SelectObject(hdc, oldBackBit);
		DeleteObject(BackBit);
		DeleteDC(hdc);
		EndPaint(hWnd, &ps);
		break;

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

