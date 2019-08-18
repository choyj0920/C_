#include "pch.h"
#include "GRADE.h"



GRADE::GRADE(const char * name)
{
	int len = strlen(name)+1;
	sprintf_s(_name, len, name);

}

void GRADE::set_score(int ks, int es, int ms)
{
	korean_score = ks;
	english_score = es;
	math_score = ms;
	aver_score = (ks + es + ms) / (double)3;
}

void GRADE::print_score()
{
	cout << "이름 : " << _name << endl;
	cout << "국어 : " << korean_score << "점" << endl;
	cout << "영어 : " << english_score << "점" << endl;
	cout << "수학 : " << math_score << "점" << endl;
	printf("평균 : %.1lf점\n", aver_score);
}


GRADE::~GRADE()
{
}
