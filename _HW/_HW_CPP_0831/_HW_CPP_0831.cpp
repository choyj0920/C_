#include "pch.h"
#include <iostream>
#include "MathM.h"
#include "vector2.h"

int main()
{
	
	vector2 start_loc;
	vector2 final_loc(52.11,40.44);
	vector2 dir_v();
	start_loc.setvector2(12.33, 15.33);
	dir_v() = MathM::Direction(start_loc, final_loc);
	cout << "start : ";
	start_loc.showinfo();
	cout << endl;
	cout << "final : ";
	final_loc.showinfo();
	cout << "Direction : ";
	dir_v().showinfo();


}
