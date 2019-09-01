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
	static void save_file(Student **stus, int stu_count);
	static void print_Info(Student **stus);
	static void set_count(int n);
	void setInfo(const char *, int ban, int kon_s, int eng_s);
	~Student();
};