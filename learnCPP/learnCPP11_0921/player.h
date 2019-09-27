#pragma once
class player
{
	int oldx, oldy;
	int nowx, nowy;
	int color, bgcolor;
	int speed;
	
	eObjectType _myType;
	string shape;
	bool isDraw;
public:
	player();
	void initialize(int nowx, int nowy, int color, int bgcolor, string shape,int speed);
	void DrawMode();
	void moveProcess(unsigned char key);

};

