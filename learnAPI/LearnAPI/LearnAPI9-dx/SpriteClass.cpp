#include "framework.h"

bool SpriteClass::InitializeBuffers(ID3D11Device* device)
{
	VertexType* vertices;
	unsigned long* indices;
	D3D11_BUFFER_DESC vertexBufferDesc, indexBufferDesc;
	D3D11_SUBRESOURCE_DATA vertexData, indexData;
	HRESULT result;
	int i;

	// ���� �迭�� �������� �����մϴ�.
	_VertexCount = 6;
	//�ε��� �迭�� �ε����� ����
	_IndexCount = _VertexCount;

	//���ؽ� �迭 �����.
	vertices = new VertexType[_VertexCount];
	if (!vertices)
		return false;
	//�ε��� �迭 �����.
	indices = new unsigned long[_IndexCount];
	if (!indices)
		return false;
	//���� �����迭 0���� �ʱ�ȭ
	memset(vertices, 0, (sizeof(VertexType) * _VertexCount));

	for (i = 0; i < _IndexCount; i++) {
		indices[i] = i;
	}

	// ���� ���� ������ ������ �����Ѵ�.
	vertexBufferDesc.Usage = D3D11_USAGE_DYNAMIC;
	vertexBufferDesc.ByteWidth = sizeof(VertexType) * _IndexCount;
	vertexBufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
	vertexBufferDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
	vertexBufferDesc.MiscFlags = 0;
	vertexBufferDesc.StructureByteStride = 0;

	//���� ���ҽ� ������ ���� �����Ϳ� ���� �����͸� �ο��մϴ�.
	vertexData.pSysMem = vertices;
	vertexData.SysMemPitch = 0;
	vertexData.SysMemSlicePitch = 0;

	//���� ���ؽ� ���۸� ����ϴ�.
	result = device->CreateBuffer(&vertexBufferDesc, &vertexData, &_VertexBuffer);

	//���� �ε��� ���ۿ� ���� ���� ����
	indexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
	indexBufferDesc.ByteWidth = sizeof(unsigned long) * _IndexCount;
	indexBufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
	indexBufferDesc.CPUAccessFlags = 0;
	indexBufferDesc.MiscFlags = 0;
	indexBufferDesc.StructureByteStride = 0;

	//���� ���ҽ� ������ �ε��� �����͸� ����Ű�� ���� ���ҽ� ����ü�� �ۼ��մϴ�.
	indexData.pSysMem = indices;
	indexData.SysMemPitch = 0;
	indexData.SysMemSlicePitch = 0;

	// �ε��� ���۸� �����մϴ�.
	result = device->CreateBuffer(&indexBufferDesc, &indexData, &_IndexBuffer);
	if (FAILED(result))
		return false;

	// �����ǰ� ���� �Ҵ�� ���� ���ۿ� �ε��� ���۸� �����մϴ�.
	//���ؽ��� �ε��� ���۰� �����ǰ� �ε�� ���¿��� �迭�� �����ϴ�.
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
	
	//����� ��� �������� �Ǵ� ��ġ ������Ʈ
	_PreviousPosX = positionX;
	_PreviousPosY = positionY;

	//��Ʈ���� ���ʸ��� ȭ�� ��ǥ�� ����մϴ�,
	left = (float)((_ScreenW / 2) * -1) + (float)positionX;
	//��Ʈ���� �������� ȭ�� ��ǥ�� ���
	right = left+(float)_BitmapW;
	//��Ʈ�� ����� ȭ�� ��ǥ�� ����մϴ�.
	top = (float)((_ScreenH / 2) * -1) + (float)positionY;
	//��Ʈ���� �Ʒ��U�� ȭ�� ��ǥ�� ����Ͻʽÿ�.
	bottom = top - (float)_BitmapH;

	//���ؽ� �迭
	vertices = new VertexType[_VertexCount];
	if (!vertices)
		return false;
	
	//���ؽ� �迭�� ������ �ε�
	//ù���� �ﰢ��
	vertices[0].position = XMFLOAT3(left, top, 0.0f);
	vertices[0].texture = XMFLOAT2(0.0f, 0.0f);
	
	vertices[1].position = XMFLOAT3(right, bottom, 0.0f);
	vertices[1].texture = XMFLOAT2(1.0f, 1.0f);
	vertices[2].position = XMFLOAT3(left, bottom, 0.0f);
	vertices[2].texture = XMFLOAT2(0.0f, 1.0f);
	//�ι�°
	vertices[3].position = XMFLOAT3(left, top, 0.0f);
	vertices[3].texture = XMFLOAT2(0.0f, 0.0f);
	vertices[4].position = XMFLOAT3(right, top, 0.0f);
	vertices[4].texture = XMFLOAT2(01.0f, 0.0f);
	vertices[5].position = XMFLOAT3(right, bottom, 0.0f);
	vertices[5].texture = XMFLOAT2(1.0f, 1.0f);

	//���ؽ� ���۸� ���� �ֵ��� ��׽ʽÿ�.
	result = deviceContext->Map(_VertexBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedResource);
	if (FAILED(result))
		return false;

	//���ؽ� ������ �����Ϳ� ���� ������ ��������
	verticesPtr = (VertexType*)mappedResource.pData;

	//�����͸� ���� ���ۿ� �����մϴ�.
	memcpy(verticesPtr, (void*)vertices, (sizeof(VertexType) * _VertexCount));

	//���ؽ� ���� �������.
	deviceContext->Unmap(_VertexBuffer, 0);

	//���ؽ� �迭�� �� �̻� �ʿ����� �ʰ� �����Ͻʽÿ�.
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

	//�� ��Ʈ ���� �״��� �� ��ġ�� ������� ���� ��� ���� �����ٸ� �Ű������� �����Ƿ� ���� ���۸� ������Ʈ ���� �ʽ��ϴ�.
	/*if ((positionX == _PreviousPosX) && (positionY == _PreviousPosY))
		return true;*/

	//����� ��� �������� �Ǵ� ��ġ ������Ʈ
	_PreviousPosX = positionX;
	_PreviousPosY = positionY;

	//��Ʈ���� ���ʸ��� ȭ�� ��ǥ�� ����մϴ�,
	left = (float)((_ScreenW / 2) * -1) + (float)positionX;
	//��Ʈ���� �������� ȭ�� ��ǥ�� ���
	right = left + (float)_BitmapW;
	//��Ʈ�� ����� ȭ�� ��ǥ�� ����մϴ�.
	top = (float)((_ScreenH / 2) * -1) + (float)positionY;
	//��Ʈ���� �Ʒ��U�� ȭ�� ��ǥ�� ����Ͻʽÿ�.
	bottom = top - (float)_BitmapH;

	//���ؽ� �迭
	vertices = new VertexType[_VertexCount];
	if (!vertices)
		return false;

	//���ؽ� �迭�� ������ �ε�
	//ù���� �ﰢ��
	vertices[0].position = XMFLOAT3(left, top, 0.0f);
	vertices[0].texture = XMFLOAT2(posU, posV);

	vertices[1].position = XMFLOAT3(right, bottom, 0.0f);
	vertices[1].texture = XMFLOAT2(posU+sizeU, posV+sizeV);
	vertices[2].position = XMFLOAT3(left, bottom, 0.0f);
	vertices[2].texture = XMFLOAT2(posU, posV+sizeV);
	//�ι�°
	vertices[3].position = XMFLOAT3(left, top, 0.0f);
	vertices[3].texture = XMFLOAT2(posU, posV);
	vertices[4].position = XMFLOAT3(right, top, 0.0f);
	vertices[4].texture = XMFLOAT2(posU+sizeU, posV);
	vertices[5].position = XMFLOAT3(right, bottom, 0.0f);
	vertices[5].texture = XMFLOAT2(posU + sizeU , posV + sizeV);

	//���ؽ� ���۸� ���� �ֵ��� ��׽ʽÿ�.
	result = deviceContext->Map(_VertexBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedResource);
	if (FAILED(result))
		return false;

	//���ؽ� ������ �����Ϳ� ���� ������ ��������
	verticesPtr = (VertexType*)mappedResource.pData;

	//�����͸� ���� ���ۿ� �����մϴ�.
	memcpy(verticesPtr, (void*)vertices, (sizeof(VertexType) * _VertexCount));

	//���ؽ� ���� �������.
	deviceContext->Unmap(_VertexBuffer, 0);

	//���ؽ� �迭�� �� �̻� �ʿ����� �ʰ� �����Ͻʽÿ�.
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
