#include "System.h"
//=================================================================================================

System::System()
{
	// Ű�Է�, �׷���Ŭ���� NULL
	InputC = NULL;
	graphics = NULL;
	_TimeC = NULL;
	_cpuC = NULL;
}

System::~System()
{
}


void System::ShutdownWindows()//������ ���� �Լ�
{
	
	ShowCursor(true);
	if (isFullScreen) {//Ǯ ��ũ�� �̿����� ���÷��� ���� �ʱ�ȭ
		ChangeDisplaySettings(NULL, 0);

	}
	// â ����
	DestroyWindow(m_hWnd);

	// ������ �ڵ� NULL
	m_hWnd = NULL;

	//������ Ŭ���� ��� ����
	UnregisterClass(_ApplicationName, _Inst);
	// �ν��Ͻ� �ʱ�ȭ
	_Inst = NULL;
}
// ������ Ŭ���� ���� �� â ������ִ� �Լ�
void System::InitializeWindows(HINSTANCE hInst, bool isFull, int& screenW, int& screenH)
{
	WNDCLASSEX wc; //������ Ŭ���� ����
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
	else { //Ǯ��ũ�� ��尡 �ƴ� ���� 
		posX = (GetSystemMetrics(SM_CXSCREEN) - screenW) / 2; //ȭ�� �߰��� ����
		posY = (GetSystemMetrics(SM_CYSCREEN) - screenH) / 2;
	}
	//â ����� 
	m_hWnd = CreateWindowEx(WS_EX_APPWINDOW, _ApplicationName, _ApplicationName,
		WS_CLIPSIBLINGS|WS_CLIPCHILDREN|WS_OVERLAPPEDWINDOW,posX,posY,
		screenW,screenH, NULL, NULL, _Inst, NULL);
	ShowWindow(m_hWnd, SW_SHOW); //â ���̰�
	SetForegroundWindow(m_hWnd); //����
	SetFocus(m_hWnd); //
	
}


//Ű, �׷��� ����-���� �߻��� false����
bool System::Frame()
{	//Ű�� esc������ -false����
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
	if (!graphics->Frame()) {//�׷��� �߸� �׸��� false���� ����
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

	return true; //�ƴϸ� true
}



// �޽��� ����
int System::Run()
{
	bool done; //��� ���� ����
	ZeroMemory(&msg, sizeof(MSG));
	done = false;
	while (!done) { //���ᰡ ���� ������ 
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		if (msg.message == WM_QUIT) {//���� �޽��� ������ ����
			done = true;
		}
		else {
		
			done = !Frame();
		}
	}
	// ���� �� �� -Shutdown����
	Shutdown(); 
	return (int)msg.wParam;
}

//���� �Լ�
void System::Shutdown()
{
	if (graphics) { //�׷����� �Ҵ�Ǿ� ������
		graphics->Release(); //�׷��� �����Լ�
		delete graphics; //�׷����Ҵ� ����
		graphics = NULL;
	}
	if (InputC) { //�Ҵ� �Ǿ�������
		delete InputC; //��ǲ �����Լ�
		InputC = NULL;
	}
	if (_TimeC) { //�Ҵ� �Ǿ�������
		delete _TimeC; //��ǲ �����Լ�
		_TimeC = NULL;
	}
	if (_cpuC) { //�Ҵ� �Ǿ�������
		delete _cpuC; //��ǲ �����Լ�
		_cpuC = NULL;
	}
	ShutdownWindows(); //������api���� ����
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

// ������ �ʱ�ȭ �Լ�
bool System::Initialize(HINSTANCE hinstance, bool isFull, int screenW, int screenH)
{
	bool result = true; // �ʱ�ȭ ���� ���� ����
	InitializeWindows(hinstance, isFull, screenW, screenH);//������ api- �ʱ�ȭ�Լ�
	
	//�̰��� ��ü ���� N �ʱ�ȭ
	//input ��ü ����
	if (InputC == NULL) {
		InputC = new InputClass; //Ű�Է� ���� �Ҵ�
		if (!InputC) //�Ҵ� �ȵǸ� ����
			return false;
	}
	InputC->Initialize(); //input�ʱ�ȭ
	//�׷��� ��ü ����
	if (graphics == NULL) {
		graphics = new GraphicsClass; //�׷��� �����Ҵ�
		if (!graphics) //�Ҵ� �ȵǸ� ����
			return false;
	}
	result = graphics->Initialize(screenW, screenH, m_hWnd, isFull);//�ʱ�ȭ ����� �ȵǸ� ����
	if (!result) {
		return false;
	}

	//Ÿ�� Ŭ���� ��ü ����
	if (_TimeC == NULL) {
		_TimeC = new TimeClass; //�׷��� �����Ҵ�
		if (!_TimeC) //�Ҵ� �ȵǸ� ����
			return false;
	}
	
	result = _TimeC->Initialize();//�ʱ�ȭ ����� �ȵǸ� ����
	if (!result) {
		return false;
	}
	//cpu Ŭ���� ��ü ����
	if (_cpuC == NULL) {
		_cpuC = new CPUClass; //�׷��� �����Ҵ�
		if (!_cpuC) //�Ҵ� �ȵǸ� ����
			return false;
	}

	result = _cpuC->Initialize();//�ʱ�ȭ ����� �ȵǸ� ����
	if (!result) {
		return false;
	}

	return true;
	
}
