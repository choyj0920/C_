#include "framework.h"

enermyObject::enermyObject()
{
	_posX = 0;
	_posY = 5;
	_MoveSpeed = 0.0f;
	_Model = NULL;
	_movePy = false;
}

enermyObject::enermyObject(const enermyObject& copy)
{
}

enermyObject::~enermyObject()
{
}

bool enermyObject::Initialize(HWND _hwnd, ID3D11Device* device, int screenx, int screeny, int bitx, int bity)
{
	_sizeX = bitx;
	_sizeY = bity;
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

void enermyObject::Release()
{
	if (_Model) {
		_Model->Release();
		delete _Model;
		_Model = 0;
	}
}


bool enermyObject::Process(float deltatime)
{
	if (_movePy) {
		if (_posY >= 9)
			_movePy = false;
	}
	else
		if (_posY <= 2)
			_movePy = true;
	int up = _movePy ? 1 : -1;
	_posY += up * deltatime * _MoveSpeed;
	/*_checkTime += deltatime;
	if (_checkTime > 0.05f) {
		_checkTime = 0;
		_posX += _movePx * deltatime * _MoveSpeed;

	}*/



	return true;
}

bool enermyObject::istriger(SpriteObjectClass* cat)
{
	
	float _xcenter = _posX + _sizeX / 2;
	float _ycenter = _posY - _sizeY / 2;

	float cat_xcenter = cat->getposX() + (cat->getsizeX() / 2);
	float cat_ycenter = cat->getposY() - (cat->getsizeY() / 2);
	float dis_x = _xcenter - cat_xcenter;
	if (dis_x <= 0) {
		dis_x *= -1;
	}
	if (dis_x <= (_sizeX / 2) || dis_x <= (cat->getsizeX() / 2)) {
		float dis_y = _ycenter - cat_ycenter;
		if (dis_y <= 0) {
			dis_y *= -1;
		}
		if (dis_y <= (_sizeY / 2) || dis_y <= (cat->getsizeY() / 2)) {
			return true;
		}
	}
	
	return false;
}

void enermyObject::isupspeed()
{
	_MoveSpeed += 2.0f;
}

bool enermyObject::Render(ID3D11DeviceContext* deviceContext, XMMATRIX world, XMMATRIX view, XMMATRIX orthoM, TextureShader* pTexShader)
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



