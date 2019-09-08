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
	cout << name << ", \t" << price << ",\t" << grade << "등급.\n";
}

void item::show_info2()
{
	cout << "이름 : "<< name << "\n가격 : " << price << "\n등급 : " << grade << "등급\n";

}

item::~item()
{
}
