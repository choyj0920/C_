
#include "pch.h"
#include <iostream>
#include"Printer.h"
#include "Rectangle2.h"
#include "CIrcle.h"
int main()
{
	//예제 1
	Printer p1;
	p1.scanf_str("Hello World!!");

	p1.print_str();
	p1.scanf_str("I LOVE C++");
	p1.print_str();

	//예제 2
	Rectangle2 rec1(4.5, 12.3);
	Circle cir1(8.5);

	printf(" 둘레 : %.2lf\n", rec1.print_dool());
	printf(" 면적 : %.2lf\n", rec1.print_nul());
	printf(" 둘레 : %.2lf\n", cir1.print_dool());
	printf(" 면적 : %.2lf\n", cir1.print_nul());

}

