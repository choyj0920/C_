#pragma once
class BASEBALL
{
	int _num[3];
public:
	bool strike3 = false;
	BASEBALL(int * num);
	~BASEBALL();
	void pitching(int *num);
};

