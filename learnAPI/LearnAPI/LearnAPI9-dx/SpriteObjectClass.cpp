#include "framework.h"

SpriteObjectClass::SpriteObjectClass()
{ 
	_posX = -8;
	_posY = 2;
	_MoveSpeed = 10.0f;
	_Model = NULL;
}

SpriteObjectClass::SpriteObjectClass(const SpriteObjectClass& copy)
{
}

SpriteObjectClass::~SpriteObjectClass()
{
}

bool SpriteObjectClass::Initialize(HWND _hwnd, ID3D11Device* device, int screenx, int screeny, int bitx, int bity)
{
	bool result;
	_Model = new SpriteClass;
	if (!_Model)
		return false;

	result = _Model->Initialize(device, screenx, screeny, _T("냐옹이.jpg"), bitx, bity);
	if (!result) {
		MessageBox(_hwnd, _T("텍스쳐 초기화 실패..종료"), _T("Error"), MB_OK);
		return false;
	}
	return true;
}

void SpriteObjectClass::Release()
{
	if (_Model) {
		_Model->Release();
		delete _Model;
		_Model = 0;
	}
}

bool SpriteObjectClass::Process(float deltatime, float mx, float my)
{
	double dis = (mx * mx) + (my * my);
	dis = sqrt(dis);
	if (dis == 0)
		return true;
	_posX += mx / dis * deltatime * _MoveSpeed;
	_posY += my / dis * deltatime * _MoveSpeed;

	return true;
}

bool SpriteObjectClass::Render(ID3D11DeviceContext* deviceContext, XMMATRIX world, XMMATRIX view, XMMATRIX orthoM, TextureShader* pTexShader)
{
	
	if (!_Model->Render(deviceContext, _posX, _posY)) {
		return false;
	}
	
	if (!pTexShader->Render(deviceContext, _Model->GetIndexCount(),
		world, view, orthoM, _Model->GetTexture())) {
		return false;
	}

	return true;
}
