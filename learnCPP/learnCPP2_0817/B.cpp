#include "pch.h"
#include "B.h"
#include "A.h"



B::B(int _data)
{
	data = _data;
}

B::~B()
{
}

void B::showdataA(A a)
{
	cout << "a.data : " << a.data << endl;
}
