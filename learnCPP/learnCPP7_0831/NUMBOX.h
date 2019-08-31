#pragma once
//NUMBOX.h
class NUMBOX {
private:
	int num1, num2;
public:
	NUMBOX(int num1, int num2);
	void ShowNumber();
	NUMBOX operator+(NUMBOX &ref);
	NUMBOX operator+(int num);
	friend NUMBOX operator+(int num, NUMBOX ref);
	NUMBOX operator++();
	NUMBOX operator++(int);
};