#include "pch.h"
#include "pen.h"




pen::pen(const char * name, material mater) :ink()
{
	strcpy_s(this->name, sizeof(this->name), name);
	this->mater = mater;
}

pen::~pen()
{
}

void pen::setname(const char * name)
{
	strcpy_s(this->name, sizeof(this->name), name);

}

void pen::setmat(material mater)
{
	this->mater = mater;

}

void pen::print_pen()
{
	print_ink();
	switch (mater)
	{
	case 플라스틱:
		cout << "플라스틱";
		break;
	case 고무:
		cout << "고무 입니다";

		break;
	case 나무:
		cout << "나무";

		break;
	case 알류미늄:
		cout << "알류미늄";

		break;
	case 탄소:
		cout << "탄소";

		break;
	default:
		break;
	}
	cout <<" "<<name<<"으로 글을 쓴다\n";

}
