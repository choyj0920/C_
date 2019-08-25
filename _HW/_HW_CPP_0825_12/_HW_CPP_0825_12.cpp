// _HW_CPP_0825_12.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include "BASEBALL.h"
int main()
{
	BASEBALL *BB;
	int num[3] = { 0, };
	
	while (num[1] == num[2] || num[2] == num[0] || num[1] == num[0]) {
		cout << "0~ 9 중 숫자 3개를 입력하세요 : ";
		cin >> num[0] >> num[1] >> num[2];
	}
	BB = new BASEBALL(num);
	system("cls");
	while(!(BB->strike3)){
		num[0] = num[1] = num[2] = 0;

		while (num[1] == num[2] || num[2] == num[0] || num[1] == num[0]) {

			cout << "숫자 3개를 맞춰 보세요 : ";
			cin >> num[0] >> num[1] >> num[2];
		}
		BB->pitching(num);
	}
	cout << "잘 맞추셨어요 ~~~.\n";
	
	delete BB;
	
	
	return 0;

}

