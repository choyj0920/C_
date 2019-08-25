#include "pch.h"
#include "student.h"

student::student(int sid, const char * name, int age): person(name,age)
{
	student_id_ = sid;
}

student::~student()
{
}

void student::showpersoninfo()
{
	person::showpersoninfo();
	cout << "이 학생의 학번은 " << student_id_<<"입니다\n";
}
