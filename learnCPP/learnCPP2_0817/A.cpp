#include "pch.h"
#include "A.h"

#include "B.h"


A::A(int _data)
{
	data = _data;
}

void A::showdata(B b)
{
	cout << "b.data : " << b.data << endl;
}
