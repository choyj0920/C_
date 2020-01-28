#include "pch.h"

int main()
{
	std::cout << "201810754 조윤직\n";

	Ticket ticket("홍길동 날다", 1000, "seat1.txt");
	ticket.reserve();
	ticket.reserve();
	ticket.reserve();
	cout << "총 공연 수입 : " << ticket.getTotalIncome() << endl;
	ticket.confirm();
	ticket.cancel();
	ticket.showseat();
	cout << "총 공연 수입 : " << ticket.getTotalIncome() << endl;


	Ticket ticket1(ticket);
	ticket.showseat();
}

