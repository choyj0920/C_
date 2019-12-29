#include "framework.h"

Model_mal::Model_mal()
{
	_posX = -8;
	_posY = 2;
	_MoveSpeed = 5.0f;
	_posU = 0;
	_posV = 0;
	_sizeU = 0.25f;
	_sizeV = 0.25f;
	_CheckTime = 0.0f;


	_Model = NULL;
}

Model_mal::Model_mal(const Model_mal& copy)
{
}

Model_mal::~Model_mal()
{
}

bool Model_mal::Initialize(HWND _hwnd, ID3D11Device* device, int screenx, int screeny, int bitx, int bity)
{
	bool result;
	_Model = new SpriteClass;
	if (!_Model)
		return false;

	result = _Model->Initialize(device, screenx, screeny, _T("마알.png"), bitx, bity);
	if (!result) {
		MessageBox(_hwnd, _T("텍스쳐 초기화 실패..종료"), _T("Error"), MB_OK);
		return false;
	}
	return true;
}

void Model_mal::Release()
{
	if (_Model) {
		_Model->Release();
		delete _Model;
		_Model = 0;
	}
}

bool Model_mal::Process(float deltatime, float mx, float my)
{
	double dis = (mx * mx) + (my * my);
	dis = sqrt(dis);
	if (dis != 0) {
		_posX += mx / dis * deltatime * _MoveSpeed;
		_posY += my / dis * deltatime * _MoveSpeed;
	}
	
	_CheckTime += deltatime;
	if (_CheckTime >= 0.05f) {
		_posU++;
		_CheckTime = 0;
		if (_posU >= 4) {
			_posU = 0;
			_posV++;
		}
		if (_posV >= 4) {
			_posV = 0;
			_posU = 0;
		}
			

	}
	return true;
}



bool Model_mal::Render(ID3D11DeviceContext* deviceContext, XMMATRIX world, XMMATRIX view, XMMATRIX orthoM, TextureShader* pTexShader)
{
	if (!_Model->Render(deviceContext, _posX, _posY,_sizeU,_sizeV,_posU*_sizeU,_posV*_sizeV)) {
		return false;
	}

	if (!pTexShader->Render(deviceContext, _Model->GetIndexCount(),
		world, view, orthoM, _Model->GetTexture())) {
		return false;
	}

	return true;
}
