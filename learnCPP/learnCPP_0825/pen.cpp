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
	case �ö�ƽ:
		cout << "�ö�ƽ";
		break;
	case ��:
		cout << "�� �Դϴ�";

		break;
	case ����:
		cout << "����";

		break;
	case �˷��̴�:
		cout << "�˷��̴�";

		break;
	case ź��:
		cout << "ź��";

		break;
	default:
		break;
	}
	cout <<" "<<name<<"���� ���� ����\n";

}
