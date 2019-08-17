#include "pch.h"
#include "apple.h"
#include "Beggar.h"


apple::apple()
{
	apple_count = 15;
}

void apple::print_Count()
{
	cout << "현재 사과의 갯수는 " << apple_count << "입니다\n";
}
