#pragma once

class TextureShader
{
	struct MatrixBufferType {
		XMMATRIX world;
		XMMATRIX view;
		XMMATRIX projection;
	};
	ID3D11VertexShader* _VertexShader;
	ID3D11PixelShader* _PixelShader;
	ID3D11InputLayout* _Layout;
	ID3D11Buffer* _MatrixBuffer;
	ID3D11SamplerState* _SampleState;

public:
	TextureShader();
	TextureShader(const TextureShader& copy);
	~TextureShader();

	bool Initiallize(ID3D11Device* device, HWND hwnd);
	void Release();
	bool Render(ID3D11DeviceContext*, int, XMMATRIX world, XMMATRIX view, XMMATRIX projection, ID3D11ShaderResourceView*);

private:
	bool InitShader(ID3D11Device* device, HWND hwnd, const TCHAR* vsFilename, const TCHAR* psFilename);
	void ReleaseShader();

	bool SetShaderParameters(ID3D11DeviceContext* devicecontext, XMMATRIX world, XMMATRIX view, XMMATRIX projection,ID3D11ShaderResourceView*);
	void RenderShader(ID3D11DeviceContext*, int);
};


