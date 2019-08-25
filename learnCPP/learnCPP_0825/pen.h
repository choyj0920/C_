#pragma once
#include "ink.h"
typedef enum material {
	ÇÃ¶ó½ºÆ½ = 1, °í¹«, ³ª¹«, ¾Ë·ù¹Ì´½,Åº¼Ò
}material;
class pen : public ink
{
	char name[20];
	material mater;
	
public:
	pen(const char* name, material mater);
	~pen();
	void setname(const char* name);
	void setmat(material mater);
	void print_pen();
};

