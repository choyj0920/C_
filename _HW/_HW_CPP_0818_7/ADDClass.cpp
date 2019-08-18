#include "pch.h"
#include "ADDClass.h"


void ADDClass::Hap()
{
	cout << a + b << endl;
}

ADDClass::ADDClass()
{

}

void ADDClass::Set(int a1, int b1)
{
	a = a1;
	b = b1;
}

void ADDClass::Disp1(ADDClass * p)
{
	printf("%d + %d = ", p->a, p->b);
	p->Hap();
}
