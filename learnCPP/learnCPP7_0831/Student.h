#pragma once
class Student
{
private:
	char *name;
	int age;
public:
	Student(const char* name, int age);
	void Showinfo();
	Student& operator=(Student& ref);
	~Student();
};

