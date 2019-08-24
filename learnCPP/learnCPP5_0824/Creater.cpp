#include "pch.h"
#include "Creater.h"




Creater::Creater(int _age, const char * _name, const char * compan) :Human(_age, _name)
{
	strcpy_s(this->compan, sizeof(this->compan), compan);
}

void Creater::whatdoing_cre(int n)
{
	if (n > 24 || n < 0) {
		cout << "잘못 입력하셨습니다\n";
		return;
	}
	cout << "이 개발자는 지금 ";
	whatdoing(n);
	if (n == 7) cout << "출근 준비\n";
	else if (n == 9) cout << "출근 중~\n";
	else if (n <13 && n>=10) cout << "오전 근무 중~\n";
	else if (n <19 && n>=15) cout << "오후 작업 중~\n";
	else if (n <22 && n>=20) cout << "야근 중~\n";
	else if (n <24 && n>=22) cout << "야식 ㅎ~\n";
	else if (n ==14) cout << "티타임\n";
	else if (n ==24|| n==0) cout << "집가는중 \n";
	else if (n ==1) cout << "개인 시간 \n";
}

void Creater::createrInfo()
{
	showInfo();
	cout << "소속 회사 : " << compan << endl;
}


Creater::~Creater()
{
}
