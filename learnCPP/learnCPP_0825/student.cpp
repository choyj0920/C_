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
	cout << "�� �л��� �й��� " << student_id_<<"�Դϴ�\n";
}
