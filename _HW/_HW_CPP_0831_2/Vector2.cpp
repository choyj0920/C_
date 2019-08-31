#include "pch.h"
#include "Vector2.h"


Vector2::Vector2()
{
}

Vector2::Vector2(float x, float y):x(x),y(y)
{
}

void Vector2::setVector2(float x, float y)
{
	this->x = x;
	this->y = y;
}

void Vector2::showinfo()
{
	printf("x = %.3lf, y = %.3lf\n", x, y);

}

Vector2 Vector2::operator+(Vector2 & ref)
{
	return Vector2(x + ref.x, y + ref.y);
}

Vector2 Vector2::operator-(Vector2 & ref)
{
	return Vector2(x - ref.x, y - ref.y);
}

Vector2 Vector2::operator*(float num)
{
	return Vector2(x*num,y*num);
}

float Vector2::Distance()
{
	return sqrt(x*x + y * y);
}

Vector2 Vector2::Normalize()
{
	return *(this)*(1 / Distance());
}


Vector2::~Vector2()
{
}
