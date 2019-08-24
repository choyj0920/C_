#include "pch.h"
#include "Human.h"




Human::Human()
{
}

Human::Human(int _age, const char * name) :age(_age)
{
	strcpy_s(this->name, strlen(name) + 1, name);
}

void Human::breakfast()
{
	cout << "��ħ��!" << endl;
}

void Human::luncheon()
{
	cout << "���ɹ�!" << endl;
}

void Human::abendessen()
{
	cout << "�����!\n";
}
void Human::showInfo()
{
	cout << "�̸� : " << name << endl;
	cout << "���� : " << age << endl;
}

void Human::InitialData(int age, const char * name)
{
	this->age = age;
	strcpy_s(this->name, sizeof(this->name), name);
}

char * Human::getname()
{

	return name;
}

int Human::getAge()
{
	return age;
}

Human::~Human()
{
	
}

void Human::whatdoing(int n)
{
	if (n >= 2 && n < 7) cout << "�ڴ��� \n";
	else if (n == 8) cout << "��ħ\n";
	else if (n == 13) cout << "����~\n";
	else if (n == 19) cout << "����~\n";
}
