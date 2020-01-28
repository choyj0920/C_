#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <Windows.h>
using namespace std;

void _HW01();
void _HW02();
void _HW03();
int get_num();



int main()
{
	int menu = 0;
	while (menu != 4) {

		menu = 0;
		while (menu > 4 || menu < 1) {
			system("cls");
			cout << "======== 201810754 ������ ==========" << endl;
			cout << "1) ����1   2) ����2   3) ����3   4) ����" << endl;
			cout << "�޴��� �����ϼ��� : ";
			menu = get_num();

		}

		switch (menu)
		{
		case 1:
			_HW01();
			break;
		case 2:
			_HW02();
			break;
		case 3:
			_HW03();
			break;
		case 4:
			break;

		}
		system("pause");
	}
}

//�������� �ޱ� ���� �Լ� ������ �ƴ� ���� ������ �ٽ� �Է� �ް�
int get_num() {
	int num;

	cin >> num;
	if (cin.fail()) {
		cout << "�ٽ� �Է��ϼ���. : ";
		cin.clear();
		cin.ignore(256, '\n');
		return get_num();
	}
	return num;
}

void _HW01() {
	int money = 500;
	int buy_v;
	cout << "====== ���� 1 ========" << endl;
	do {
		cout << "���� �ݾ��� �Է��ϼ���[0~500] : ";
		buy_v = get_num();
	} while (buy_v > 500 || buy_v < 0);
	money -= buy_v;
	cout << money << "�� �Ž������� ������ ����.\n";
	int cou_100, cou_50, cou_10, cou_1;
	cou_100 = money / 100;
	cou_50 = (money % 100) / 50;
	cou_10 = (money % 50) / 10;
	cou_1 = money % 10;
	cout << "100�� ¥�� ���� : " << cou_100 << "��\n";
	cout << "  50�� ¥�� ���� : " << cou_50 << "��\n";
	cout << "  10�� ¥�� ���� : " << cou_10 << "��\n";
	cout << "    1�� ¥�� ���� : " << cou_1 << "��\n";
}

void _HW02() {

	int money, choco = 0, coupon = 0;
	cout << "====== ���� 2 ========" << endl;
	do {
		cout << "* ���� �־� �ּ��� : ";
		money = get_num();
	} while (money < 0);
	cout << "================== \n";
	choco += money;
	coupon += choco;
	do {
		int temp = coupon / 7;
		choco += temp;
		coupon = coupon % 7;
		coupon += temp;

	} while (coupon >= 7);

	cout << "* ���ݸ� " << choco << "��, ���� " << coupon << "��\n\n";


}


void _HW03() {
	cout << "====== ���� 3 ========" << endl;
	int count = 0;
	int T, O, G, D;
	cout << "TOO + TOO + TOO + TOO = GOOD\n";
	cout << "��: (T * 100 + O * 11) * 4 = G * 1000 + O * 110 + D\n";
	for (T = 0; T < 10; T++) {
		for (O = 0; O < 10; O++) {
			if (T == O)
				continue;
			for (G = 0; G < 10; G++) {
				if (T == G || G == O)
					continue;
				for (D = 0; D < 10; D += 2) {
					if (D == T || D == O || T == G)
						continue;
					else if (T * 100 * 4 == (G * 1000 + O * 66 + D)) {
						count++;
						cout << "��� " << count << " : T = " << T << ", O = " << O << ", G = " << G << ", D = " << D << endl;
					}
				}
			}
		}
	}

}

