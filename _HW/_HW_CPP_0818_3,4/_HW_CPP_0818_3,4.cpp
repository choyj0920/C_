
#include "pch.h"
#include <iostream>
#include "NameCard.h"
int main()
{
	//예제 3
	NameCard nc("Lee Ji Sun", "333-333", "www.ezsun.net", 3);
	nc.print_info();
	
	cout << endl;
	cout << endl;

	//예제4
	NameCard * human[5];  //포인터 배열
	int n = 2;
	for (int i = 0; i < n; i++) {
		human[i] = new NameCard();
		cout << i + 1 << "번 째 명함 생성! \n정보를 입력하세요\n";
		human[i]->setName();
		human[i]->setNum();	
		human[i]->setAdr();
		human[i]->setgrad();
	}
	for (int i = 0; i < n; i++) {
		cout << i + 1 << "번 째 명함 : \n";
		human[i]->print_info();
		delete human[i];
	}
	
	
}
