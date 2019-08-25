#include "pch.h"
#include "BASEBALL.h"





BASEBALL::BASEBALL(int * num)
{
	for (int i = 0; i < 3; i++)
		_num[i] = num[i];
}

BASEBALL::~BASEBALL()
{
}

void BASEBALL::pitching(int * num)
{
	int str_count = 0;
	int bob_count = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (_num[i] == num[j]) {
				if (i == j) str_count++;
				else bob_count++;
			}
		}
	}
	if (str_count != 0)
		cout << str_count << "스트라잌!! ";
	if (bob_count != 0)
		cout << bob_count << "볼!! ";
	if (str_count == 0 && bob_count == 0)
		cout << "아웃!! ";
	cout << endl;
	if (str_count == 3)
		strike3 = true;

}
