#pragma once
#include "ink.h"
typedef enum material {
	�ö�ƽ = 1, ��, ����, �˷��̴�,ź��
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

