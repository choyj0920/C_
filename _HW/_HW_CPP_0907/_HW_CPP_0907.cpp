#include "pch.h"
#include <iostream>
#include <list>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <string>

void show_list(list<int>& it) {
	list<int>::iterator iter;
	cout << "--리스트 출력--\n";
	for (iter = it.begin(); iter != it.end(); ++iter) {
		cout << *iter << '\t';
	}
	cout << endl;
}

float ave = 0;

bool over_ave(int n) {
	return n > ave;
}
int main()
{
	srand((unsigned int)time(NULL));
	//예제1
	list<int>  it;
	//랜덤 값 입력
	for (int i = 0; i < 10; i++) {
		int rand_num = rand();
		it.push_back(rand_num);
	}

	show_list(it);
	cout << "reverse 실행\n";
	it.reverse();
	show_list(it);
	//예제2
	cout << "오름차순 실행\n";
	it.sort();
	show_list(it);

	ave =accumulate(it.begin(), it.end(),0)/it.size(); //numeric 헤더 
	it.remove_if(over_ave); //평균초과 제거
	cout << "평균 : " << ave << endl;
	show_list(it);
	
	//예제3
	list<int>  it2;
	for (int i = 0; i < 5; i++) {
		int rand_num = rand();
		it2.push_back(rand_num);
	}
	cout << "list1"; show_list(it);
	cout << "list2"; show_list(it2);
	
	//merge를 쓰기위해  정렬 되어있지 않은 it2를 정렬 해줌
	it2.sort();
	it.merge(it2);
	cout << "--merge--\n";
	
	show_list(it);

	//예제 4
	vector<string> STL;
	string str;
	int count = 0;
	cout << "STL에 담을 문장을 입력하세요.\n";
	getline(cin, str);
	STL.push_back(str);
	cout << "검색할 문장을 입력해주세요" << endl;
	getline(cin, str);
	
	size_t pos = 0;
	while ((pos = STL.at(0).find(str, pos)) != string::npos) {
		count++;
		pos += str.length();
	}
	
	cout << endl << STL.at(0) << endl;
	cout <<str<< "문자열이 " << count << "개 있습니다." << endl;
}

