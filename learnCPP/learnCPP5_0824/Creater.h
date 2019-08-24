#pragma once
#include "Human.h"

class Creater :public Human
{
	char compan[30];


public:
	Creater(int _age, const char* _name, const char* compan);
	void whatdoing_cre(int n);
	void createrInfo();
	~Creater();
};

