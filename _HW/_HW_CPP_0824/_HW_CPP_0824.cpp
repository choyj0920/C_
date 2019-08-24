#include "pch.h"
#include <iostream>

#include "Monster.h"
#include "Status.h"
int main()
{
	int hp, att, def,pers,trib;
	char name[20];
	Status stat =  Status("Uz",10,10,10,평범함);
	stat.showInfo();
	Monster mon("HY", 20, 20, 20, 난폭함, 악마);
	mon.showMonster();


	return 0;
}
