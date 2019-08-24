#pragma once
#include "Human.h"
class Student :public Human
{
private:
	char school[30];
	int id;
public:
	void SetInfo(int _age, const char* _name, const char* _school, int id);
	Student();
	void GetInfo();
	Student(int _age,const char* _name,const char* _school,int id);
	void schoolInfo();
	~Student();
};

