#include "pch.h"
#include "note.h"

note::note(const char * name, material mater, int total, int now) :pen(name,mater)
{
	total_count = total;
	now_count = now;
}

note::~note()
{
}

void note::setline(int now)
{
	now_count = now;
}

void note::display()
{
	cout << "총 길이가 " << total_count<<"줄인 공책의 "<<now_count<<"줄에 ";
	print_pen();

}
