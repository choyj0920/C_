#pragma once
#include "pen.h"
class note :
	public pen
{
	int now_count,total_count;

public:
	note(const char* name,material mater,int total,int now);
	~note();
	void setline(int now);
	void display();
};

