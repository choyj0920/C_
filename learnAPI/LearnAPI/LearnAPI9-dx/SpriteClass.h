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
	int _ScreenW;
	int _ScreenH;
	int _BitmapW;
	int _BitmapH;
	int _PreviousPosX;
	int _PreviousPosY;

	bool InitializeBuffers(ID3D11Device* device);
	void ReleaseBuffers();
	bool UpdateBuffers(ID3D11DeviceContext* deviceContext, int positionX, int positionY);
	void RenderBuffers(ID3D11DeviceContext* deviceContext);
	bool LoadTexture(ID3D11Device* device,const WCHAR* filename);
	void ReleaseTexture();

public:
	SpriteClass();
	SpriteClass(const SpriteClass& copy);
	~SpriteClass();

	bool Initialize(ID3D11Device* device,int screenWidth,int screenHeight,const WCHAR* textureFilename,int bitmapWidth , int bitmapHeight);
	void Release();
	bool Render(ID3D11DeviceContext* deviceContext,int positionX ,int positionY);
	int GetIndexCount();
	ID3D11ShaderResourceView* GetTexture();

};

