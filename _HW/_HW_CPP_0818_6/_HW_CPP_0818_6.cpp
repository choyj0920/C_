#include "pch.h"
#include <iostream>
#include "GRADE.h"
int main()
{
	GRADE n1("김철수");
	GRADE n2("김영희");

	n1.set_score(52, 68, 71);
	n2.set_score(83, 70, 91);
	n1.print_score();
	n2.print_score();

}
