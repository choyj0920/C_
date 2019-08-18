#pragma once
class GRADE
{
	char _name[100] = { 0, };
	int korean_score;
	int english_score;
	int math_score;
	double aver_score;
public:
	GRADE(const char*name);
	void set_score(int ks,int es,int ms);
	void print_score();
	~GRADE();
};

