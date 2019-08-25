#include "pch.h"
#include "ink.h"


void ink::set(color colo, amount much)
{
	this->colo = colo;
	this->much = much;
}

void ink::setcolor(color colo)
{
	this->colo = colo;
}

void ink::setmuch(amount much)
{
	this->much = much;

}

void ink::print_ink()
{
	cout << "양이 ";
	switch (much)
	{
	case 없음:
		cout << "없음";
		break;
	case 조금:
		cout << "조금";

		break;
	case 보통:
		cout << "보통";

		break;
	case 넉넉:
		cout << "넉넉";

		break;
	case 많음:
		cout << "많음";

		break;
	default:
		break;
	}
	cout << "인 ";

	switch (colo)
	{
	case red:
		cout << "빨간";
		break;
	case yellow:
		cout << "노란";

		break;
	case blue:
		cout << "파란";

		break;
	case white:
		cout << "하얀";

		break;
	case black:
		cout << "검은";

		break;

	}
	cout << "색의 ";
}

ink::ink()
{
}


ink::~ink()
{
}
