#include "ConsoleControl.h"
void gotoxy(int x, int y)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);  //������ �ڵ�  -�ܼ�â�� �ڵ��� ������ ����
	COORD pos;      //long ����x,y �ΰ��� �������ִ� ������api�� ����ü COORD
	pos.Y = y;
	pos.X = x;
	SetConsoleCursorPosition(hConsole, pos); //�ܼ� �ڵ��� Ŀ���� pos��ġ�� ����
	return;
}

void SetColor(int color)
{
	HANDLE std_output_handle = GetStdHandle(STD_OUTPUT_HANDLE); //������ �ڵ�  -�ܼ�â�� �ڵ��� ������ ����
	SetConsoleTextAttribute(std_output_handle, color);  //�ܼ��ڵ��� �ؽ�Ʈ �� ����
}

void SetCursorvisible(bool visible)
{
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = visible;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);

}