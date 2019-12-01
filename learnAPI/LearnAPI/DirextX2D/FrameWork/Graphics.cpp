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

	// Direct3D 객체를 생성합니다.
	_D3DC = new D3DClass;
	if (!_D3DC)
	{
		return false;
	}

	// Direct3D 객체를 초기화합니다.
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
	// D3D 객체를 해제합니다.
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

	// 그래픽 렌더링을 수행합니다.
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

	// 씬 그리기를 시작하기 위해 버퍼의 내용을 지웁니다.
	_D3DC->BeginScene(0.3f, 0.3f, 0.3f, 1.0f);

	// 버퍼에 그려진 씬을 화면에 표시합니다.
	_D3DC->EndScene();

	return true;
}


