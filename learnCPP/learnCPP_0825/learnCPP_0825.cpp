

#include "pch.h"
#include <iostream>
#include "Class.h"
#include "Class_PC.h"
#include "Animal.h"
#include "MaleFemale.h"
#include "note.h"
#include "student.h"
void set_info(MaleFemale * M);

int main()
{
	// 상속오버라이딩
	/*
	B b;
	b.over();
	A *pa = &b;
	pa->over();
	*/
	//가상함수
	/*
	Parent P, *pP;
	Child C;
	pP = &P;
	pP->func();
	pP = &C;
	pP->func();
	return 0;
	*/
	//연습문제9 
	/*
	int menu=0;
	MaleFemale A;
	set_info(&A);

	while (menu != 3) {
		menu = 0;

		while (menu>3 || menu < 1) {
			cout << "메뉴를 선택 하세요 \n" << "1. 출력\n2. 수정\n3. 종료\n";
			scanf_s(" %d", &menu);
		}
		switch (menu)
		{
		case 1:
			A.printInfo();
			break;
		case 2:
			set_info(&A);
			break;
		case 3:
			break;
		}
		
	}
	*/
	//연습문제 10
	/*
	note gongcheck("싸인펜", 플라스틱, 25, 1);
	gongcheck.setcolor(red);
	gongcheck.setmuch(조금);
	gongcheck.display();
	gongcheck.setline(10);
	gongcheck.setcolor(black);
	gongcheck.setname("볼펜");
	gongcheck.setmat(나무);
	gongcheck.display();*/

	//연습문제 11
	student s(123456789, "순신", 35);
	s.showpersoninfo();

}

void set_info(MaleFemale * M) {
	char name[20];
	int leg;
	int male;
	cout << "이름과 다리수를 입력하세요 :";
	cin >> name >> leg;
	cout << "성별을 입력하세요(성별 0= 여성) : ";
	cin >> male;
	M->setInfo(name,leg,male);
	
}