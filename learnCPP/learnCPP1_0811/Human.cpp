#include "pch.h"
#include "Human.h"


//Human::Human() {
//	cout << "�����ڰ� ȣ��~" << endl;
//}

Human::Human(const char *name, int age, bool isman) {
	int len = strlen(name) + 1;
	_name = new char[len];
	sprintf_s(_name, len, name);
	_age = age;
	_isMan = isman;
}


void Human::ShowInfo() {
	char sex[10] = { 0, };
	if (_isMan)
		sprintf_s(sex, sizeof(sex), "����");
	else
		sprintf_s(sex, sizeof(sex), "����");
	cout << "�̸� : " << _name << " ����: " << _age <<" "<< sex << endl;

}
void Human::SetInfo(const char* name, int age, bool isman) {
	int len = strlen(name) + 1;
	if (_name) {
		delete[] _name;
		_name = NULL;
	}
	name = new char[len];
	sprintf_s(_name, len, name);
	_age = age;
	_isMan = isman;
}
void Human::Showlaughter() {
	if (_isMan)
		cout << "��������" << endl;
	else
		cout << "ȣȣȣȣ" << endl;
}
void Human::SetAge(int age) {
	_age = age;
}
int Human::GetAge() {
	return _age;
} 

char* Human::GetName() {
	return _name;
}
Human::~Human() {
	cout <<GetName()<<" �Ҹ��ڰ� ȣ��."<<endl;
	delete[] _name;

}