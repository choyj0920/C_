#include "pch.h"
#include "Rectangle.h"


Rectangle2::Rectangle2(double a, double b)
{
	_a = a;
	_b = b;
}




double Rectangle2::print_nul()
{
	return _a*_b;
}

double Rectangle2::print_dool()
{
	return (_a+_b)*2;

}

Rectangle2::~Rectangle2()
{
}
