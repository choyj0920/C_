#include "pch.h"
#include "Monster.h"

Monster::Monster(const char * name, int hp, int att, int def, int perso, int trib) :Status( name,hp,att,def,perso)
{
	this->trib = trib;
	Settribname();
}
Monster::~Monster()
{
}
void Monster::Settribname()
{
	switch (trib) {
	case 언데드:
		strcpy_s(tribname, sizeof(tribname), "언데드");
		break;
	case 악마:
		strcpy_s(tribname, sizeof(tribname), "악마");
		break;
	case 야수:
		strcpy_s(tribname, sizeof(tribname), "야수");
		break;
	case 정령:
		strcpy_s(tribname, sizeof(tribname), "정령");
		break;

	}
}
void Monster::showMonster()
{
	showInfo();	
	cout << "이 몬스터는 " << tribname << "족 입니다.\n";
}
