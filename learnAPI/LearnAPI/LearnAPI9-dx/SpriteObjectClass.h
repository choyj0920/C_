#pragma once
class SpriteObjectClass
{
	float _posX, _posY;
	float _MoveSpeed;
	SpriteClass* _Model;

public:
	SpriteObjectClass();
	SpriteObjectClass(const SpriteObjectClass& copy);
	~SpriteObjectClass();
	
	bool Initialize(HWND _hwnd, ID3D11Device* device, int screenx, int screeny, int bitx, int bity);
	void Release();
	bool Process(float deltatime, float mx, float my);
	
	bool Render(ID3D11DeviceContext* deviceContext, XMMATRIX world, XMMATRIX view, XMMATRIX orthoM, TextureShader* pTexShader);
};

