#include "pch.h"
#include "Human.h"


//Human::Human() {
//	cout << "생성자가 호출~" << endl;
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
		sprintf_s(sex, sizeof(sex), "남자");
	else
		sprintf_s(sex, sizeof(sex), "여자");
	cout << "이름 : " << _name << " 나이: " << _age <<" "<< sex << endl;

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
		cout << "하하하하" << endl;
	else
		cout << "호호호호" << endl;
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
	cout <<GetName()<<" 소멸자가 호출."<<endl;
	delete[] _name;

}