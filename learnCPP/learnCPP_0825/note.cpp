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
	cout << "�� ���̰� " << total_count<<"���� ��å�� "<<now_count<<"�ٿ� ";
	print_pen();

}
