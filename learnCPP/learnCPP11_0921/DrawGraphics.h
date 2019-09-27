#pragma once
class DrawGraphics
{
public:
	static void gotoxy(int posx, int posy);
	static void setcolor(int color, int bgcolor);
	static void cursor(int n); //1. 커서 보이기  & 0: 숨기기
};

