
#include "pch.h"
#include <iostream>
#include "BON.h"
#include "DOG.h"
int main()
{
	DOG puppy("멍뭉이", 3);
	BON Bo1(적게);
	BON Bo2(많이);
	
	puppy.print_info();
	puppy.eat_bone(Bo1);
	puppy.eat_bone(Bo2);
}
