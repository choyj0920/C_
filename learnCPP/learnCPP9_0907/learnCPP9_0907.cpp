

#include "pch.h"
#include <iostream>
#include <list>
#include <vector>

void ReplaceStringInPlace(std::string& subject, const std::string& search, const std::string& replace)
{
	//subject 원본 replace 바꿀 녀석
	size_t pos = 0;

	while ((pos = subject.find(search, pos)) != std::string::npos)

	{
		subject.replace(pos, search.length(), replace); //찾은 위치부터 serch의 길이만큼 replace 로 대체 

		pos += replace.length();

	}

}
std::string ReplaceString(std::string subject, const std::string &search, const std::string &replace)

{

	size_t pos = 0;

	while ((pos = subject.find(search, pos)) != std::string::npos)

	{

		subject.replace(pos, search.length(), replace);

		pos += replace.length();

	}

	return subject;

}

bool Predicate(int n) {
	return n >= 30;
}
int main()
{
	//sscanf_s 
	/*char buffers[] = { "fadfafaff sdfasdfasdf dafsdfasd" };
	char str1[100] = { 0, }, str2[100] = { 0, };
	sscanf_s(buffers, "%s %s", str1, sizeof(str1), str2,sizeof(str2));
	cout << "original : " << buffers << endl;
	cout << str1 << endl << str2 << endl;*/

	//sscanf_s 2
	/*
	char buffers[] = { "조윤직 111 88 77"};
	char str1[100] = { 0, };
	int num = 0, kor = 0, eng = 0;
	sscanf_s(buffers, "%s %d %d %d", str1, sizeof(str1), &num,&kor,&eng);
	cout << "original : " << buffers << endl;
	cout << "이름 : " << str1 << endl << "num : " << num << endl << "kor : " << kor << endl << "eng : " << eng << endl; */

	//string 
	/*
	string mystring = "abcdef";
	 
	cout << mystring << endl;
	mystring = 'z';

	mystring = "안녕하세요.";
	
	cout << mystring << endl << "cap : " << mystring.capacity() << endl;
	cout << mystring << endl << "max : " << mystring.max_size() << endl;

	string base = "hello world!";

	cout << base.at(0)<<endl;
	cout<<base.at(4)<<endl;
	cout << base.find("world!");

	string a = "I am string one!!";

	string b = "string";

		if (a.compare(b) == 0)

		{
			// 두 문자열이 같을 때
		}

		else if (a.compare(b) < 0)

		{
			// a가 b보다 사전순으로 앞일 때
		}
		else if (a.compare(b) > 0)
		{
			// a가 b보다 사전순으로 뒤일 때
		}
		*/

	//string 
	/*
	// int ---> string
	string s;
	int i = 10;
	s = std::to_string(i);
	cout << s << endl;
	// string ---> int
	string s2 = "123";
	int j;
	j = std::stoi(s2);
	cout << j << endl;
	*/

	//문자열 대체하기
	/*
	string input = "Hello C++!!";
	cout << "input string : " << input.c_str() << endl;
	cout << "ReplaceString()반환 값 : " << ReplaceString(input, "lo", "!!").c_str() << endl;
	cout << "ReplaceString() input string 안바뀜  : " <<input.c_str() << endl;
	ReplaceStringInPlace(input, "lo", "??");
	cout << "ReplaceStringlnplace()input string 바뀜 : " << input.c_str() << endl;
	*/

	//중간 예제
	/*
	string str ="나는 C++을 배우고 있습니다";
	str += "\n나는 열심히 하고 있는 걸까요";
	cout << "문자열의 총 길이는 " << str.length() << endl;
	ReplaceStringInPlace(str, "나는", "");
	cout << str.c_str() << endl;
	*/
	
	//리스트 예제 
	/*
	list<int> it;
	it.push_back(10);
	it.push_back(20);
	it.push_back(30);
	it.push_back(40);
	it.push_back(50);
	list<int>::iterator iter;
	for (iter = it.begin(); iter != it.end(); ++iter) {
		cout << *iter << ' ';
	}
	cout << endl;
	iter = it.begin();
	iter++;
	iter++;

	//erase 삭제
	list<int>::iterator iter2 = it.erase(iter);
	for (iter = it.begin(); iter != it.end(); ++iter) {
		cout << *iter << ' ';
	}
	cout << endl;
	cout << "iter2 : " << *iter2 << endl;

	it.push_back(10);
	it.push_back(10);

	for (iter = it.begin(); iter != it.end(); ++iter) {
		cout << *iter << ' ';
	}
	cout << endl;

	//리스트에서 원소 10제거
	it.remove(10);
	for (iter = it.begin(); iter != it.end(); ++iter) {
		cout << *iter << ' ';
	}
	cout << endl;

	//predicate 함수에 해당하는 원소 제거(30보다 크다)
	it.remove_if(Predicate);
	for (iter = it.begin(); iter != it.end(); ++iter) {
		cout << *iter << ' ';
	}
	cout << endl;
	*/

	//vector 예제 
	/*
	vector<int> v;
	v.reserve(8); //벡터 메모리 공간 8예약 할당

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	for (vector<int>::size_type i = 0; i < v.size(); ++i) {
		cout << v[i] << endl;
	}
	cout << endl;
	cout << "size : " << v.size(); //벡터 원소 개수
	cout << " capacity : " << v.capacity();
	cout << "max_size : " << v.max_size() << endl;
	cout << endl << "--resize(10) --" << endl;

	v.resize(10);

	//벡터의 size타입으로 i를 지정한다
	for (vector<int>::size_type i = 0; i < v.size(); ++i) {
		cout << v[i] << endl;
	}
	cout << endl;

	cout << "size : " << v.size(); //벡터 원소 개수
	cout << " capacity : " << v.capacity();
	cout << " max_size : " << v.max_size() << endl;
	cout << endl << "--resize(3) --" << endl;

	//
	v.resize(3);  //capacity변화는 없음

	for (vector<int>::size_type i = 0; i < v.size(); ++i) {
		cout << v[i] << endl;
	}
	cout << endl;

	cout << "size : " << v.size(); //벡터 원소 개수
	cout << " capacity : " << v.capacity();
	cout << " max_size : " << v.max_size() << endl;
	
	cout << endl << "--vector clear()--" << endl;

	v.clear();
	if (v.empty()) {
		cout << "벡터에 원소가 없다.\n";
	}
	cout << "size : " << v.size(); //벡터 원소 개수
	cout << " capacity : " << v.capacity();
	cout << " max_size : " << v.max_size() << endl;
	
	return 0; 
	*/



}
