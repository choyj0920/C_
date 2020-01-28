#pragma once
class SpriteObjectClass
{
	float _posX, _posY;
	float _MoveSpeed;
	SpriteClass* _Model;
	bool _movePx;
	float _checkTime;
	float _sizex, _sizey;

public:
	SpriteObjectClass();
	SpriteObjectClass(const SpriteObjectClass& copy);
	~SpriteObjectClass();
	
	bool Initialize(HWND _hwnd, ID3D11Device* device, int screenx, int screeny, int bitx, int bity);
	bool Initialize(HWND _hwnd, ID3D11Device* device, int screenx, int screeny, int bitx, int bity, int posx, int posy,bool movePx);
	void Release();
	bool Process(float deltatime, float mx, float my);
	bool Process(float deltatime);
	
	bool isoutboundry();

	float getposX();
	float getposY();
	float getsizeY();
	float getsizeX();
	bool Render(ID3D11DeviceContext* deviceContext, XMMATRIX world, XMMATRIX view, XMMATRIX orthoM, TextureShader* pTexShader);
};

