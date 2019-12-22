#pragma once

class D3DClass {
	bool _Vsync_enabled;
	ID3D11Device* _Device;
	ID3D11DeviceContext* _DeviceContext;
	IDXGISwapChain* _swapChain;
	ID3D11RenderTargetView* _RenderTargetView;
	ID3D11Texture2D* _DepthStencilBuffer;
	ID3D11DepthStencilState* _DepthStencilState;
	ID3D11DepthStencilState* _DepthDisabledStencilState;
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

	void TurnZBufferOn();
	void TurnZBufferOff();

private:
	bool CreateDeviceNContext(); //**ID3D11Device�� ID3D11DeviceContext�� ����**
	bool CheckQualityLevels(UINT*); // **4X MSAA ǰ�� ���� ���� ����.**
	void FillSwapChainSt(int, int, HWND, bool, UINT, DXGI_SWAP_CHAIN_DESC*);//������ ��ȯ�罽 ����
	bool CreateSwapChain(DXGI_SWAP_CHAIN_DESC*); //��ȯ �罽 �����
	bool CreateRenderTargetV(); //���� ��� �����
	bool CreatedepthNStencil(int, int, UINT); //���� ���ٽ� �� ����
	bool PipelineBinding(); //��� ���ձ⿡ ����
	void SettingViewPort(int screenW, int screenH, float sDepth, float sNear);


};