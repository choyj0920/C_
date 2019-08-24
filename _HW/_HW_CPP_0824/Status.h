#pragma once
typedef enum personal {
	난폭함 = 1, 조급함, 평범함, 느긋함, 조용함
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