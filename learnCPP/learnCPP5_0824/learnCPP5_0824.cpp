// learnCPP5_0824.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include"Human.h"
#include "Student.h"
#include "Creater.h"

int main()
{
	//상속 클래스 
	/*
	Student stu(23, "조윤직", "sbs학교");
	stu.schoolInfo();
	stu.breakfast();
	stu.luncheon();
	stu.abendessen();
	*/

	//연습문제
	/*
	int n;
	Creater cre(23, "조윤직", "SBSarc");
	cre.createrInfo();
	cout << "지금은 몇시인가요? : ";
	cin >> n;
	cre.whatdoing_cre(n);
	*/

	//상속 클래스 객체배열 등등등 
	/*
	Student stu[5];
	char name[10];
	int age;
	for (int n = 0; n < 5; n++) {
		cin >> name >> age;
		stu[n].SetInfo(age, name, "SBS학교", n + 1);
	}
	for (int n = 0; n < 5; n++) {
		stu[n].GetInfo();
	}
	*/
	
	//생성자초기화 인 클래스 객체 배열
	/*
	Student stu[3] = {Student(23,"wdw","sbsa",10),Student(22,"dgd","sbsa",10) , Student(21,"wddd","sbsa",10) };
	for (int n = 0; n < 3; n++) {
		stu[n].GetInfo();
	}
	*/

	//클래스포인터 배열
	/*Student *stu[3];
	char name[20];
	int age, studentID;
	for (int n = 0; n < 3; n++) {
		cin >> name >> age >> studentID;
		stu[n] = new Student(age, name, "SBS아카", studentID);
	}
	for (int n = 0; n < 3; n++) {
		stu[n]->GetInfo();
	}
	delete[] stu; */

	// 동적할당으로 변하는 학생수~ 이중 포인터를 사용하는 이유 : 기본생성자가 없을때 초기화 생성자를 사용할때까지 객체 생성 안하기
	/*
	Student** stu =NULL;
	char name[20];
	int age, studentID;

	stu = new Student*[3];
	for (int n = 0; n < 3; n++) {
		cin >> name >> age >> studentID;
		stu[n] = new Student(age, name, "SBS아카", studentID);
	}
	for (int n = 0; n < 3; n++) {
		stu[n]->GetInfo();
	}
	for (int n = 0; n < 3; n++) {
		delete stu[n];
	}
	delete[] stu;
	*/


	system("pause");
	return 0;
}
