#include "pch.h"
#include "person.h"





person::person(const char* name, int age)
{
	strcpy_s(this->name, sizeof(this->name), name);
	age_ = age;
}

void person::showpersoninfo()
{
	cout << name << "의 나이는 " << age_ << "살 입니다.\n";
}

person::~person()
{
}
