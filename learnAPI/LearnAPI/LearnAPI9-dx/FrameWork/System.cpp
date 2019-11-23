#include "System.h"


//=================================================================================================

System::System()
{
	InputC = NULL;
	graphics = NULL;
}

System::~System()
{
}

void System::ShutdownWindows()
{
	ShowCursor(true);
	if (isFullScreen) {
		ChangeDisplaySettings(NULL, 0);

	}
	DestroyWindow(m_hWnd);

	m_hWnd = NULL;

	UnregisterClass(_ApplicationName, _Inst);
	_Inst = NULL;
}

void System::InitializeWindows(HINSTANCE hInst, bool isFull, int& screenW, int& screenH)
{
	WNDCLASSEX wc;
	// DEVMODE ������ ������ ������ �Ǵ� ���÷��� ��ġ�� �ʱ�ȭ �� ȯ�濡 ���� ������ �����մϴ�.
	DEVMODE dmScreenSettings;
	int posX, posY;


	//���ø����̼� �ν��Ͻ�
	_Inst = hInst;
	//������ ��ũ�� ����
	isFullScreen = isFull;
	//���ø����̼��� �̸� ����
	_ApplicationName = _T("FramWork");

	
	//������ Ŭ���� �⺻�������� ����ϴ�.
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
	RegisterClassEx(&wc); //���� ���� ������ wc�� ������ â Ŭ���� ����

	if (isFullScreen) {// Ǯ��ũ�� ����̸�
		screenW = GetSystemMetrics(SM_CXSCREEN);
		screenH = GetSystemMetrics(SM_CYSCREEN);
		memset(&dmScreenSettings, 0, sizeof(dmScreenSettings));
		dmScreenSettings.dmSize = sizeof(dmScreenSettings);
		dmScreenSettings.dmPelsWidth = (unsigned long)screenW;
		dmScreenSettings.dmPelsHeight = (unsigned long)screenH;
		dmScreenSettings.dmBitsPerPel = 32;
		dmScreenSettings.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;
		//�ý�ũ���� �´� ���ÿ��� ������ �մϴ�.
		ChangeDisplaySettings(&dmScreenSettings, CDS_FULLSCREEN);
		//�������� ��ġ�� ȭ���� �������� ����ϴ�
		posX = posY = 0;
	}
	else {
		posX = (GetSystemMetrics(SM_CXSCREEN) - screenW) / 2;
		posY = (GetSystemMetrics(SM_CYSCREEN) - screenH) / 2;
	}

	m_hWnd= m_hWnd = CreateWindowEx(WS_EX_APPWINDOW, _ApplicationName, _ApplicationName,
		WS_CLIPSIBLINGS|WS_CLIPCHILDREN|WS_OVERLAPPEDWINDOW,posX,posY,
		screenW,screenH, NULL, NULL, _Inst, NULL);
	ShowWindow(m_hWnd, SW_SHOW);
	SetForegroundWindow(m_hWnd);
	SetFocus(m_hWnd);
	
}



bool System::Frame()
{
	if (InputC->IsKeyDown(VK_ESCAPE)) {
		return false;
	}
	if (!graphics->Frame()) {
		return false;
	}
	return true;
}






int System::Run()
{
	bool done;
	ZeroMemory(&msg, sizeof(MSG));
	done = false;
	while (!done) {
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		if (msg.message == WM_QUIT) {
			done = true;
		}
		else
			done = !Frame();
	}

	Shutdown();
	return (int)msg.wParam;


}

void System::Shutdown()
{
	if (graphics) {
		graphics->Release();
		delete graphics;
		graphics = NULL;
	}
	if (InputC) {
		delete InputC;
		InputC = NULL;
	}
	ShutdownWindows();
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
	case WM_KEYDOWN: //Ű���� �ٿ� 
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

bool System::Initialize(HINSTANCE hinstance, bool isFull, int screenW, int screenH)
{
	bool result = true;
	InitializeWindows(hinstance, isFull, screenW, screenH);
	
	//�̰��� ��ü ���� N �ʱ�ȭ
	//input ��ü ����
	if (InputC == NULL) {
		InputC = new InputClass;
		if (!InputC)
			return false;
	}
	InputC->Initialize();

	if (graphics == NULL) {
		graphics = new GraphicsClass;
		if (!graphics)
			return false;
	}
	result =graphics->Initialize(screenW, screenH, m_hWnd, isFull);
	if (!result) {
		return false;
	}
	return true;
	
}




