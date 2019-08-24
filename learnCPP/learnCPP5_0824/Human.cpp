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
	cout << "¾ÆÄ§¹ä!" << endl;
}

void Human::luncheon()
{
	cout << "Á¡½É¹ä!" << endl;
}

void Human::abendessen()
{
	cout << "Àú³á¹ä!\n";
}
void Human::showInfo()
{
	cout << "ÀÌ¸§ : " << name << endl;
	cout << "³ªÀÌ : " << age << endl;
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
	if (n >= 2 && n < 7) cout << "ÀÚ´ÂÁß \n";
	else if (n == 8) cout << "¾ÆÄ§\n";
	else if (n == 13) cout << "Á¡½É~\n";
	else if (n == 19) cout << "Àú³á~\n";
}
