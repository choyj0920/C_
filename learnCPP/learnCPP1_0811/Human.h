#pragma once

class Human {
	char* _name;
	int _age;
	bool _isMan;
public:
	//Human();  //�⺻ ������
	Human(const char *name,int age, bool isman);  //�ʱ�ȭ ������ , ���� �ʱ�ȭ(�����ϸ� �ʱ�ȭ����~)
	void ShowInfo();
	void SetInfo(const char* name, int age, bool isman);
	void Showlaughter();
	void SetAge(int age);
	int GetAge();
	char* GetName();
	~Human();
};
