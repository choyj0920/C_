#pragma once
class item
{
	string name;
	int price;
	int grade;
public:
	item(const string,int price, int grade);
	item();
	void show_info();
	void show_info2();
	~item();
};

