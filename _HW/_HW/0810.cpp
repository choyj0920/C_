#include<iostream>
#include<Windows.h>

using namespace std; 

int scan_num(const char* directive) {
	int num;
	cout << directive;
	cin >> num;
	return num;
}

int main() {
	cout << scan_num("���ڸ� �Է��ϼ��� : ") << endl;

	system("pause");
	return 0;
}