#include "pch.h"
#include <iostream>
#include "ADDClass.h"
int main()
{
	ADDClass adc;
	adc.Set(10, 40);
	ADDClass::Disp1(&adc);
	adc.Set(40, 100);
	ADDClass::Disp1(&adc);

}
