#include "pch.h"
#include <iostream>
#include <map>
#include "item.h"


void show_inven(map<string, item> inven);
void searh_info(map<string, item> inven);
void edit_info(map<string, item>* inven);
int main()
{
	//STL map 예제
	/*
	map<int, int> m;
	m.insert(pair<int, int>(5, 100)); //임의 pair insert
	m.insert(pair<int, int>(3, 100)); //임의 pair insert

	pair<int, int> p(9, 50);
	m.insert(p);

	m[11] = 200;
	m[12] = 200;
	m[13] = 40;
	
	map<int, int> ::iterator iter;
	for (iter = m.begin(); iter != m.end(); ++iter) {
		cout << "(" << (*iter).first << "," << (*iter).second << ")" << " ";
	}
	cout << endl;

	m[13] = 140;
	//-> 연산자 호출
	for (iter = m.begin(); iter != m.end(); ++iter) {
		cout << "(" << (*iter).first << "," << (*iter).second << ")" << " ";
	}
	cout << endl;

	pair<map<int, int>::iterator, bool>pr;
	
	//insert 결과 성공
	pr = m.insert(pair<int, int>(10, 30));

	if (true == pr.second) {
		cout << "key : " << pr.first->first << ", value : " << pr.first->second << "저장 완료!" << endl;
	}
	else
		cout << "key 10가 이미 m에 있습니다." << endl;

	for (iter = m.begin(); iter != m.end(); ++iter) {
		cout << "(" << (*iter).first << "," << (*iter).second << ")" << " ";
	}
	cout << endl;

	//insert 결과 실패(중복 key삽입)

	pr = m.insert(pair<int, int>(10, 40));
	if (true == pr.second) {
		cout << "key : " << pr.first->first << ", value : " << pr.first->second << "저장 완료!" << endl;
	}
	else
		cout << "key 10가 이미 m에 있습니다." << endl;

	return 0;
	*/

	//stl map 연습문제
	map<string, item> inven;
	inven.insert(pair<string, item>("청동검", item("청동검", 500, 9)));
	inven.insert(pair<string, item>("철도끼", item("철도끼", 900, 8)));
	inven.insert(pair<string, item>("가죽갑옷", item("가죽갑옷", 250, 9)));
	inven.insert(pair<string, item>("천신발", item("천신발", 100, 10)));
	inven.insert(pair<string, item>("각궁", item(" 각궁 ", 2500, 6)));

	//map<string, item> ::iterator iter;
	//for (iter = inven.begin(); iter != inven.end(); ++iter) {
	//	(*iter).second.show_info();
	//}
	//cout << endl;

	int menu = 0;
	while (menu != 3) {
		menu = 0;
		while (menu < 1 || menu>3) {
			cout << "============================" << endl;
			cout << "1. 정보 검색" << endl;
			cout << "2. 정보 삭제" << endl;
			cout << "3. 나가기" << endl;
			cout << "무엇을 하시겠습니까? ";
			cin >> menu;
		}
		switch (menu)
		{
		case 1:
			searh_info(inven);
			break;
		case 2:
			edit_info(&inven);
			break;
		case 3:
			cout << "종료... \n";
			break;
		}
	}

}
//정보 출력 
void show_inven(map<string, item> inven) {
	map<string, item> ::iterator iter;
	cout << "[";
	for (iter = inven.begin(); iter != inven.end(); ++iter) {
		cout << (*iter).first << " ";
	}
	cout << "] 의 " << inven.size() << "개의 아이템이 있습니다.\n";
	cout << "나가기: Q\n";
}

//정보 검색
void searh_info(map<string, item> inven) {
	
	string name;

	do {
		show_inven(inven);
		cout << "알고 싶은 아이템을 선택 하세요 : ";
		cin >> name;
		if (name == "Q") {
			break;
		}
		if (inven.find(name) == inven.end()) {
			cout << "그 이름의 아이템이 없습니다.\n";
			continue;
		}
		inven[name].show_info2();
	} while (true);

}

//정보 삭제
void edit_info(map<string, item>* inven) {
	string name;
	
	do {
		show_inven(*inven);
		cout << "삭제 하고 싶은 아이템을 선택 하세요 : ";
		cin >> name;
		if (name == "Q") {
			break;
		}
		//키 값 검사
		if (inven->find(name) == inven->end()) {
			cout << "그 이름의 아이템이 없습니다.\n";
			continue;
		}
		inven->erase(name);
	} while (true);

}