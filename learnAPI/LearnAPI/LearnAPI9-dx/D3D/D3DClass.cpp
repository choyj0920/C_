#include "../framework.h"

#include "D3DClass.h"



D3DClass::D3DClass()
{
	_Device = NULL;
	_DeviceContext = NULL;
	_swapChain = NULL;
	_RenderTargetView = NULL;
	_DepthStencilBuffer = NULL;
	_DepthStencilState = NULL;
	_DepthStencilView = NULL;
	_RasterState = NULL;

	_mEnable4xMsaa = false;
}


D3DClass::D3DClass(const D3DClass& other)
{
}


D3DClass::~D3DClass()
{
}


bool D3DClass::Initialize(int screenW, int screenH, bool vSync, HWND hWnd
	, bool isFullScreen, float sDepth, float sNear)
{
	UINT m4xMsaaQuality = 0;
	DXGI_SWAP_CHAIN_DESC swapChainDesc;
	// ���� ü�� description�� �ʱ�ȭ�մϴ�.
	ZeroMemory(&swapChainDesc, sizeof(swapChainDesc));

	_Vsync_enabled = vSync;

	// 1. D3D11CreateDevice�Լ��� �̿��ؼ� ID3D11Device �������̽���
	//    ��ġ ����, ID3D11DeviceContext �������̽��� �����Ѵ�.
	if (!CreateDeviceNContext())
		return false;

	// 2. ID3D11Device::CheckMultisampleQualityLevels �Լ���
	//    �̿��Ͽ� 4XMSAA ǰ�� ���� ���� ���θ� �����Ѵ�.
	if (!CheckQualityLevels(&m4xMsaaQuality))
		return false;

	// 3. ������ ��ȯ �罽�� Ư���� �����ϴ�
	//    DXGI_SWAP_CHAIN_DESC����ü�� ä���.
	FillSwapChainSt(screenW, screenH, hWnd, isFullScreen,
		m4xMsaaQuality, &swapChainDesc);

	// 4. ��ġ�� �����ϴµ� ����ߴ� IDXGIFactory �������̽��� �����ؼ�
	//    IDXGISwapChain �ν��Ͻ��� �����Ѵ�.
	if (!CreateSwapChain(&swapChainDesc))
		return false;

	// 5. ��ȯ �罽�� �ĸ� ���ۿ� ���� ���� ��� �並 �����Ѵ�.
	if (!CreateRenderTargetV())
		return false;

	// 6. ����, ���Ľ� ���ۿ� �׿� ����Ǵ� ����, ���Ľ� �並 �����Ѵ�.
	if (!CreatedepthNStencil(screenW, screenH, m4xMsaaQuality))
		return false;

	// 7. ���� ��� ��� ����, ���Ľ� �並 Dirext3D�� ����� �� �ֵ���
	//    ������ ������������ ��� ���ձ� �ܰ迡 ���´�.
	if (!PipelineBinding())
		return false;

	// 8. ����Ʈ�� �����Ѵ�.
	SettingViewPort(screenW, screenH, sDepth, sNear);

	return true;
}


void D3DClass::Release()
{
	if (_RasterState != NULL)
	{
		_RasterState->Release();
		_RasterState = NULL;
	}

	if (_DepthStencilView != NULL)
	{
		_DepthStencilView->Release();
		_DepthStencilView = NULL;
	}

	if (_DepthStencilState != NULL)
	{
		_DepthStencilState->Release();
		_DepthStencilState = NULL;
	}

	if (_DepthStencilBuffer != NULL)
	{
		_DepthStencilBuffer->Release();
		_DepthStencilBuffer = NULL;
	}

	if (_RenderTargetView != NULL)
	{
		_RenderTargetView->Release();
		_RenderTargetView = NULL;
	}

	if (_swapChain != NULL)
	{
		_swapChain->Release();
		_swapChain = NULL;
	}

	if (_DeviceContext != NULL)
	{
		_DeviceContext->Release();
		_DeviceContext = NULL;
	}

	if (_Device != NULL)
	{
		_Device->Release();
	}
}


void D3DClass::BeginScene(float red, float green, float blue, float alpha)
{
	float color[4];

	// ���۸� � �������� ���� ������ �����մϴ�.
	color[0] = red;
	color[1] = green;
	color[2] = blue;
	color[3] = alpha;
	// ������� ������ ����ϴ�.
	_DeviceContext->ClearRenderTargetView(_RenderTargetView, color);

	// ���� ���۸� ����ϴ�.
	_DeviceContext->ClearDepthStencilView(_DepthStencilView, D3D11_CLEAR_DEPTH, 1.0f, 0);
}


void D3DClass::EndScene()
{
	// �������� �Ϸ�Ǿ����Ƿ� ������� ������ ȭ�鿡 ǥ���մϴ�.
	if (_Vsync_enabled)
	{
		// ���ΰ�ħ ������ �����մϴ�.
		_swapChain->Present(1, 0);
	}
	else
	{
		// ������ �� ������ ǥ���մϴ�.
		_swapChain->Present(0, 0);
	}
}


ID3D11Device* D3DClass::GetDevice()
{
	return _Device;
}


ID3D11DeviceContext* D3DClass::GetDeviceContext()
{
	return _DeviceContext;
}


void D3DClass::GetProjectionMatrix(XMMATRIX& mat)
{
	mat = _ProjectionMatrix;
}


void D3DClass::GetWorldMatrix(XMMATRIX& mat)
{
	mat = _WorldMatrix;
}

void D3DClass::GetOrthoMatrix(XMMATRIX& mat)
{
	mat = _OrthoMatrix;
}

bool D3DClass::CreateDeviceNContext()
{
	UINT createDeviceFlags = 0;
#if defined(DEBUG) || defined(_DEBUG)// ����׸���϶� ����� ���� Ȱ��ȭ.
	createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif
	D3D_FEATURE_LEVEL featureLevel;	// D3D�� Ư¡ ����

	HRESULT hr = D3D11CreateDevice(0							// �⺻ �����.
		, D3D_DRIVER_TYPE_HARDWARE	//���÷��� ����͸� �����Ѵ�. 0�̸� �⺻ ���÷��� ����͸� �����Ѵ�.//�Ϲ������δ� �������� 3���� �׷��� ������ ����ǰ� �ϱ� ���� �� �Ű������� D3D_DRIVER_TYPE_HARDWARE �� �����Ѵ�.
		, 0							// ����Ʈ���� ��ġ�� ������� ����.
		, createDeviceFlags			//�߰����� ��ġ ���� �÷��׵��� �����Ѵ�.
		, 0, 0						//��� ���� �����ϴ� ������ 0���� �ϸ� �ְ� ��� ������ �����Ѵ�, //D3D_FEATURE_LEVEL�� ���� �����̴�. pFeatureLevels �� 0���� ������ �� �͵� 0���� ���� �Ѵ�.
		, D3D11_SDK_VERSION
		, &_Device					//�Լ��� ������ ID3D11Device�� �����ش�.���� ������.. ��ü�� ���� �־��� ��  ����̽��� �ּҸ� ���� ���� �����ϰ� �ϱ� ���� ����
		, &featureLevel				// pFeatureLevels �迭���� ó������ �����Ǵ� ���(pFeatureLevels�� 0���� �ϸ� �����Ǵ� ���� ���� ��� ����)�� �����ش�.
		, &_DeviceContext);			////�Լ����� ������ ID3D11DeviceContext�� �����ش�. --�굵 ���� ������

	if (FAILED(hr))
	{
		MessageBox(NULL, _T("D3D11CreateDevice Faild!!"), NULL, MB_OK);
		return false;
	}

	if (featureLevel != D3D_FEATURE_LEVEL_11_0)
	{
		MessageBox(NULL, _T("Direct3D Feature Level 11 unsupported"), NULL, MB_OK);
		return false;
	}

	return true;
}


bool D3DClass::CheckQualityLevels(UINT* m4xMsaaQuality)
{
	HRESULT hr = _Device->CheckMultisampleQualityLevels(DXGI_FORMAT_B8G8R8A8_UNORM, 4, m4xMsaaQuality);
	if (FAILED(hr))
	{
		MessageBox(NULL, _T("4XMSAA Faild!!"), NULL, MB_OK);
		return false;
	}

	return true;
}


void D3DClass::FillSwapChainSt(int screenW, int screenH, HWND hWnd, bool IsFullScreen
	, UINT m4xMsaaQuality, DXGI_SWAP_CHAIN_DESC* swapChainDesc)
{
	// ������� �ʺ�� ���̸� �����մϴ�.
	swapChainDesc->BufferDesc.Width = screenW;
	swapChainDesc->BufferDesc.Height = screenH;
	// ������� ���ΰ�ħ ������ �����մϴ�.
	swapChainDesc->BufferDesc.RefreshRate.Numerator = 60;
	swapChainDesc->BufferDesc.RefreshRate.Denominator = 1;
	// ����۷� �Ϲ����� 32bit�� �����̽��� �����մϴ�.
	swapChainDesc->BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	// ��ĵ������ ���İ� ��ĵ���̴��� �������� ��������(unspecified)
	// �����մϴ�.
	swapChainDesc->BufferDesc.ScanlineOrdering
		= DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
	swapChainDesc->BufferDesc.Scaling
		= DXGI_MODE_SCALING_UNSPECIFIED;
	// 4X MSAA�� ����ϴ°�?
	if (_mEnable4xMsaa)
	{
		swapChainDesc->SampleDesc.Count = 4;
		swapChainDesc->SampleDesc.Quality = m4xMsaaQuality - 1;
	}
	else
	{
		// ��Ƽ���ø��� ���ϴ�.
		swapChainDesc->SampleDesc.Count = 1;
		swapChainDesc->SampleDesc.Quality = 0;
	}
	// ������� �뵵�� �����մϴ�.
	swapChainDesc->BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	// �ϳ��� ����۸��� ����ϵ��� �մϴ�.
	swapChainDesc->BufferCount = 1;
	// �������� �̷���� �������� �ڵ��� �����մϴ�.
	swapChainDesc->OutputWindow = hWnd;
	// ������ ��� �Ǵ� Ǯ��ũ�� ��带 �����մϴ�.
	if (IsFullScreen)
	{
		swapChainDesc->Windowed = false;
	}
	else
	{
		swapChainDesc->Windowed = true;
	}
	// ��µ� ������ ������� ������ �������� �մϴ�.
	swapChainDesc->SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
	// �߰� �ɼ� �÷��׸� ������� �ʽ��ϴ�.
	swapChainDesc->Flags = 0;
}


bool D3DClass::CreateSwapChain(DXGI_SWAP_CHAIN_DESC* swapChainDesc)
{
	IDXGIDevice* dxgiDevice = NULL;
	HRESULT hr = _Device->QueryInterface(__uuidof(IDXGIDevice), (void**)&dxgiDevice);
	if (FAILED(hr))
	{
		MessageBox(NULL, _T("IDXGIDevice Faild!!"), NULL, MB_OK);
		return false;
	}

	IDXGIAdapter* dxgiAdapter = NULL;
	hr = dxgiDevice->GetParent(__uuidof(IDXGIAdapter), (void**)&dxgiAdapter);
	if (FAILED(hr))
	{
		MessageBox(NULL, _T("IDXGIAdapter Faild!!"), NULL, MB_OK);
		return false;
	}

	// ���⼭ IDXGIFactory �������̽��� ��´�.
	IDXGIFactory* dxgiFactory = NULL;
	hr = dxgiAdapter->GetParent(__uuidof(IDXGIFactory), (void**)&dxgiFactory);
	if (FAILED(hr))
	{
		MessageBox(NULL, _T("IDXGIFactory Faild!!"), NULL, MB_OK);
		return false;
	}

	// ���� ��ȯ �罽�� �����Ѵ�.
	hr = dxgiFactory->CreateSwapChain(_Device, swapChainDesc, &_swapChain);
	if (FAILED(hr))
	{
		MessageBox(NULL, _T("IDXGISwapChain Faild!!"), NULL, MB_OK);
		return false;
	}

	// ȹ���� COM �������̽��� ����.
	dxgiDevice->Release();
	dxgiDevice = NULL;
	dxgiAdapter->Release();
	dxgiAdapter = NULL;
	dxgiFactory->Release();
	dxgiFactory = NULL;

	return true;
}


bool D3DClass::CreateRenderTargetV()
{
	ID3D11Texture2D* backBuffer = NULL;
	_swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), reinterpret_cast<void**>(&backBuffer));
	HRESULT hResult = _Device->CreateRenderTargetView(backBuffer, 0, &_RenderTargetView);
	if (FAILED(hResult)) {
		MessageBox(NULL, _T("ID3D11RenderTargetView Faild!!"), NULL, MB_OK);
		return false;
	}
	backBuffer->Release();
	backBuffer = NULL;

	return true;
}


bool D3DClass::CreatedepthNStencil(int screenW, int screenH, UINT m4xMsaaQuality)
{
	D3D11_TEXTURE2D_DESC depthBufferDesc;
	D3D11_DEPTH_STENCIL_DESC depthStencilDesc;
	D3D11_DEPTH_STENCIL_VIEW_DESC depthStencilViewDesc;

	// ���� ������ description�� �ʱ�ȭ�մϴ�.
	ZeroMemory(&depthBufferDesc, sizeof(depthBufferDesc));

	// ���� ������ description�� �ۼ��մϴ�.
	depthBufferDesc.Width = screenW;
	depthBufferDesc.Height = screenH;
	depthBufferDesc.MipLevels = 1;
	depthBufferDesc.ArraySize = 1;
	depthBufferDesc.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;

	if (_mEnable4xMsaa)
	{
		depthBufferDesc.SampleDesc.Count = 4;
		depthBufferDesc.SampleDesc.Quality = m4xMsaaQuality - 1;
	}
	else
	{
		depthBufferDesc.SampleDesc.Count = 1;
		depthBufferDesc.SampleDesc.Quality = 0;
	}
	depthBufferDesc.Usage = D3D11_USAGE_DEFAULT;
	depthBufferDesc.BindFlags = D3D11_BIND_DEPTH_STENCIL;
	depthBufferDesc.CPUAccessFlags = 0;
	depthBufferDesc.MiscFlags = 0;

	// description�� ����Ͽ� ���� ������ �ؽ��ĸ� �����մϴ�.
	HRESULT hr = _Device->CreateTexture2D(&depthBufferDesc, NULL, &_DepthStencilBuffer);
	if (FAILED(hr))
	{
		MessageBox(NULL, _T("_DepthStencilBuffer Failed"), NULL, MB_OK);
		return false;
	}

	// ���ٽ� ������ description�� �ʱ�ȭ�մϴ�.
	ZeroMemory(&depthStencilDesc, sizeof(depthStencilDesc));
	// ���ٽ� ������ description�� �ۼ��մϴ�.
	depthStencilDesc.DepthEnable = true;
	depthStencilDesc.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ALL;
	depthStencilDesc.DepthFunc = D3D11_COMPARISON_LESS;
	depthStencilDesc.StencilEnable = true;
	depthStencilDesc.StencilReadMask = 0xFF;
	depthStencilDesc.StencilWriteMask = 0xFF;
	// �ȼ��� ������ ���� ���ٽ� �۾�.
	depthStencilDesc.FrontFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;
	depthStencilDesc.FrontFace.StencilDepthFailOp = D3D11_STENCIL_OP_INCR;
	depthStencilDesc.FrontFace.StencilPassOp = D3D11_STENCIL_OP_KEEP;
	depthStencilDesc.FrontFace.StencilFunc = D3D11_COMPARISON_ALWAYS;
	// �ȼ��� ������ �� ��� ���ٽ� �۾�.
	depthStencilDesc.BackFace.StencilFailOp = D3D11_STENCIL_OP_KEEP;
	depthStencilDesc.BackFace.StencilDepthFailOp = D3D11_STENCIL_OP_DECR;
	depthStencilDesc.BackFace.StencilPassOp = D3D11_STENCIL_OP_KEEP;
	depthStencilDesc.BackFace.StencilFunc = D3D11_COMPARISON_ALWAYS;

	// ����-���ٽ� ���¸� �����մϴ�.
	hr = _Device->CreateDepthStencilState(&depthStencilDesc, &_DepthStencilState);
	if (FAILED(hr))
	{
		MessageBox(NULL, _T("_DepthStencilState Failed"), NULL, MB_OK);
		return false;
	}

	// ����-���ٽ� ���¸� �����մϴ�.
	_DeviceContext->OMSetDepthStencilState(_DepthStencilState, 1);

	// ����-���ٽ� ���� description�� �ʱ�ȭ�մϴ�.
	ZeroMemory(&depthStencilViewDesc,
		sizeof(depthStencilViewDesc));

	// ����-���ٽ� ���� description�� �ۼ��մϴ�.
	depthStencilViewDesc.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
	depthStencilViewDesc.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2D;
	depthStencilViewDesc.Texture2D.MipSlice = 0;

	hr = _Device->CreateDepthStencilView(_DepthStencilBuffer, &depthStencilViewDesc, &_DepthStencilView);
	if (FAILED(hr))
	{
		MessageBox(NULL, _T("_DepthStencilView Failed"), NULL, MB_OK);
		return false;
	}

	return true;
}


bool D3DClass::PipelineBinding()
{
	_DeviceContext->OMSetRenderTargets(1, &_RenderTargetView, _DepthStencilView);

	D3D11_RASTERIZER_DESC rasterDesc;
	// � ������ ��� �׸� ������ �����ϴ� ������ȭ�� description��
	// �ۼ��մϴ�.
	rasterDesc.AntialiasedLineEnable = false;
	rasterDesc.CullMode = D3D11_CULL_BACK;
	rasterDesc.DepthBias = 0;
	rasterDesc.DepthBiasClamp = 0.0f;
	rasterDesc.DepthClipEnable = true;
	rasterDesc.FillMode = D3D11_FILL_SOLID;
	rasterDesc.FrontCounterClockwise = false;
	rasterDesc.MultisampleEnable = false;
	rasterDesc.ScissorEnable = false;
	rasterDesc.SlopeScaledDepthBias = 0.0f;

	// �ۼ��� description���κ��� ������ȭ�� ���¸� �����մϴ�.
	HRESULT hr = _Device->CreateRasterizerState(&rasterDesc, &_RasterState);
	if (FAILED(hr))
	{
		return false;
	}
	// ������ȭ�� ���¸� �����մϴ�.
	_DeviceContext->RSSetState(_RasterState);

	return true;
}


void D3DClass::SettingViewPort(int screenW, int screenH, float sDepth, float sNear)
{
	D3D11_VIEWPORT viewport;
	float fieldOfView, screenAspect;
	// �������� ���� ����Ʈ�� �����մϴ�.
	viewport.Width = (float)screenW;
	viewport.Height = (float)screenH;
	viewport.MinDepth = 0.0f;
	viewport.MaxDepth = 1.0f;
	viewport.TopLeftX = 0.0f;
	viewport.TopLeftY = 0.0f;

	// ����Ʈ�� �����մϴ�.
	_DeviceContext->RSSetViewports(1, &viewport);

	//	// ���� ����� �����մϴ�.
	fieldOfView = (float)XM_PI / 4.0f;
	screenAspect = (float)screenW / (float)screenH;
	// 3D �������� ���� ���� ����� �����մϴ�.
	// (D3DXMatrixPerspectiveFovLH)
	_ProjectionMatrix = XMMatrixPerspectiveFovLH(fieldOfView, screenAspect, sNear, sDepth);

	// ���� ����� ���� ��ķ� �ʱ�ȭ�մϴ�.(D3DXMatrixIdentity)
	_WorldMatrix = XMMatrixIdentity();

	// 2D �������� ���� ���翵 ����� �����մϴ�.
	// (XMMatrixOrthographicLH)
	_OrthoMatrix = XMMatrixOrthographicLH((float)screenW, (float)screenH, sDepth, sNear);
}

