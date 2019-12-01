#include "../Stdafx.h"

#include "ApplicationClass.h"



// �������� ������ ���ν��� �Լ�.
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	// �����찡 ���ŵǾ����� Ȯ���մϴ�.
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	// �����찡 �������� Ȯ���մϴ�. 
	case WM_CLOSE:
		PostQuitMessage(0);
		break;

	// �ٸ� ��� �޼������� system Ŭ������ �޼��� ó���⿡ �����մϴ�. 
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
	// �������� api�� ����Ͽ� �ʱ�ȭ�Ѵ�.
	InitializeWindows(hInst, isFullScreen, ScreenW, ScreenH);

	// �̰��� ��ü ���� N �ʱ�ȭ.
	// Input ��ü ����.
	if (_InputC == NULL)
	{
		_InputC = new InputClass;
		if (!_InputC)
			return false;
	}
	// Input ��ü �ʱ�ȭ.
	_InputC->Initialize();

	// graphics ��ü�� ����.
	if (_GraphicsC == NULL)
	{
		_GraphicsC = new GraphicsClass;
		if (!_GraphicsC)
			return false;
	}
	// graphics ��ü�� �ʱ�ȭ.
	result = _GraphicsC->Initialize(ScreenW, ScreenH, _hWnd, isFullScreen);
	if (!result)
	{
		return false;
	}

	return result;
}


void ApplicationClass::Shutdown()
{
	// �̰��� ��ü�� ��ȯ
	// Graphics ��ü�� ��ȯ.
	if (_GraphicsC)
	{
		_GraphicsC->Release();
		delete _GraphicsC;
		_GraphicsC = NULL;
	}

	// Input ��ü ��ȯ.
	if (_InputC != NULL)
	{
		delete _InputC;
		_InputC = NULL;
	}

	// â�� �����ŵ�ϴ�.
	ShutdownWindows();
}


bool ApplicationClass::Frame()
{
	// ESCŰ�� ������ �����Ų��.
	if (_InputC->IsKeyDown(VK_ESCAPE))
	{
		return false;
	}

	// graphics��ü�� �۾��� ó���մϴ�.
	if (!_GraphicsC->Frame())
	{
		return false;
	}

	return true;
}


int ApplicationClass::Run()
{
	bool done;
	// �޼��� ����ü�� �ʱ�ȭ�մϴ�.
	ZeroMemory(&_Msg, sizeof(MSG));

	// �����κ��� ���� �޼����� ���� ������ ������ ���ϴ�.
	done = false;
	while (!done)
	{
		// ������ �޼����� ó���մϴ�.
		if (PeekMessage(&_Msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&_Msg);
			DispatchMessage(&_Msg);
		}
		// �����쿡�� ���ø����̼��� ���Ḧ ��û�ϴ� ��� ���������ϴ�.
		if (_Msg.message == WM_QUIT)
		{
			done = true;
		}
		else
		{
			// �� �ܿ��� Frame �Լ��� ó���մϴ�.
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
	// Ű���尡 Ű�� ���ȴ��� Ȯ���մϴ�.
	case WM_KEYDOWN:
		// Ű�� ���ȴٸ� input��ü�� �� ����� �����Ͽ� ����ϵ��� �մϴ�.
		_InputC->KeyDown((unsigned int)wParam);
		break;
	// Ű������ ���� Ű�� ���������� Ȯ���մϴ�.
	case WM_KEYUP:
		// Ű�� �������ٸ� input��ü�� �� ����� �����Ͽ� �� Ű�� ��������մϴ�.
		_InputC->KeyUp((unsigned int)wParam);
		break;
	// �ٸ� �޼������� ������� �����Ƿ� �⺻ �޼��� ó���⿡ �����մϴ�.
	default:
		break;
	}

	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}


void ApplicationClass::InitializeWindows(HINSTANCE hInst, bool isFullScreen, int& ScreenW, int& ScreenH)
{
	WNDCLASSEX wc;
	// DEVMODE ������ ������ ������ �Ǵ� ���÷��� ��ġ�� �ʱ�ȭ �� ȯ�濡 ���� ������ �����մϴ�.
	DEVMODE dmScreenSettings;
	int posX, posY;

	// ������ ��ũ�� ��� ����.
	_IsFullScreen = isFullScreen;

	// �� ���ø����̼��� �ν��Ͻ��� �����ɴϴ�.
	_hInstance = hInst;

	// ���ø����̼��� �̸��� �����մϴ�.
	_ApplicationName = _T("FramWork");

	// ������ Ŭ������ �⺻ �������� ����ϴ�.
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

	// ������ Ŭ������ ����մϴ�.
	RegisterClassEx(&wc);

	// Ǯ��ũ�� ��� ������ ���� ���� ȭ�� ������ �մϴ�.
	if (_IsFullScreen)
	{
		// ����� ȭ���� �ػ󵵸� �˾ƿɴϴ�.
		ScreenW = GetSystemMetrics(SM_CXSCREEN);
		ScreenH = GetSystemMetrics(SM_CYSCREEN);
		// ���� Ǯ��ũ�� ����� ȭ�� ũ�⸦ ����ũ�� ũ�⿡ ���߰� ������ 32bit�� �մϴ�.
		memset(&dmScreenSettings, 0, sizeof(dmScreenSettings));
		dmScreenSettings.dmSize = sizeof(dmScreenSettings);
		dmScreenSettings.dmPelsWidth = (unsigned long)ScreenW;
		dmScreenSettings.dmPelsHeight = (unsigned long)ScreenH;
		dmScreenSettings.dmBitsPerPel = 32;
		dmScreenSettings.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;
		// Ǯ��ũ���� �´� ���÷��� ������ �մϴ�.
		ChangeDisplaySettings(&dmScreenSettings, CDS_FULLSCREEN);
		// �������� ��ġ�� ȭ���� ���� ���� ����ϴ�.
		posX = posY = 0;
	}
	else
	{
		// â�� ������� �߾ӿ� ������ �մϴ�.
		posX = (GetSystemMetrics(SM_CXSCREEN) - ScreenW) / 2;
		posY = (GetSystemMetrics(SM_CYSCREEN) - ScreenH) / 2;
	}

	// ������ ���� ������ â�� ����� �� �ڵ��� �����ɴϴ�.
	_hWnd = CreateWindowEx(WS_EX_APPWINDOW, _ApplicationName, _ApplicationName,
		WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_OVERLAPPEDWINDOW, posX, posY,
		ScreenW, ScreenH, NULL, NULL, _hInstance, NULL);

	// �����츦 ȭ�鿡 ǥ���ϰ� ��Ŀ���� �ݴϴ�.
	ShowWindow(_hWnd, SW_SHOW);
	SetForegroundWindow(_hWnd);
	SetFocus(_hWnd);

	// ���콺 Ŀ���� ǥ������ �ʽ��ϴ�.
	//ShowCursor(false);
}


void ApplicationClass::ShutdownWindows()
{
	// ���콺 Ŀ���� ǥ���մϴ�.
	ShowCursor(true);

	// Ǯ��ũ�� ��带 �������� �� ���÷��� ������ �ٲߴϴ�.
	if (_IsFullScreen)
	{
		ChangeDisplaySettings(NULL, 0);
	}

	// â�� �����մϴ�.
	DestroyWindow(_hWnd);
	_hWnd = NULL;

	// ���ø����̼� �ν��Ͻ��� �����մϴ�.
	UnregisterClass(_ApplicationName, _hInstance);
	_hInstance = NULL;
}

