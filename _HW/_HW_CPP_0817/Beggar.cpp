#include "pch.h"
#include "Beggar.h"
#include "apple.h"


Beggar::Beggar()
{
}


Beggar::~Beggar()
{
}

void Beggar::ddagi(apple* A)
{
	if (A->apple_count == 0) {
		cout << "���̻� ����� ���� �����ϴ� ����� 0������ ��\n"; return ;
	}
	A->apple_count --;
	cout << "����� ������ϴ� !! \n";
	cout << "��� ������ ��� ���� : " << A->apple_count << endl;
}
