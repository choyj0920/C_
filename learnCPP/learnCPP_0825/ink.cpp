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
	cout << "���� ";
	switch (much)
	{
	case ����:
		cout << "����";
		break;
	case ����:
		cout << "����";

		break;
	case ����:
		cout << "����";

		break;
	case �˳�:
		cout << "�˳�";

		break;
	case ����:
		cout << "����";

		break;
	default:
		break;
	}
	cout << "�� ";

	switch (colo)
	{
	case red:
		cout << "����";
		break;
	case yellow:
		cout << "���";

		break;
	case blue:
		cout << "�Ķ�";

		break;
	case white:
		cout << "�Ͼ�";

		break;
	case black:
		cout << "����";

		break;

	}
	cout << "���� ";
}

ink::ink()
{
}


ink::~ink()
{
}
