#include "pch.h"
#include <iostream>
#include "MathM.h"
int main()
{
	
	Vector2 start_loc;
	Vector2 final_loc(52.11, 40.44);
	Vector2 dir_v;
	start_loc.setVector2(12.33, 15.33);
	dir_v= MathM::Direction(start_loc, final_loc);
	cout << "start : ";
	start_loc.showinfo();
	cout << "final : ";
	final_loc.showinfo();
	cout << "Direction : ";
	dir_v.showinfo();

}
