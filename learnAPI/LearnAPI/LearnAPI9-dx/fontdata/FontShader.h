#pragma once
class FontShader
{
	struct ConstantBufferType {
		XMMATRIX world;
		XMMATRIX view;
		XMMATRIX projection;
	};

	struct PixelBufferType {
		XMFLOAT4 pixelColor;
	};

	ID3D11VertexShader* _VertexShader;
	ID3D11PixelShader* _PixelShader;
	ID3D11InputLayout* _Layout;
	ID3D11Buffer* _ConstantBuffer;
	ID3D11SamplerState* _SampleState;
	ID3D11Buffer* _PixelBuffer;


private:
	bool InitializeShader(ID3D11Device* device, HWND hwnd, const TCHAR* vsFilename, const TCHAR* psFilename);
	void ReleaseShader();

	bool SetShaderParameters(ID3D11DeviceContext* devicecontext, XMMATRIX worldMatrix, XMMATRIX view, XMMATRIX projection, ID3D11ShaderResourceView*,XMFLOAT4 pixelColor);
	void RenderShader(ID3D11DeviceContext* deviceContext, int indexCount);


public:
	FontShader();
	FontShader(const FontShader& copy);
	~FontShader();

	bool Initiallize(ID3D11Device* device, HWND hwnd);
	void Release();
	bool Render(ID3D11DeviceContext* deviceContext, int indexCount, XMMATRIX world, XMMATRIX view, XMMATRIX projection, ID3D11ShaderResourceView*,XMFLOAT4 pixelColor);

};

