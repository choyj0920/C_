#pragma once


class ApplicationClass : public Singleton<ApplicationClass>
{
	LPCWSTR _ApplicationName;
	HINSTANCE _hInstance;
	HWND _hWnd;
	bool _IsFullScreen;
	MSG _Msg;

	// ����� ��ü�� ����.
	InputClass* _InputC;
	GraphicsClass* _GraphicsC;

public:
	ApplicationClass();
	ApplicationClass(const ApplicationClass&);
	~ApplicationClass();

	bool Initialize(HINSTANCE, bool = false, int = 800, int = 600);
	void Shutdown();
	int Run();
	LRESULT CALLBACK ApplicationProc(HWND, UINT, WPARAM, LPARAM);

private:
	bool Frame();
	void InitializeWindows(HINSTANCE, bool, int&, int&);
	void ShutdownWindows();

};


static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

