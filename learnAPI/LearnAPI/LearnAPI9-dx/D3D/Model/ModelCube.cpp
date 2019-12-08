#include "../../framework.h"

ModelCube::ModelCube()
{
	_VertexBuffer = NULL;
	_IndexBuffer = NULL;
}



ModelCube::~ModelCube()
{
}

bool ModelCube::Initialize(ID3D11Device* device)
{
	if (!InitializeBuffers(device))
		return false;

	return true;
}

void ModelCube::Release()
{
	// ���� ���ۿ� �ε��� ���۸� �����մϴ�.
	ReleaseBuffers();
}

void ModelCube::Render(ID3D11DeviceContext* deviceContext)
{
	// ���� ���ۿ� �ε��� ���۸� �׷��Ƚ� ���������ο� �־� ȭ�鿡 �׸� �غ� �մϴ�.
	RenderBuffers(deviceContext);
}

int ModelCube::GetIndexCount()
{
	return _IndexCount;
}

bool ModelCube::InitializeBuffers(ID3D11Device* device)
{
	VertexType* vertices;
	unsigned long* indices;
	D3D11_BUFFER_DESC vertexBufferDesc;
	D3D11_BUFFER_DESC indexBufferDesc;
	D3D11_SUBRESOURCE_DATA vertexData;
	D3D11_SUBRESOURCE_DATA indexData;
	HRESULT result;

	// ���� �迭�� ���̸� �����մϴ�.
	_VertexCount = 8;
	// �ε��� �迭�� ���̸� �����մϴ�.
	_IndexCount = 36;
	// ���� �迭�� �����մϴ�.
	vertices = new VertexType[_VertexCount];
	if (!vertices)
		return false;
	// �ε��� �迭�� �����մϴ�.
	indices = new unsigned long[_IndexCount];
	if (!indices)
		return false;

	// ���� �迭�� ���� �ֽ��ϴ�. -���� ��ü verterx 8�� 
	/*
		{ -3.0f, 3.0f, -3.0f, D3DCOLOR_XRGB(0, 0, 255), },
		{ 3.0f, 3.0f, -3.0f, D3DCOLOR_XRGB(0, 255, 0), },
		{ -3.0f, -3.0f, -3.0f, D3DCOLOR_XRGB(255, 0, 0), },
		{ 3.0f, -3.0f, -3.0f, D3DCOLOR_XRGB(0, 255, 255), },

		{ -3.0f, 3.0f, 3.0f, D3DCOLOR_XRGB(0, 0, 255), },
		{ 3.0f, 3.0f, 3.0f, D3DCOLOR_XRGB(255, 0, 0), },
		{ -3.0f, -3.0f, 3.0f, D3DCOLOR_XRGB(0, 255, 0), },
		{ 3.0f, -3.0f, 3.0f, D3DCOLOR_XRGB(0, 255, 255), },
*/

	for (int i = 0; i < 8; i++) {
		vertices[i]._Position = XMFLOAT3((i % 2 ? 1.0f : -1.0f), ((i % 4)/ 2 ? -1.0f : 1.0f), ((i / 4) ? 1.0f : -1.0f));
		vertices[i]._Color = XMFLOAT4((i == 2 || i == 5 ? 1.0f : 0.0f), (i == 1 || i == 3 || i == 6 || i == 7 ? 1.0f : 0.0f), (((i % 4) == 0 || (i % 4) == 3 )? 1.0f : 0.0f), 1.0f);
	}
	

	// �ε��� �迭�� ���� �ֽ��ϴ�.
	int index[] = {
		0, 1, 2,    // side 1
		2, 1, 3,
		4, 0, 6,    // side 2
		6, 0, 2,
		7, 5, 6,    // side 3
		6, 5, 4,
		3, 1, 7,    // side 4
		7, 1, 5,
		4, 5, 0,    // side 5
		0, 5, 1,
		3, 7, 2,    // side 6
		2, 7, 6,
	};
	for (int i = 0; i < _IndexCount/3; i++) {
		for (int j = 0; j < 3; j++) {
			indices[i * 3 + j] = index[i*3 + j];
		}
	}
	

	// ���� ������ description�� �ۼ��մϴ�.
	vertexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
	vertexBufferDesc.ByteWidth = sizeof(VertexType) * _VertexCount;
	vertexBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	vertexBufferDesc.CPUAccessFlags = 0;
	vertexBufferDesc.MiscFlags = 0;
	vertexBufferDesc.StructureByteStride = 0;

	// ���� �����͸� ����Ű�� ���� ���ҽ� ����ü�� �ۼ��մϴ�.
	vertexData.pSysMem = vertices;
	vertexData.SysMemPitch = 0;
	vertexData.SysMemSlicePitch = 0;

	// ���� ���۸� �����մϴ�.
	result = device->CreateBuffer(&vertexBufferDesc, &vertexData, &_VertexBuffer);
	if (FAILED(result))
		return false;

	// �ε��� ������ description�� �ۼ��մϴ�.
	indexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
	indexBufferDesc.ByteWidth = sizeof(unsigned long) * _IndexCount;
	indexBufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
	indexBufferDesc.CPUAccessFlags = 0;
	indexBufferDesc.MiscFlags = 0;
	indexBufferDesc.StructureByteStride = 0;

	// �ε��� �����͸� ����Ű�� ���� ���ҽ� ����ü�� �ۼ��մϴ�.
	indexData.pSysMem = indices;
	indexData.SysMemPitch = 0;
	indexData.SysMemSlicePitch = 0;

	// �ε��� ���۸� �����մϴ�.
	result = device->CreateBuffer(&indexBufferDesc, &indexData, &_IndexBuffer);
	if (FAILED(result))
		return false;

	// �����ǰ� ���� �Ҵ�� ���� ���ۿ� �ε��� ���۸� �����մϴ�.
	delete[] vertices;
	vertices = NULL;
	delete[] indices;
	indices = NULL;

	return true;
}

void ModelCube::ReleaseBuffers()
{
	// �ε��� ���۸� �����մϴ�.
	if (_IndexBuffer)
	{
		_IndexBuffer->Release();
		_IndexBuffer = NULL;
	}
	// ���� ���۸� �����մϴ�.
	if (_VertexBuffer)
	{
		_VertexBuffer->Release();
		_VertexBuffer = NULL;
	}
	return;
}

void ModelCube::RenderBuffers(ID3D11DeviceContext* deviceContext)
{
	unsigned int stride;
	unsigned int offset;
	// ���� ������ ������ �������� �����մϴ�.
	stride = sizeof(VertexType);
	offset = 0;

	// input assembler�� ���� ���۸� Ȱ��ȭ�Ͽ� �׷��� �� �ְ� �մϴ�.
	deviceContext->IASetVertexBuffers(0, 1, &_VertexBuffer, &stride, &offset);
	// input assembler�� �ε��� ���۸� Ȱ��ȭ�Ͽ� �׷��� �� �ְ� �մϴ�.
	deviceContext->IASetIndexBuffer(_IndexBuffer, DXGI_FORMAT_R32_UINT, 0);
	// ���� ���۷� �׸� �⺻���� �����մϴ�. ���⼭�� �ﰢ���Դϴ�.
	deviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

}
