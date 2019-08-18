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
	cout << " �̸� : ";
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
	cout << " ��ȭ��ȣ : ";
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
	cout << " �ּ� : ";
	scanf_s(" %[^\n]s", adr,200);
	len = strlen(adr) + 1;
	_adr = new char[len];
	sprintf_s(_adr, len, adr);
}

void NameCard::setgrad()
{
	cout << "1. ���� \n2. �븮\n3. ����\n4. ����\n5. ����\n ������ �Է��ϼ��� : ";
	cin >> _grad;

}

void NameCard::print_info()
{
	cout << "��	�� : " << _name << endl;
	cout << "��ȭ ��ȣ : "<<_num <<endl;
	cout << "��	�� : " << _adr << endl;
	cout << "��	�� : ";


	switch (_grad)
	{
	case ����:
		cout << "����";
		break;
	case �븮:
		cout << "�븮";
		break;
	case ����:
		cout << "����";
		break;
	case ����:
		cout << "����";
		break;
	case ����:
		cout << "����";
		break;
	}
	cout << endl;

}

