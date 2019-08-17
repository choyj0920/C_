#pragma once
class B;


class A
{
private:
	int data;
public:
	A(int _data);
	void showdata(B b);
	friend class B;
};

