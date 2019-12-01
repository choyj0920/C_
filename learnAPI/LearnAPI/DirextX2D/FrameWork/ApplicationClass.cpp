#include "../Stdafx.h"

#include "ApplicationClass.h"



// 전역으로 정의한 프로시져 함수.
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	// 윈도우가 제거되었는지 확인합니다.
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	// 윈도우가 닫히는지 확인합니다. 
	case WM_CLOSE:
		PostQuitMessage(0);
		break;

	// 다른 모든 메세지들은 system 클래스의 메세지 처리기에 전달합니다. 
	default:
		break;
	}

	return ApplicationClass::GetInstance()->ApplicationProc(hWnd, uMsg, wParam, lParam);
}



ApplicationClass::ApplicationClass()
{
	_InputC = NULL;
	_GraphicsC = NULL;
}


ApplicationClass::ApplicationClass(const ApplicationClass& other)
{
}


ApplicationClass::~ApplicationClass()
{
}


bool ApplicationClass::Initialize(HINSTANCE hInst, bool isFullScreen, int ScreenW, int ScreenH)
{
	bool result = true;
	// 윈도우즈 api를 사용하여 초기화한다.
	InitializeWindows(hInst, isFullScreen, ScreenW, ScreenH);

	// 이곳에 객체 생성 N 초기화.
	// Input 객체 생성.
	if (_InputC == NULL)
	{
		_InputC = new InputClass;
		if (!_InputC)
			return false;
	}
	// Input 객체 초기화.
	_InputC->Initialize();

	// graphics 객체를 생성.
	if (_GraphicsC == NULL)
	{
		_GraphicsC = new GraphicsClass;
		if (!_GraphicsC)
			return false;
	}
	// graphics 객체를 초기화.
	result = _GraphicsC->Initialize(ScreenW, ScreenH, _hWnd, isFullScreen);
	if (!result)
	{
		return false;
	}

	return result;
}


void ApplicationClass::Shutdown()
{
	// 이곳에 객체를 반환
	// Graphics 객체를 반환.
	if (_GraphicsC)
	{
		_GraphicsC->Release();
		delete _GraphicsC;
		_GraphicsC = NULL;
	}

	// Input 객체 반환.
	if (_InputC != NULL)
	{
		delete _InputC;
		_InputC = NULL;
	}

	// 창을 종료시킵니다.
	ShutdownWindows();
}


bool ApplicationClass::Frame()
{
	// ESC키가 눌리면 종료시킨다.
	if (_InputC->IsKeyDown(VK_ESCAPE))
	{
		return false;
	}

	// graphics객체의 작업을 처리합니다.
	if (!_GraphicsC->Frame())
	{
		return false;
	}

	return true;
}


int ApplicationClass::Run()
{
	bool done;
	// 메세지 구조체를 초기화합니다.
	ZeroMemory(&_Msg, sizeof(MSG));

	// 유저로부터 종료 메세지를 받을 때까지 루프를 돕니다.
	done = false;
	while (!done)
	{
		// 윈도우 메세지를 처리합니다.
		if (PeekMessage(&_Msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&_Msg);
			DispatchMessage(&_Msg);
		}
		// 윈도우에서 어플리케이션의 종료를 요청하는 경우 빠져나갑니다.
		if (_Msg.message == WM_QUIT)
		{
			done = true;
		}
		else
		{
			// 그 외에는 Frame 함수를 처리합니다.
			done = !Frame();
		}
	}

	Shutdown();

	return (int)_Msg.wParam;
}


LRESULT CALLBACK ApplicationClass::ApplicationProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	// 키보드가 키가 눌렸는지 확인합니다.
	case WM_KEYDOWN:
		// 키가 눌렸다면 input객체에 이 사실을 전달하여 기록하도록 합니다.
		_InputC->KeyDown((unsigned int)wParam);
		break;
	// 키보드의 눌린 키가 떼어졌는지 확인합니다.
	case WM_KEYUP:
		// 키가 떼어졌다면 input객체에 이 사실을 전달하여 이 키를 해제토록합니다.
		_InputC->KeyUp((unsigned int)wParam);
		break;
	// 다른 메세지들은 사용하지 않으므로 기본 메세지 처리기에 전달합니다.
	default:
		break;
	}

	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}


void ApplicationClass::InitializeWindows(HINSTANCE hInst, bool isFullScreen, int& ScreenW, int& ScreenH)
{
	WNDCLASSEX wc;
	// DEVMODE 데이터 구조는 프린터 또는 디스플레이 장치의 초기화 및 환경에 대한 정보를 포함합니다.
	DEVMODE dmScreenSettings;
	int posX, posY;

	// 윈도우 스크린 모드 설정.
	_IsFullScreen = isFullScreen;

	// 이 어플리케이션의 인스턴스를 가져옵니다.
	_hInstance = hInst;

	// 어플리케이션의 이름을 설정합니다.
	_ApplicationName = _T("FramWork");

	// 윈도우 클래스를 기본 설정으로 맞춥니다.
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = _hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);
	wc.hIconSm = wc.hIcon;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = _ApplicationName;
	wc.cbSize = sizeof(WNDCLASSEX);

	// 윈도우 클래스를 등록합니다.
	RegisterClassEx(&wc);

	// 풀스크린 모드 변수의 값에 따라 화면 설정을 합니다.
	if (_IsFullScreen)
	{
		// 모니터 화면의 해상도를 알아옵니다.
		ScreenW = GetSystemMetrics(SM_CXSCREEN);
		ScreenH = GetSystemMetrics(SM_CYSCREEN);
		// 만약 풀스크린 모드라면 화면 크기를 데스크톱 크기에 맞추고 색상을 32bit로 합니다.
		memset(&dmScreenSettings, 0, sizeof(dmScreenSettings));
		dmScreenSettings.dmSize = sizeof(dmScreenSettings);
		dmScreenSettings.dmPelsWidth = (unsigned long)ScreenW;
		dmScreenSettings.dmPelsHeight = (unsigned long)ScreenH;
		dmScreenSettings.dmBitsPerPel = 32;
		dmScreenSettings.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;
		// 풀스크린에 맞는 디스플레이 설정을 합니다.
		ChangeDisplaySettings(&dmScreenSettings, CDS_FULLSCREEN);
		// 윈도우의 위치를 화면의 왼쪽 위로 맞춥니다.
		posX = posY = 0;
	}
	else
	{
		// 창을 모니터의 중앙에 오도록 합니다.
		posX = (GetSystemMetrics(SM_CXSCREEN) - ScreenW) / 2;
		posY = (GetSystemMetrics(SM_CYSCREEN) - ScreenH) / 2;
	}

	// 설정한 것을 가지고 창을 만들고 그 핸들을 가져옵니다.
	_hWnd = CreateWindowEx(WS_EX_APPWINDOW, _ApplicationName, _ApplicationName,
		WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_OVERLAPPEDWINDOW, posX, posY,
		ScreenW, ScreenH, NULL, NULL, _hInstance, NULL);

	// 윈도우를 화면에 표시하고 포커스를 줍니다.
	ShowWindow(_hWnd, SW_SHOW);
	SetForegroundWindow(_hWnd);
	SetFocus(_hWnd);

	// 마우스 커서를 표시하지 않습니다.
	//ShowCursor(false);
}


void ApplicationClass::ShutdownWindows()
{
	// 마우스 커서를 표시합니다.
	ShowCursor(true);

	// 풀스크린 모드를 빠져나올 때 디스플레이 설정을 바꿉니다.
	if (_IsFullScreen)
	{
		ChangeDisplaySettings(NULL, 0);
	}

	// 창을 제거합니다.
	DestroyWindow(_hWnd);
	_hWnd = NULL;

	// 어플리케이션 인스턴스를 제거합니다.
	UnregisterClass(_ApplicationName, _hInstance);
	_hInstance = NULL;
}

