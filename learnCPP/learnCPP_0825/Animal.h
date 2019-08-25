#pragma once
class Animal
{
	char name[20];
	int leg_count;
public:
	Animal();
	~Animal();
	char* getname();
	int * getleg();
	void setIN(const char* name, int leg);
	void printIN();
};

