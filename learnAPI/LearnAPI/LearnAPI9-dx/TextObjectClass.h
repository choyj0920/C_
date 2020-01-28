#pragma once
class TextObjectClass
{
	struct SentenceType
	{
		ID3D11Buffer *vertexBuffer, * indexBuffer;
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
	SentenceType* _Sentence2;

	bool InitializeSentence(SentenceType** sentence, int maxLength, ID3D11Device* device);

	bool UpdateSentence(SentenceType* sentence, const char* text, int positionX, int positionY, float red, float green, float blue, ID3D11DeviceContext* deviceContext);
	void ReleaseSentence(SentenceType** sentence);
	bool RenderSentence(ID3D11DeviceContext* deviceContext, SentenceType*sentence, XMMATRIX worldMatrix, XMMATRIX orthoMatirx);

public:
	TextObjectClass();
	TextObjectClass(const TextObjectClass& copy);
	~TextObjectClass();

	bool Initialize(ID3D11Device* device, ID3D11DeviceContext* deviceContext, HWND hwnd, int screenWidth, int screenHeight, XMMATRIX baseViewMatrix);
	void Release();
	bool Render(ID3D11DeviceContext* deviceContext, XMMATRIX, XMMATRIX);

};

