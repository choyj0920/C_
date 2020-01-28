#include "../framework.h"
#include "../D3DUtilClass.h"
bool FontShader::InitializeShader(ID3D11Device* device, HWND hwnd, const TCHAR* vsFilename, const TCHAR* psFilename)
{
	HRESULT result;
	ID3D10Blob* errorMessage;
	ID3D10Blob* vertexShaderBuffer;
	ID3D10Blob* pixelShaderBuffer;
	D3D11_INPUT_ELEMENT_DESC polygonLayout[2];
	unsigned int numElements;
	D3D11_BUFFER_DESC matrixBufferDesc;
	D3D11_BUFFER_DESC pixelBufferDesc;
	D3D11_SAMPLER_DESC samplerDesc;

	//이 함수에서 사용하는 포인터들을 null로 설정합니다.
	errorMessage = NULL;
	vertexShaderBuffer = NULL;
	pixelShaderBuffer = NULL;

	//정점셰이더를 컴파일 합니다.
	result = D3DCompileFromFile(vsFilename, NULL, NULL, "FontVertexShader", "vs_5_0",
		D3D10_SHADER_ENABLE_STRICTNESS, NULL, &vertexShaderBuffer, &errorMessage);
	if (FAILED(result))
	{
		// 셰이더가 컴파일에 실패하면 에러 메세지를 기록합니다.
		if (errorMessage)
		{
			OutputShaderErrorMessage(errorMessage, hwnd, vsFilename);
		}
		// 에러 메세지가 없다면 셰이더 파일을 찾지 못한 것입니다.
		else
		{
			MessageBox(hwnd, vsFilename, L"Missing Shader File", MB_OK);
		}

		return false;
	}
	//픽셀셔에더를 컴파일 합니다.
	result = D3DCompileFromFile(psFilename, NULL, NULL, "FontPixelShader", "ps_5_0",
		D3D10_SHADER_ENABLE_STRICTNESS, NULL, &pixelShaderBuffer, &errorMessage);
	if (FAILED(result))
	{
		// 셰이더 컴파일이 실패하면 에러 메세지를 기록합니다.
		if (errorMessage)
		{
			OutputShaderErrorMessage(errorMessage, hwnd, psFilename);
		}
		// 에러 메세지가 없다면 단순히 셰이더 파일을 찾지 못한 것입니다.
		else
		{
			MessageBox(hwnd, psFilename, L"Missing Shader File", MB_OK);
		}

		return false;
	}

	// 버퍼로부터 정점 셰이더를 생성합니다.
	result = device->CreateVertexShader(vertexShaderBuffer->GetBufferPointer(),
		vertexShaderBuffer->GetBufferSize(), NULL, &_VertexShader);
	if (FAILED(result))
		return false;

	// 버퍼로부터 픽셀 셰이더를 생성합니다.
	result = device->CreatePixelShader(pixelShaderBuffer->GetBufferPointer(),
		pixelShaderBuffer->GetBufferSize(), NULL, &_PixelShader);
	if (FAILED(result))
		return false;
	// 정점 입력 레이아웃 description을 작성합니다.
// 이 설정은 ModelClass와 셰이더에 있는 VertexType와 일치해야 합니다.
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

	// 레이아웃의 요소 갯수를 가져옵니다.
	numElements = sizeof(polygonLayout) / sizeof(polygonLayout[0]);
	// 정점 입력 레이아웃을 생성합니다.
	result = device->CreateInputLayout(polygonLayout, numElements, vertexShaderBuffer->GetBufferPointer(),
		vertexShaderBuffer->GetBufferSize(), &_Layout);
	if (FAILED(result))
		return false;

	// 더 이상 사용되지 않는 정점 셰이더 퍼버와 픽셀 셰이더 버퍼를 해제합니다.
	vertexShaderBuffer->Release();
	vertexShaderBuffer = 0;
	pixelShaderBuffer->Release();
	pixelShaderBuffer = 0;

	// 정점 셰이더에 있는 행렬 상수 버퍼의 description을 작성합니다.
	matrixBufferDesc.Usage = D3D11_USAGE_DYNAMIC;
	matrixBufferDesc.ByteWidth = sizeof(ConstantBufferType);
	matrixBufferDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	matrixBufferDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
	matrixBufferDesc.MiscFlags = 0;
	matrixBufferDesc.StructureByteStride = 0;

	// 상수 버퍼 포인터를 만들어 이 클래스에서 정점 셰이더 상수 버퍼에 접근할 수 있게 합니다.
	result = device->CreateBuffer(&matrixBufferDesc, NULL, &_ConstantBuffer);
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
	//텍스처 샘플러 상태를 만듬
	result = device->CreateSamplerState(&samplerDesc, &_SampleState);
	if (FAILED(result)) {
		return false;
	}
	//픽셀 쉐이더에 있는 동적 픽셀 상수 
	
	pixelBufferDesc.Usage = D3D11_USAGE_DYNAMIC;
	pixelBufferDesc.ByteWidth = sizeof(PixelBufferType);
	pixelBufferDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	pixelBufferDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
	pixelBufferDesc.MiscFlags = 0;
	pixelBufferDesc.StructureByteStride = 0;

	//이 클래스 내에서 픽셀 셔에더 상수 버퍼에 액세스 할 수 있도록 픽셀 상수 버퍼포인터를 만든다.
	result = device->CreateBuffer(&pixelBufferDesc, NULL, &_PixelBuffer);
	if (FAILED(result))
		return false;
	////

	return true;
}

void FontShader::ReleaseShader()
{
	// 상수 버퍼를 해제합니다.
	if (_ConstantBuffer)
	{
		_ConstantBuffer->Release();
		_ConstantBuffer = 0;
	}

	if (_SampleState)
	{
		_SampleState->Release();
		_SampleState = 0;
	}

	// 레이아웃을 해제합니다.
	if (_Layout)
	{
		_Layout->Release();
		_Layout = 0;
	}

	// 픽셀 셰이더를 해제합니다.
	if (_PixelShader)
	{
		_PixelShader->Release();
		_PixelShader = 0;
	}

	// 정점 셰이더를 해제합니다.
	if (_VertexShader)
	{
		_VertexShader->Release();
		_VertexShader = 0;
	}
	// 픽셀 셰이더를 해제합니다.
	if (_PixelShader)
	{
		_PixelShader->Release();
		_PixelShader = 0;
	}

	return;
}

bool FontShader::SetShaderParameters(ID3D11DeviceContext* deviceContext, XMMATRIX worldMatrix, XMMATRIX viewMatrix, XMMATRIX projectionMatrix, ID3D11ShaderResourceView* texture, XMFLOAT4 pixelColor)
{
	HRESULT result;
	D3D11_MAPPED_SUBRESOURCE mappedResource;
	ConstantBufferType* dataPtr;
	PixelBufferType* dataPtr2;
	unsigned int bufferNumber;

	// 행렬을 transpose하여 셰이더에서 사용할 수 있게 합니다.
	worldMatrix = XMMatrixTranspose(worldMatrix);
	viewMatrix = XMMatrixTranspose(viewMatrix);
	projectionMatrix = XMMatrixTranspose(projectionMatrix);

	// 상수 버퍼의 내용을 쓸 수 있도록 잠급니다.
	result = deviceContext->Map(_ConstantBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedResource);
	if (FAILED(result))
		return false;

	// 상수 버퍼의 데이터에 대한 포인터를 가져옵니다.
	dataPtr = (ConstantBufferType*)mappedResource.pData;

	// 상수 버퍼에 행렬을 복사합니다.
	dataPtr->world = worldMatrix;
	dataPtr->view = viewMatrix;
	dataPtr->projection = projectionMatrix;

	// 상수 버퍼의 잠금을 풉니다.
	deviceContext->Unmap(_ConstantBuffer, 0);

	// 정점 셰이더에서의 상수 버퍼의 위치를 설정합니다.
	bufferNumber = 0;

	// 마지막으로 정점 셰이더의 상수 버퍼를 바뀐 값으로 바꿉니다.
	deviceContext->VSSetConstantBuffers(bufferNumber, 1, &_ConstantBuffer);

	deviceContext->PSSetShaderResources(0, 1, &texture);
	
	/////
	result = deviceContext->Map(_PixelBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0
		, &mappedResource);
	if (FAILED(result)) {
		return false;
	}

	//픽셀 상수 버퍼의 데이터에 대한 포인터를 가져옵니다.
	dataPtr2 = (PixelBufferType*)mappedResource.pData;
	dataPtr2->pixelColor=pixelColor;

	deviceContext->Unmap(_PixelBuffer, 0);
	bufferNumber = 0;

	deviceContext->PSSetConstantBuffers(bufferNumber, 1, &_PixelBuffer);

	return true;
}

void FontShader::RenderShader(ID3D11DeviceContext* deviceContext, int indexCount)
{
	// 정점 입력 레이아웃을 설정합니다.
	deviceContext->IASetInputLayout(_Layout);


	// 삼각형을 그릴 정점 셰이더와 픽셀 셰이더를 설정합니다.
	deviceContext->VSSetShader(_VertexShader, NULL, 0);
	deviceContext->PSSetShader(_PixelShader, NULL, 0);

	deviceContext->PSSetSamplers(0, 1, &_SampleState);

	// 삼각형을 그립니다.
	deviceContext->DrawIndexed(indexCount, 0, 0);

	return;
}

FontShader::FontShader()
{
	_VertexShader = NULL;
	_PixelShader = NULL;
	_Layout = NULL;
	_ConstantBuffer = NULL;
	_SampleState = NULL;
	_PixelBuffer = NULL;
}

FontShader::FontShader(const FontShader& copy)
{
}

FontShader::~FontShader()
{
}

bool FontShader::Initiallize(ID3D11Device* device, HWND hwnd)
{
	bool result;
	//정점 셰이더와 픽셀 셰이더를 초기화합니다.
	result = InitializeShader(device, hwnd, _T("fontdata\\Font.vs"), _T("fontdata\\Font.ps"));
	if (!result)
		return false;

	return true;
}

void FontShader::Release()
{
	// 정점 셰이더와 픽실 셰이더 및 그와 관련된 것들을 반환합니다.
	ReleaseShader();
}

bool FontShader::Render(ID3D11DeviceContext* deviceContext, int indexCount, XMMATRIX world, XMMATRIX view, XMMATRIX projection, ID3D11ShaderResourceView* texture, XMFLOAT4 pixelColor)
{
	bool result;
	// 렌더링에 사용할 셰이더의 인자를 입력합니다.
	result = SetShaderParameters(deviceContext, world, view, projection, texture,pixelColor);
	if (!result)
		return false;

	// 셰이더를 이용하여 준비된 버퍼를 그립니다.
	RenderShader(deviceContext, indexCount);

	return true;
}
