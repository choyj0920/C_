#include "pch.h"
#include "Ticket.h"
#include <fstream>

Ticket::Ticket()
{
}

Ticket::Ticket(string name, double price, string fname): Tname(name),price(price),Fname(fname)
{
	ifstream file(this->Fname);
	file >> row >> col;
	map = new int*[row];
	user = new User*[row];
	for (int i = 0; i < row; i++) {
		map[i] = new int[col];
		user[i] = new User[col];
		for (int j = 0; j < col; j++) {
			file >> map[i][j];
		}
	}
}

Ticket::Ticket(Ticket & t) : Tname(t.Tname), price(t.price), Fname(t.Fname),row(t.row),col(col), totalincome(t.totalincome)
{
	map = new int*[row];
	user = new User*[row];
	for (int i = 0; i < row; i++) {
		map[i] = new int[col];
		user[i] = new User[col];
		for (int j = 0; j < col; j++) {
			map[i][j] = t.map[i][j];
			user[i][j].setUser(t.user[i][j]);
		}
	}
}


Ticket::~Ticket()
{
	for (int i = 0; i < row; i++) {
		delete[] map[i];
		delete[] user[i];
	}
	delete[] map;
	delete[] user;
}

void Ticket::showseat() const
{
	string ss[] = { "","☆","○","□","★","●","■" };
	cout << "********* 좌석 현황 *********\n";
	cout << "===============================\n";
	cout << "\t";
	for (int i = 0; i < col; i++)
		cout << i + 1 << "\t";
	cout << "\n";
	cout << "===============================\n";
	for (int i = 0; i < row; i++) {
		cout << i + 1 << "\t";
		for (int j = 0; j < col; j++) {
			if (map[i][j] < 0)
				cout << ss[3 - map[i][j]] << "\t";
			else
				cout << ss[map[i][j]] << "\t";
		}
		cout << endl;
	}
}

void Ticket::reserve()
{
	showseat();
	int x, y;
	int m;
	
	while (true) {
		cout << "좌석 선택하세요 (ex, 1 1) : ";
		cin >> x >> y;
		x--; y--;
		if (map[x][y] < 0) {
			cout << "이미 예약된 좌석 입니다.다른 좌석을 선택하세요.\n";
			continue;
		}

		cout << "예약 정보를 입력 하세요(아이디 비밀번호 : ";
		string name, pass;
		cin >> name >> pass;
		double pri;
		switch (map[x][y])
		{
		case 1:
			pri = this->price*1.2;
			break;
		case 2:
			pri = this->price*1;
			break;
		case 3:
			pri = this->price*0.9;
			break;
		}

		totalincome += pri;
		cout << pri << "가격에 예약이 완료 되었습니다\n";
		user[x][y].setUser(name, pass);
		map[x][y] *= -1;
		break;
	}
	
}

void Ticket::confirm()
{
	cout << "확인 할 예약 아이디와 비밀 번호를 입력하세요 : ";
	string id;
	string password;
	cin >> id >> password;
	
	int cnt=0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (map[i][j] < 0 && user[i][j].checkuser(id, password))
				cnt++;
		}
	}

	cout << "총 " << cnt << "개의 예매가 확인되었습니다." << endl;
	
}

void Ticket::cancel()
{
	string id, password;
	cout << "취소할 예약 아이디를 입력하세요 : ";
	cin >> id;
	int cnt=0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (map[i][j] < 0 && user[i][j].checkuser(id))
				cnt++;
		}
	}
	int cnt_ = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (map[i][j] < 0 && user[i][j].checkuser(id)) {
				cout << "비밀 번호를 입력하세요 : ";
				cin >> password;
				if (!user[i][j].checkuser(id, password))
					continue;
				double pri;
				switch (map[i][j])
				{
				case -1:
					pri = this->price*1.2;
					break;
				case -2:
					pri = this->price * 1;
					break;
				case -3:
					pri = this->price*0.9;
					break;
				}
				user[i][j].setUser("", "");
				map[i][j] *= -1;
				totalincome -= pri;
				cnt_++;
				cout << cnt_ << "/" << cnt << " 예매 정보가 취소 되었습니다.\n";
				if (cnt_ != cnt) {
					string c;
					cout << "다른 예매 정보도 취소 하시겠습니까?(y/n)";
					cin >> c;
					if (!c.compare("n"))
						return;

				}
				else
					return;
			}
		}
	}
	

	
}

double Ticket::getTotalIncome()
{
	return totalincome;
}
