#pragma once
#include "Score.h"
class Student :
	public Score
{
private:
	static int count;
	char name[20];
	int ban;
public:
	Student(const char * name,int ban,int kon_s, int eng_s);
	static void showInfo();
	~Student();
};

