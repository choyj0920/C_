#include "ConsoleControl.h"
void gotoxy(int x, int y)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);  //윈도우 핸들  -콘솔창의 핸들을 변수로 설정
	COORD pos;      //long 변수x,y 두개를 가지고있는 윈도우api내 구조체 COORD
	pos.Y = y;
	pos.X = x;
	SetConsoleCursorPosition(hConsole, pos); //콘솔 핸들의 커서를 pos위치로 설정
	return;
}

void SetColor(int color)
{
	HANDLE std_output_handle = GetStdHandle(STD_OUTPUT_HANDLE); //윈도우 핸들  -콘솔창의 핸들을 변수로 설정
	SetConsoleTextAttribute(std_output_handle, color);  //콘솔핸들의 텍스트 색 설정
}

void SetCursorvisible(bool visible)
{
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = visible;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);

}