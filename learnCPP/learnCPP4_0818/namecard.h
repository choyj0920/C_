#pragma once

enum jick {
	���� = 1,
	�븮,
	����,
	����,
	����

};

class namecard
{
	char* _name;
	int numbers[7];
	char* _address;
	int _grade;
public:
	namecard();
	void setinfo(const char *name, int * nums, const char* add, int grade);
	namecard(const char *name, int * nums, const char* add,int grade);
	void print_info();
	~namecard();
};

