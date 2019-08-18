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
	cout << _name << "의 나이는 " << _age << "살 이다.\n";
}

void DOG::eat_bone(BON bon)
{
	cout << _name << "는 살이 ";
	switch (bon.sal_q)
	{
	case 많이:
		cout << "많이";
		break;
	case 적당히:
		cout << "적당히";
		break;
	case 적게:
		cout << "적게";
		break;
	}
	cout << " 붙은 뼈다귀를 먹고 있다\n";
}

