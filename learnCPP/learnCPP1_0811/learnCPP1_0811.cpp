
#include "pch.h"
#include <iostream>
#include "Human.h"

int InputNumberTostring(const char* explan) {
	int num = 0;
	cout << explan;
	cin >> num;
	return num;
}

int main()
{
	//동적할당
	/*
	char* ch = NULL;
	if (!ch)
		//ch = new char; //ch에 char 동적할당
		ch = new char[20]; //ch에 char 동적할당 배열


	if (ch) {
		delete []ch; //동적할당 해제
		ch = NULL;
	}
	*/

	//동적할당 연습문제
	/*
	int* arr = 0;
	int arr_count, arr_start, arr_multiple;
	arr_count= InputNumberTostring("배열의 수를 입력하세요 : ");
	arr_start = InputNumberTostring("입력할 시작 번호를 입력하세여 : ");
	arr_multiple = InputNumberTostring("입력할 수의 배수를 입력하세요 : ");;

	if(!arr)   arr = new int[arr_count];  //배열 동적할당
	for (int i = 0; i < arr_count; i++) arr[i] = arr_start + arr_multiple * i;  //배열 값 넣기
	cout << "배열 출력 \n";
	for (int i = 0; i < arr_count; i++) cout << "arr[" << i << "] = " << arr[i] << endl; //단순 배열 출력

	if (arr) { 
		//배열 동적할당 해제
		delete[] arr;
		arr = NULL;
	}
	*/

	//클래스  human 
	/*
	Human men,girl;
	men.SetInfo("철수킴", 18, true);
	men.ShowInfo();
	men.Showlaughter();
	girl.SetInfo("이영희", 18, false);
	girl.ShowInfo();
	girl.Showlaughter();
	men.SetAge(20);
	cout << men.GetName() << "의 나이는 " << men.GetAge() << "이(가) 되었습니다." << endl;
	*/

	//클래스 human /*
	Human* pboy =NULL;  //휴먼 객체가아닌 휴먼객체를 가르킬수있는 객체 생성
	cout << "주소 변수 선언." << endl;
	pboy = new Human("김철수",18,true);
	pboy->ShowInfo();
	Human girl("maria", 16, false);

	delete pboy;



	system("pause");
	return 0;
}
