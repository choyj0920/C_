#pragma once
class FontClass
{
	struct FontType
	{
		float left;
		float right;
		int size;
	};

	struct VertexType {
		XMFLOAT3 position;
		XMFLOAT2 texture;
	};

	FontType* _Font;
	TextureClass* _TextureC;

	bool LoadFontData(const TCHAR* filename);
	void ReleaseFontData();
	bool LoadTexture(ID3D11Device* device, const TCHAR* filename);
	void ReleaseTexture();
	float sizeX, sizeY;

public:
	FontClass();
	FontClass(const FontClass& copy);
	~FontClass();
	float getsizeX();
	float getsizeY();
	bool Initialize(ID3D11Device* device, const TCHAR* fontFilename, const TCHAR* textureFilename);
	void Release();
	ID3D11ShaderResourceView* GetTexture();
	void BuildVertexArray(void* vertices, const char*sentence, float drawX, float drawY);
};

