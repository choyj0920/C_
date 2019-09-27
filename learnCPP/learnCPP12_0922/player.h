#pragma once
#include "Object.h"
class player :public Object
{
	int oldx, oldy;

	int speed;
	
	eObjectType _myType;
	string shape;
	bool isDraw;
public:
	player();
	void initialize(int nowx, int nowy,int sizx,int sizy, string shape, int color, int bgcolor,int speed);
	void player_DrawMode();
	void moveProcess(unsigned char key);

};

