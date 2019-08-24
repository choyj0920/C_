#include "pch.h"
#include "Status.h"

Status::Status(const char * name, int hp, int att, int def, int perso)
{
	strcpy_s(this->name, strlen(name) + 1, name);
	this->hp = hp;
	this->att = att;
	this->def = def;
	this->perso = perso;
	
}

Status::~Status()
{
}

void Status::getperso()
{
	switch (this->perso)
	{
	case 난폭함:
		cout << "난폭함\n";
		break;
	case 조급함:
		cout << "조급함\n";
		break;
	case 느긋함:
		cout << "느긋함\n";
		break;
	case 평범함:
		cout << "평범함\n";
		break;
	case 조용함:
		cout << "조용함\n";
		break;
	}
}

void Status::showInfo()
{
	cout << "이름 : " << name << endl;
	cout << "스텟 \n";
	cout << "생명력 : " << hp << "\t공격력 : " << att << "\t방어력 : " << def << endl;
	
	cout << "성격 : ";
	getperso();
}
