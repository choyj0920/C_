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
	case �𵥵�:
		strcpy_s(tribname, sizeof(tribname), "�𵥵�");
		break;
	case �Ǹ�:
		strcpy_s(tribname, sizeof(tribname), "�Ǹ�");
		break;
	case �߼�:
		strcpy_s(tribname, sizeof(tribname), "�߼�");
		break;
	case ����:
		strcpy_s(tribname, sizeof(tribname), "����");
		break;

	}
}
void Monster::showMonster()
{
	showInfo();	
	cout << "�� ���ʹ� " << tribname << "�� �Դϴ�.\n";
}
