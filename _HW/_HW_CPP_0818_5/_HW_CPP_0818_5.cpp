
#include "pch.h"
#include <iostream>
#include "SUM.h"

int main()
{
	SUM Ssum;
	cout << Ssum.Hab(12, 56) << endl;
	cout << Ssum.Hab(2.4f, 32.7f) << endl;
	cout << Ssum.ToHab(10) << endl;
	cout << Ssum.ToHab(11, 50) << endl;
}
