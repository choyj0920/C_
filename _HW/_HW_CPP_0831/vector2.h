#pragma once
#include <math.h>
#include "MathM.h"
class MathM;

class vector2
{
	float x, y;
public:
	
	vector2();
	vector2(float x, float y);
	void setvector2(float x, float y);
	void showinfo();
	vector2 operator+(vector2 &ref);
	vector2 operator-(vector2 &ref);
	vector2 operator*(double);
	float Distance();
	vector2 Normalize();
	~vector2();
};

