// learnCPP.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>

//Plus함수 오버 로딩
int Plus(int num1, int num2) {
	return num1 + num2;
}
float Plus(float num1, int num2) {
	return num1 + num2;
}
float Plus(int num1, float num2) {
	return num1 + num2;
}
float Plus(float num1, float num2) {
	return num1 + num2;
}
char* Plus(const char* str1,const char* str2) {
	static char str[100] = { 0, };
	sprintf_s(str, sizeof(str), "%s%s", str1, str2);
	return str;
}

namespace A {
	void Add() {
		cout << "A의 Add()호출!\n";
	}
	


}
namespace B {
	void Add() {
		cout << "B의 Add()호출!\n";

	}
}

//print오버로드
void printscreen() {
	cout << "Hello World" << endl;
}
void printscreen(int num) {
	cout << num << endl;
}
void printscreen(float silsu) {
	cout << silsu << endl;
}
void printscreen(int num ,float silsu) {
	cout << num<<":"<<silsu << endl;
}

//디폴트- 함수 1부터 ~입력값or(100)까지 합
int totalSum(unsigned int end = 100) {
	int t = 0;
	for (int n = 1; n <= end; n++) t += n;
	
	return t;
}
//디폴트 예제
void def_print(const char* name, int age, bool isman = true) {
	cout << "이름 : " << name << endl<<"나이 : "<<age<<endl;
	if (isman) cout << "성별 : 남자" << endl;
	else cout << "성별 : 여자" << endl;
}


using namespace A;
int main()
{
	//cout 가지고 놀기
    /*
	cout << "Hello World!"<<endl; 
    std::cout << "Hello World!"<<1234<<std::endl<<3.14; 
	cout << std::endl;
	*/
	
	//cout의 setprecision(자릿수 지정)  --이거는 cout 안에서만 사용
	/*
	cout<< setprecision(3) <<3.141597<<endl;
	cout<< setprecision(5) <<883.147597<<endl;
	cout.setf(ios::fixed);
	streamsize num = cout.precision(5);
	cout<< 1233.141597 << endl;
	cout.precision(num +1);
	cout << 1233.141597 << endl;
	*/

	//입출력 cin, cout
	/*
	int num;
	char str[100];
	cout << "숫자와 문장을 입력 하세요(숫자 문장) : ";
	std::cin  >> num >>str;
	cout <<"숫자 : "<< num<<endl << "문자열 : " << str << endl;
*/

	//예제
	/*
	int age;
	char name[100];
	float ki;
	cout << "이름을 입력하세요 : ";
	cin >> name;
	cout << "나이와 키를 입력하세요 : ";
	cin >> age >> ki;
	cout.setf(ios::fixed);
	streamsize num = cout.precision(1);
	cout << "당신의 이름은 [" << name << "]님 입니다." << endl << "당신은 " << age << "살, 키 " << ki << "Cm의 사람입니다"<<endl;
	*/

	//namespace 
	/*
	Add();
	B::Add();
	Add();
	*/

	//오버로딩 예제
	/*
	cout << 4 << "+" << 10 << "=" << Plus(4, 10)<<endl;
	cout << 4.22 << "+" << 10 << "=" << Plus(4.22f, 10) << endl;
	cout << 4 << "+" << 10.12 << "=" << Plus(4, 10.12f) << endl;
	cout << 4.22 << "+" << 10.12 << "=" << Plus(4.22f, 10.12f) << endl;
	cout << "안녕" << "+" << "하세요" << "=" << Plus("안녕", "하세요") << endl;
	*/

	//매개변수 디폴트 
	//cout << "1~ " << "99=" << totalSum(99) << endl;
	
	//디폴트 예제
	def_print("dlgkdud",22,false);
	def_print("whdbswlr",23);
	
	system("pause");
	return 0;
}

