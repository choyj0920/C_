#pragma once
#include <Windows.h>
#include "ImageDraw.h"
class GraphicsClass
{
private:
	bool _Vsync_enable;
	float _SDepth;
	float _SNear;
	
	int x;
	int y;
	bool isFull;
	HWND hwnd;
	bool Render();
	ImageDraw* imgdraw = NULL;
public:
	GraphicsClass();
	GraphicsClass(const GraphicsClass& copy);
	~GraphicsClass();

	bool Initialize(int x, int y, HWND, bool);
	void Release();
	bool Frame();



};

