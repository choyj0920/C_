#pragma once
#include "Vector2.h"
#include <math.h>
class MathM
{
public:
	MathM();
	~MathM();
	static float Distance(Vector2 &v1, Vector2 &v2);
	static Vector2 Direction(Vector2 &origin, Vector2 &target);
	
};

