#pragma once
class ModelRect
{
	struct VertexType
	{
		XMFLOAT3 _Position;
		XMFLOAT4 _Color;
	};
private:
	//�������� ������ ������ �ִ� ����
	ID3D11Buffer* _VertexBuffer;
	//�׷����� ������ ������ �ִ� ����
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

