#pragma once
class A;

class B
{
private:
	int data;
public:
	B(int _data);
	~B();
	void showdataA(A a);
	friend class A;

};
