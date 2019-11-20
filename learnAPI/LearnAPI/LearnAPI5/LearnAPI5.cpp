// LearnAPI2.cpp : 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "LearnAPI5.h"

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE _hInst;														//어플리케이션 핸들.
HWND _hWnd;																//메인 윈도우 핸들.
LPCWSTR _szWinClassName = L"CONTROLWINDOW";

//컨트롤 핸들 선언
HWND _khWnd;		//체크박스핸들러
HWND _ehWnd;		//에디트박스컨트롤러
HWND _ehWnd_;		//에디트박스컨트롤러
HWND _lhWnd;		//리스트박스컨트롤러
HWND _chWnd;		//콤보박스컨트롤러
HWND _shWnd;		//콤보박스컨트롤러

const TCHAR* _szStdNames[] = { L"bitmap.bmp",L"test.bmp",L"온조",L"박혁거세",L"김수로" };
TCHAR _szBuffer[MAX_PATH] = { 0, };
TCHAR _szFullPathName[MAX_PATH] = { 0, };
TCHAR _szbmpfile[MAX_PATH] = { 0, };
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.
TCHAR str[MAX_PATH] = { 0, };

WNDCLASS wndClass;											//커스텀할 윈도우 구조체 변수.
MSG msg;															//메시지 루프에서 사용할 변수

DrawImage draw;

int set = 0;
bool isshow = false;
int tempPos = 1;
// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
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
		//윈도우에 이미 버튼이 등록되어 있음
		CreateWindow(L"Button",L"이미지 띄우기", WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON, //자식으로(같이 움직이게), 보이게, 푸시느낌나는형식으로
			20,20,100,25,hWnd,(HMENU)ID_CON_BUTTON_1,_hInst,NULL);  
		CreateWindow(L"Button", L"이미지 지우기", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, //자식으로(같이 움직이게), 보이게, 푸시느낌나는형식으로
			125, 20, 100, 25, hWnd, (HMENU)ID_CON_BUTTON_2, _hInst, NULL);
		CreateWindow(L"Button", L"리스트 추가", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, //자식으로(같이 움직이게), 보이게, 푸시느낌나는형식으로
			20, 170, 100, 25, hWnd, (HMENU)ID_CON_BUTTON_3, _hInst, NULL);
		CreateWindow(L"Button", L"리스트 삭제", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, //자식으로(같이 움직이게), 보이게, 푸시느낌나는형식으로
			125, 170, 100, 25, hWnd, (HMENU)ID_CON_BUTTON_4, _hInst, NULL);
		CreateWindow(L"Button", L"그림 선택", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, //자식으로(같이 움직이게), 보이게, 푸시느낌나는형식으로
			20, 195, 100, 25, hWnd, (HMENU)ID_CON_BUTTON_5, _hInst, NULL);
		CreateWindow(L"Button", L"콤보 추가", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, //자식으로(같이 움직이게), 보이게, 푸시느낌나는형식으로
			140, 280, 100, 25, hWnd, (HMENU)ID_CON_BUTTON_6, _hInst, NULL);
		CreateWindow(L"Button", L"콤보 삭제", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, //자식으로(같이 움직이게), 보이게, 푸시느낌나는형식으로
			240, 280, 100, 25, hWnd, (HMENU)ID_CON_BUTTON_7, _hInst, NULL);

		_khWnd = CreateWindow(L"Button", L"이미지 그리기", WS_CHILD | WS_VISIBLE | BS_CHECKBOX
			, 10, 60, 150, 25, hWnd, (HMENU)ID_CON_CHECKBOX_1, _hInst, NULL);
		_ehWnd = CreateWindow(L"Edit", L"", WS_CHILD | WS_VISIBLE | WS_BORDER|ES_MULTILINE  //editbox style 
			, 20, 100, 200, 50, hWnd, (HMENU)ID_CON_EDIT_1, _hInst, NULL);
		_ehWnd_ = CreateWindow(L"Edit", L"", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_MULTILINE  //editbox style 
			, 140, 230, 200, 50, hWnd, (HMENU)ID_CON_EDIT_2, _hInst, NULL);

		_lhWnd = CreateWindow(L"ListBox", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | LBS_NOTIFY
			, 250, 20, 110, 200, hWnd, (HMENU)ID_CON_LIST_1, _hInst, NULL);
		_chWnd = CreateWindow(L"ComboBox", NULL, WS_CHILD | WS_VISIBLE | CBS_DROPDOWN,
			20, 230, 110, 200, hWnd, (HMENU)ID_CON_COMBO_1, _hInst, NULL);

		_shWnd = CreateWindow(L"ScrollBar", NULL, WS_CHILD | WS_VISIBLE | SBS_HORZ,
			20, 350, 300, 20, hWnd, (HMENU)ID_CON_SCROLL_1, _hInst, NULL);
		SetScrollRange(_shWnd, SB_CTL, 1, 5, TRUE);
		SetScrollPos(_shWnd, SB_CTL, 1, TRUE);

		for (int i = 0; i < 5; i++) {
			SendMessage(_lhWnd, LB_ADDSTRING, 0, (LPARAM)_szStdNames[i]);
			SendMessage(_chWnd, CB_ADDSTRING, 0, (LPARAM)_szStdNames[i]);
		}
		
		
		break;
		
	case WM_HSCROLL: {
		tempPos = GetScrollPos(_shWnd, SB_CTL);
		switch (LOWORD(wParam))
		{
		case SB_LINELEFT:
			tempPos = max(1, tempPos - 1);
			break;
		case SB_LINERIGHT:
			tempPos = min(5, tempPos + 1);
			break;
		case SB_PAGELEFT:
			tempPos = max(1, tempPos - 1);

			break;
		case SB_PAGERIGHT:
			tempPos = min(5, tempPos + 1);
			break;
		case SB_THUMBTRACK:
			tempPos = HIWORD(wParam);
			break;
		default:
			break;
		}
		SetScrollPos(_shWnd, SB_CTL, tempPos, TRUE);
		_stprintf_s(_szBuffer, -1, L"%d", tempPos);
		SetWindowText(_ehWnd, _szBuffer);
		InvalidateRect(hWnd, NULL, true); //wm_paint발생을 위해 사용 다 안지우는 거 false

		break;

	}
	
	case WM_COMMAND: {
		int id = LOWORD(wParam);
		switch (id)
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
				//SetWindowText(hWnd, _szFullPathName);
				_stprintf_s(_szbmpfile, -1, _szFullPathName);
				InvalidateRect(hWnd, NULL, true); //wm_paint발생을 위해 사용 다 안지우는 거 false

			}
			break;
		}
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		case ID_CON_BUTTON_1:
			isshow = true;
			SetWindowText(hWnd, L"이미지 뜸 ");
			InvalidateRect(hWnd, NULL, true); //wm_paint발생을 위해 사용 다 안지우는 거 false

			break;
		case ID_CON_BUTTON_2:
			isshow = false;
			SetWindowText(hWnd, L"이미지 지우기");
			InvalidateRect(hWnd, NULL, true); //wm_paint발생을 위해 사용 다 안지우는 거 false
			break;
		case ID_CON_CHECKBOX_1:
			if (SendMessage(_khWnd, BM_GETCHECK, 0, 0) == BST_UNCHECKED) {
				SendMessage(_khWnd, BM_SETCHECK, BST_CHECKED, 0);
			}
			else {
				SendMessage(_khWnd, BM_SETCHECK, BST_UNCHECKED, 0);

			}
			InvalidateRect(hWnd, NULL, true); //wm_paint발생을 위해 사용 다 안지우는 거 false
			break;
		case ID_CON_EDIT_1://이거는 어캐 쓰냐면~
			switch (HIWORD(wParam))
			{
			case EN_CHANGE:
				GetWindowText(_ehWnd, _szBuffer, MAX_PATH);
				InvalidateRect(hWnd, NULL, true); //wm_paint발생을 위해 사용 다 안지우는 거 false
				break;
			default:
				break;
			}
			break;
		case ID_CON_EDIT_2://이거는 어캐 쓰냐면~
			switch (HIWORD(wParam))
			{
			case EN_CHANGE:
				GetWindowText(_ehWnd, _szBuffer, MAX_PATH);
				InvalidateRect(hWnd, NULL, true); //wm_paint발생을 위해 사용 다 안지우는 거 false
				break;
			default:
				break;
			}
			break;
		case ID_CON_LIST_1:
			switch (HIWORD(wParam))
			{
			case LBN_SELCHANGE: {
				int num = SendMessage(_lhWnd, LB_GETCURSEL, 0, 0);
				SendMessage(_lhWnd, LB_GETTEXT, num, (LPARAM)_szBuffer); 
				SetWindowText(_ehWnd, _szBuffer);
			}
			default:
				break;
			}
			break;
		case ID_CON_BUTTON_3: {
			SendMessage(_lhWnd, LB_ADDSTRING, 0, (LPARAM)_szBuffer);
			memset(_szBuffer, 0, MAX_PATH);
			break;
		}
		case ID_CON_BUTTON_4: {
			int num = SendMessage(_lhWnd, LB_GETCURSEL, 0, 0);

			SendMessage(_lhWnd, LB_DELETESTRING, num,0);

			break;

		}
		case ID_CON_BUTTON_5: {
			if (SendMessage(_khWnd, BM_GETCHECK, 0, 0) == BST_UNCHECKED) {
				SendMessage(_khWnd, BM_SETCHECK, BST_CHECKED, 0);
			}
			set = SendMessage(_lhWnd, LB_GETCURSEL, 0, 0);
			InvalidateRect(hWnd, NULL, true); //wm_paint발생을 위해 사용 다 안지우는 거 false
			break;
		}
		case ID_CON_BUTTON_6: {
			SendMessage(_chWnd, CB_ADDSTRING, 0, (LPARAM)_szBuffer);
			break;
		}
		case ID_CON_BUTTON_7: {
			int index = SendMessage(_chWnd, CB_FINDSTRING, 0, (LPARAM)_szBuffer);
			SendMessage(_chWnd, CB_DELETESTRING,index,0);
			break;
		}
		case ID_CON_COMBO_1: {
			switch (HIWORD(wParam))
			{
			case CBN_SELCHANGE: {
				int num = SendMessage(_chWnd, CB_GETCURSEL, 0, 0);
				SendMessage(_chWnd, CB_GETLBTEXT, num, (LPARAM)_szBuffer);
				SetWindowText(_ehWnd, _szBuffer);
				break; 
			}
			case CBN_EDITCHANGE:
				GetWindowText(_chWnd, _szBuffer, MAX_PATH);
				SetWindowText(_ehWnd, _szBuffer);

				break;
			default:
				break;
			}
			break;
		}
		default:
			break;
		}
		break;

	}

	case WM_PAINT: {
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		HDC memdc = CreateCompatibleDC(hdc);
		if (SendMessage(_khWnd, BM_GETCHECK, 0, 0) == BST_CHECKED) {
			draw.set_initial(_hInst, hWnd, hdc, memdc);
			draw.draw_divied_strech(400, 200, tempPos, tempPos, _szbmpfile);

		}
		RECT rc = { 800,200,220,7 };
		DrawText(hdc, _szBuffer, -1, &rc, DT_CENTER |DT_WORDBREAK);
		DeleteObject(memdc);
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
	wndClass.hIcon = LoadIcon(NULL, MAKEINTRESOURCE(IDI_LEARNAPI5));
	wndClass.hInstance = _hInst; //hinstance;
	wndClass.lpfnWndProc = WndProc;
	wndClass.lpszClassName = _szWinClassName;
	wndClass.lpszMenuName = MAKEINTRESOURCEW(IDC_LEARNAPI5);
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