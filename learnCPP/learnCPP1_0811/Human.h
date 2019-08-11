#pragma once

class Human {
	char* _name;
	int _age;
	bool _isMan;
public:
	//Human();  //기본 생성자
	Human(const char *name,int age, bool isman);  //초기화 생성자 , 생성 초기화(생성하며 초기화까지~)
	void ShowInfo();
	void SetInfo(const char* name, int age, bool isman);
	void Showlaughter();
	void SetAge(int age);
	int GetAge();
	char* GetName();
	~Human();
};
