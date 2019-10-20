#pragma once

#include "framework.h"
#include "LearnAPI4.h"

class DrawImage
{
	HINSTANCE _hInst;
	HWND _hWnd;
	HDC _onewrDC;
	HDC _memDC;

public:
	DrawImage();
	~DrawImage();

	void set_initial(HINSTANCE hInst,HWND hWnd,HDC hdc, HDC memdc);
	//bitblt�� �̿����
	void draw_bitblt(int x,int y, TCHAR* lpmbpName);
	//strecthblt�� �̿�  ��ü ���
	void draw_strecthblt(int x, int y, int xsize, int ysize,TCHAR* lpmbpName);
	
	//strechblt�� �̿� �Ͽ� ��������ϴ��Լ�
	void draw_divied_strech(int x,int y,int wx,int wy, TCHAR* lpmbpName);

	void draw_divied_strech(int x,int y,int wx,int wy, TCHAR* lpmbpName);
	//���Ͽ��� �б�
	void image_draw(int x, int y, int xsize,int ysize,TCHAR* imagefilename);
};

