#include "framework.h"

SpriteObjectClass::SpriteObjectClass()
{ 
	_posX = -8;
	_posY = 2;
	_MoveSpeed = 20.0f;
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
	_sizex = bitx;
	_sizey = bity;
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

bool SpriteObjectClass::Initialize(HWND _hwnd, ID3D11Device* device, int screenx, int screeny, int bitx, int bity, int posx, int posy,bool movePx)
{
	_sizex = bitx;
	_sizey = bity;
	bool result;
	_Model = new SpriteClass;
	if (!_Model)
		return false;
	_posX = posx; 
	_posY = posy;
	_movePx = movePx;
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

bool SpriteObjectClass::Process(float deltatime)
{
	int right = _movePx ? 1 : -1;
	_posX += right * deltatime * _MoveSpeed;
	/*_checkTime += deltatime;
	if (_checkTime > 0.05f) {
		_checkTime = 0;
		_posX += _movePx * deltatime * _MoveSpeed;

	}*/
	
	

	return true;
}

bool SpriteObjectClass::isoutboundry()
{
	if (_posX > 50 || _posX < -50)
		return true;
	else
		return false;
}

float SpriteObjectClass::getposX()
{
	return _posX;
}

float SpriteObjectClass::getposY()
{
	return _posY;
}

float SpriteObjectClass::getsizeY()
{
	return _sizey;
}



float SpriteObjectClass::getsizeX()
{
	return _sizex;
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
