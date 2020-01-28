#include "mainheader.h"

GameManager::GameManager()
{
	initData();
}

GameManager::~GameManager()
{

}

//데이터 초기화 함수 
void GameManager::initData()
{
	//블록의 토탈 블록 초기화함수 실행
	Block::init_total();
	//현재 스테이지레벨, 라인수,점수 초기화
	stagelevel = 0;
	clearline = 0;
	score = 0;
}

void GameManager::show_gamestat()
{
	//처음에 한번만 출력한뒤 스테이지 스코어 라인 글씨는 다시 출력 안하려 한 부분인거 같은데 
//printed_text를 0이 아닌 수로 변하는 부분이 없어 딱히 의미가 없는듯? -일단 그냥 유지
	static int printed_text = 0; // 밑에있는 조건문의 조건에 들어가는 변수 조건문을 실행해줌

	SetColor(GRAY);
	if (printed_text == 0)
	{ //점수 출력
		gotoxy(35, 7);
		printf("STAGE");

		gotoxy(35, 9);
		printf("SCORE");

		gotoxy(35, 12);
		printf("LINES");


	}
	gotoxy(41, 7);
	printf("%d", stagelevel + 1);
	gotoxy(35, 10);
	printf("%10d", score);
	gotoxy(35, 13);
	printf("%10d", STAGE::stage[stagelevel].getclear_line() - clearline);
}

void GameManager::GameRun()
{
	//게임 오버 여부 담을 변수
	SetCursorvisible(false); //시작시 커서끔
	int is_gameover = 0;
	initData(); //초기화 함수 수행
	Logo(); //로고 띄우고
	while (true) //
	{
		SetCursorvisible(true);//스테이지 선택시 커서 보여줌
		input_data(); //스테이지 선택 함수
		SetCursorvisible(false); //스테이지 선택후 커서 끔
		Block::show_total_block(stagelevel); //토탈 블록 출력 - 맨처음 프레임 출력
		
		//최초 블록 세팅
		MoveBlock = Block::make_new_block(STAGE::stage[stagelevel].getStick_rate()); //블록 생성
		MoveBlock.block_start(); //시작 블록 초기화
		
		NextBlock = Block::make_new_block(STAGE::stage[stagelevel].getStick_rate()); //다음 블록 생성
		
		naviBlock.show_naviblock(MoveBlock); //네비 블록보이기
		MoveBlock.show_cur_block(); // 이동블록 출력-네비보다 먼저 하면 네비에서출력이지워짐
		NextBlock.show_next_block(stagelevel); //다음 블록 칸 표시
		show_gamestat();

		for (int i = 0; true;  i++) { //무한 루프
			if (_kbhit()) { //키입력이 있으면
				char keytemp = _getch(); 
				if (keytemp == KEY_ESC) {		//esc입력이 들어오면-종료
					initData(); //데이터 초기화
					system("cls"); //전체 초기화
					MoveBlock.block_start(); //
					break;
				}
				if (keytemp == EXT_KEY) {//확장키- 방향키입력시
					keytemp = _getch();//확장키 구분
					switch (keytemp)
					{
					case KEY_UP: { //업키- 회전 키
						MoveBlock.erase_cur_block(); //이동블록 일단 지우고
						MoveBlock.rotate_Right(); //회전 시킬수 있을 때에만 회전해주는 함수
						naviBlock.show_naviblock(MoveBlock); //네비 블록보이기
						MoveBlock.show_cur_block(); // 이동블록 출력
						break;
					}
					case KEY_LEFT: {//좌측키 -왼쪽이동키
						if (MoveBlock.getPos().x > LEFTSIDE) { //이동블록이 가장 좌측에 있지 않으면
							MoveBlock.erase_cur_block(); //이동 블록 일단지우고
							MoveBlock.moveX(-1); //한칸 이동후
							if (MoveBlock.strike_check()) { //충돌하면 
								MoveBlock.moveX(1); //다시 원 위치로
							}
							naviBlock.show_naviblock(MoveBlock); //네비 블록보이기
							MoveBlock.show_cur_block(); // 이동블록 출력
						}
						break;
					}
					case KEY_RIGHT: {//우측키 오른쪽 이동키
						if (MoveBlock.getPos().x < RIGHTSIDE) {//이동 블록이 가장 우측에 있지 않으면 -이거는 별로의미가 없는듯
							MoveBlock.erase_cur_block(); //이동 블록 일단 지우고
							MoveBlock.moveX(1); //한 칸 이동후
							if (MoveBlock.strike_check()) {//충돌하면
								MoveBlock.moveX(-1); //다시 원위치로
							}
							naviBlock.show_naviblock(MoveBlock); //네비 블록보이기
							MoveBlock.show_cur_block(); // 이동블록 출력
						}
						break;
					}
					case KEY_DOWN: { //아래키 - 내려가게하는 키
						is_gameover = move_block(); //블록을 한칸 아래로 이동함수
						if(is_gameover==0)  //0값이 출력 되었으면 
							naviBlock.show_naviblock(MoveBlock); //네비 블록보이기
						//is_gameover ==2인 아래에 도달했을때는 어쩌피 네비와 위치가 같아 출력x
						MoveBlock.show_cur_block(); // 이동블록 출력
						
						break;
					}
					default:
						break;
					}
					continue;
				}
				if (keytemp == SPACEBAR) { //스페이스바를 누르면
					while (is_gameover == 0) {
						is_gameover = move_block();// 블록이 아래에 도착할 때까지 수행
					}//이동블록 출력  이부분에서는 네비블록과 위치가 동일 하기에..
					MoveBlock.show_cur_block();
				}
				
			}
			if (is_gameover == 1) { //게임 오버되면
				showGameover(); //게임오버 출력
				SetColor(GRAY); //
				initData(); //데이터 초기화
				MoveBlock.block_start();
				is_gameover = 0;
				break;
			}
			if (STAGE::stage[stagelevel].getclear_line() <=clearline) //깬 라인수가 클리어 수보다 많으면 
			{
				clearline -= STAGE::stage[stagelevel].getclear_line(); //라인수 초기화
				Block::show_total_block(++stagelevel);  //줄 초기화 -수정
				show_gamestat(); 
				
			}
			if ((i % STAGE::stage[stagelevel].getSpeed()) == 0) {
				if (is_gameover != 1) {
					is_gameover = move_block();
					naviBlock.show_naviblock(MoveBlock); //네비 블록보이기
					MoveBlock.show_cur_block(); // 이동블록 출력
				}
				
			}
			//출력부 초기화
			gotoxy(77, 23);
			Sleep(15);
 			gotoxy(77, 23);
		}
		//함수 초기화
		initData();
	}

}

void GameManager::fullLine()
{
	clearline += 1; //라인 클리어 되면 라인 수+1
	score += 100 + (stagelevel * 10) + (rand() % 10); //점수 레벨에따른 상승
	show_gamestat(); //게임 정수판 수정
}

int GameManager::getStagelevel() const
{
	return stagelevel;
}
//블록움직여 주는 함수
int GameManager::move_block()
{
	MoveBlock.erase_cur_block(); //이전 위치의 블록 지우기

	MoveBlock.moveY(1); //아래로 한 칸 이동
	if (MoveBlock.strike_check()) {// 만약 이블록이 토탈 블록과 충돌 했으면
		MoveBlock.moveY(-1);
		if (MoveBlock.check_in_Total()) {//블록 다 떨어짐

			MoveBlock.merge_block();
			Block::check_full_line(*this);
			Block::show_total_block(stagelevel);
			show_gamestat(); //게임 정수판 수정
			MoveBlock = NextBlock; //블록 새롭게 바꾸기
			MoveBlock.block_start(); //
			NextBlock = Block::make_new_block(STAGE::stage[stagelevel].getStick_rate());
			NextBlock.show_next_block(stagelevel);
			return 2;
		}
		else {
			return 1;
		}

	}
	return 0;
}

//로고 출력 함수
void GameManager::Logo()
{
	int i, j;// 반복문에서 사용되는 변수
	//이 출력부도 수정
	gotoxy(13, 3);
	printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓"); //수정 
	Sleep(100);
	gotoxy(13, 4);
	printf("┃◆◆◆  ◆◆◆  ◆◆◆   ◆◆     ◆   ◆  ◆ ┃");
	Sleep(100);
	gotoxy(13, 5);
	printf("┃  ◆    ◆        ◆     ◆ ◆    ◆    ◆◆  ┃");
	Sleep(100);
	gotoxy(13, 6);
	printf("┃  ◆    ◆◆◆    ◆     ◆◆     ◆     ◆   ┃");
	Sleep(100);
	gotoxy(13, 7);
	printf("┃  ◆    ◆        ◆     ◆ ◆    ◆    ◆◆  ┃");
	Sleep(100);
	gotoxy(13, 8);
	printf("┃  ◆    ◆◆◆    ◆     ◆  ◆   ◆   ◆  ◆ ┃");
	Sleep(100);
	gotoxy(13, 9);
	printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛"); //수정

	gotoxy(28, 20);
	printf("Please Press Any Key~!");
	// 키를 입력 받을때 까지 계속 반복해서 블록들 출력함 
	for (i = 0; i >= 0; i++)
	{
		if (i % 40 == 0)
		{ 
			

			for (int i = 14; i < 19; i++) {
				gotoxy(6, i); printf("%95s", ""); //수정-잔상지우기위해
			}
			Block(rand() % 7, rand() % 4, {6,14}).show_cur_block();
			Block(rand() % 7, rand() % 4, { 12,14 }).show_cur_block();
			Block(rand() % 7, rand() % 4, { 19,14 }).show_cur_block();
			Block(rand() % 7, rand() % 4, { 24,14 }).show_cur_block();
			
		}
		if (kbhit())
			break;
		Sleep(30);
	}

	getche();
	system("cls");

	return;
}

//스테이지 선택 함수
void GameManager::input_data()
{
	int i = 0; // 입력받는 값을 변수로 선언
	SetColor(GRAY);
	gotoxy(10, 7);
	printf("┏━━━━━━━ < GAME KEY > ━━━━━━┓"); //수정
	Sleep(10);
	gotoxy(10, 8);
	printf("┃ UP   : Rotate Block       ┃");
	Sleep(10);
	gotoxy(10, 9);
	printf("┃ DOWN : Move One-Step Down ┃");
	Sleep(10);
	gotoxy(10, 10);
	printf("┃ SPACE: Move Bottom Down   ┃");
	Sleep(10);
	gotoxy(10, 11);
	printf("┃ LEFT : Move Left          ┃");
	Sleep(10);
	gotoxy(10, 12);
	printf("┃ RIGHT: Move Right         ┃");
	Sleep(10);
	gotoxy(10, 13);
	printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━┛"); //수정


	while (i < 1 || i>8)// 1미만 8초과인수일때 다시 입력받음
	{
		gotoxy(10, 3);
		printf("Select Start level[1-8]:              \b\b\b\b\b\b\b\b\b\b\b\b\b\b");
		scanf("%d", &i);
		while (getchar() != '\n'); //버퍼를 비움:scanf의 경우 엔터가 버퍼에 남아 값이 있다고 인식되어 무한반복되므로 
		/*
		if (scanf("%d", &i) == 0) { 위의 부분을 이런 식으로 바꿔도 ㄱㅊ
		   rewind(stdin);
		}
		*/

	}


	stagelevel = i - 1;
	system("cls");
	return;
}

//게임오버 출력
void GameManager::showGameover()
{
	//게임 오버 출력
	SetColor(RED);
	gotoxy(15, 8);
	printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
	gotoxy(15, 9);
	printf("┃**************************┃");
	gotoxy(15, 10);
	printf("┃*        GAME OVER       *┃");
	gotoxy(15, 11);
	printf("┃**************************┃");
	gotoxy(15, 12);
	printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
	fflush(stdin); //지금까지 쌓여있던 입력 버퍼를 다 지워줌
	Sleep(1000); //1초 정지후

	getche();
	system("cls");

	return;
}

