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
	// 정점 버퍼와 인덱스 버퍼를 해제합니다.
	ReleaseBuffers();
}

void ModelCube::Render(ID3D11DeviceContext* deviceContext)
{
	// 정점 버퍼와 인덱스 버퍼를 그래픽스 파이프라인에 넣어 화면에 그릴 준비를 합니다.
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

	// 정점 배열의 길이를 설정합니다.
	_VertexCount = 8;
	// 인덱스 배열의 길이를 설정합니다.
	_IndexCount = 36;
	// 정점 배열을 생성합니다.
	vertices = new VertexType[_VertexCount];
	if (!vertices)
		return false;
	// 인덱스 배열을 생성합니다.
	indices = new unsigned long[_IndexCount];
	if (!indices)
		return false;

	// 정점 배열에 값을 넣습니다. -정육 면체 verterx 8개 
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
	

	// 인덱스 배열에 값을 넣습니다.
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
	

	// 정점 버퍼의 description을 작성합니다.
	vertexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
	vertexBufferDesc.ByteWidth = sizeof(VertexType) * _VertexCount;
	vertexBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	vertexBufferDesc.CPUAccessFlags = 0;
	vertexBufferDesc.MiscFlags = 0;
	vertexBufferDesc.StructureByteStride = 0;

	// 정점 데이터를 가리키는 보조 리소스 구조체를 작성합니다.
	vertexData.pSysMem = vertices;
	vertexData.SysMemPitch = 0;
	vertexData.SysMemSlicePitch = 0;

	// 정점 버퍼를 생성합니다.
	result = device->CreateBuffer(&vertexBufferDesc, &vertexData, &_VertexBuffer);
	if (FAILED(result))
		return false;

	// 인덱스 버퍼의 description을 작성합니다.
	indexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
	indexBufferDesc.ByteWidth = sizeof(unsigned long) * _IndexCount;
	indexBufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
	indexBufferDesc.CPUAccessFlags = 0;
	indexBufferDesc.MiscFlags = 0;
	indexBufferDesc.StructureByteStride = 0;

	// 인덱스 데이터를 가리키는 보조 리소스 구조체를 작성합니다.
	indexData.pSysMem = indices;
	indexData.SysMemPitch = 0;
	indexData.SysMemSlicePitch = 0;

	// 인덱스 버퍼를 생성합니다.
	result = device->CreateBuffer(&indexBufferDesc, &indexData, &_IndexBuffer);
	if (FAILED(result))
		return false;

	// 생성되고 값이 할당된 정점 버퍼와 인덱스 버퍼를 해제합니다.
	delete[] vertices;
	vertices = NULL;
	delete[] indices;
	indices = NULL;

	return true;
}

void ModelCube::ReleaseBuffers()
{
	// 인덱스 버퍼를 해제합니다.
	if (_IndexBuffer)
	{
		_IndexBuffer->Release();
		_IndexBuffer = NULL;
	}
	// 정점 버퍼를 해제합니다.
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
	// 정점 버퍼의 단위와 오프셋을 설정합니다.
	stride = sizeof(VertexType);
	offset = 0;

	// input assembler에 정점 버퍼를 활성화하여 그려질 수 있게 합니다.
	deviceContext->IASetVertexBuffers(0, 1, &_VertexBuffer, &stride, &offset);
	// input assembler에 인덱스 버퍼를 활성화하여 그려질 수 있게 합니다.
	deviceContext->IASetIndexBuffer(_IndexBuffer, DXGI_FORMAT_R32_UINT, 0);
	// 정점 버퍼로 그릴 기본형을 설정합니다. 여기서는 삼각형입니다.
	deviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

}
