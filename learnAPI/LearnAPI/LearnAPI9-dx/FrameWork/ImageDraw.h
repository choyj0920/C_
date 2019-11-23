#pragma once
#include <Windows.h>
#include <Ole2.h> // ÀÌ°Å¾øÀ¸¸é ¿¡·¯ ÆøÅº
#include  <gdiplus.h>
#pragma comment(lib, "Msimg32.lib")

#pragma comment(lib,"gdiplus")
using namespace Gdiplus;

class ImageDraw
{
private:
	ULONG_PTR _gdiplustoken;

public:
	ImageDraw();
	
	~ImageDraw();

	void TestDrawImage(HDC hdc,const TCHAR* szName, int x, int y);
	void DrawImageToSlice(HDC hdc, const TCHAR* szName, int sx, int sy, int sliceX, int sliceY);
	void DrawImage_s(HDC hdc, const TCHAR* szName, int sx, int sy, int sizex, int sizey);
	void DrawPuzzle(HDC hdc,int x, int y, int sx, int sy, int sliceX, int sliceY, const TCHAR* imagefilename, const POINT set[][8]);
	void PiceDrawImage(HDC hdc, const TCHAR* szName, int dx, int dy, int dw, int dh, int sx, int sy);
	void PiceDrawImage(HDC hdc, const TCHAR* szName, int dx, int dy, int dw, int dh, int sx, int sy, int sw, int sh);
	void PiceDrawImage(HDC hdc, const TCHAR* szName, const RECT dpos, int sx, int sy, int sw, int sh);
};

