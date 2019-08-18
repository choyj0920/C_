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
	cout << "�̸� : " << _name << endl;
	cout << "���� : " << korean_score << "��" << endl;
	cout << "���� : " << english_score << "��" << endl;
	cout << "���� : " << math_score << "��" << endl;
	printf("��� : %.1lf��\n", aver_score);
}


GRADE::~GRADE()
{
}
