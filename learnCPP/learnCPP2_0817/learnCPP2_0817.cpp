// learnCPP2_0817.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include "pch.h"
#include <iostream>
#include "MathC.h"

#define GOB3(x) ((x)*(x)*(x))

inline int CU(int x) {
	return x * x*x;
}

#include "A.h"
#include "B.h"
#include "apple.h"
#include "Beggar.h"
int main()
{
	// 객체 복사 얇은 복사 ,깊은 복사,  static 정적 변수 
	/*
	MyClass mc1(50, 40, "Hello C++");
	mc1.ShowData();
	cout << "mc1.count = " << mc1.count << endl;
	MyClass mc2 = mc1;
	mc2.ShowData();
	cout << "mc2.count = " << mc2.count << endl;

	mc1.count = 100;
	mc1.SetNum1(99);
	mc1.SetNum2(2);
	mc1.ShowData();
	MyClass::count = 999;
	cout << "mc1.count = " << mc1.count << endl;
	mc2.ShowData();
	cout << "mc2.count = " << mc2.count << endl;
	*/

	//정적 메소드
	/* 
	cout<<"10+ 76 = "<<MathC::Plus(10, 76)<< endl;
	*/

	// inline 키워드 함수  #define과의 차이
	/*
	cout << GOB3(7.2) << endl;
	cout << CU(7.2) << endl;
	*/

	//friend class 
	/*
	A a(10);
	B b(20);
	a.showdata(b);
	b.showdataA(a);
		*/

	//연습문제
	apple appletree;
	Beggar b;
	appletree.print_Count();
	for (int i = 0; i <= 15; i++) {
		b.ddagi(&appletree);
	}

	system("pause");
	return 0;

}
