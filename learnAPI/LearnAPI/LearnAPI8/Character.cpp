#include "Character.h"

Character::Character(const TCHAR* filename, const RECT& pos, int perx, int pery,int anicount) :filename(filename), pos(pos), perx(perx), pery(pery),anicount(anicount)
{
	now_ani = 7;
	speed = 0;
}

void Character::randspeed()
{
	speed = rand() % 10+1;
	return;
}

void Character::run()
{
	if (work) {
		pos.left += speed;
		now_ani = (now_ani + 1) % anicount;
	}
	

}

Character::~Character()
{
}
