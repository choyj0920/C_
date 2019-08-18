#include "pch.h"
#include "CIrcle.h"
#include<iostream>


double Circle::print_nul()
{
	return _r * _r*RADIAN;
}

double Circle::print_dool()
{
	return _r * 2 * RADIAN;

}

Circle::Circle(double r)
{
	_r = r;
}



Circle::~Circle()
{
}
