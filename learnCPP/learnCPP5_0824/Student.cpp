#include "pch.h"
#include "Student.h"



void Student::SetInfo(int _age, const char * _name, const char * _school, int id)
{
	InitialData(_age, _name);
	strcpy_s(school, sizeof(school),_school);
	this->id = id;
}

Student::Student()
{

}

void Student::GetInfo()
{
	showInfo();
	cout << "�й� : " << id << endl;
}



Student::Student(int _age, const char * _name, const char * _school,int id) :Human(_age,_name)
{
	strcpy_s(school, sizeof(school), _school);
	this->id = id;
}



void Student::schoolInfo()
{
	showInfo();
	cout << "�Ҽ� �б� : " << school << endl;
}

Student::~Student()
{
}
