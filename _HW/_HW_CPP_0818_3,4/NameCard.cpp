#include "pch.h"
#include "NameCard.h"


NameCard::NameCard()
{
	_name = new char[200];
	_adr = new char[200];
	_num = new char[20];
}

NameCard::NameCard(const char * name, const char * num, const char * adr, int grad)
{
	int len_name = strlen(name) + 1;
	int len_num = strlen(num) + 1;
	int len_adr = strlen(adr) + 1;

	_name = new char[len_name];
	_num = new char[len_num];
	_adr = new char[len_adr];
	sprintf_s(_name, len_name, name);
	sprintf_s(_num, len_num, num);
	sprintf_s(_adr, len_adr, adr);
	_grad = grad;

}

void NameCard::setName()
{
	char name[200];
	int len;
	if (_name) {
		delete[] _name;
		_name = 0;
	}
	cout << " 이름 : ";
	scanf_s(" %[^\n]",name,200);
	len = strlen(name) + 1;
	_name = new char[len];
	sprintf_s(_name, len, name);
	
}

void NameCard::setNum()
{
	char num[20];
	int len;
	if (_num) {
		delete[] _num;
		_num = 0;
	}
	cout << " 전화번호 : ";
	scanf_s(" %[^\n]s", num,20);
	len = strlen(num) + 1;
	_num = new char[len];
	sprintf_s(_num, len, num);

}

void NameCard::setAdr()
{
	char adr[200];
	int len;
	if (_adr) {
		delete[] _adr;
		_adr = 0;
	}
	cout << " 주소 : ";
	scanf_s(" %[^\n]s", adr,200);
	len = strlen(adr) + 1;
	_adr = new char[len];
	sprintf_s(_adr, len, adr);
}

void NameCard::setgrad()
{
	cout << "1. 인턴 \n2. 대리\n3. 과장\n4. 부장\n5. 사장\n 직급을 입력하세요 : ";
	cin >> _grad;

}

void NameCard::print_info()
{
	cout << "이	름 : " << _name << endl;
	cout << "전화 번호 : "<<_num <<endl;
	cout << "주	소 : " << _adr << endl;
	cout << "직	급 : ";


	switch (_grad)
	{
	case 인턴:
		cout << "인턴";
		break;
	case 대리:
		cout << "대리";
		break;
	case 과장:
		cout << "과장";
		break;
	case 부장:
		cout << "부장";
		break;
	case 사장:
		cout << "사장";
		break;
	}
	cout << endl;

}

