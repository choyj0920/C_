#include "framework.h"
#include "ImageDraw.h"

ImageDraw::ImageDraw()
{
	GdiplusStartupInput gdiplusStartupInput;
	
	GdiplusStartup(&_gdiplustoken, &gdiplusStartupInput, NULL);

	
}

ImageDraw::~ImageDraw()
{
	GdiplusShutdown(_gdiplustoken);
}

void ImageDraw::TestDrawImage(HDC hdc,const TCHAR* szName, int x, int y)
{
	Graphics grapics(hdc);
	Image img(szName);
	RECT rc = {x + img.GetWidth() , y, img.GetWidth() / 3, img.GetHeight() / 3 };
	
	grapics.DrawImage(&img, x, y);
	
}

void ImageDraw::DrawImageToSlice(HDC hdc, const TCHAR* szName, int sx, int sy, int sliceX, int sliceY)
{
	Graphics grapics(hdc);
	Image img(szName);
	int perx = img.GetWidth() / sliceX;
	int pery = img.GetHeight() / sliceY;
	for (int i = 0; i < sliceX; i++) {
		for (int j = 0; j < sliceY; j++) {
			grapics.DrawImage(&img,(perx + 1) * i,(pery + 1) * j ,  perx * i,pery * j ,perx,pery ,UnitPixel);
		}
	}
}

void ImageDraw::DrawImage_s(HDC hdc, const TCHAR* szName, int sx, int sy, int sizex, int sizey)
{
	Graphics grapics(hdc);
	Image img(szName);
	grapics.DrawImage(&img, { sx,sy,sizex,sizey },0,0,img.GetWidth(),img.GetHeight(),UnitPixel);
}

void ImageDraw::DrawPuzzle(HDC hdc,int x, int y, int sx, int sy, int sliceX, int sliceY, const TCHAR* szName, const POINT set[][8])
{
	Graphics grapics(hdc);
	Image img(szName);
	int perx = img.GetWidth() / sliceX;
	int pery = img.GetHeight() / sliceY;
	int perw_s = sx / sliceX;
	int perh_s = sy / sliceY;
	
	for (int i = 0; i < sliceX; i++) {
		for (int j = 0; j < sliceY; j++) {
			if (i == sliceX - 1 && j == sliceY - 1) continue;
			grapics.DrawImage(&img, { x + (perw_s ) * set[j][i].x,y + (perh_s ) * set[j][i].y,perw_s-1,perh_s-1 }, perx * i, pery * j, perx, pery, UnitPixel);

		}
	}
}

void ImageDraw::PiceDrawImage(HDC hdc, const TCHAR* szName, int dx, int dy, int dw, int dh, int sx, int sy)
{
	Graphics graphics(hdc);
	Image img(szName);
	Rect rc(dx, dy, dw, dh);
	graphics.DrawImage(&img, rc, sx, sy, dw, dh, UnitPixel);
}

void ImageDraw::PiceDrawImage(HDC hdc, const TCHAR* szName, int dx, int dy, int dw, int dh, int sx, int sy, int sw, int sh)
{
	Graphics graphics(hdc);
	Image img(szName);
	Rect rc(dx, dy, dw, dh);
	graphics.DrawImage(&img, rc, sx, sy, sw, sh, UnitPixel);
}

void ImageDraw::PiceDrawImage(HDC hdc, const TCHAR* szName, const RECT dpos, int sx, int sy, int sw, int sh)
{
	Graphics graphics(hdc);
	Image img(szName);
	graphics.DrawImage(&img, Rect(dpos.left,dpos.top,dpos.right,dpos.bottom), sx, sy, sw, sh, UnitPixel);
}
