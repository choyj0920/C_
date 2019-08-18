#pragma once
#include "BON.h"

class DOG
{
private:
	char _name[20];
	int _age;
public:
	DOG(const char * name,int age);
	void print_info();
	void eat_bone(BON bon);
};

