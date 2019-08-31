#include "pch.h"
#include "MathM.h"

float MathM::Distance(vector2 v1,vector2 v2)
{
	
	//float dis2 = (v2.x - v1.x)*(v2.x - v1.x) + (v2.y - v1.y)*(v2.y - v1.y);
	//return sqrt(dis2);

	vector2 vec = v2 - v1;	//vector2 operator-
	return vec.Distance();
}

vector2 MathM::Direction(vector2  origin, vector2 target)
{
	vector2 dir_v= target - origin;  //vector2 operator-
	return dir_v * (1 / Distance(origin, target));  //vector2 operator*(float)
}
