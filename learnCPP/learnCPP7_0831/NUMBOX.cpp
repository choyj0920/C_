#include "pch.h"
#include "NUMBOX.h"



NUMBOX::NUMBOX(int num1, int num2) :num1(num1), num2(num2)
{
	
}

void NUMBOX::ShowNumber()
{
	cout << "num1: " << num1 << " num2: " << num2 << endl;
}

NUMBOX NUMBOX::operator+(NUMBOX & ref)
{
	return NUMBOX(num1 + ref.num1, num2 + ref.num2);
}

NUMBOX NUMBOX::operator+(int num)
{

	return NUMBOX(num1 + num, num2 + num);
}

NUMBOX NUMBOX::operator++()  //++를 앞에 붙일때
{
	num1 += 1; num2 += 1;
	return *this;
}

NUMBOX NUMBOX::operator++(int) //++를 뒤에 붙일때 
{
	NUMBOX temp(*this);
	num1 += 1; num2 += 1;
	return temp;
}

NUMBOX operator+(int num, NUMBOX ref) //이 자체가 이항연산자기 때문에
{
	ref.num1 += num;
	ref.num2 += num;
	return ref;
}