#pragma once
#include "framework.h"

class Character
{
private:
	int now_ani;
	RECT pos;
	bool work=false;
	const TCHAR * filename;
	int perx, pery;
	int speed;
	int anicount;
public:
	friend class Ch_Manager;
	Character(const TCHAR* filename, const RECT& pos, int perx, int pery,int anicount);
	void randspeed();
	void run();
	~Character();
};

