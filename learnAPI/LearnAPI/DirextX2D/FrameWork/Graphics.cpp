#include "../Stdafx.h"

#include "Graphics.h"



GraphicsClass::GraphicsClass()
{
	_SDepth = 1000.0f;
	_SNear = 0.1f;
	_D3DC = NULL;
	_Vsync_enabled = false;
}


GraphicsClass::GraphicsClass(const GraphicsClass& other)
{
}


GraphicsClass::~GraphicsClass()
{
}


bool GraphicsClass::Initialize(int screenW, int screenH, HWND hWnd, bool IsFullScreen)
{
	bool result = false;

	// Direct3D ��ü�� �����մϴ�.
	_D3DC = new D3DClass;
	if (!_D3DC)
	{
		return false;
	}

	// Direct3D ��ü�� �ʱ�ȭ�մϴ�.
	result = _D3DC->Initialize(screenW, screenH, _Vsync_enabled, hWnd, IsFullScreen, _SDepth, _SNear);
	if (!result)
	{
		MessageBox(hWnd, _T("Could not initialize Direct3D"), _T("Error"), MB_OK);
		return false;
	}

	return true;
}


void GraphicsClass::Release()
{
	// D3D ��ü�� �����մϴ�.
	if (_D3DC)
	{
		_D3DC->Release();
		delete _D3DC;
		_D3DC = NULL;
	}
}


bool GraphicsClass::Frame()
{
	bool result = false;

	// �׷��� �������� �����մϴ�.
	result = Render();
	if (!result)
	{
		return false;
	}

	return true;
}


bool GraphicsClass::Render()
{
	bool result = false;

	// �� �׸��⸦ �����ϱ� ���� ������ ������ ����ϴ�.
	_D3DC->BeginScene(0.3f, 0.3f, 0.3f, 1.0f);

	// ���ۿ� �׷��� ���� ȭ�鿡 ǥ���մϴ�.
	_D3DC->EndScene();

	return true;
}


