#include "pch.h"
#include "player.h"
#include "FrameClass.h"
#include "itemObject.h"
int main()
{
	//실습1
	/*
	DrawGraphics::gotoxy(30, 10);
	cout << "hellow!";
	DrawGraphics::gotoxy(10, 3);
	cout << "good~";
	DrawGraphics::gotoxy(50, 20);
	cout << "??!!~~" << endl;
	*/
	//하트 만들기
	/*
	DrawGraphics::gotoxy(5, 2);	cout << "♥♥♥";
	DrawGraphics::gotoxy(13, 2);	cout << "♥♥♥";
	DrawGraphics::gotoxy(4, 3);	cout << "♥♥♥♥♥";
	DrawGraphics::gotoxy(12, 3);	cout << "♥♥♥♥♥";
	DrawGraphics::gotoxy(3, 4);	cout << "♥♥♥♥♥♥♥";
	DrawGraphics::gotoxy(11, 4);	cout << "♥♥♥♥♥♥♥";
	DrawGraphics::gotoxy(3, 5);	cout << "♥♥♥♥♥♥♥♥♥♥♥♥♥♥♥";
	DrawGraphics::gotoxy(4, 6);	cout << "♥♥♥♥♥♥♥♥♥♥♥♥♥";
	DrawGraphics::gotoxy(5, 7);	cout << "♥♥♥♥♥♥♥♥♥♥♥";
	DrawGraphics::gotoxy(6, 8);	cout << "♥♥♥♥♥♥♥♥♥";
	DrawGraphics::gotoxy(7, 9);	cout << "♥♥♥♥♥♥♥";
	DrawGraphics::gotoxy(8, 10);	cout << "♥♥♥♥♥";
	DrawGraphics::gotoxy(9, 11);	cout << "♥♥♥";
	DrawGraphics::gotoxy(10, 12);	cout << "♥";*/
	//입력  
	/*
	unsigned char key;
	int x = 40, y = 12;
	DrawGraphics::gotoxy(x, y);
	cout << "♥";
	while (true) {
		//key =_getch();
		//if (key == 'q' || key == 'Q')
		//	break;
		//cout << key<<endl;
		key = _getch();
		DrawGraphics::gotoxy(x, y);
		cout << " ";
		switch (key) {
		case 'a':
			x--;
			break;
		case 'd':
			x++;
			break;
		case 'w':
			y--;
			break;
		case 's':
			y++;
			break;
		}
		DrawGraphics::gotoxy(x, y);
		cout << "♥";

	}
*/
// 입력  색 바꾸기, 커서 추가
/*
unsigned char key;
int x = 40, y = 12, number =0;
int isExit =0 ;
DrawGraphics::setcolor(10, 14);
DrawGraphics::cursor(0);

DrawGraphics::gotoxy(x, y);
cout << "♥";
while (!isExit) {
	if(_kbhit()){
	key = _getch();
	if (key == 0xE0 || key == 0) {
		key = _getch();
		DrawGraphics::setcolor(15, 0);
		DrawGraphics::gotoxy(x, y);
		cout << " ";
		switch (key) {
		case LEFTKEY:
			x--;
			break;
		case RIGHTKEY:
			x++;
			break;
		case UPKEY:
			y--;
			break;
		case DOWNKEY:
			y++;
			break;
		}
		DrawGraphics::setcolor(10, 14);
		DrawGraphics::gotoxy(x, y);
		cout << "♥";
		DrawGraphics::gotoxy(0, 0);
		cout << ++number;
	}
	else {
		switch (key) {
		case ESCKEY:
			isExit = true;
			break;
		}
	}
	}


}
*/

	//예제
	unsigned char key;
	boolean isExit= 0;

	DrawGraphics::cursor(0);
	int number = 0;
	player play;
	FrameClass fc(15, 0);
	itemObject testitem(5, 5, "<B>", 5, 3, 11, 7);

	fc.DrawFrame();
	testitem.DrawMode1();
	play.initialize(12, 10, 10, 14, "<A>", 1);
	play.DrawMode();

	fc.Drawboard();
	DWORD txtCheckTime = 0;
	DWORD ticktime = 500;
	txtCheckTime = timeGetTime();

	while (!isExit) {
		if (_kbhit()) {
			key = _getch();
			if (key == 0xE0 || key == 0) {
				key = _getch();
				play.moveProcess(key);
			}
			else {
				switch (key) {
				case ESCKEY:
					isExit = true;
					break;
				}

			}
		}
		if (timeGetTime() - txtCheckTime > ticktime) {
			txtCheckTime = timeGetTime();
			DrawGraphics::gotoxy(0, 0);
			cout << ++number;
		}
		
		
	}

}