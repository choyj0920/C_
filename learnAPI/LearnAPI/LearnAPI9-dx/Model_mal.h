#pragma once
class Model_mal
{
	float _posX, _posY;
	float _MoveSpeed;
	float _posU;
	float _posV;
	float _sizeU;
	float _sizeV;
	float _CheckTime;
	SpriteClass* _Model;

public:
	Model_mal();
	Model_mal(const Model_mal& copy);
	~Model_mal();

	bool Initialize(HWND _hwnd, ID3D11Device* device, int screenx, int screeny, int bitx, int bity);
	void Release();
	bool Process(float deltatime, float mx, float my);
	bool Render(ID3D11DeviceContext* deviceContext, XMMATRIX world, XMMATRIX view, XMMATRIX orthoM, TextureShader* pTexShader);
};

