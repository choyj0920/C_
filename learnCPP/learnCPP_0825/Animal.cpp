#include "pch.h"
#include "Animal.h"


Animal::Animal()
{
}


Animal::~Animal()
{
}

char * Animal::getname()
{
	return name;
}

int * Animal::getleg()
{
	return &leg_count;
}

void Animal::setIN(const char* name,int leg)
{
	strcpy_s(this->name, sizeof(this->name), name);
	this->leg_count = leg;
}

void Animal::printIN()
{
	cout << "�̸� : " << this->name << " \\ �ٸ� �� : " << leg_count;
}
