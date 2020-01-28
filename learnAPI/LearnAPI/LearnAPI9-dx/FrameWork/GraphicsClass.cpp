#include "../framework.h"

bool GraphicsClass::Render()
{
	XMMATRIX worldMatrix, viewMatrix, projectionMatrix,orthoMatrix;
	bool result = false;

	// �� �׸��⸦ �����ϱ� ���� ������ ������ ����ϴ�.
	_D3DC->BeginScene(0.3f, 0.3f, 0.3f, 1.0f);
	//ī�޶��� ��ġ�� ������� �� ����������մϴ�.
	_Camera->Render();
	// ī�޶� �� d3d��ü���� ����, �� �� ���� ��� ��������.
	//_Camera->GetViewMatrix();
	 // Get the world, view, and projection matrices from the camera and d3d objects.
	_Camera->GetViewMatrix(viewMatrix);
	_D3DC->GetWorldMatrix(worldMatrix);
	_D3DC->GetProjectionMatrix(projectionMatrix);
	_D3DC->GetOrthoMatrix(orthoMatrix);

	_axis->Render(_D3DC->GetDeviceContext());

	result = _ShaderClass->Render(_D3DC->GetDeviceContext(), _axis->GetIndexCount(), worldMatrix, viewMatrix,
		projectionMatrix);

	// �߰�. ���� ȸ�� �� �� �ֵ��� ȸ�� ����ŭ ���� ����� ȸ���մϴ�.
	//worldMatrix = XMMatrixRotationY(rotation);

	// Put the model vertex and index buffers on the graphics pipeline to prepare them for drawing.
	_Model->Render(_D3DC->GetDeviceContext());


	// Render the model using the shader.
	result = _ShaderClass->Render(_D3DC->GetDeviceContext(), _Model->GetIndexCount(), worldMatrix, viewMatrix,
		projectionMatrix);

	// ��� 2D�������� �����Ϸ��� Z���۸� ���ϴ�.
	_D3DC->TurnZBufferOff();

	//��Ʈ�� ���ؽ� �� �ε��� ���۸� �׷��� ���������ο� ��ġ  ������� �غ�
	//result = _spriteModel->Render(_D3DC->GetDeviceContext(), -8, 5);
	//if (!result) {
	//	return false;
	//}
	//
	////���̴��� ����Ͽ� �� ������.
	//result = _Textureshader->Render(_D3DC->GetDeviceContext(), _spriteModel->GetIndexCount(), worldMatrix, viewMatrix,
	//	projectionMatrix, _spriteModel->GetTexture());
	//if (!result)
	//	return false;
	   
	//������Ʈ Ŭ���� �̿�׸���
	//���� ���� on
	_D3DC->EnableAlphaBlending();

	//�� �׸���
	
	//�ؽ��� �׸���
	result = _textObject->Render(_D3DC->GetDeviceContext(), worldMatrix, orthoMatrix);
	if (!result)
		return false;

	result = _spriteObject->Render(_D3DC->GetDeviceContext(), worldMatrix, viewMatrix, projectionMatrix, orthoMatrix, _Textureshader);
	if (!result)
		return false;

	//���� ���� off
	_D3DC->DisableAlphaBlending();
	//2D������ ���� �� z����on 
	_D3DC->TurnZBufferOn();

	// ���ۿ� �׷��� ���� ȭ�鿡 ǥ���մϴ�.
	_D3DC->EndScene();

	return true;
}

GraphicsClass::GraphicsClass()
{
	_SDepth = 1000.0f;
	_SNear = 0.1f;
	_D3DC = NULL;
	_Vsync_enable = true;
	_Camera = NULL;
	_Model = NULL;
	_axis = NULL;
	_ShaderClass = NULL;
	_Textureshader = NULL;
	_spriteModel = NULL;
	_spriteObject = NULL;
	_textObject = NULL;
	// �߰� Ŭ���� �ʱ�ȭ.
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
	_hwnd = hWnd;
	// Direct3D ��ü�� �����մϴ�.
	_D3DC = new D3DClass;
	if (!_D3DC)
	{
		return false;
	}
	
	// Direct3D ��ü�� �ʱ�ȭ�մϴ�.
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
	//_Camera->SetRotation(1.0f, 10.0f, 0.0f);

	XMMATRIX baseViewMatrix;
	_Camera->SetPosition(0.0f, 0.0f, -1.0f);
	_Camera->Render();

	_Camera->SetPosition(-3.0f, 3.0f, -10.0f);
	_Camera->GetViewMatrix(baseViewMatrix);


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

	result = _spriteModel->Initialize(_D3DC->GetDevice(), 0, 00, _T("�Ŀ���.jpg"),5, 5);
	if (!result) {
		MessageBox(hWnd, _T("�ؽ��� �ʱ�ȭ ����..����"), _T("Error"), MB_OK);
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
	/* �� ��
	_spriteObject = new Model_mal2;
	if (!_spriteObject)
		return false;
	result = _spriteObject->Initialize(hWnd, _D3DC->GetDevice(), 0, 0, 5, 5, _T("MalModel.txt"));
	if (!result)
		return false;
*/
	
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

	
	_textObject = new TextObjectClass;
	if (!_textObject)
		return false;
	result = _textObject->Initialize(_D3DC->GetDevice(), _D3DC->GetDeviceContext(), hWnd, screenW, screenH, baseViewMatrix);
	if (!result) {
		MessageBox(hWnd, _T("Could not initialize the text object."), _T("Error"), MB_OK);
		return false;
	}
	_spriteObject = new Mal_with_text;
	if (!_spriteObject)
		return false;
	result = _spriteObject->Initialize(hWnd, _D3DC->GetDevice(), _D3DC->GetDeviceContext(), 0, 0, 3, 3, _T("MalModel.txt"), screenW, screenH, baseViewMatrix);
	if (!result)
		return false;

	return true;

}

void GraphicsClass::Release()
{
	if (_textObject)
	{
		_textObject->Release();
		delete _textObject;
		_textObject = NULL;
	}

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
	// D3D ��ü�� �����մϴ�.
	if (_D3DC)
	{
		_D3DC->Release();
		delete _D3DC;
		_D3DC = NULL;
	}
	
}

bool GraphicsClass::Frame(float deltaTime, float mx , float my,bool shot)
{
	bool result;
	static float checktime = 0.0f;
	result = _spriteObject->Process(deltaTime, mx, my, _D3DC->GetDeviceContext());
	if (!result)
		return false;
	checktime += deltaTime;
	if (shot) {
		if (checktime > 0.3f) {
			checktime = 0.0f;
			_spriteObject->shotcat(_hwnd, _D3DC->GetDevice(), 0, 0, 1, 1);

		}
	}
	return true;
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
