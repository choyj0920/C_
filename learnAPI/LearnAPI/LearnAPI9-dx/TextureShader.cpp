#include "framework.h"
#include "D3DUtilClass.h"

TextureShader::TextureShader()
{
	_VertexShader = NULL;
	_PixelShader = NULL;
	_Layout = NULL;
	_MatrixBuffer = NULL;
	_SampleState = NULL;
}

TextureShader::TextureShader(const TextureShader& copy)
{
}

TextureShader::~TextureShader()
{
}

bool TextureShader::Initiallize(ID3D11Device* device, HWND hwnd)
{
	bool result;
	//���� ���̴��� �ȼ� ���̴��� �ʱ�ȭ�մϴ�.
	result = InitShader(device, hwnd, _T("D3D\\Shader\\Texture.vs"), _T("D3D\\Shader\\Texture.ps"));
	if (!result)
		return false;

	return true;
}

void TextureShader::Release()
{
	// ���� ���̴��� �Ƚ� ���̴� �� �׿� ���õ� �͵��� ��ȯ�մϴ�.
	ReleaseShader();
}

bool TextureShader::Render(ID3D11DeviceContext* deviceContext, int indexCount, XMMATRIX world, XMMATRIX view, XMMATRIX projection, ID3D11ShaderResourceView*texture)
{
	bool result;
	// �������� ����� ���̴��� ���ڸ� �Է��մϴ�.
	result = SetShaderParameters(deviceContext, world, view, projection, texture);
	if (!result)
		return false;

	// ���̴��� �̿��Ͽ� �غ�� ���۸� �׸��ϴ�.
	RenderShader(deviceContext, indexCount);

	return true;
}


bool TextureShader::InitShader(ID3D11Device* device, HWND hwnd, const TCHAR* vsFilename, const TCHAR* psFilename)
{
	HRESULT result;
	ID3D10Blob* errorMessage;
	ID3D10Blob* vertexShaderBuffer;
	ID3D10Blob* pixelShaderBuffer;
	D3D11_INPUT_ELEMENT_DESC polygonLayout[2];
	unsigned int numElements;
	D3D11_BUFFER_DESC matrixBufferDesc;
	D3D11_SAMPLER_DESC samplerDesc;

	//�� �Լ����� ����ϴ� �����͵��� null�� �����մϴ�.
	errorMessage = NULL;
	vertexShaderBuffer = NULL;
	pixelShaderBuffer = NULL;

	//�������̴��� ������ �մϴ�.
	result = D3DCompileFromFile(vsFilename, NULL, NULL, "TextureVertexShader", "vs_5_0",
		D3D10_SHADER_ENABLE_STRICTNESS, NULL, &vertexShaderBuffer, &errorMessage);
	if (FAILED(result))
	{
		// ���̴��� �����Ͽ� �����ϸ� ���� �޼����� ����մϴ�.
		if (errorMessage)
		{
			OutputShaderErrorMessage(errorMessage, hwnd, vsFilename);
		}
		// ���� �޼����� ���ٸ� ���̴� ������ ã�� ���� ���Դϴ�.
		else
		{
			MessageBox(hwnd, vsFilename, L"Missing Shader File", MB_OK);
		}

		return false;
	}
	//�ȼ��ſ����� ������ �մϴ�.
	result = D3DCompileFromFile(psFilename, NULL, NULL, "TexturePixelShader", "ps_5_0",
		D3D10_SHADER_ENABLE_STRICTNESS, NULL, &pixelShaderBuffer, &errorMessage);
	if (FAILED(result))
	{
		// ���̴� �������� �����ϸ� ���� �޼����� ����մϴ�.
		if (errorMessage)
		{
			OutputShaderErrorMessage(errorMessage, hwnd, psFilename);
		}
		// ���� �޼����� ���ٸ� �ܼ��� ���̴� ������ ã�� ���� ���Դϴ�.
		else
		{
			MessageBox(hwnd, psFilename, L"Missing Shader File", MB_OK);
		}

		return false;
	}

	// ���۷κ��� ���� ���̴��� �����մϴ�.
	result = device->CreateVertexShader(vertexShaderBuffer->GetBufferPointer(),
		vertexShaderBuffer->GetBufferSize(), NULL, &_VertexShader);
	if (FAILED(result))
		return false;

	// ���۷κ��� �ȼ� ���̴��� �����մϴ�.
	result = device->CreatePixelShader(pixelShaderBuffer->GetBufferPointer(),
		pixelShaderBuffer->GetBufferSize(), NULL, &_PixelShader);
	if (FAILED(result))
		return false;
	// ���� �Է� ���̾ƿ� description�� �ۼ��մϴ�.
// �� ������ ModelClass�� ���̴��� �ִ� VertexType�� ��ġ�ؾ� �մϴ�.
	polygonLayout[0].SemanticName = "POSITION";
	polygonLayout[0].SemanticIndex = 0;
	polygonLayout[0].Format = DXGI_FORMAT_R32G32B32_FLOAT;
	polygonLayout[0].InputSlot = 0;
	polygonLayout[0].AlignedByteOffset = 0;
	polygonLayout[0].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
	polygonLayout[0].InstanceDataStepRate = 0;

	polygonLayout[1].SemanticName = "TEXCOORD";
	polygonLayout[1].SemanticIndex = 0;
	polygonLayout[1].Format = DXGI_FORMAT_R32G32_FLOAT;
	polygonLayout[1].InputSlot = 0;
	polygonLayout[1].AlignedByteOffset = D3D11_APPEND_ALIGNED_ELEMENT;
	polygonLayout[1].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
	polygonLayout[1].InstanceDataStepRate = 0;

	// ���̾ƿ��� ��� ������ �����ɴϴ�.
	numElements = sizeof(polygonLayout) / sizeof(polygonLayout[0]);
	// ���� �Է� ���̾ƿ��� �����մϴ�.
	result = device->CreateInputLayout(polygonLayout, numElements, vertexShaderBuffer->GetBufferPointer(),
		vertexShaderBuffer->GetBufferSize(), &_Layout);
	if (FAILED(result))
		return false;

	// �� �̻� ������ �ʴ� ���� ���̴� �۹��� �ȼ� ���̴� ���۸� �����մϴ�.
	vertexShaderBuffer->Release();
	vertexShaderBuffer = 0;
	pixelShaderBuffer->Release();
	pixelShaderBuffer = 0;

	// ���� ���̴��� �ִ� ��� ��� ������ description�� �ۼ��մϴ�.
	matrixBufferDesc.Usage = D3D11_USAGE_DYNAMIC;
	matrixBufferDesc.ByteWidth = sizeof(MatrixBufferType);
	matrixBufferDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	matrixBufferDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
	matrixBufferDesc.MiscFlags = 0;
	matrixBufferDesc.StructureByteStride = 0;

	// ��� ���� �����͸� ����� �� Ŭ�������� ���� ���̴� ��� ���ۿ� ������ �� �ְ� �մϴ�.
	result = device->CreateBuffer(&matrixBufferDesc, NULL, &_MatrixBuffer);
	if (FAILED(result))
		return false;

	samplerDesc.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;
	samplerDesc.AddressU = D3D11_TEXTURE_ADDRESS_WRAP;
	samplerDesc.AddressV = D3D11_TEXTURE_ADDRESS_WRAP;
	samplerDesc.AddressW = D3D11_TEXTURE_ADDRESS_WRAP;

	samplerDesc.MipLODBias = 0.0f;
	samplerDesc.MaxAnisotropy = 1;
	samplerDesc.ComparisonFunc = D3D11_COMPARISON_ALWAYS;
	samplerDesc.BorderColor[0] = 0;
	samplerDesc.BorderColor[1] = 0;
	samplerDesc.BorderColor[2] = 0;
	samplerDesc.BorderColor[3] = 0;
	samplerDesc.MinLOD = 0;
	samplerDesc.MaxLOD = D3D11_FLOAT32_MAX;
	result = device->CreateSamplerState(&samplerDesc, &_SampleState);
	if (FAILED(result)) {
		return false;
	}


	return true;
}

void TextureShader::ReleaseShader()
{
	// ��� ���۸� �����մϴ�.
	if (_MatrixBuffer)
	{
		_MatrixBuffer->Release();
		_MatrixBuffer = 0;
	}

	if (_SampleState)
	{
		_SampleState->Release();
		_SampleState = 0;
	}

	// ���̾ƿ��� �����մϴ�.
	if (_Layout)
	{
		_Layout->Release();
		_Layout = 0;
	}

	// �ȼ� ���̴��� �����մϴ�.
	if (_PixelShader)
	{
		_PixelShader->Release();
		_PixelShader = 0;
	}

	// ���� ���̴��� �����մϴ�.
	if (_VertexShader)
	{
		_VertexShader->Release();
		_VertexShader = 0;
	}

	return;
}

bool TextureShader::SetShaderParameters(ID3D11DeviceContext* deviceContext, XMMATRIX worldMatrix,
	XMMATRIX viewMatrix, XMMATRIX projectionMatrix, ID3D11ShaderResourceView*texture)
{
	HRESULT result;
	D3D11_MAPPED_SUBRESOURCE mappedResource;
	MatrixBufferType* dataPtr;
	unsigned int bufferNumber;

	// ����� transpose�Ͽ� ���̴����� ����� �� �ְ� �մϴ�.
	worldMatrix = XMMatrixTranspose(worldMatrix);
	viewMatrix = XMMatrixTranspose(viewMatrix);
	projectionMatrix = XMMatrixTranspose(projectionMatrix);

	// ��� ������ ������ �� �� �ֵ��� ��޴ϴ�.
	result = deviceContext->Map(_MatrixBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedResource);
	if (FAILED(result))
		return false;

	// ��� ������ �����Ϳ� ���� �����͸� �����ɴϴ�.
	dataPtr = (MatrixBufferType*)mappedResource.pData;

	// ��� ���ۿ� ����� �����մϴ�.
	dataPtr->world = worldMatrix;
	dataPtr->view = viewMatrix;
	dataPtr->projection = projectionMatrix;

	// ��� ������ ����� Ǳ�ϴ�.
	deviceContext->Unmap(_MatrixBuffer, 0);

	// ���� ���̴������� ��� ������ ��ġ�� �����մϴ�.
	bufferNumber = 0;

	// ���������� ���� ���̴��� ��� ���۸� �ٲ� ������ �ٲߴϴ�.
	deviceContext->VSSetConstantBuffers(bufferNumber, 1, &_MatrixBuffer);
	
	deviceContext->PSSetShaderResources(0, 1, &texture);

	return true;
}

void TextureShader::RenderShader(ID3D11DeviceContext* deviceContext, int indexCount)
{
	// ���� �Է� ���̾ƿ��� �����մϴ�.
	deviceContext->IASetInputLayout(_Layout);


	// �ﰢ���� �׸� ���� ���̴��� �ȼ� ���̴��� �����մϴ�.
	deviceContext->VSSetShader(_VertexShader, NULL, 0);
	deviceContext->PSSetShader(_PixelShader, NULL, 0);

	deviceContext->PSSetSamplers(0, 1, &_SampleState);

	// �ﰢ���� �׸��ϴ�.
	deviceContext->DrawIndexed(indexCount, 0, 0);

	return;
}

