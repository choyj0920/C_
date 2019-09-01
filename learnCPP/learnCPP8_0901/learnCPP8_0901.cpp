
#include "pch.h"
#include <iostream>
#include "DataClass.h"
#include "Student.h"
char inputString[MAX_BUFFSIZE];

void func(int a, int b) {
	if (b == 0)
		throw b;
	cout << a << "를 " << b << "로 나눈 몫은 " << a / b << "입니다.\n";

}
void func1() { throw 0; }
void func2() { func1(); }
void func3() { func2(); }
void func4() { func3(); }


int main()
{
	//템플릿 배열 
	/*
	DataClass<int> data1(4); data1.ShowInfo();
	DataClass<char> data2(3); data2.ShowInfo();
	DataClass<float> data3(4); data3.ShowInfo();
	*/
	
	//예외 처리
	/*
	int a, b;
	cout << "두개의 정수를 입력하세요 : ";
	cin >> a >> b;
	if (b == 0)
		cout << "나누는 수가 0이 될 수 없습니다." << endl;
	else
		cout << a << "를 " << b << "로 나눈 몫은 " << a / b << "입니다.\n";
	*/

	//try ~catch,throw 
	/*
	int a, b;
	cout << "두개의 정수를 입력하세요 : ";
	cin >> a >> b;
	try {
		if (b == 0)
			throw b;
		cout << a << "를 " << b << "로 나눈 몫은 " << a / b << "입니다.\n";

	}
	catch (int exception) {
		cout <<"예외 발생, " << "나누는 수는 "<<exception<<"가 될 수 없습니다." << endl;
	}
	*/

	//함수 예외 처리
	/*
	int a, b;
	cout << "두개의 정수를 입력하세요 : ";
	cin >> a >> b;
	try {
		func(a, b);
	}
	catch (int exception) {
		cout << "예외 발생, " << "나누는 수는 " << exception << "가 될 수 없습니다." << endl;
	}
	*/

	//스택 풀기 
	/*
	try {
		func4();
	}
	catch (int exception) {
		cout << "예외 발생," << exception << "!\n";
	}
	*/

	//파일 입출력
	//파일 쓰기
	/*
	ofstream outFile("output.txt");
	for (int i = 0; i < 10; i++) {
		outFile << i << endl;
	}
	outFile.close();

	//파일 읽기
	ifstream inFile("output.txt");
	if (inFile.is_open()) {
		while (!inFile.eof()) {
			//inFile.getline(inputString, 100); //100바이트 까지 받아옴
			//cout << inputString << endl;
			cout << inFile.get();
		}
		inFile.close();
	}
	 */

	//예제
	char name_[20];
	int ban_,kor_s,eng_s;
	int stu_cou;
	Student **stu;
	cout << "몇 명의 학생을 입력하시겠습니까?";
	cin >> stu_cou;
	stu = new Student*[stu_cou];
	for (int i = 0; i < stu_cou; i++) {
		cout << i + 1 << "번쨰 학생의 이름을 입력하세요 : ";
		cin >> name_;
		cout << i + 1 << "번쨰 학생의 반을 입력하세요 : ";
		cin >> ban_;
		cout << i + 1 << "번쨰 학생의 국어 점수를 입력하세요 : ";
		cin >> kor_s;
		cout << i + 1 << "번쨰 학생의 영어 점수를 입력하세요 : ";
		cin >> eng_s;
		stu[i] = new Student(name_, ban_, kor_s, eng_s);
	}
	return 0;

}
