#pragma once
#include <math.h>
#include "vector2.h"

class vector2;

class MathM
{
	
public:
	static float Distance(vector2 v1, vector2 v2);
	static vector2 Direction(vector2 origin,vector2 target);
};

