#include "System.h"
//=================================================================================================

System::System()
{
	// 키입력, 그래픽클래스 NULL
	InputC = NULL;
	graphics = NULL;
	_TimeC = NULL;
	_cpuC = NULL;
}

System::~System()
{
}


void System::ShutdownWindows()//윈도우 종료 함수
{
	
	ShowCursor(true);
	if (isFullScreen) {//풀 스크린 이였으면 디스플레이 설정 초기화
		ChangeDisplaySettings(NULL, 0);

	}
	// 창 삭제
	DestroyWindow(m_hWnd);

	// 윈도우 핸들 NULL
	m_hWnd = NULL;

	//윈도우 클래스 등록 해제
	UnregisterClass(_ApplicationName, _Inst);
	// 인스턴스 초기화
	_Inst = NULL;
}
// 윈도우 클래스 선언 및 창 만들어주는 함수
void System::InitializeWindows(HINSTANCE hInst, bool isFull, int& screenW, int& screenH)
{
	WNDCLASSEX wc; //윈도우 클래스 선언
	// DEVMODE 데이터 구조는 프린터 또는 디스플레이 장치의 초기화 및 환경에 대한 정보를 포함합니다.
	DEVMODE dmScreenSettings;
	int posX, posY;


	//어플리케이션 인스턴스
	_Inst = hInst;
	//윈도우 스크린 설정
	isFullScreen = isFull;
	//어플리케이션의 이름 설정
	_ApplicationName = _T("FramWork");

	
	//윈도우 클래스 기본설정으로 맞춥니다.
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	wc.lpfnWndProc = statiproc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInst;
	wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);
	wc.hIconSm = wc.hIcon;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = _ApplicationName;
	wc.cbSize = sizeof(WNDCLASSEX);
	RegisterClassEx(&wc); //지금 까지 저장한 wc로 윈도우 창 클래스 선언

	if (isFullScreen) {// 풀스크린 모드이면
		screenW = GetSystemMetrics(SM_CXSCREEN);
		screenH = GetSystemMetrics(SM_CYSCREEN);
		memset(&dmScreenSettings, 0, sizeof(dmScreenSettings));
		dmScreenSettings.dmSize = sizeof(dmScreenSettings);
		dmScreenSettings.dmPelsWidth = (unsigned long)screenW;
		dmScreenSettings.dmPelsHeight = (unsigned long)screenH;
		dmScreenSettings.dmBitsPerPel = 32;
		dmScreenSettings.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;
		//플스크린에 맞는 디스플에이 설정을 합니다.
		ChangeDisplaySettings(&dmScreenSettings, CDS_FULLSCREEN);
		//윈도우의 위치를 화면의 왼쪽위로 맞춥니다
		posX = posY = 0;
	}
	else { //풀스크린 모드가 아닐 때는 
		posX = (GetSystemMetrics(SM_CXSCREEN) - screenW) / 2; //화면 중간에 띄우기
		posY = (GetSystemMetrics(SM_CYSCREEN) - screenH) / 2;
	}
	//창 만들기 
	m_hWnd = CreateWindowEx(WS_EX_APPWINDOW, _ApplicationName, _ApplicationName,
		WS_CLIPSIBLINGS|WS_CLIPCHILDREN|WS_OVERLAPPEDWINDOW,posX,posY,
		screenW,screenH, NULL, NULL, _Inst, NULL);
	ShowWindow(m_hWnd, SW_SHOW); //창 보이게
	SetForegroundWindow(m_hWnd); //몰라
	SetFocus(m_hWnd); //
	
}


//키, 그래픽 실행-오류 발생시 false리턴
bool System::Frame()
{	//키가 esc눌리면 -false리턴
	_cpuC->Frame();
	int x = 0;
	if (InputC->IsKeyDown(VK_LEFT))
		x--;
	if (InputC->IsKeyDown(VK_RIGHT))
		x++;
	int y = 0;
	if (InputC->IsKeyDown(VK_UP))
		y++;
	if (InputC->IsKeyDown(VK_DOWN))
		y--;
	   	 
	_TimeC->Frame();

	if (!graphics->Frame(_TimeC->GetdeltaTime(), x, y))
		return false;
	if (InputC->IsKeyDown(VK_ESCAPE)) {
		return false;
	}
	if (!graphics->Frame()) {//그래픽 잘못 그리면 false리턴 종료
		return false;
	}


	TCHAR str1[MAX_PATH] = { 0, };
	TCHAR str2[MAX_PATH] = { 0, };
	byte ms = ((int)(_TimeC->GetdelTime() * 100) % 100);
	byte cho = (((int)(_TimeC->GetdelTime() * 100) / 100) % 60);
	byte bun = (((int)(_TimeC->GetdelTime() * 100) / 6000) % 60);
	swprintf_s(str1, L"%d:%d:%d", bun, cho, ms);
	swprintf_s(str2, L"FPS:%d,CPUUSAGE: %d %%, DeltaTIme : %f,GameTIme : %s", _TimeC->GetFps(), _cpuC->GetCpuPercentage(), _TimeC->GetdeltaTime(), str1);
	SetWindowText(m_hWnd, str2);

	return true; //아니면 true
}



// 메시지 루프
int System::Run()
{
	bool done; //계속 수행 변수
	ZeroMemory(&msg, sizeof(MSG));
	done = false;
	while (!done) { //종료가 없을 때까지 
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		if (msg.message == WM_QUIT) {//종료 메시지 들어오면 종료
			done = true;
		}
		else {
		
			done = !Frame();
		}
	}
	// 종료 될 때 -Shutdown실행
	Shutdown(); 
	return (int)msg.wParam;
}

//종료 함수
void System::Shutdown()
{
	if (graphics) { //그래픽이 할당되어 있을때
		graphics->Release(); //그래픽 해제함수
		delete graphics; //그래픽할당 해제
		graphics = NULL;
	}
	if (InputC) { //할당 되어있으면
		delete InputC; //인풋 해제함수
		InputC = NULL;
	}
	if (_TimeC) { //할당 되어있으면
		delete _TimeC; //인풋 해제함수
		_TimeC = NULL;
	}
	if (_cpuC) { //할당 되어있으면
		delete _cpuC; //인풋 해제함수
		_cpuC = NULL;
	}
	ShutdownWindows(); //윈도우api관련 해제
}


LRESULT System::AppProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_CREATE: {
		

		/*child.setchild(m_hWnd, _Inst, LoadCursor(nullptr, IDC_HAND), (HBRUSH)GetStockObject(GRAY_BRUSH), _szChildWndClassName, false);
		popup.setchild(m_hWnd, _Inst, LoadCursor(nullptr, IDC_HELP), (HBRUSH)GetStockObject(WHITE_BRUSH), _szPopupWndClassName, true);*/
		break;
	}
	case WM_TIMER:
		
		break;
	case WM_KEYDOWN: //키보드 다운 
		InputC->KeyDown((unsigned int)wParam);
		break;
	case WM_KEYUP:
		InputC->KeyUp((unsigned int)wParam);
		break;
	case WM_COMMAND:
	{
		
	}
	break;
		
	}
	return DefWindowProc(hWnd, message, wParam, lParam);
}

LRESULT System::statiproc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	switch (iMsg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_CLOSE:
		PostQuitMessage(0);
		break;
	
	}
	return GetInstance()->AppProc(hWnd, iMsg, wParam, lParam);
}

// 윈도우 초기화 함수
bool System::Initialize(HINSTANCE hinstance, bool isFull, int screenW, int screenH)
{
	bool result = true; // 초기화 성공 여부 변수
	InitializeWindows(hinstance, isFull, screenW, screenH);//윈도우 api- 초기화함수
	
	//이곳에 객체 생성 N 초기화
	//input 객체 생성
	if (InputC == NULL) {
		InputC = new InputClass; //키입력 동적 할당
		if (!InputC) //할당 안되면 종료
			return false;
	}
	InputC->Initialize(); //input초기화
	//그래픽 객체 생성
	if (graphics == NULL) {
		graphics = new GraphicsClass; //그래픽 동적할당
		if (!graphics) //할당 안되면 종료
			return false;
	}
	result = graphics->Initialize(screenW, screenH, m_hWnd, isFull);//초기화 제대로 안되면 종료
	if (!result) {
		return false;
	}

	//타임 클래스 객체 생성
	if (_TimeC == NULL) {
		_TimeC = new TimeClass; //그래픽 동적할당
		if (!_TimeC) //할당 안되면 종료
			return false;
	}
	
	result = _TimeC->Initialize();//초기화 제대로 안되면 종료
	if (!result) {
		return false;
	}
	//cpu 클래스 객체 생성
	if (_cpuC == NULL) {
		_cpuC = new CPUClass; //그래픽 동적할당
		if (!_cpuC) //할당 안되면 종료
			return false;
	}

	result = _cpuC->Initialize();//초기화 제대로 안되면 종료
	if (!result) {
		return false;
	}

	return true;
	
}
