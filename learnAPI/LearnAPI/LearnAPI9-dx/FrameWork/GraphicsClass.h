#pragma once

class GraphicsClass
{
private:
	bool _Vsync_enable;
	float _SDepth;
	float _SNear;
	HWND _hwnd;
	int _screenx, _screeny;
	D3DClass* _D3DC;
	Camera* _Camera;
	ColorShader* _ShaderClass;
	//ModelTraingle* _Model;
	//ModelRect* _Model;
	ModelCube* _Model;
	TextureShader* _Textureshader;
	ModelAxis* _axis;
	SpriteClass* _spriteModel;
	//SpriteObjectClass* _spriteObject;
	//Model_mal* _spriteObject;
	//Model_mal2* _spriteObject;
	Mal_with_text* _spriteObject;
	TextObjectClass* _textObject;
public:
	GraphicsClass();
	GraphicsClass(const GraphicsClass& copy);
	~GraphicsClass();


	bool Initialize(int x, int y, HWND, bool);
	void Release();
	bool Frame();
	bool Frame(float,float,float,bool shot);

private:
	bool Render();

};

