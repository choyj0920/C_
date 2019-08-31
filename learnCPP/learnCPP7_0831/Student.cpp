#include "pch.h"
#include "Student.h"

Student::Student(const char * name, int age): age(age)
{
	this->name = new char[10];
	strcpy_s(this->name, strlen(name) + 1, name);
}

void Student::Showinfo()
{
	cout << "이름: " << name << endl; 
	cout << "나이: " << age << endl;
}

Student & Student::operator=(Student & ref)
{
	delete[]name;
	name = new char[strlen(ref.name) + 1];
	strcpy_s(name, strlen(ref.name) + 1, ref.name);
	age = ref.age;
	return *this;
}

Student::~Student()
{
	delete[] name;
	cout << "~student 소멸자 호출!\n";
}
