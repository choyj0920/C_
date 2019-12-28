#pragma once
class SpriteClass
{
	struct VertexType
	{
		XMFLOAT3 position;
		XMFLOAT2 texture;
	};
private:
	//꼭짓점의 정보를 가지고 있는 버퍼
	ID3D11Buffer* _VertexBuffer;
	//그려지는 순서를 가지고 있는 버퍼
	ID3D11Buffer* _IndexBuffer;
	int _VertexCount;
	int _IndexCount;
	TextureClass* _Texture;
	float _ScreenW;
	float _ScreenH;
	float _BitmapW;
	float _BitmapH;
	int _PreviousPosX;
	int _PreviousPosY;

	bool InitializeBuffers(ID3D11Device* device);
	void ReleaseBuffers();
	bool UpdateBuffers(ID3D11DeviceContext* deviceContext, float positionX, float positionY);
	bool UpdateBuffers(ID3D11DeviceContext* deviceContext, float sizeU, float sizeV, float posU, float posV, float positionX, float positionY);
	void RenderBuffers(ID3D11DeviceContext* deviceContext);
	bool LoadTexture(ID3D11Device* device,const WCHAR* filename);
	void ReleaseTexture();

public:
	SpriteClass();
	SpriteClass(const SpriteClass& copy);
	~SpriteClass();
	bool Initialize(ID3D11Device* device,int screenWidth,int screenHeight,const WCHAR* textureFilename,int bitmapWidth , int bitmapHeight);
	void Release();
	bool Render(ID3D11DeviceContext* deviceContext,float positionX , float positionY);
	bool Render(ID3D11DeviceContext* deviceContext, float positionX, float positionY, float sizeU, float sizeV, float posU, float posV);
	int GetIndexCount();
	ID3D11ShaderResourceView* GetTexture();

};

