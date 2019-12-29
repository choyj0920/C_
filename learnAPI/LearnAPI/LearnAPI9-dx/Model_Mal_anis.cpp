#include "framework.h"

bool Model_mal2::rightwork = true;

Model_mal2::Model_mal2()
{
	_posX = -8;
	_posY = 2;
	_MoveSpeed = 5.0f;
	_posU = 0;
	_posV = 0;
	_sizeU = 0;
	_sizeV = 0;
	_CheckTime = 0.0f;
	_ani_count = 0;
	_AniType = ANI_WORK3;
	rightwork = true;
	_Model = NULL;
}

Model_mal2::Model_mal2(const Model_mal2& copy)
{
}

Model_mal2::~Model_mal2()
{
}

void Model_mal2::setPos(float& posU, float& posV, int index)
{
	int i = 1 / _sizeU;
	posU = index % i;

	posV = index / i;
	return;
}

bool Model_mal2::Initialize(HWND _hwnd, ID3D11Device* device, int screenx, int screeny, int bitx, int bity, const TCHAR* filepath)
{
	bool result;
	_Model = new SpriteClass;
	if (!_Model)
		return false;
	
	InitializeInfo(filepath);
	
	_sizeU = _FileInfo->fsizeU;
	_sizeV = _FileInfo->fsizeV;
	
	_ani_count = _FileInfo->aniMaxCnt[_AniType];
	setPos(_posU, _posV, _ani_count);




	result = _Model->Initialize(device, screenx, screeny, _FileInfo->szFIleName, bitx, bity);
	if (!result) {
		MessageBox(_hwnd, _T("텍스쳐 초기화 실패..종료"), _T("Error"), MB_OK);
		return false;
	}
	return true;
}

void Model_mal2::Release()
{
	if (_Model) {
		_Model->Release();
		delete _Model;
		_Model = 0;
	}
}

bool Model_mal2::Process(float deltatime, float mx, float my)
{
	if (mx > 0) {
		rightwork = true;
	}
	else if(mx<0)
		rightwork = false;

	double dis = (mx * mx) + (my * my);
	dis = sqrt(dis);
	if (dis != 0) {
		_posX += mx / dis * deltatime * _MoveSpeed;
		_posY += my / dis * deltatime * _MoveSpeed;
	}
	
	_CheckTime += deltatime;
	if (_CheckTime >= 0.1f) {
		_CheckTime = 0;
		_ani_count++;
		if (_ani_count >= _FileInfo->aniMaxCnt[_AniType + 1]) {
			_ani_count = _FileInfo->aniMaxCnt[_AniType];
		}
		setPos(_posU, _posV, _ani_count);			

	}
	return true;
}



bool Model_mal2::Render(ID3D11DeviceContext* deviceContext, XMMATRIX world, XMMATRIX view, XMMATRIX orthoM, TextureShader* pTexShader)
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
