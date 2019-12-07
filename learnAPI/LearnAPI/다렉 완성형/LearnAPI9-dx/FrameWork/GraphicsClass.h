#pragma once

class GraphicsClass
{
private:
	bool _Vsync_enable;
	float _SDepth;
	float _SNear;
	
	D3DClass* _D3DC;
	Camera* _Camera;
	ColorShader* _ShaderClass;
	ModelTraingle* _Model;
public:
	GraphicsClass();
	GraphicsClass(const GraphicsClass& copy);
	~GraphicsClass();


	bool Initialize(int x, int y, HWND, bool);
	void Release();
	bool Frame();

private:
	bool Render();

};

