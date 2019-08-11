
#include "pch.h"
#include <iostream>
#include "character.h"

typedef enum  personality
{
	������ = 1,
	������,
	�����,
	������,
	������
}personality;

typedef enum tribe {
	�ΰ� = 1,
	�Ǹ�
}tribe;

character::character() {
	_name = 0;
	_pers = �����;
	_trib = �ΰ�;
}

void character::SetInfo(const char* name, int pers, int trib) {
	int len = strlen(name) + 1;
	_name = new char[len];
	sprintf_s(_name, len, name);
	_pers = pers;
	_trib = trib;
}



void character::ShowInfo() {
	print_trib();
	cout << "�� " << _name << "�� ";
	print_pers();
	cout<<" �����Դϴ�" << endl;
}

void character::print_pers() {
	switch (_pers) {
	case ������: 
		cout << "������";
		break;
	case ������:
		cout << "������";
		break;
	case �����:
		cout << "�����";
		break;
	case ������:
		cout << "������";
		break;
	case ������:
		cout << "������";
		break;
	}
}
void character::print_trib() {
	switch(_trib) {
	case �ΰ�:
		cout << "�ΰ�";
		break;
	case �Ǹ�:
		cout << "�Ǹ�";
		break;
	}
	
}

character::~character() {
	cout << _name << " �Ҹ��� ȣ��!" << endl;
	delete(_name);
	_name = NULL;
}
