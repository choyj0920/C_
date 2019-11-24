#include "D3DClass.h"

ID3D11Device* D3DClass::GetDevice()
{
	return _Device;
}

ID3D11DeviceContext* D3DClass::GetDeviceContext()
{
	return _DeviceContext;
}

void D3DClass::GetProjectionMatrix(XMMATRIX& copy)
{
	copy = _ProjectionMatrix;
}

void D3DClass::GetWorldMatrix(XMMATRIX& copy)
{
	copy = _WorldMatrix;
}

void D3DClass::GetOrthoMatrix(XMMATRIX& copy)
{
	copy = _OrthoMatrix;
}

D3DClass::D3DClass()
{
	_Device = NULL;
	_DeviceContext = NULL;
	_swapChain = NULL;
	_RenderTargetView = NULL;
	_DepthStencilBUffer = NULL;
	_DepthStencilState = NULL;
	_DepthStencilView = NULL;
	_RasterState = NULL;

	_mEnable4xMsaa = false;
}

D3DClass::D3DClass(const D3DClass& copy)
{
}

D3DClass::~D3DClass()
{
}

bool D3DClass::Initialize(int screenW, int screenH, bool vSync, HWND hWnd, bool isFullScreen, float sDepth, float sNear)
{
	UINT m4xMsaaQuality = 0;
	DXGI_SWAP_CHAIN_DESC swapChinDesc;
	//����ü�� description�� �ʱ�ȭ�մϴ�.
	ZeroMemory(&swapChinDesc, sizeof(swapChinDesc));

	_Vsync_enabled = vSync;
	// 1.D3D11 create 
	//��ġ����, 
	if (!CreateDeviceNContext())
		return false;
	//2.D
	// 
	if (!CheckQualityLevels(&m4xMsaaQuality))
		return false;
	//3. ������ ��ȯ�罽�� Ư���� �����ϴ� 
	// DXGI_SWAP_CHAIN_DESC ����ü�� ä���.
	FillSwapChainSt(screenW, screenH, hWnd, isFullScreen, m4xMsaaQuality, &swapChinDesc);

	//4. ��ġ�� �����ϴµ� ����ߴ� IDXGIFactory�������̽��� ���� �ؼ� 
	// IDXGISwapChain �ν��Ͻ��� �����Ѵ�.
	if (!CreateSwapChain(&swapChinDesc))
		return false;
	//5.��ȯ�罽�� �ĸ� ���ۿ� ���� ���� ��� �並 �����Ѵ�.
	CreateRenderTargetV();

	//6. ����, ���Ľ� ���ۿ� �׿� ����Ǵ� ����, ���ٽ� �並 �����Ѵ�.
	if (!CreatedepthNStencil(screenW, screenH, m4xMsaaQuality))
		return false;

	// 7.���� ��� ��� ���� ���Ľ� �並 direct3D�� ����Ҽ� �ֵ��� 
	//������ ������������ ��� ���ձ� �ܰ迡 ���´�.
	if (!PipelineBinding())
		return false;

	// 8.����Ʈ�� �����Ѵ�.
	SettingViewPort(screenW, screenH, sDepth, sNear);

	return true;
}
