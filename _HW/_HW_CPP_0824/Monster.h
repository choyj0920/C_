#pragma once
#include "Status.h"
typedef enum tribe {
	언데드=1,
	악마, 
	야수,
	정령
}tribe;
class Monster :public Status
{
	int trib;
	char tribname[20];
public:
	Monster(const char * name, int hp, int att, int def, int perso,int trib);
	~Monster();
	void Settribname();
	void showMonster();

};

