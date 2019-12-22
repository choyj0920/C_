#include"framework.h"

HRESULT TextureClass::CreateShaderResourceViewFromFile(ID3D11Device* device, const TCHAR* filename, const TCHAR* ext)
{
	TexMetadata imageMetadata;
	ScratchImage ScratchImgage;

	HRESULT hr;
	if (_wcsicmp(ext, L".dds") == 0)
	{
		hr = LoadFromDDSFile(filename, DDS_FLAGS_NONE, 0, ScratchImgage);
	}
	else if (_wcsicmp(ext, L".tga") == 0) {
		hr = LoadFromTGAFile(filename, 0, ScratchImgage);
	}
	else if (_wcsicmp(ext, L".hdr") == 0) {
		hr = LoadFromHDRFile(filename, nullptr, ScratchImgage);
	}
	else {
		hr = LoadFromWICFile(filename, WIC_FLAGS_NONE, 0, ScratchImgage);
	}
	if (SUCCEEDED(hr)) {
		hr = CreateShaderResourceView(device, ScratchImgage.GetImages(), ScratchImgage.GetImageCount(),
			ScratchImgage.GetMetadata(), &_Texture);
	}
	return hr;
}

TextureClass::TextureClass()
{
	_Texture = NULL;
}

TextureClass::TextureClass(const TextureClass& other)
{
}

TextureClass::~TextureClass()
{
}

bool TextureClass::Initialize(ID3D11Device* device, const TCHAR* filename)
{
	HRESULT result;

	TCHAR ext[_MAX_EXT];
	TCHAR name[_MAX_EXT];
	//_wsplitpath(filename, 0, 0, name, ext);

	result = CreateShaderResourceViewFromFile(device, filename, ext);
	if (FAILED(result))
		return false;
	return true;

}

void TextureClass::Release()
{
	if (_Texture != NULL) {
		_Texture->Release();
		_Texture = 0;
	}
}

ID3D11ShaderResourceView* TextureClass::GetTexture()
{
	return _Texture;
}
