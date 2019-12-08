#pragma once
class TextureClass
{
	ID3D11ShaderResourceView* _Texture;
	HRESULT CreateShaderResourceViewFromFile(ID3D11Device* device, const TCHAR*filename, const TCHAR* ext);

public:
	TextureClass();
	TextureClass(const TextureClass& other);
	~TextureClass();
	
	bool Initialize(ID3D11Device* device, const TCHAR* filename);
	void Release();

	ID3D11ShaderResourceView* GetTexture();

};

