
#include "pch.h"
#include <iostream>


#include "apple.h"
#include "Beggar.h"

int main()
{
    apple appletree;
	Beggar b;
	appletree.print_Count();
	for (int i = 0; i <= 15; i++) {
		b.ddagi(&appletree);
	}

	system("pause");
	return 0;
}
