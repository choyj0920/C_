#include "../framework.h"

ModelTraingle::ModelTraingle()
{
	_VertexBuffer = NULL;
	_IndexBuffer = NULL;
}



ModelTraingle::~ModelTraingle()
{
}

bool ModelTraingle::Initialize(ID3D11Device* device)
{
	if (!InitializeBuffers(device))
		return false;

	return true;
}

void ModelTraingle::Release()
{
	// 정점 버퍼와 인덱스 버퍼를 해제합니다.
	ReleaseBuffers();
}

void ModelTraingle::Render(ID3D11DeviceContext* deviceContext)
{
	// 정점 버퍼와 인덱스 버퍼를 그래픽스 파이프라인에 넣어 화면에 그릴 준비를 합니다.
	RenderBuffers(deviceContext);
}

int ModelTraingle::GetIndexCount()
{
	return _IndexCount;
}

bool ModelTraingle::InitializeBuffers(ID3D11Device* device)
{
	VertexType* vertices;
	unsigned long* indices;
	D3D11_BUFFER_DESC vertexBufferDesc;
	D3D11_BUFFER_DESC indexBufferDesc;
	D3D11_SUBRESOURCE_DATA vertexData;
	D3D11_SUBRESOURCE_DATA indexData;
	HRESULT result;

	// 정점 배열의 길이를 설정합니다.
	_VertexCount = 3;
	// 인덱스 배열의 길이를 설정합니다.
	_IndexCount = 3;
	// 정점 배열을 생성합니다.
	vertices = new VertexType[_VertexCount];
	if (!vertices)
		return false;
	// 인덱스 배열을 생성합니다.
	indices = new unsigned long[_IndexCount];
	if (!indices)
		return false;

	// 정점 배열에 값을 넣습니다.
	vertices[0]._Position = XMFLOAT3(-1.0f, -1.0f, 0.0f); // 왼쪽 아래 
	vertices[0]._Color = XMFLOAT4(0.0f, 0.0f, 1.0f, 1.0f);

	vertices[1]._Position = XMFLOAT3(0.0f, 1.0f, 0.0f); // 상단 가운데 
	vertices[1]._Color = XMFLOAT4(0.0f, 1.0f, 0.0f, 1.0f);

	vertices[2]._Position = XMFLOAT3(1.0f, -1.0f, 0.0f); // 오른쪽 아래
	vertices[2]._Color = XMFLOAT4(1.0f, 0.0f, 0.0f, 1.0f);

	// 인덱스 배열에 값을 넣습니다.
	indices[0] = 0; // 왼쪽 아래 Bottom left.
	indices[1] = 1; // 상단 가운데
	indices[2] = 2; // 오른쪽 아래

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

void ModelTraingle::ReleaseBuffers()
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

void ModelTraingle::RenderBuffers(ID3D11DeviceContext* deviceContext)
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
