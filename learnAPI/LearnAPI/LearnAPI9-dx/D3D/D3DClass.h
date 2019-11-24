#include <d3dcommon.h>
#include <d3d11.h>
#include <DirectXMath.h>
#include <DirectXPackedVector.h>
using namespace DirectX;
class D3DClass {
	bool _Vsync_enabled;
	ID3D11Device* _Device;
	ID3D11DeviceContext* _DeviceContext;
	IDXGISwapChain* _swapChain;
	ID3D11RenderTargetView* _RenderTargetView;
	ID3D11Texture2D* _DepthStencilBUffer;
	ID3D11DepthStencilState* _DepthStencilState;
	ID3D11DepthStencilView* _DepthStencilView;
	ID3D11RasterizerState* _RasterState;

	bool _mEnable4xMsaa;
	XMMATRIX _ProjectionMatrix;
	XMMATRIX _WorldMatrix;
	XMMATRIX _OrthoMatrix;
public:
	D3DClass();
	D3DClass(const D3DClass& copy);
	~D3DClass();

	bool Initialize(int screenW, int screenH, bool vSync, HWND hWnd, bool isFullScreen, float sDepth, float sNear);
	void Release();
	
	void BeginScene(float, float, float, float);
	void EndScene();

	ID3D11Device* GetDevice();
	ID3D11DeviceContext* GetDeviceContext();

	void GetProjectionMatrix(XMMATRIX& copy);
	void GetWorldMatrix(XMMATRIX& copy);
	void GetOrthoMatrix(XMMATRIX& copy);

private:
	bool CreateDeviceNContext();
	bool CheckQualityLevels(UINT*);
	void FillSwapChainSt(int, int, HWND, bool, UINT, DXGI_SWAP_CHAIN_DESC*);
	bool CreateSwapChain(DXGI_SWAP_CHAIN_DESC*);
	void CreateRenderTargetV();
	bool CreatedepthNStencil(int, int, UINT);
	bool PipelineBinding();
	void SettingViewPort(int, int, float, float);



};