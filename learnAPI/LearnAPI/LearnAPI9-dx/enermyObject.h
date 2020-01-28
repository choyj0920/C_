#pragma once
class enermyObject
{
	float _posX, _posY;
	float _MoveSpeed;
	SpriteClass* _Model;
	bool _movePy;
	float _checkTime;
	float _sizeX, _sizeY;

public:
	enermyObject();
	enermyObject(const enermyObject& copy);
	~enermyObject();

	bool Initialize(HWND _hwnd, ID3D11Device* device, int screenx, int screeny, int bitx, int bity);
	void Release();
	bool Process(float deltatime);

	bool istriger(SpriteObjectClass* cat);
	void isupspeed();
	bool Render(ID3D11DeviceContext* deviceContext, XMMATRIX world, XMMATRIX view, XMMATRIX orthoM, TextureShader* pTexShader);
};

