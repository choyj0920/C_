#include "pch.h"


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
