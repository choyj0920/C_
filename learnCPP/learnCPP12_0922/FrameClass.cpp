#include "pch.h"
#include "FrameClass.h"




FrameClass::FrameClass(int color, int bgcolor)
{
	_frameColor = color;
	_frameBGColor = bgcolor;
}

FrameClass::~FrameClass()
{
}

void FrameClass::DrawFrame()
{
	for (int n = 2; n < SCREEN_WIDTH; n += 2) {
		DrawGraphics::gotoxy(n, 0);   cout << "─";
		DrawGraphics::gotoxy(n, SCREEN_HEIGHT);  cout << "─";
	}
	for (int n = 0; n < SCREEN_HEIGHT; n++) {
		DrawGraphics::gotoxy(0, n); cout << "│";
		DrawGraphics::gotoxy(GAME_SCREEN_W , n); cout << "│";
		DrawGraphics::gotoxy(SCREEN_WIDTH - 1, n); cout << "│"; 
	}
	DrawGraphics::gotoxy(0,0); cout << "┌";
	DrawGraphics::gotoxy(SCREEN_WIDTH - 1,0); cout << "┐";
	DrawGraphics::gotoxy(SCREEN_WIDTH - 1, SCREEN_HEIGHT);	cout << "┘";
	DrawGraphics::gotoxy(0, SCREEN_HEIGHT); cout << "└";
	DrawGraphics::gotoxy(GAME_SCREEN_W, 0); cout << "┬";
	DrawGraphics::gotoxy(GAME_SCREEN_W, SCREEN_HEIGHT); cout << "┴";
	
}

void FrameClass::Drawboard()
{
	DrawGraphics::gotoxy(GAME_SCREEN_W + 1, 2); cout << " ======STAGE======";
	DrawGraphics::gotoxy(GAME_SCREEN_W + 1, 4); cout << " =====경과시간====";
	DrawGraphics::gotoxy(GAME_SCREEN_W + 1, 6); cout << " =====먹을글자====";

}

