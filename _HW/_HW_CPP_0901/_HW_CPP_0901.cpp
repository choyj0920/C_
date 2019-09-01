#include "pch.h"
#include <iostream>
#include "Student.h"

Student **stu;
int stu_cou;
char trash[200];
void set_stu();
void load_stu();
void edit_stu();
int main()
{
	int menu = 0;
	while (menu != 6) {
		menu = 0;
		while (menu < 1 || menu>6) {
			cout << "============================"<<endl;
			cout << "1. 학생 정보 입력"<<endl;
			cout << "2. 학생 정보 수정"<<endl;
			cout << "3. 학생 정보 출력"<<endl;
			cout << "4. 파일 저장"<<endl;
			cout << "5. 파일 불러오기"<<endl;
			cout << "6. 종료"<<endl;
			cout << "메뉴를 선택하세요 : ";
			cin >> menu;
		}
		switch (menu)
		{
		case 1:
			set_stu();
			break;
		case 2:
			edit_stu();
			break;
		case 3:
			Student::print_Info(stu);
			break;
		case 4:
			Student::save_file(stu,stu_cou);
			break;
		case 5:
			load_stu();
			break;
		case 6:
			load_stu();
			break;
		}
	}
	
	return 0;
}

// 학생 정보 입력을 받는 함수
void set_stu() {
	char name_[20];
	int ban_, kor_s, eng_s;
	
	if (stu) {
		for (int i = 0; i < stu_cou; i++) {
			delete stu[i];
		}
		delete stu;
		stu = NULL;
	}
	cout << "몇 명의 학생을 입력하시겠습니까? : ";
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
	Student::set_count(stu_cou);

	

}

//파일을 불러오는 함수
void load_stu() {
	
	ifstream inFile("Data.txt");
	if (inFile.is_open()) {
		char name_[20];
		int ban_, kor_s, eng_s;
		if (stu) {
			for (int i = 0; i < stu_cou; i++) {
				delete stu[i];
			}
			delete stu;
			stu = NULL;
		}
		stu_cou = -1; //맨 마지막줄은 빈칸이기 때문
		while (!inFile.eof()) {
			inFile.getline(trash, 100);
			stu_cou++;
		}
		inFile.clear();
		inFile.seekg(0); //파일 포인터 커서 시작 지점으로
		stu = new Student*[stu_cou];
		for (int i = 0; i < stu_cou; i++) {
			inFile >> name_;
			inFile>> ban_ >> kor_s >> eng_s;
			stu[i] = new Student(name_, ban_, kor_s, eng_s);
		}
		inFile.close();
		Student::set_count(stu_cou);
		cout << "파일 로드 완료!\n";
	}
	else {
		cout << "파일이 없습니다.\n";
		return;
	}
}

//학생중 한명을 수정하는 함수
void edit_stu() {
	char name_[20];
	int ban_, kor_s, eng_s;
	int n;
	cout << "몇 번 학생을 수정하시겠습니까? (1 ~ " << stu_cou << ") :";
	cin >> n;
	cout << n << "번쨰 학생의 이름을 입력하세요 : ";
	cin >> name_;
	cout << n << "번쨰 학생의 반을 입력하세요 : ";
	cin >> ban_;
	cout << n << "번쨰 학생의 국어 점수를 입력하세요 : ";
	cin >> kor_s;
	cout << n << "번쨰 학생의 영어 점수를 입력하세요 : ";
	cin >> eng_s;
	stu[n - 1]->setInfo(name_, ban_, kor_s, eng_s);
}