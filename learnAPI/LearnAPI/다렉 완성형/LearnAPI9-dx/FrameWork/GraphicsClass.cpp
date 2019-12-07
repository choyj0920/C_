#include "../framework.h"

bool GraphicsClass::Render()
{
	XMMATRIX worldMatrix, viewMatrix, projectionMatrix;
	bool result = false;
		
	// 씬 그리기를 시작하기 위해 버퍼의 내용을 지웁니다.
	_D3DC->BeginScene(0.3f, 0.3f, 0.3f, 1.0f);
	//카메라의 위치를 기반으로 뷰 행렬을생성합니다.
	_Camera->Render();
	// 카메라 및 d3d객체에서 세계, 뷰 및 투영 행렬 가져오기.
	//_Camera->GetViewMatrix();
	 // Get the world, view, and projection matrices from the camera and d3d objects.
	_Camera->GetViewMatrix(viewMatrix);
	_D3DC->GetWorldMatrix(worldMatrix);
	_D3DC->GetProjectionMatrix(projectionMatrix);

	// 추가. 모델이 회전 할 수 있도록 회전 값만큼 월드 행렬을 회전합니다.
	//worldMatrix = XMMatrixRotationY(rotation);

	// Put the model vertex and index buffers on the graphics pipeline to prepare them for drawing.
	_Model->Render(_D3DC->GetDeviceContext());

	// Render the model using the shader.
	result = _ShaderClass->Render(_D3DC->GetDeviceContext(), _Model->GetIndexCount(), worldMatrix, viewMatrix,
		projectionMatrix);


	// 버퍼에 그려진 씬을 화면에 표시합니다.
	_D3DC->EndScene();


	return true;	
}

GraphicsClass::GraphicsClass()
{
	_SDepth = 1000.0f;
	_SNear = 0.1f;
	_D3DC = NULL;
	_Vsync_enable = false;	
	_Camera = NULL;
	_Model = NULL;
	_ShaderClass = NULL;
	// 추가 클래스 초기화.
	/*
	_LightShader = NULL;
	_LightC = NULL;
	_MultiTexC = NULL;
	_AlphamapShader = NULL;
	_BumpMapShader = NULL;
	_SpeculaMapShader = NULL;*/
}

GraphicsClass::GraphicsClass(const GraphicsClass& copy) :_Vsync_enable(copy._Vsync_enable), _SDepth(copy._SDepth), _SNear(copy._SNear)
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
	result = _D3DC->Initialize(screenW, screenH, _Vsync_enable, hWnd, IsFullScreen, _SDepth, _SNear);
	if (!result)
	{
		MessageBox(hWnd, _T("Could not initialize Direct3D"), _T("Error"), MB_OK);
		return false;
	}
	// Create the camera object.
	_Camera = new Camera;
	if (!_Camera)
		return false;

	// Set the initial position of the camera.
	_Camera->SetPosition(0.0f, 0.0f, -10.0f);
	// Create the model object.
	_Model = new ModelTraingle;
	if (!_Model)
		return false;

	// Initialize the model object.
	result = _Model->Initialize(_D3DC->GetDevice());
	if (!result)
	{
		MessageBox(hWnd, _T("Could not initialize the model object."), _T("Error"), MB_OK);
		return false;
	}

	// Create the color shader object.
	_ShaderClass = new ColorShader;
	if (!_ShaderClass)
		return false;

	// Initialize the color shader object.
	result = _ShaderClass->Initiallize(_D3DC->GetDevice(), hWnd);
	if (!result)
	{
		MessageBox(hWnd, _T("Could not initialize the color shader object."), _T("Error"), MB_OK);
		return false;
	}

	return true;

}

void GraphicsClass::Release()
{
	// Release the color shader object.
	if (_ShaderClass)
	{
		_ShaderClass->Release();
		delete _ShaderClass;
		_ShaderClass = 0;
	}
	// Release the model object.
	if (_Model)
	{
		_Model->Release();
		delete _Model;
		_Model = 0;
	}

	if (_Camera) {
		delete _Camera;
		_Camera = NULL;
	}
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
