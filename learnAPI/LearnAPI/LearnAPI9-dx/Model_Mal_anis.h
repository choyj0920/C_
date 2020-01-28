#pragma once
class Model_mal2:public ModelFileInfoClass
{
	float _posX, _posY;
	float _MoveSpeed;
	float _posU;
	float _posV;
	float _sizeU;
	float _sizeV;
	float _CheckTime;
	int _ani_count;
	PlayerAnimationType _AniType;
	
	SpriteClass* _Model;
		
public:
	static bool rightwork;
	Model_mal2();
	Model_mal2(const Model_mal2& copy);
	~Model_mal2();
	
	void setPos(float& posU, float& posV, int count);

	bool Initialize(HWND _hwnd, ID3D11Device* device, int screenx, int screeny, int bitx, int bity,const TCHAR* filepath);
	void Release();
	bool Process(float deltatime, float mx, float my);
	bool Render(ID3D11DeviceContext* deviceContext, XMMATRIX world, XMMATRIX view, XMMATRIX orthoM, TextureShader* pTexShader);
};

