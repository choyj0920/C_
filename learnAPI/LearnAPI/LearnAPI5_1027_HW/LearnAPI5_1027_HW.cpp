
#include "framework.h"
#include "LearnAPI5_1027_HW.h"
#include <list>

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE _hInst;														//어플리케이션 핸들.
HWND _hWnd;																//메인 윈도우 핸들.
LPCWSTR _szWinClassName = L"그림 판";



WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.
TCHAR str[MAX_PATH] = { 0, };

 
WNDCLASS wndClass;											//커스텀할 윈도우 구조체 변수.
MSG msg;															//메시지 루프에서 사용할 변수

// 추가 부분
class ske {
public:
	RECT spos;
	int shapeset;
	int brushset;

	ske(const RECT pos, const int sha, int bru) {
		spos.left = pos.left;
		spos.right = pos.right;
		spos.bottom = pos.bottom;
		spos.top = pos.top;
		shapeset = sha;
		brushset = bru;
	}
};
//컨트롤 핸들 선언
HWND _lhWnd1;		//리스트박스컨트롤러
HWND _lhWnd2;		//리스트박스컨트롤러
HWND _chWnd;		//콤보박스컨트롤러
HWND _shWnd1;		//스크롤박스컨트롤러
HWND _shWnd2;		//스크롤박스컨트롤러

TCHAR _szFullPathName[MAX_PATH] = { 0, };
TCHAR _szbmpfile[MAX_PATH] = { 0, };
TCHAR _bmpfile[MAX_PATH] = { 0, };
using namespace std;
std::list<ske> sketch;

DrawImage draw;
int set = 1;
int brushset = 1;
bool isshow = false;
int tempPosx = 1;
int tempPosy = 1;
int div_setx = 1;
int div_sety = 1;

bool mounseMOVE=false;
RECT pos = { 0, };

RECT base = { 200,10,1000,610 };


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
		CreateWindow(L"Button", L"삭제", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, //자식으로(같이 움직이게), 보이게, 푸시느낌나는형식으로
			10, 210, 50, 25, hWnd, (HMENU)ID_CON_BUTTON_1, _hInst, NULL);
		CreateWindow(L"Button", L"그리기", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, //자식으로(같이 움직이게), 보이게, 푸시느낌나는형식으로
			60, 210, 50, 25, hWnd, (HMENU)ID_CON_BUTTON_2, _hInst, NULL);
		CreateWindow(L"Button", L"그림지우기", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, //자식으로(같이 움직이게), 보이게, 푸시느낌나는형식으로
			110, 210, 80, 25, hWnd, (HMENU)ID_CON_BUTTON_6, _hInst, NULL);
	
		_lhWnd1 = CreateWindow(L"ListBox", NULL, WS_CHILD  | WS_BORDER | LBS_NOTIFY
			, 10, 10, 180, 200, hWnd, (HMENU)ID_CON_LIST_1, _hInst, NULL);
		_lhWnd2 = CreateWindow(L"ListBox", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | LBS_NOTIFY
			, 10, 10, 180, 200, hWnd, (HMENU)ID_CON_LIST_1, _hInst, NULL);

		CreateWindow(L"Button", L"스케치 지우기", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, //자식으로(같이 움직이게), 보이게, 푸시느낌나는형식으로
			10, 400, 100, 25, hWnd, (HMENU)ID_CON_BUTTON_3, _hInst, NULL);


		

		_shWnd1 = CreateWindow(L"ScrollBar", NULL, WS_CHILD | WS_VISIBLE | SBS_HORZ,
			200, 620, 750, 20, hWnd, (HMENU)ID_CON_SCROLL_1, _hInst, NULL);

		CreateWindow(L"Button", L"적용", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, //자식으로(같이 움직이게), 보이게, 푸시느낌나는형식으로
			950, 620, 50, 20, hWnd, (HMENU)ID_CON_BUTTON_4, _hInst, NULL);
		SetScrollRange(_shWnd1, SB_CTL, 1, 10, TRUE);
		SetScrollPos(_shWnd1, SB_CTL, 1, TRUE);

		_shWnd2 = CreateWindow(L"ScrollBar", NULL, WS_CHILD | WS_VISIBLE | SBS_VERT,
			1020, 10, 20, 550, hWnd, (HMENU)ID_CON_SCROLL_2, _hInst, NULL);
		CreateWindow(L"Button", L"적용", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,  //자식으로(같이 움직이게), 보이게, 푸시느낌나는형식으로
			1020, 560, 50, 50, hWnd, (HMENU)ID_CON_BUTTON_5, _hInst, NULL);
		SetScrollRange(_shWnd2, SB_CTL, 1, 10, TRUE);
		SetScrollPos(_shWnd2, SB_CTL, 1, TRUE);
		InvalidateRect(hWnd, NULL, true); //wm_paint발생을 위해 사용 다 안지우는 거 false

		break;

	case WM_HSCROLL: {
		tempPosx = GetScrollPos(_shWnd1, SB_CTL);
		switch (LOWORD(wParam))
		{
		case SB_LINELEFT:
			tempPosx = max(1, tempPosx - 1);
			break;
		case SB_LINERIGHT:
			tempPosx = min(10, tempPosx + 1);
			break;
		case SB_PAGELEFT:
			tempPosx = max(1, tempPosx - 1);

			break;
		case SB_PAGERIGHT:
			tempPosx = min(10, tempPosx + 1);
			break;
		case SB_THUMBTRACK:
			tempPosx = HIWORD(wParam);
			break;
		default:
			break;
		}
		SetScrollPos(_shWnd1, SB_CTL, tempPosx, TRUE);
		
		
		//InvalidateRect(hWnd, NULL, true); //wm_paint발생을 위해 사용 다 안지우는 거 false

		break;
	}
	case WM_VSCROLL: {
		tempPosy = GetScrollPos(_shWnd2, SB_CTL);
		switch (LOWORD(wParam))
		{
		case SB_LINEUP:
			tempPosy = max(1, tempPosy - 1);
			break;
		case SB_LINEDOWN:
			tempPosy = min(10, tempPosy + 1);
			break;
		case SB_PAGEUP:
			tempPosy = max(1, tempPosy - 1);

			break;
		case SB_PAGEDOWN:
			tempPosy = min(10, tempPosy + 1);
			break;
		case SB_THUMBTRACK:
			tempPosy = HIWORD(wParam);
			break;
		default:
			break;
		}
		SetScrollPos(_shWnd2, SB_CTL, tempPosy, TRUE);
		//InvalidateRect(hWnd, NULL, true); //wm_paint발생을 위해 사용 다 안지우는 거 fals
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
				SendMessage(_lhWnd1, LB_ADDSTRING, 0, (LPARAM)_szbmpfile);
				PathStripPath(_szbmpfile);
				SendMessage(_lhWnd2, LB_ADDSTRING, 0, (LPARAM)_szbmpfile);
				InvalidateRect(hWnd, NULL, true); //wm_paint발생을 위해 사용 다 안지우는 거 false

			}
			break;
		}
		case ID_32771:
			set = 1;
			break;
		case ID_32772:
			set = 2;
			break;
		case ID_32773:
			set = 3;
			break;
		case ID_32774:
			brushset = 1;
			break;
		case ID_32775:
			brushset = 2;
			break;
		case ID_32776:
			brushset = 3;
			break;
		case ID_32777:
			brushset = 4;
			break;
		case ID_32778:
			brushset = 5;
			break;

		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		case ID_CON_BUTTON_1: {
			int num = SendMessage(_lhWnd2, LB_GETCURSEL, 0, 0);
			SendMessage(_lhWnd2, LB_DELETESTRING, num, 0);
			SendMessage(_lhWnd1, LB_DELETESTRING, num, 0);
			break;
		}
		case ID_CON_BUTTON_2: {
			int num = SendMessage(_lhWnd2, LB_GETCURSEL, 0, 0);
			SendMessage(_lhWnd1, LB_GETTEXT, num, (LPARAM)_bmpfile);
			isshow = true;
			InvalidateRect(hWnd, NULL, true); //wm_paint발생을 위해 사용 다 안지우는 거 false
			break;
		}
		case ID_CON_BUTTON_3: {
			if (!sketch.empty()) {
				sketch.pop_back();
				InvalidateRect(hWnd, NULL, true); //wm_paint발생을 위해 사용 다 안지우는 거 false
			}
			break;
		}
		case ID_CON_BUTTON_4: {
			div_setx = tempPosx;
			InvalidateRect(hWnd, NULL, true); //wm_paint발생을 위해 사용 다 안지우는 거 false
			break;
		}
		case ID_CON_BUTTON_5: {
			div_sety = tempPosy;
			InvalidateRect(hWnd, NULL, true); //wm_paint발생을 위해 사용 다 안지우는 거 false
			break;
		}
		case ID_CON_BUTTON_6:
			isshow = false;
			InvalidateRect(hWnd, NULL, true); //wm_paint발생을 위해 사용 다 안지우는 거 false
			break;
		
		default:
			break;
		}
		break;

	}
	
	case WM_LBUTTONDOWN:
		pos.left = LOWORD(IParam);
		pos.top = HIWORD(IParam);
		
		if (pos.left >= base.left && pos.left <= base.right && pos.top <= base.bottom && pos.top >= base.top) {
			InvalidateRect(hWnd, NULL, false);   // 다지우기 true 
			pos.bottom = pos.top, pos.right = pos.left;
			mounseMOVE = true;
		}
		break;
	case WM_MOUSEMOVE:
		if (mounseMOVE ) {
			pos.right = LOWORD(IParam);
			pos.bottom = HIWORD(IParam);
			if (pos.right < base.left) pos.right = base.left;
			else if (pos.right > base.right) pos.right = base.right;
			if (pos.bottom < base.top) pos.bottom = base.top;
			else if (pos.bottom > base.bottom) pos.bottom = base.bottom;
			InvalidateRect(hWnd, NULL, false);   // 다지우기 true 
		}
		break;
	case WM_LBUTTONUP:
		if (mounseMOVE) {
			mounseMOVE = false;
			sketch.push_back(ske(pos, set, brushset));
			InvalidateRect(hWnd, NULL, false);   // 다지우기 true 
		}
		break;

	case WM_PAINT: {
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		HDC memdc = CreateCompatibleDC(hdc);
		//base출력
		Rectangle(hdc, base.left, base.top, base.right, base.bottom);
		if (isshow) {//그림 출력
			draw.set_initial(_hInst, hWnd, hdc, memdc);
			draw.draw_divied_strech_(base.left, base.top, base.right - base.left, base.bottom - base.top, div_setx, div_sety, _bmpfile);
		}
		
		//스케치 출력 구문
		list<ske>::iterator iter;
		for (iter = sketch.begin(); iter != sketch.end(); ++iter) {
			LOGBRUSH lplb;
			HBRUSH brush;
			if (iter->brushset<=3) {
				lplb.lbStyle = (iter->brushset == 1 ? BS_HOLLOW : BS_SOLID);
				lplb.lbHatch = 0;
				lplb.lbColor = (iter->brushset == 2 ? RGB(0, 0, 0) : RGB(0, 255, 0));
				brush = CreateBrushIndirect(&lplb);
			}
			else if (iter->brushset == 4) {
				brush = CreateHatchBrush(HS_DIAGCROSS, RGB(0, 255, 0));

			}
			else{
				brush = CreateHatchBrush(HS_FDIAGONAL, RGB(0, 255, 0));

			}

			HGDIOBJ obrush = (HBRUSH)SelectObject(hdc, brush);

			switch (iter->shapeset)
			{
			case 1: {
				MoveToEx(hdc, iter->spos.left, iter->spos.top, NULL);
				LineTo(hdc, iter->spos.right, iter->spos.bottom);
				break;
			}
			case 2: {
				Rectangle(hdc, iter->spos.left, iter->spos.top, iter->spos.right, iter->spos.bottom); //그래서 원 먼저 그리면 사각형 그리면서 사라짐
				break;
			}
			case 3: {
				Ellipse(hdc, iter->spos.left, iter->spos.top, iter->spos.right, iter->spos.bottom); //그래서 원 먼저 그리면 사각형 그리면서 사라짐
				break;
			}
			default:
				break;
			}
			SelectObject(hdc, obrush);
			DeleteObject(brush);
			DeleteObject(obrush);
		}
		if (mounseMOVE) {
			LOGBRUSH lplb;
			HBRUSH brush;
			if (brushset <= 3) {
				lplb.lbStyle = (brushset == 1 ? BS_HOLLOW : BS_SOLID);
				lplb.lbHatch = 0;
				lplb.lbColor = (brushset == 2 ? RGB(0, 0, 0) : RGB(0, 255, 0));
				brush = CreateBrushIndirect(&lplb);
			}
			else if (brushset == 4) {
				brush = CreateHatchBrush(HS_DIAGCROSS, RGB(0, 255, 0));

			}
			else {
				brush = CreateHatchBrush(HS_FDIAGONAL, RGB(0, 255, 0));

			}
			HGDIOBJ obrush = (HBRUSH)SelectObject(hdc, brush);
			switch (set)
			{
			case 1: {
				MoveToEx(hdc, pos.left, pos.top, NULL);
				LineTo(hdc,pos.right,pos.bottom);
				break;
			}
			case 2: {
				Rectangle(hdc, pos.left,pos.top, pos.right, pos.bottom); //그래서 원 먼저 그리면 사각형 그리면서 사라짐
				break;
			}
			case 3: {
				Ellipse(hdc, pos.left, pos.top, pos.right, pos.bottom); //그래서 원 먼저 그리면 사각형 그리면서 사라짐
				break;
			}
			default:
				break;
			}
			SelectObject(hdc, obrush);
			DeleteObject(brush);
			DeleteObject(obrush);
		}
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
	wndClass.hIcon = LoadIcon(NULL, MAKEINTRESOURCE(IDI_LEARNAPI51027HW));
	wndClass.hInstance = _hInst; //hinstance;
	wndClass.lpfnWndProc = WndProc;
	wndClass.lpszClassName = _szWinClassName;
	wndClass.lpszMenuName = MAKEINTRESOURCEW(IDC_LEARNAPI51027HW);
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

