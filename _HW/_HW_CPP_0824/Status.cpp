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
	case ������:
		cout << "������\n";
		break;
	case ������:
		cout << "������\n";
		break;
	case ������:
		cout << "������\n";
		break;
	case �����:
		cout << "�����\n";
		break;
	case ������:
		cout << "������\n";
		break;
	}
}

void Status::showInfo()
{
	cout << "�̸� : " << name << endl;
	cout << "���� \n";
	cout << "����� : " << hp << "\t���ݷ� : " << att << "\t���� : " << def << endl;
	
	cout << "���� : ";
	getperso();
}
