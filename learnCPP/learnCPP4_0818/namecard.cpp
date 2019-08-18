#include "pch.h"
#include "namecard.h"




namecard::namecard()
{
	_name = 0;
	_address = 0;
}

void namecard::setinfo(const char * name, int * nums, const char * add, int grade)
{
	int len_name = strlen(name) + 1;
	int len_add = strlen(add) + 1;
	if (_name) {
		delete[]  _name ;
		_name = NULL;
	}
	if (_address) {
		delete[] _address;
		_address = NULL;
	}

	_name = new char[len_name];
	_address = new char[len_add];
	sprintf_s(_name, len_name, name);
	sprintf_s(_address, len_add, add);
	for (int i = 0; i < 7; i++) numbers[i] = *(nums + i);
	_grade = grade;
}

namecard::namecard(const char * name, int * nums, const char * add, int grade)
{
	int len_name = strlen(name) + 1;
	int len_add = strlen(add) + 1;
	if (_name) {
		delete[] _name;
		_name = NULL;
	}
	if (_address) {
		delete[] _address;
		_address = NULL;
	}
	_name = new char[len_name];
	_address = new char[len_add];
	sprintf_s(_name, len_name, name);
	sprintf_s(_address, len_add, add);
	for (int i = 0; i < 7; i++) numbers[i] = *(nums + i);
	_grade = grade;
}

void namecard::print_info()
{
	cout << "이름 : " << _name << endl;
	cout << "전화 번호 : ";
	for (int i = 0; i < 7; i++) {
		if (i == 3) cout << "-";
		cout << numbers[i];
	}
	cout << endl;
	cout << "주소 : " << _address << endl;
	cout << "직급 : ";
	

	switch (_grade)
	{
	case 인턴:
		printf("인턴");
		break;
	case 대리:
		printf("대리");
		break;
	case 과장:
		printf("과장");
		break;
	case 부장:
		printf("부장");
		break;
	case 사장:
		printf("사장");
		break;
	}
	cout << endl;

}

namecard::~namecard()
{
	if (_name) {
		delete[]_name;
		_name = NULL;
	}
	if (_address) {
		delete[]_address;
		_address = NULL;
	}
}
