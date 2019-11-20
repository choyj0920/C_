#pragma once

#include "framework.h"


class DrawImage
{
	HINSTANCE _hInst;
	HWND _hWnd;
	HDC _onewrDC;
	HDC _memDC;

public:
	DrawImage();
	~DrawImage();

	void set_initial(HINSTANCE hInst, HWND hWnd, HDC hdc, HDC memdc);
	//bitblt를 이용출력
	void draw_bitblt(int x, int y, TCHAR* lpmbpName);
	//strecthblt를 이용  전체 출력
	void draw_strecthblt(int x, int y, int xsize, int ysize, TCHAR* lpmbpName);

	//strechblt를 이용 하여 조각출력하는함수
	void draw_divied_strech(int x, int y, int wx, int wy, const TCHAR* lpmbpName);

	void draw_divied_strech_(int x, int y,int sx,int sy, int wx, int wy, const TCHAR* lpmbpName);
	void draw_divied_strech_puzzle(int x, int y,int sx,int sy, int wx, int wy, const TCHAR* lpmbpName,const POINT set[][8]);
	//파일에서 읽기
	void image_draw(int x, int y, int xsize, int ysize, const TCHAR* imagefilename);
	void image_draw2(int x, int y, int xsize, int ysize, const TCHAR* imagefilename);
};

