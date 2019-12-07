#pragma once
class ModelRect
{
	struct VertexType
	{
		XMFLOAT3 _Position;
		XMFLOAT4 _Color;
	};
private:
	//꼭짓점의 정보를 가지고 있는 버퍼
	ID3D11Buffer* _VertexBuffer;
	//그려지는 순서를 가지고 있는 버퍼
	ID3D11Buffer* _IndexBuffer;
	int _VertexCount;
	int _IndexCount;

public:
	ModelRect();
	ModelRect(const ModelRect& copy);
	~ModelRect();

	bool Initialize(ID3D11Device* device);
	void Release();
	void Render(ID3D11DeviceContext* deviceContext);
	int GetIndexCount();
private:
	bool InitializeBuffers(ID3D11Device* device);
	void ReleaseBuffers();
	void RenderBuffers(ID3D11DeviceContext* deviceContext);

};

