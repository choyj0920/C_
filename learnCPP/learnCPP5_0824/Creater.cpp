#include "pch.h"
#include "Creater.h"




Creater::Creater(int _age, const char * _name, const char * compan) :Human(_age, _name)
{
	strcpy_s(this->compan, sizeof(this->compan), compan);
}

void Creater::whatdoing_cre(int n)
{
	if (n > 24 || n < 0) {
		cout << "�߸� �Է��ϼ̽��ϴ�\n";
		return;
	}
	cout << "�� �����ڴ� ���� ";
	whatdoing(n);
	if (n == 7) cout << "��� �غ�\n";
	else if (n == 9) cout << "��� ��~\n";
	else if (n <13 && n>=10) cout << "���� �ٹ� ��~\n";
	else if (n <19 && n>=15) cout << "���� �۾� ��~\n";
	else if (n <22 && n>=20) cout << "�߱� ��~\n";
	else if (n <24 && n>=22) cout << "�߽� ��~\n";
	else if (n ==14) cout << "ƼŸ��\n";
	else if (n ==24|| n==0) cout << "�������� \n";
	else if (n ==1) cout << "���� �ð� \n";
}

void Creater::createrInfo()
{
	showInfo();
	cout << "�Ҽ� ȸ�� : " << compan << endl;
}


Creater::~Creater()
{
}
