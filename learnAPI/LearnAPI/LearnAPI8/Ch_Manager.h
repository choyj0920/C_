#pragma once
#include "framework.h"
class Character;
class Ch_Manager
{
private:
	Character* charac[CH_COU];
	int use = 0;;
	int start;
	int finishcount;
	ImageDraw imgdr;
public:
	Ch_Manager();
	bool add(Character* new_ch);
	int rank[CH_COU] = { 0, };
	void s_start();
	void run();
	void check();
	void empty();
	void randspeed();
	~Ch_Manager();
	void draw(HDC hwnd);
	
};

