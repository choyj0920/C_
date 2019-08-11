#pragma once

class character {
	char* _name;
	int _pers;
	int _trib;
	void print_pers();
	void print_trib();
public:
	character();
	void SetInfo(const char* name,int pers, int trib);
	void ShowInfo();
	
	~character();

};
