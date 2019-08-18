#pragma once
enum position {
	인턴 = 1,
	대리,
	과장,
	부장,
	사장
};

class NameCard
{
	char *_name = 0;
	char *_num = 0;
	char *_adr = 0;
	int _grad;
public:
	NameCard();
	NameCard(const char* name, const char* num,const char* adr,int grad);
	void setName();
	void setNum();
	void setAdr();
	void setgrad();
	void print_info();


	~NameCard()
	{
		if (_name) {
			delete[] _name;
			_name = 0;
		}
		if (_num) {
			delete[] _num;
			_num = 0;
		}
		if (_adr) {
			delete[] _adr;
			_adr = 0;
		}
	}
};

