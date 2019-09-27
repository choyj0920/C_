#include "pch.h"
#include "DrawGraphics.h"

void DrawGraphics::gotoxy(int posx, int posy)
{
	COORD Pos;
	Pos.X = posx;
	Pos.Y = posy;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);


}

void DrawGraphics::setcolor(int color, int bgcolor)
{
	color &= 0xf;  //��Ʈ ���� �ؿ� 4��Ʈ�� ..
	bgcolor &= 0xf;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (bgcolor << 4) | color);
}

void DrawGraphics::cursor(int n)
{
	HANDLE hconsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;

	hconsole = GetStdHandle(STD_OUTPUT_HANDLE);

	ConsoleCursor.bVisible = n;
	ConsoleCursor.dwSize = 1;
	
	SetConsoleCursorInfo(hconsole, &ConsoleCursor);
}
