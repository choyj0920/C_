#include "GraphicsClass.h"

bool GraphicsClass::Render()
{
	PAINTSTRUCT ps;

	/** 더블버퍼링 시작처리입니다. **/
	static HDC hdc, MemDC;
	static HBITMAP BackBit, oldBackBit;
	static RECT bufferRT;
	MemDC = BeginPaint(hwnd, &ps);

	GetClientRect(hwnd, &bufferRT);
	hdc = CreateCompatibleDC(MemDC);
	BackBit = CreateCompatibleBitmap(MemDC, bufferRT.right, bufferRT.bottom);
	oldBackBit = (HBITMAP)SelectObject(hdc, BackBit);
	PatBlt(hdc, 0, 0, bufferRT.right, bufferRT.bottom, WHITENESS);

	// TODO: 여기에 그리기 코드를 추가합니다.


	/** 더블버퍼링 끝처리 입니다. **/
	GetClientRect(hwnd, &bufferRT);
	BitBlt(MemDC, 0, 0, bufferRT.right, bufferRT.bottom, hdc, 0, 0, SRCCOPY);
	SelectObject(hdc, oldBackBit);
	DeleteObject(BackBit);
	DeleteDC(hdc);
	EndPaint(hwnd, &ps);

	return true;
}

GraphicsClass::GraphicsClass()
{
}

GraphicsClass::GraphicsClass(const GraphicsClass& copy) :_Vsync_enable(copy._Vsync_enable), _SDepth(copy._SDepth), _SNear(copy._SNear)
{
	
}

GraphicsClass::~GraphicsClass()
{
}

bool GraphicsClass::Initialize(int w, int h, HWND hwnd, bool isFull)
{
	//출력 위치, 전체화면, 이니셜 라이저
	this->x = w;
	this->y = h;
	this->isFull = isFull;
	this->hwnd = hwnd;
	if (imgdraw == NULL)
		imgdraw = new ImageDraw;

	return true;
}

void GraphicsClass::Release()
{
	if (imgdraw)
		delete imgdraw;
}

bool GraphicsClass::Frame()
{
	bool result;
	result = Render();
	if (!result) {

		return false;
	}
	return true;

	
}
