#include "pch.h"
#include "item.h"

item::item(string name, int price, int grade) :name(name), price(price),grade(grade)
{
}

item::item()
{
}

void item::show_info()
{
	cout << name << ", \t" << price << ",\t" << grade << "���.\n";
}

void item::show_info2()
{
	cout << "�̸� : "<< name << "\n���� : " << price << "\n��� : " << grade << "���\n";

}

item::~item()
{
}
