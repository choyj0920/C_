// LearnAPI.cpp : 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "LearnAPI.h"

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.
HWND hWnd;
// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_LEARNAPI, szWindowClass, MAX_LOADSTRING); 
    MyRegisterClass(hInstance); 

    // 응용 프로그램 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))  //만들어 지지 않았다면 초기화
    {
        return FALSE;
    }
	//텍스트 출력해보기 이렇게 하면 한번만 출력 계속 띄울라면 paint 머시기에서
	//
	srand(time(0));
	HDC  hdc = GetDC(hWnd);
	//TextOut(hdc, 300, 100, L"오늘 처음 API 시작",lstrlenW(L"오늘 처음 API 시작")); //text 출력(hdc, x위치 ,y위치에, ㅁㅁ출력하는것,출력하는거 크기?)
	//ReleaseDC(hWnd, hdc);
	//

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LEARNAPI));

    MSG msg;  

    // 기본 메시지 루프입니다:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
			//SetPixel(hdc, rand() % 500, rand() % 400, RGB(rand() % 256, rand() % 256, rand() % 256)); //출력 픽셀 설정

            TranslateMessage(&msg);
            DispatchMessage(&msg);  //t
        }
    }
	//while (true) {
	//	if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {
	//		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg)) {
	//			if (msg.message == WM_QUIT)
	//				break;
	//			TranslateMessage(&msg);
	//			DispatchMessage(&msg);  //t
	//		}
	//		else {
	//			SetPixel(hdc, rand() % 500, rand() % 400, RGB(rand() % 256, rand() % 256, rand() % 256)); //출력 픽셀 설정

	//		}
	//	}
	//}
	//ReleaseDC(hWnd, hdc);

    return (int) msg.wParam;
}



//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;    //윈도우 클래스 확장이라는 구조체

    wcex.cbSize = sizeof(WNDCLASSEX);	//윈도우 클래스의 크기

    wcex.style          = CS_HREDRAW | CS_VREDRAW;  //비트 or 연산으로 기능을 합산해서 서아용
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;    //윈도우 클래스를 등록하는 프로그램의 고유  번호 
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LEARNAPI)); // 
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW); //커서 설정
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW + 1 ); //백그라운드 색 설정 
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_LEARNAPI);  //null로 하면 도구 메뉴 안뜸
    wcex.lpszClassName  = szWindowClass;  //클래스 이름 위에 보면 전역으로 이름 선언 되있음
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));  //스몰 아이콘 지정

    return RegisterClassExW(&wcex);
}
//리소스 뷰에서 폴더 안에 메뉴에서 윈도우 도구창 설정 가능

//
//   함수: InitInstance(HINSTANCE, int)
//
//   용도: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   주석:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,   //실질적으로 구조체를 가져옴  ,sztitle 창 위에뜨는 이름, 윈도우 형태, 
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);    
   //윈도우 위치 x,y,윈도우크기 x,y ,부모윈도우,메뉴핸들, 어느 응용프로그램 번호, 파라미터? 동시에 사용하는 윈도우에 쓸떄(종속도 아닌 평등한 응용프로그램)
	//cw_userdefault 기본 값 설정

   if (!hWnd) //안만들어 졌으면...
   {
      return FALSE;
   }
   //윈도우  실행
   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   //메시지 출력
   MessageBox(NULL, L"윈도우가 시작 되었습니다.",L"알림",MB_YESNO);

   return TRUE;
}

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 응용 프로그램 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//
//콜백함수는 전역으로 전역이 아니면 찾지 못해요
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) 
	//	메시지를 받을 윈도우 핸들 ,메시지 , 어떤 종류의 메시지인가를 나타낸다 ,전달된 메시지에대한 부가적인 정보 , 전달된 메시지에 대한 부가적인 정보
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 메뉴 선택을 구문 분석합니다:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
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
   //         // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
			//RECT rt = { 100,100,500,200 };
			////SetTextAlign(hdc, TA_RIGHT);   //문자열 정렬 함수 지정좌표가,뒤에 매개 에따라 중간이든 왼쪽이든 오른쪽이든 됨
			//TextOut(hdc, 100, 10, L"오늘 처음 API 시작",lstrlenW(L"오늘 처음 API 시작")); //text 출력(hdc, x위치 ,y위치에, ㅁㅁ출력하는것,출력하는거 크기?)
			//DrawText(hdc, L"오늘 수업은 참으로 졸리죠~~~ 다그래요~~ㅋ", -1, &rt, DT_CENTER | DT_VCENTER);
			//SetPixel(hdc, 350, 350, RGB(255, 0, 0)); //픽셀 찍기 진짜로  딱 1픽셀 찍어서 잘안보임
			
	/*		int x=100,y =100;
			MoveToEx(hdc, x, y, NULL);
			do {
				if (x == 100)
					if (y == 100)
						x += 300;
					else
						y -= 300;
				else
					if (y == 100)
						y += 300;
					else
						x -= 300;
				LineTo(hdc, x, y);

			} while (x != 100 || y != 100);
*/
	// 3 0
	// 2 1
			//사각형 출력
			int x = 100, y = 100; //맨왼쪽 점 위치

			int lengt = 300; //변 길이
			MoveToEx(hdc, x, y, NULL);
			for (int i = 0; i < 4; i++) {
				LineTo(hdc, x + (lengt * !(i / 2)), y + (lengt* (i / 2 ^ i % 2)));
			}
			Rectangle(hdc, 600, 200, 800, 500); //이게 사실 내부도 칠하는 것
			Ellipse(hdc, 600, 200, 800, 500); //그래서 원 먼저 그리면 사각형 그리면서 사라짐
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

// 정보 대화 상자의 메시지 처리기입니다.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
