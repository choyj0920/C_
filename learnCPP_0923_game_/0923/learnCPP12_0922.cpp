#include "pch.h"
#include "player.h"
#include "Object.h"
#include "FrameClass.h"
#include "itemObject.h"

string itemname[7] = { "<A>","<B>", "<C>","<D>","<E>","<F>","<G>" };

void stagestart(int n);
bool fail = 0;

int main()
{
	srand((unsigned)time(0));
	DrawGraphics::cursor(0);	//커서 안보이게
	FrameClass fc(15, 0);		//frame생성을 위한 객체생성
	
	int n = 1;			//첫 스테이지 1번
	while (!fail) {   //실패 하지 않았으면 계속 
		system("cls");
		fc.DrawFrame();				//프레임 출력
		fc.Drawboard();				//오른쪽 블록에 출력 프레임? 출력
		stagestart(n);
		n++;
		if (n > 8) break;
	}
	system("pause");
}

void stagestart(int n)
{
	//3초뒤 시작
	DWORD ticktime = 3000;
	//시작 시간 저장
	DWORD txtCheckTime = timeGetTime();

	//3초뒤 시작
	while (txtCheckTime+ticktime > timeGetTime()) {
		DrawGraphics::gotoxy(28, 12); cout << (int)(txtCheckTime + ticktime - timeGetTime()) / 1000<< "초 뒤 시작";
	}
	//3초뒤 시작 출력했던 줄 지우기
	DrawGraphics::gotoxy(28, 11); cout << "          ";
	DrawGraphics::gotoxy(28, 12); cout << "          ";

	//스테이지 이름 출력 
	DrawGraphics::gotoxy(GAME_SCREEN_W + 1, 3); cout << "        "<<n<<"       ";

	unsigned char key;
	boolean isExit = 0;

	DrawGraphics::cursor(0);
	int number = 0;
	player play;
	play.initialize(12, 10, 6, 1+n/2, "<user>", 10, 14, 1);

	itemObject ** testitem = NULL;
	testitem = new itemObject*[n];
	
	//n개 아이템 생성
	for (int i = 0; i < n; i++) {
		//랜덤한 위치 값.. 테두리에 안걸리는
		int x = rand() % (58 - n/2) +1 ; 
		int y = rand() % (22-(n/2)) + 1;
		testitem[i] = new itemObject(x, y, itemname[i], 3 + n / 2, 1+ n / 2, 11, 7);  //아이템 i번째 생성  ,3+n/2 , 1+n/2는 스테이지에 따른 아이템 블록 크기
		//메모리 할당 ??
		if (testitem[i] == NULL) {
			i--;
			continue;
		}
		// 플레이어와 겹칠경우 다시 생성
		if (testitem[i]->CheckCollider(&play)) {
			i--;
			delete testitem[i];
			continue;
		}
		else
			for (int j = 0; j < i; j++) {  //다른 아이템과 겹칠경우 다시 생성
				if (testitem[i]->CheckCollider(testitem[j])) {
					i--;
					delete testitem[i];
					break;
				}
			}
	}
	//아이템  출력
	for (int i = 0; i < n; i++)
		testitem[i]->DrawMode1();

	//플레이어 출력
	play.player_DrawMode();

	int step = 0;

	txtCheckTime = timeGetTime();
	while (!isExit) {
		// 다음 먹어야할 글자 출력
		DrawGraphics::gotoxy(GAME_SCREEN_W + 1, 7); cout << "        " << (char)('A' + step) << "    ";
		// 경과 시간 출력
		float overtime = (timeGetTime() - txtCheckTime) / 1000.0;
		DrawGraphics::gotoxy(GAME_SCREEN_W + 1, 5); printf("%4s%.1f초 지남", " ", overtime);

		//스텝이 하나씩 더해져 n도달 모든 아이템 다먹음..
		if (step == n) {
			DrawGraphics::gotoxy(25, 11);
			cout << "스테이지 완료!";

			//할당 해제
			if (testitem != NULL) {
				for (int i = 0; i < n; i++)
					delete testitem[i];
				delete[] testitem;
			}
			isExit = true;
			break;
		}
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
		//충돌 체크
		for (int i = step; i < n; i++) {
			bool collide = testitem[i]->CheckCollider(&play);
			//출동했을때에
			if (collide) {
				//그것이 먹어야 할 글자가 맞으면..
				if (i == step) { 
					step++;
					testitem[i]->erase_shape();  //아이템 지우고
					play.player_DrawMode();	//겹쳐진 play다시
				}
				else {
					DrawGraphics::gotoxy(25, 11);
					cout << "스테이지 실패..";
					fail = true; //실패..
					isExit = true;
					break;
				}
				
			}
		}
	}
}
