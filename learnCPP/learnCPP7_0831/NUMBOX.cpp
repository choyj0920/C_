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

NUMBOX NUMBOX::operator++()  //++�� �տ� ���϶�
{
	num1 += 1; num2 += 1;
	return *this;
}

NUMBOX NUMBOX::operator++(int) //++�� �ڿ� ���϶� 
{
	NUMBOX temp(*this);
	num1 += 1; num2 += 1;
	return temp;
}

NUMBOX operator+(int num, NUMBOX ref) //�� ��ü�� ���׿����ڱ� ������
{
	ref.num1 += num;
	ref.num2 += num;
	return ref;
}