#include "pch.h"
#include "vector2.h"

vector2::vector2()
{
	x = 0;
	y = 0;
}

vector2::vector2(float x, float y) :x(x), y(y)
{
}

void vector2::setvector2(float x, float y)
{
	this->x = x;
	this->y = y;
}

void vector2::showinfo()
{
	printf("x = %.3lf, y = %.3lf\n", x, y);
}

vector2 vector2::operator+(vector2 & ref)
{
	return vector2(x + ref.x, y + ref.y);
}

vector2 vector2::operator-(vector2 & ref)
{
	return vector2(x - ref.x, y - ref.y);
}

vector2 vector2::operator*(double num)
{
	return vector2(x*num, y*num);
}

float vector2::Distance()
{
	return sqrt(x*x + y * y);
}

vector2 vector2::Normalize()
{
	return *(this) *(1 / Distance());
}

vector2::~vector2()
{
}
