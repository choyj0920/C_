#include "pch.h"
#include "Class.h"

void A::over()
{
	cout << "AŬ������ over �Լ� ȣ��!" << endl;
}

void B::over()
{
	A::over();
	cout << "BŬ������ over �Լ� ȣ��!" << endl;

}
