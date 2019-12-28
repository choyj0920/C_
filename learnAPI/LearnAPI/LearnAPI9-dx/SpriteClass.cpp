#include "framework.h"

bool SpriteClass::InitializeBuffers(ID3D11Device* device)
{
	VertexType* vertices;
	unsigned long* indices;
	D3D11_BUFFER_DESC vertexBufferDesc, indexBufferDesc;
	D3D11_SUBRESOURCE_DATA vertexData, indexData;
	HRESULT result;
	int i;

	// 정점 배열의 정점수를 설정합니다.
	_VertexCount = 6;
	//인덱스 배열의 인덱스수 설정
	_IndexCount = _VertexCount;

	//버텍스 배열 만들기.
	vertices = new VertexType[_VertexCount];
	if (!vertices)
		return false;
	//인덱스 배열 만들기.
	indices = new unsigned long[_IndexCount];
	if (!indices)
		return false;
	//먼저 정점배열 0으로 초기화
	memset(vertices, 0, (sizeof(VertexType) * _VertexCount));

	for (i = 0; i < _IndexCount; i++) {
		indices[i] = i;
	}

	// 정적 정점 버퍼의 설명을 설정한다.
	vertexBufferDesc.Usage = D3D11_USAGE_DYNAMIC;
	vertexBufferDesc.ByteWidth = sizeof(VertexType) * _IndexCount;
	vertexBufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
	vertexBufferDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
	vertexBufferDesc.MiscFlags = 0;
	vertexBufferDesc.StructureByteStride = 0;

	//하위 리소스 구조에 정점 데이터에 대한 포인터를 부여합니다.
	vertexData.pSysMem = vertices;
	vertexData.SysMemPitch = 0;
	vertexData.SysMemSlicePitch = 0;

	//이제 버텍스 버퍼를 만듭니다.
	result = device->CreateBuffer(&vertexBufferDesc, &vertexData, &_VertexBuffer);

	//정적 인덱스 버퍼에 대한 설명 설정
	indexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
	indexBufferDesc.ByteWidth = sizeof(unsigned long) * _IndexCount;
	indexBufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
	indexBufferDesc.CPUAccessFlags = 0;
	indexBufferDesc.MiscFlags = 0;
	indexBufferDesc.StructureByteStride = 0;

	//하위 리소스 구조에 인덱스 데이터를 가리키는 보조 리소스 구조체를 작성합니다.
	indexData.pSysMem = indices;
	indexData.SysMemPitch = 0;
	indexData.SysMemSlicePitch = 0;

	// 인덱스 버퍼를 생성합니다.
	result = device->CreateBuffer(&indexBufferDesc, &indexData, &_IndexBuffer);
	if (FAILED(result))
		return false;

	// 생성되고 값이 할당된 정점 버퍼와 인덱스 버퍼를 해제합니다.
	//버텍스와 인덱스 버퍼가 생성되고 로드된 상태에서 배열을 놓습니다.
	delete[] vertices;
	vertices = NULL;
	delete[] indices;
	indices = NULL;


	return true;
}

void SpriteClass::ReleaseBuffers()
{
	if (_IndexBuffer) {
		_IndexBuffer->Release();
		_IndexBuffer = NULL;
	}
	if (_VertexBuffer) {
		_VertexBuffer->Release();
		_VertexBuffer = NULL;
	}

}

bool SpriteClass::UpdateBuffers(ID3D11DeviceContext* deviceContext, float positionX, float positionY)
{
	float left, right, top, bottom;
	VertexType* vertices;
	D3D11_MAPPED_SUBRESOURCE mappedResource;
	VertexType* verticesPtr;
	HRESULT result;

	if ((positionX == _PreviousPosX) && (positionY == _PreviousPosY))
		return true;
	
	//변경된 경우 ㅇ렌더링 되는 위치 업데이트
	_PreviousPosX = positionX;
	_PreviousPosY = positionY;

	//비트맵의 왼쪽면의 화면 좌표를 계산합니다,
	left = (float)((_ScreenW / 2) * -1) + (float)positionX;
	//비트맵의 오른쪽의 화면 좌표를 계산
	right = left+(float)_BitmapW;
	//비트맵 상단의 화면 좌표를 계산합니다.
	top = (float)((_ScreenH / 2) * -1) + (float)positionY;
	//비트맵의 아래쪾의 화면 좌표를 계산하십시오.
	bottom = top - (float)_BitmapH;

	//버텍스 배열
	vertices = new VertexType[_VertexCount];
	if (!vertices)
		return false;
	
	//버텍스 배열에 데이터 로드
	//첫번쨰 삼각형
	vertices[0].position = XMFLOAT3(left, top, 0.0f);
	vertices[0].texture = XMFLOAT2(0.0f, 0.0f);
	
	vertices[1].position = XMFLOAT3(right, bottom, 0.0f);
	vertices[1].texture = XMFLOAT2(1.0f, 1.0f);
	vertices[2].position = XMFLOAT3(left, bottom, 0.0f);
	vertices[2].texture = XMFLOAT2(0.0f, 1.0f);
	//두번째
	vertices[3].position = XMFLOAT3(left, top, 0.0f);
	vertices[3].texture = XMFLOAT2(0.0f, 0.0f);
	vertices[4].position = XMFLOAT3(right, top, 0.0f);
	vertices[4].texture = XMFLOAT2(01.0f, 0.0f);
	vertices[5].position = XMFLOAT3(right, bottom, 0.0f);
	vertices[5].texture = XMFLOAT2(1.0f, 1.0f);

	//버텍스 버퍼를 쓸수 있도록 잠그십시오.
	result = deviceContext->Map(_VertexBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedResource);
	if (FAILED(result))
		return false;

	//버텍스 버퍼의 데이터에 대한 데이터 가져오기
	verticesPtr = (VertexType*)mappedResource.pData;

	//데이터를 정점 버퍼에 복사합니다.
	memcpy(verticesPtr, (void*)vertices, (sizeof(VertexType) * _VertexCount));

	//버텍스 버퍼 잠금해제.
	deviceContext->Unmap(_VertexBuffer, 0);

	//버텍스 배열을 더 이상 필요하지 않게 해제하십시오.
	delete[] vertices;
	vertices = NULL;

	return true;
}

bool SpriteClass::UpdateBuffers(ID3D11DeviceContext* deviceContext, float sizeU, float sizeV, float posU, float posV, float positionX, float positionY)
{
	float left, right, top, bottom;
	VertexType* vertices;
	D3D11_MAPPED_SUBRESOURCE mappedResource;
	VertexType* verticesPtr;
	HRESULT result;

	//이 비트 맵을 네더링 할 위치가 변경되지 않은 경우 현재 ㅇㄹ바른 매개변수가 있으므로 정점 버퍼를 업데이트 하지 않습니다.
	/*if ((positionX == _PreviousPosX) && (positionY == _PreviousPosY))
		return true;*/

	//변경된 경우 ㅇ렌더링 되는 위치 업데이트
	_PreviousPosX = positionX;
	_PreviousPosY = positionY;

	//비트맵의 왼쪽면의 화면 좌표를 계산합니다,
	left = (float)((_ScreenW / 2) * -1) + (float)positionX;
	//비트맵의 오른쪽의 화면 좌표를 계산
	right = left + (float)_BitmapW;
	//비트맵 상단의 화면 좌표를 계산합니다.
	top = (float)((_ScreenH / 2) * -1) + (float)positionY;
	//비트맵의 아래쪾의 화면 좌표를 계산하십시오.
	bottom = top - (float)_BitmapH;

	//버텍스 배열
	vertices = new VertexType[_VertexCount];
	if (!vertices)
		return false;

	//버텍스 배열에 데이터 로드
	//첫번쨰 삼각형
	vertices[0].position = XMFLOAT3(left, top, 0.0f);
	vertices[0].texture = XMFLOAT2(posU, posV);

	vertices[1].position = XMFLOAT3(right, bottom, 0.0f);
	vertices[1].texture = XMFLOAT2(posU+sizeU, posV+sizeV);
	vertices[2].position = XMFLOAT3(left, bottom, 0.0f);
	vertices[2].texture = XMFLOAT2(posU, posV+sizeV);
	//두번째
	vertices[3].position = XMFLOAT3(left, top, 0.0f);
	vertices[3].texture = XMFLOAT2(posU, posV);
	vertices[4].position = XMFLOAT3(right, top, 0.0f);
	vertices[4].texture = XMFLOAT2(posU+sizeU, posV);
	vertices[5].position = XMFLOAT3(right, bottom, 0.0f);
	vertices[5].texture = XMFLOAT2(posU + sizeU , posV + sizeV);

	//버텍스 버퍼를 쓸수 있도록 잠그십시오.
	result = deviceContext->Map(_VertexBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedResource);
	if (FAILED(result))
		return false;

	//버텍스 버퍼의 데이터에 대한 데이터 가져오기
	verticesPtr = (VertexType*)mappedResource.pData;

	//데이터를 정점 버퍼에 복사합니다.
	memcpy(verticesPtr, (void*)vertices, (sizeof(VertexType) * _VertexCount));

	//버텍스 버퍼 잠금해제.
	deviceContext->Unmap(_VertexBuffer, 0);

	//버텍스 배열을 더 이상 필요하지 않게 해제하십시오.
	delete[] vertices;
	vertices = NULL;

	return true;
}

void SpriteClass::RenderBuffers(ID3D11DeviceContext* deviceContext)
{
	unsigned int stride;
	unsigned int offset;

	stride = sizeof(VertexType);
	offset = 0;

	deviceContext->IASetVertexBuffers(0, 1, &_VertexBuffer, &stride, &offset);

	deviceContext->IASetIndexBuffer(_IndexBuffer, DXGI_FORMAT_R32_UINT, 0);

	deviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
}

bool SpriteClass::LoadTexture(ID3D11Device* device,const WCHAR* filename)
{
	bool result;

	_Texture = new TextureClass;
	if (!_Texture)
		return false;
	result = _Texture->Initialize(device, filename);
	if (!result)
		return false;

	return true;
}

void SpriteClass::ReleaseTexture()
{
	if (_Texture) {
		_Texture->Release();
		delete _Texture;
		_Texture = NULL;
	}
}

SpriteClass::SpriteClass()
{
	_VertexBuffer = NULL;
	_IndexBuffer = NULL;
	_Texture = NULL;
}

SpriteClass::SpriteClass(const SpriteClass& copy)
{
}

SpriteClass::~SpriteClass()
{
}


bool SpriteClass::Initialize(ID3D11Device* device, int screenWidth, int screenHeight,const WCHAR* textureFilename, int bitmapWidth, int bitmapHeight)
{
	bool result;

	_ScreenW  = screenWidth;
	_ScreenH = screenHeight;

	_BitmapW = bitmapWidth;
	_BitmapH = bitmapHeight;

	_PreviousPosX = -1;
	_PreviousPosY = -1;

	result = InitializeBuffers(device);
	if (!result) {
		return false;
	}

	result = LoadTexture(device, textureFilename);
	if (!result) {
		return false;
	}
	return true;

}

void SpriteClass::Release()
{
	ReleaseTexture();
	
	ReleaseBuffers();
}

bool SpriteClass::Render(ID3D11DeviceContext* deviceContext, float positionX, float positionY)
{
	bool result;

	result = UpdateBuffers(deviceContext, positionX, positionY);
	if (!result)
		return false;

	RenderBuffers(deviceContext);

	return true;
}

bool SpriteClass::Render(ID3D11DeviceContext* deviceContext, float positionX, float positionY, float sizeU, float sizeV, float posU, float posV)
{
	bool result;

	result = UpdateBuffers(deviceContext, sizeU, sizeV, posU, posV, positionX, positionY);
	if (!result)
		return false;

	RenderBuffers(deviceContext);

	return true;
}

int SpriteClass::GetIndexCount()
{
	return _IndexCount;
}

ID3D11ShaderResourceView* SpriteClass::GetTexture()
{
	return _Texture->GetTexture();
}
