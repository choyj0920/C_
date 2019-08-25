#pragma once
#include "Animal.h"
class MaleFemale :private Animal
{
	int male;
public:
	MaleFemale();
	~MaleFemale();
	void setInfo(const char* name,int leg, int male);
	void printInfo();
};

