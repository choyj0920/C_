#pragma once
class person
{
	char name[20];
	int age_;
public:
	person(const char* name, int age);
	virtual void showpersoninfo();
	~person();
};

