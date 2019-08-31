#include "pch.h"
#include "MathM.h"

MathM::MathM()
{
}

MathM::~MathM()
{
}

float MathM::Distance(Vector2 & v1, Vector2 & v2)
{
	//float dis2 = (v2.x - v1.x)*(v2.x - v1.x) + (v2.y - v1.y)*(v2.y - v1.y);
	//return sqrt(dis2);
	Vector2 dis = v2 - v1; //vector2 operator-
	return dis.Distance();
}

Vector2 MathM::Direction(Vector2 & origin, Vector2 & target)
{
	Vector2 dir = target - origin; //vector2 operator-
	return dir * (1 / Distance(origin, target));	//vector2 operator
}
