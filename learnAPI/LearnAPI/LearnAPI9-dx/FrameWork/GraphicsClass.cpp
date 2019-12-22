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

	_axis->Render(_D3DC->GetDeviceContext());

	result = _ShaderClass->Render(_D3DC->GetDeviceContext(), _axis->GetIndexCount(), worldMatrix, viewMatrix,
		projectionMatrix);

	// 추가. 모델이 회전 할 수 있도록 회전 값만큼 월드 행렬을 회전합니다.
	//worldMatrix = XMMatrixRotationY(rotation);

	// Put the model vertex and index buffers on the graphics pipeline to prepare them for drawing.
	_Model->Render(_D3DC->GetDeviceContext());

	

	// Render the model using the shader.
	result = _ShaderClass->Render(_D3DC->GetDeviceContext(), _Model->GetIndexCount(), worldMatrix, viewMatrix,
		projectionMatrix);

	// 모든 2D렌더링을 시작하려면 Z버퍼를 끕니다.
	_D3DC->TurnZBufferOff();

	//비트맵 버텍스 및 인덱스 버퍼를 그래프 파이프라인에 배치  드로잉을 준비
	//result = _spriteModel->Render(_D3DC->GetDeviceContext(), -8, 5);
	//if (!result) {
	//	return false;
	//}
	//
	////셰이더를 사용하여 모델 렌더링.
	//result = _Textureshader->Render(_D3DC->GetDeviceContext(), _spriteModel->GetIndexCount(), worldMatrix, viewMatrix,
	//	projectionMatrix, _spriteModel->GetTexture());
	//if (!result)
	//	return false;



	//오브젝트 클래스 이용그리기
	result = _spriteObject->Render(_D3DC->GetDeviceContext(), worldMatrix, viewMatrix, projectionMatrix, _Textureshader);
	if (!result)
		return false;

	_D3DC->TurnZBufferOn();

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
	_axis = NULL;
	_ShaderClass = NULL;
	_Textureshader = NULL;
	_spriteModel = NULL;
	_spriteObject = NULL;
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
	_Camera->SetPosition(-3.0f, 3.0f, -10.0f);
	_Camera->SetRotation(1.0f, 10.0f, 0.0f);
	// Create the model object.
	_Model = new ModelCube;
	if (!_Model)
		return false;

	_axis = new ModelAxis;
	if (!_axis)
		return false;

	_spriteModel = new SpriteClass;
	if (!_spriteModel)
		return false;

	result = _spriteModel->Initialize(_D3DC->GetDevice(), 0, 00, _T("냐옹이.jpg"),5, 5);
	if (!result) {
		MessageBox(hWnd, _T("텍스쳐 초기화 실패..종료"), _T("Error"), MB_OK);
		return false;
	}
	// Initialize the model object.
	result = _Model->Initialize(_D3DC->GetDevice());
	if (!result)
	{
		MessageBox(hWnd, _T("Could not initialize the model object."), _T("Error"), MB_OK);
		return false;
	}
	result = _axis->Initialize(_D3DC->GetDevice());
	if (!result)
	{
		MessageBox(hWnd, _T("Could not initialize the model object."), _T("Error"), MB_OK);
		return false;
	}
	_Textureshader = new TextureShader;
	if (!_Textureshader)
	{
		return false;
	}
	// Initialize the color shader object.
	result = _Textureshader->Initiallize(_D3DC->GetDevice(), hWnd);
	if (!result)
	{
		MessageBox(hWnd, _T("Could not initialize the texture shader object."), _T("Error"), MB_OK);
		return false;
	}

	_spriteObject = new SpriteObjectClass;
	if (!_spriteObject)
		return false;
	result = _spriteObject->Initialize(hWnd, _D3DC->GetDevice(), 0, 0, 5, 5);
	if (!result)
		return false;


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
	if (_Textureshader) {
		_Textureshader->Release();
		delete _Textureshader;
		_Textureshader = 0;
	}
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

	if (_axis)
	{
		_axis->Release();
		delete _axis;
		_axis = 0;
	}
	if (_spriteObject) {
		_spriteObject->Release();
		delete _spriteObject;
		_spriteObject = 0;
	}
	if (_spriteModel) {
		_spriteModel->Release();
		delete _spriteModel;
		_spriteModel = 0;
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

bool GraphicsClass::Frame(float deltaTime, float mx , float my)
{
	bool result;

	result = _spriteObject->Process(deltaTime, mx, my);
	if (!result)
		return false;

	return true;
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
