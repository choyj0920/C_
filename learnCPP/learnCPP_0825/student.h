#pragma once
#include "person.h"
class student :
	public person
{
	int student_id_;
public:
	student(int sid,const char*name,int age);
	~student();
	virtual void showpersoninfo();
};

