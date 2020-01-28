#pragma once
class Mal_with_text :public ModelFileInfoClass
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
	list<SpriteObjectClass*> catshot;

	enermyObject* target;
public:
	static bool rightwork;
	Mal_with_text();
	Mal_with_text(const Mal_with_text& copy);
	~Mal_with_text();

	void setPos(float& posU, float& posV, int index);

	bool Initialize(HWND _hwnd, ID3D11Device* device,ID3D11DeviceContext* deviceContext, int screenx, int screeny, int bitx, int bity, const TCHAR* filepath, int textscreenW, int textscreenH, XMMATRIX baseViewMatrix);
	void Release();
	bool Process(float deltatime, float mx, float my, ID3D11DeviceContext* deviceContext);
	bool Render(ID3D11DeviceContext* deviceContext, XMMATRIX world, XMMATRIX view, XMMATRIX orthoM, XMMATRIX textorthoM, TextureShader* pTexShader);

	void shotcat(HWND _hwnd, ID3D11Device* device, int screenx, int screeny, int bitx, int bity);

	struct SentenceType
	{
		ID3D11Buffer* vertexBuffer, * indexBuffer;
		int vertexCount, indexCount, maxLength;
		float red, green, blue;
	};

	struct VertexType
	{
		XMFLOAT3 position;
		XMFLOAT2 texture;
	};

	FontClass* _Font;
	FontShader* _FontShader;
	int _ScreenWidth;
	int _screenHeight;
	XMMATRIX _BaseViewMatrix;
	SentenceType* _Sentence1;

	bool InitializeSentence(SentenceType** sentence, int maxLength, ID3D11Device* device);

	bool UpdateSentence(SentenceType* sentence, const char* text, int positionX, int positionY, float red, float green, float blue, ID3D11DeviceContext* deviceContext);
	void ReleaseSentence(SentenceType** sentence);
	bool RenderSentence(ID3D11DeviceContext* deviceContext, SentenceType* sentence, XMMATRIX worldMatrix, XMMATRIX orthoMatirx);


};

