#pragma once
typedef enum personal {
	������ = 1, ������, �����, ������, ������
}pers;

class Status
{
	char name[20];
	int hp;
	int att;
	int def;
	int perso;
public:
	Status(const char *name,int hp,int att,int def,int perso);
	
	~Status();
	void getperso();
	void showInfo();
};