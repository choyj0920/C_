#include "pch.h"
#include "person.h"





person::person(const char* name, int age)
{
	strcpy_s(this->name, sizeof(this->name), name);
	age_ = age;
}

void person::showpersoninfo()
{
	cout << name << "�� ���̴� " << age_ << "�� �Դϴ�.\n";
}

person::~person()
{
}
