
#include "pch.h"
#include <iostream>
#include "character.h"

typedef enum  personality
{
	난폭한 = 1,
	예민한,
	평범한,
	무난한,
	게으른
}personality;

typedef enum tribe {
	인간 = 1,
	악마
}tribe;

character::character() {
	_name = 0;
	_pers = 평범한;
	_trib = 인간;
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
	cout << "족 " << _name << "은 ";
	print_pers();
	cout<<" 성격입니다" << endl;
}

void character::print_pers() {
	switch (_pers) {
	case 난폭한: 
		cout << "난폭한";
		break;
	case 예민한:
		cout << "예민한";
		break;
	case 평범한:
		cout << "평범한";
		break;
	case 무난한:
		cout << "무난함";
		break;
	case 게으른:
		cout << "게으른";
		break;
	}
}
void character::print_trib() {
	switch(_trib) {
	case 인간:
		cout << "인간";
		break;
	case 악마:
		cout << "악마";
		break;
	}
	
}

character::~character() {
	cout << _name << " 소멸자 호출!" << endl;
	delete(_name);
	_name = NULL;
}
