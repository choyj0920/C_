//
#include "pch.h"
//
//using namespace std; //이걸 쓰면 std:: 안써도 ㄱㅊ
//int MyClass::count = 0;
//
//void MyClass::ShowData() {
//	std::cout<<"num1 : " << num1 << "  num2 : "<<num2<<endl;
//	cout << str<<endl;
//
//}
//void MyClass::SetNum1(int n)
//{
//	num1 = n;
//}
//void MyClass::SetNum2(int n)
//{
//	num2 = n;
//}
//MyClass::MyClass(int a, int b, const char* ex) {
//	int len = strlen(ex) + 1;
//	num1 = a, num2 = b;
//	str = new char[len];
//	strcpy_s(str, len, ex);
//}
//
//MyClass::MyClass(const MyClass & my)
//{
//	int len = strlen(my.str) + 1;
//	num1 = my.num1;
//	num2 = my.num2;
//	// str = my.str 얕은 복사가 되버림
//	str = new char[len];
//	strcpy_s(str, len, my.str);
//}
//
//MyClass::~MyClass()
//{
//	if (str) {
//		delete[] str;
//		str = NULL;
//	}
//	
//}