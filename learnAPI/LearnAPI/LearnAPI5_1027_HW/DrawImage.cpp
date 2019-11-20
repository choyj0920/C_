#include "DrawImage.h"

DrawImage::DrawImage()
{
	_hInst = NULL;
	_hWnd = NULL;
	_onewrDC = NULL;
	_memDC = NULL;
}

DrawImage::~DrawImage()
{
}

void DrawImage::set_initial(HINSTANCE hInst, HWND hWnd, HDC hdc, HDC memdc)
{
	_hInst = hInst;
	_hWnd = hWnd;
	_onewrDC = hdc;
	_memDC = memdc;

}

void DrawImage::draw_bitblt(int x, int y, TCHAR* lpmbpName)
{
	HBITMAP hbit = LoadBitmap(_hInst, lpmbpName);
	HBITMAP oldbit = (HBITMAP)SelectObject(_memDC, hbit);
	BITMAP bit;
	GetObject(hbit, sizeof(BITMAP), &bit);
	BitBlt(_onewrDC, x, y, bit.bmWidth, bit.bmHeight, _memDC, 0, 0, SRCCOPY);
	SelectObject(_onewrDC, oldbit);
	DeleteObject(hbit);

}

void DrawImage::draw_strecthblt(int x, int y, int xsize, int ysize, TCHAR* lpmbpName)
{
	HBITMAP hbit = LoadBitmap(_hInst, lpmbpName);
	HBITMAP oldbit = (HBITMAP)SelectObject(_memDC, hbit);
	BITMAP bit;
	GetObject(hbit, sizeof(BITMAP), &bit);
	StretchBlt(_onewrDC, x, y, xsize, ysize, _memDC, 0, 0, bit.bmWidth, bit.bmHeight, SRCCOPY);
	SelectObject(_onewrDC, oldbit);
	DeleteObject(hbit);
}

void DrawImage::draw_divied_strech(int x, int y, int wx, int wy, const TCHAR* imagefilename)
{
	HBITMAP hbit = (HBITMAP)LoadImage(NULL, imagefilename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	//HBITMAP hbit = LoadBitmap(_hInst, lpmbpName);
	HBITMAP oldbit = (HBITMAP)SelectObject(_memDC, hbit);
	BITMAP bit;
	GetObject(hbit, sizeof(BITMAP), &bit);
	int perw = bit.bmWidth / wx;
	int perw_s = perw + 3;
	int perh = bit.bmHeight / wy;
	int perh_s = perh + 3;
	for (int i = 0; i < wx; i++) {
		for (int j = 0; j < wy; j++) {
			StretchBlt(_onewrDC, x + perw_s * i, y + perh_s * j, perw, perh, _memDC, perw * i, perh * j, perw, perh, SRCCOPY);
		}
	}
	SelectObject(_onewrDC, oldbit);
	DeleteObject(hbit);

}

void DrawImage::draw_divied_strech_(int x, int y, int sx, int sy, int wx, int wy, const TCHAR* imagefilename)
{
	HBITMAP hbit = (HBITMAP)LoadImage(NULL, imagefilename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	//HBITMAP hbit = LoadBitmap(_hInst, lpmbpName);
	HBITMAP oldbit = (HBITMAP)SelectObject(_memDC, hbit);
	BITMAP bit;
	GetObject(hbit, sizeof(BITMAP), &bit);
	HDC copydc = CreateCompatibleDC(_onewrDC);
	int perw = bit.bmWidth / wx;
	int perw_s = sx / wx;
	int perh = bit.bmHeight / wy;
	int perh_s = sy / wy;
	for (int i = 0; i < wx; i++) {
		for (int j = 0; j < wy; j++) {
			StretchBlt(_onewrDC, x + perw_s * i, y + perh_s * j, perw_s-3, perh_s-3, _memDC, perw * i, perh * j, perw, perh, SRCCOPY);
		}
	}

	SelectObject(_onewrDC, oldbit);
	DeleteObject(copydc);
	DeleteObject(hbit);

}

void DrawImage::image_draw(int x, int y, int xsize, int ysize, const  TCHAR* imagefilename)
{
	HBITMAP hbit = (HBITMAP)LoadImage(NULL, imagefilename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	HBITMAP oldbit = (HBITMAP)SelectObject(_memDC, hbit);
	BITMAP bit;
	GetObject(hbit, sizeof(BITMAP), &bit);
	//StretchBlt(_onewrDC, x, y, xsize, ysize, _memDC, 0, 0, bit.bmWidth, bit.bmHeight, SRCCOPY);
	BitBlt(_onewrDC, x, y, xsize, ysize, _memDC, 0, 0, SRCCOPY);

	BLENDFUNCTION bf;
	memset(&bf, 0, sizeof(bf));
	bf.AlphaFormat = AC_SRC_OVER;
	bf.SourceConstantAlpha = 100;
	AlphaBlend(_onewrDC, x, y, bit.bmWidth, bit.bmHeight, _memDC, 0, 0, bit.bmWidth, bit.bmHeight, bf);

	SelectObject(_memDC, oldbit);
	DeleteObject(hbit);
}

void DrawImage::image_draw2(int x, int y, int xsize, int ysize, const TCHAR* imagefilename)
{
	HBITMAP hbit = (HBITMAP)LoadImage(NULL, imagefilename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	HBITMAP oldbit = (HBITMAP)SelectObject(_memDC, hbit);
	BITMAP bit;
	GetObject(hbit, sizeof(BITMAP), &bit);
	BitBlt(_onewrDC, x, y, xsize, ysize, _memDC, 0, 0, SRCCOPY);
	//StretchBlt(_onewrDC, x, y, xsize, ysize, _memDC, 0, 0, bit.bmWidth, bit.bmHeight, SRCCOPY);
	SelectObject(_onewrDC, oldbit);

	DeleteObject(hbit);
}
