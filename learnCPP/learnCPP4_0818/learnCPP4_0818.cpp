// learnCPP4_0818.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include"Printer.h"
#include"Rectangle.h"
#include"Circle.h"
#include"namecard.h"
#include"SUM.h"
int main()
{
	//예제 
	/*
	Printer p1;
	p1.scanf_str("Hello World!!");

	p1.print_str();
	p1.scanf_str("I LOVE C++");
	p1.print_str();
	*/
	//예제 2
	/*

	Rectangle2 rec1(4.5, 12.3);
	Circle cir1(8.5);

	printf(" 둘레 : %.2lf\n", rec1.print_dool());
	printf(" 면적 : %.2lf\n", rec1.print_nul());
	printf(" 둘레 : %.2lf\n", cir1.print_dool());
	printf(" 면적 : %.2lf\n", cir1.print_nul());
	*/
	//예제3,4
	/*
	int num[7] = { 3,3,3,3,3,3,3 };
	
	namecard hum[5];
	char df[200];
	char name[200] , add[200];
	int grade;
	for (int i = 0; i < 1; i++) {
		cout << i + 1 << "번째 사람 정보 입력 !\n";

		cout << "이름 : ";
		gets_s(name, 200);
		
	
		cout << "전화 번호 : ";
		for (int i = 0; i < 7; i++) scanf_s(" %1d", &num[i]);
		gets_s(df,200);
		cout << "주소 : ";
		gets_s(add, 200);
		cout << "1. 인턴 \n 2.대리\n3.과장\n4.부장\n5.사장\n 직급을 입력하세요 : ";
		cin >> grade;
		hum[i].setinfo(name, num, add, grade);
		gets_s(df, 200);

	}
	for (int i = 0; i < 1; i++) {
		hum[i].print_info();
	}
	*/
	//예제5
	SUM Ssum;
	cout << Ssum.Hab(12, 56) << endl;
	cout << Ssum.Hab(2.4f, 32.7f) << endl;
	cout << Ssum.ToHab(10) << endl;
	cout << Ssum.ToHab(11, 50) << endl;

}

