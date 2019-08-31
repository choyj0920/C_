
#include "pch.h"
#include <iostream>
#include "NUMBOX.h"
#include "Student.h"
#include "vector2.h"

template<typename T>
void Swap(T& num1, T& num2) {
	T temp = num1;
	num1 = num2;
	num2 = temp;
}
int main()
{
	//연산자 오버로딩 +,-,*,/연산을 클래스 객체도 할수있게   
	/*
	NUMBOX nb1(10, 20);
	NUMBOX nb2(5, 2);
	NUMBOX result = nb1 + nb2;
	NUMBOX result2 = nb1.operator+ (nb2);
	NUMBOX result3 = nb1 + 10;

	nb1.ShowNumber();
	nb2.ShowNumber();
	result.ShowNumber();
	result2.ShowNumber();
	result3.ShowNumber();
	*/
	
	//
	/*
	NUMBOX nb1(10, 20);
	NUMBOX result =10+ nb1 + 40;
	nb1.ShowNumber();
	result.ShowNumber();
	*/
	//단항 연산자
	/*
	NUMBOX nb1(10, 20);
	nb1.ShowNumber();
	(++nb1).ShowNumber();
	(nb1++).ShowNumber();
	nb1.ShowNumber();
	*/

	//대입연산자 오버로딩 
	/*
	Student st1("김철수", 14);
	Student st2("이영희", 15);
	st1.Showinfo();
	st2.Showinfo();
	cout << "==============================\n";
	st2 = st1;
	st1.Showinfo();
	st2.Showinfo();
	*/

	//예제 vector2 클래스 
	/*
	vector2 v1(10.55, 12.4);
	vector2 v2(12.05, 11.24);
	v1.showinfo();
	v2.showinfo();
	//벡터 연산
	vector2 vr = v1 + v2;
	vr.showinfo();
	vr = v1 - v2;
	vr.showinfo();
	vr = v1 * 30;
	vr.showinfo();
	//단위 벡터로 만들기
	cout << "단위 벡터 만들기 \n";
	vr = vr.Normalize();
	vr.showinfo();
	cout<<vr.Distance()<<endl;
	*/
	//템플릿
	int num1 = 10, num2 = 40;
	cout << "before,	num1 : " << num1 << "	num2 : " << num2 << endl;
	Swap(num1, num2);
	cout << "after,	num1 : " << num1 << "	num2 : " << num2 << endl;

	double num3 = 15.6, num4 = 14.44;
	cout << "before,	num3 : " << num3 << "	num4 : " << num4 << endl;
	Swap(num3, num4);
	cout << "after,	num3 : " << num3 << "	num4 : " << num4 << endl;

	char ch1 = 'a',  ch2 = 'Q';
	cout << "before,	ch1 : " << ch1 << "	ch2 : " << ch2 << endl;
	Swap(ch1, ch2);
	cout << "after,	ch1 : " << ch1 << "	ch2 : " << ch2 << endl;

}
