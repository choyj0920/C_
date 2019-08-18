#include "pch.h"
#include "DOG.h"

DOG::DOG(const char * name, int age)
{
	int len = strlen(name) + 1;
	sprintf_s(_name, len, name);
	_age = age;
}

void DOG::print_info()
{
	cout << _name << "�� ���̴� " << _age << "�� �̴�.\n";
}

void DOG::eat_bone(BON bon)
{
	cout << _name << "�� ���� ";
	switch (bon.sal_q)
	{
	case ����:
		cout << "����";
		break;
	case ������:
		cout << "������";
		break;
	case ����:
		cout << "����";
		break;
	}
	cout << " ���� ���ٱ͸� �԰� �ִ�\n";
}

