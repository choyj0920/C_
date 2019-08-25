#include "pch.h"
#include "MaleFemale.h"


MaleFemale::MaleFemale() : Animal()
{
}


MaleFemale::~MaleFemale()
{
}

void MaleFemale::setInfo(const char * name, int leg, int male)
{
	setIN(name, leg);
	this->male = male;
}



void MaleFemale::printInfo()
{
	printIN();
	cout<< " \\ ���� : ";
	if (!male) cout << "����\n";
	else cout << "����\n";
}
