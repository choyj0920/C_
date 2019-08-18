#include "pch.h"
#include "Printer.h"


void Printer::scanf_str(const char * str)
{
	int len = strlen(str) + 1;
	if (_str) {
		delete []_str;
		_str = NULL;
	}
	_str = new char[len];

	sprintf_s(_str, len, str);
}

void Printer::print_str()
{
	cout << _str<<endl;
}

Printer::Printer()
{

}


Printer::~Printer()
{
}
