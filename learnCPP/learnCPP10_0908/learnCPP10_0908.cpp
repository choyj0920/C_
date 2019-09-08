#include "pch.h"

void show_inven(map<string, item> inven);
void searh_info(map<string, item> inven);
void edit_info(map<string, item>* inven);
void add_info(map<string, item>* inven);
void load_stu(map<string, item>* inven);
static int item_cou = 0;

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
	int menu = 0;
	load_stu(&inven);
	while (menu != 4) {
		menu = 0;
		while (menu < 1 || menu>4) {
			cout << "============================" << endl;
			cout << "1. 정보 검색" << endl;
			cout << "2. 정보 삭제" << endl;
			cout << "3. 정보 삽입" << endl;
			cout << "4. 나가기" << endl;
			cout << "무엇을 하시겠습니까? ";
			cin >> menu;
		}
		switch (menu)
		{
		case 1:
			cout << "(정보 검색)\n";
			searh_info(inven);
			break;
		case 2:
			cout << "(정보 삭제)\n";
			edit_info(&inven);
			break;
		case 3:
			cout << "(정보 삽입)\n";
			add_info(&inven);
			break;
		case 4:
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
		item::save_file(inven,inven->size());
	} while (true);

}

//정보 삽입
void add_info(map<string, item>* inven) {
	string name;
	int price, grade;
	do {
		show_inven(*inven);
		cout << "아이템 이름? :";
		cin >> name;
		if (name == "Q") {
			break;
		}
		//키 값 검사
		if (inven->find(name) != inven->end()) {
			cout << "그 이름의 아이템이 이미 있습니다.\n";
			continue;
		}
		cout << "아이템 가격? : ";
		cin >> price;
		cout << "아이템 등급? : ";
		cin >> grade;
		inven->insert(pair<string, item>(name, item(name, price, grade)));
		item::save_file(inven, inven->size());


	} while (true);
}

//파일 로드
void load_stu(map<string, item>* inven) {

	ifstream inFile("Data.txt");
	if (inFile.is_open()) {
		string name;
		char trash[100];
		int price, grade;
		item_cou = -1; //맨 마지막줄은 빈칸이기 때문
		while (!inFile.eof()) {
			inFile >> name >> price >> grade;
			if (name == "")	break;
			inven->insert(pair<string, item>(name, item(name, price, grade)));
			item_cou++;
		}
		
		inFile.close();
		
		cout << "파일 로드 완료!\n";
	}
	else {
		cout << "파일이 없습니다.\n";
		return;
	}
}