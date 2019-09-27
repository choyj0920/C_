#include "pch.h"
#include "player.h"

player::player()
{
	
}

void player::initialize(int nowx, int nowy, int color, int bgcolor, string shape,int speed)
{
	_myType = OBJ_player;
	isDraw = true;
	this->nowx = oldx = nowx;
	this->nowy = oldy = nowy;
	this->color = color;
	this->bgcolor = bgcolor;
	this->shape = shape;
	this->speed = speed;
}

void player::DrawMode()
{
	if (isDraw) {
		DrawGraphics::setcolor(15, 0);
		DrawGraphics::gotoxy(oldx, oldy);
		for (int i = 0; i < shape.length(); i++) {
			if (shape[i] == '\n')
				cout << "\n";
			else
				cout << " ";
		}
		DrawGraphics::setcolor(color, bgcolor);
		DrawGraphics::gotoxy(nowx, nowy);
		cout << shape;
		DrawGraphics::setcolor(15, 0);

		isDraw = false;
	}
}

void player::moveProcess(unsigned char key)
{
	oldx =nowx, oldy= nowy;
	
	switch (key)
	{
	case UPKEY:
		nowy -= speed;
		break;
	case DOWNKEY:
		nowy += speed;
		break;
	case LEFTKEY:
		nowx -= speed;
		break;
	case RIGHTKEY:
		nowx += speed;
		break;
	}


	if (nowx <= 1)		
		nowx = 2;
	else if (nowx >= GAME_SCREEN_W - shape.length()) 
		nowx = GAME_SCREEN_W - shape.length();
	if (nowy <= 0)		
		nowy = 1;
	else if (nowy >= SCREEN_HEIGHT ) 
		nowy = SCREEN_HEIGHT -1 ;

	isDraw = true;
	player::DrawMode();
}

