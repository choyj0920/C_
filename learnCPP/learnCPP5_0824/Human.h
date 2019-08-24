#pragma once
class Human
{
private:
	int age;
	char name[10];
public:
	Human();
	Human(int _age, const char* _name);
	void breakfast();
	void luncheon();
	void abendessen();
	~Human();
	void whatdoing(int n);
	void showInfo();

protected:
	void  InitialData(int age, const char * name);
	char* getname();
	int getAge();

};

