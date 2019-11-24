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
	//스왑체인 description을 초기화합니다.
	ZeroMemory(&swapChinDesc, sizeof(swapChinDesc));

	_Vsync_enabled = vSync;
	// 1.D3D11 create 
	//장치문맥, 
	if (!CreateDeviceNContext())
		return false;
	//2.D
	// 
	if (!CheckQualityLevels(&m4xMsaaQuality))
		return false;
	//3. 생성할 교환사슬의 특성을 서술하는 
	// DXGI_SWAP_CHAIN_DESC 구조체를 채운다.
	FillSwapChainSt(screenW, screenH, hWnd, isFullScreen, m4xMsaaQuality, &swapChinDesc);

	//4. 장치를 생성하는데 사용했던 IDXGIFactory인터페이스를 질의 해서 
	// IDXGISwapChain 인스턴스를 생성한다.
	if (!CreateSwapChain(&swapChinDesc))
		return false;
	//5.교환사슬의 후면 버퍼에 대한 렌더 대상 뷰를 생성한다.
	CreateRenderTargetV();

	//6. 깊이, 스탠실 버퍼와 그에 연결되는 깊이, 스텐실 뷰를 생성한다.
	if (!CreatedepthNStencil(screenW, screenH, m4xMsaaQuality))
		return false;

	// 7.렌더 대상 뷰와 깊이 스탠실 뷰를 direct3D가 사용할수 있도록 
	//렌더링 파이프라인의 출력 병합기 단계에 묶는다.
	if (!PipelineBinding())
		return false;

	// 8.뷰포트를 설정한다.
	SettingViewPort(screenW, screenH, sDepth, sNear);

	return true;
}
