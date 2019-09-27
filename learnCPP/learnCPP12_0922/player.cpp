#include "pch.h"
#include "player.h"
player::player() : Object()
{
	
}

void player::initialize(int nowx, int nowy, int sizx, int sizy, string shape, int color, int bgcolor, int speed)
{
	set_(nowx, nowy, sizx, sizy, shape, color, bgcolor);
	isDraw = true;
	oldx = _posX;
	oldy = _posY;
	this->speed = speed;

}


void player::player_DrawMode()
{
	if (isDraw) {
		DrawGraphics::setcolor(15, 0);
		for (int i = 0; i < _sizeY; i++) {
			for (int j = 0; j < _sizeX; j++) {
				DrawGraphics::gotoxy(oldx + j, oldy + i);
				cout << " ";
			}
		}
		this->DrawMode1();

		isDraw = false;
	}
}

void player::moveProcess(unsigned char key)
{
	oldx =_posX, oldy= _posY;
	
	switch (key)
	{
	case UPKEY:
		_posY -= speed;
		break;
	case DOWNKEY:
		_posY += speed;
		break;
	case LEFTKEY:
		_posX -= speed;
		break;
	case RIGHTKEY:
		_posX += speed;
		break;
	}


	if (_posX <= 1)
		_posX = 2;
	else if (_posX >= GAME_SCREEN_W - _sizeX)
		_posX = GAME_SCREEN_W - _sizeX;
	if (_posY <= 0)
		_posY = 1;
	else if (_posY+_sizeY >= SCREEN_HEIGHT )
		_posY  = SCREEN_HEIGHT - _sizeY;

	isDraw = true;
	player::player_DrawMode();
}

