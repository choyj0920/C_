#include "pch.h"
#include "SUM.h"


inline int SUM::Hab(int a, int b)
{

	return a+b;
}

inline float SUM::Hab(float a, float b)
{
	return a+b;
}

inline int SUM::ToHab(int a)
{
	int tot = 0;
	for (int n = 1; n <= a; tot += n++);
	return tot;
}

inline int SUM::ToHab(int a, int b)
{
	int tot = 0;
	for (int n = a; n <= b; tot += n++);

	return tot;
}

SUM::SUM()
{
}


SUM::~SUM()
{
}
