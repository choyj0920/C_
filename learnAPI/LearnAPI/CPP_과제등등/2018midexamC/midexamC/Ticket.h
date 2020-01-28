#pragma once
class Ticket
{
private:
	string Tname;
	double price;
	string Fname;
	int row, col;
	int**map;
	User**user;
	double totalincome;

public:
	Ticket();
	Ticket(string name,double price,string fname);
	Ticket(Ticket &t);
	~Ticket();

	void showseat() const;
	void reserve();
	void confirm();
	void cancel();
	double getTotalIncome();
};

