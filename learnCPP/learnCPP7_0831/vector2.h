#pragma once
#include <math.h>
class vector2
{
	double x, y;
public:
	vector2();
	vector2(double x, double y);
	void setvector2(double x, double y);
	void showinfo();
	vector2 operator+(vector2 &ref);
	vector2 operator-(vector2 &ref);
	vector2 operator*(double);
	double Distance();
	vector2 Normalize();
	~vector2();
};

