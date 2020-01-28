#include "mainheader.h"

char Block::total_block[21][14] = { 0, };
const char Block::block[7][4][4][4] = { //[도형의 모양 0~6][도형의 각도 0~3][y][x]
   //막대모양
   1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,   1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,   1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,   1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,

   //네모모양
   1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,   1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,   1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,   1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,

   //'ㅓ' 모양
   0,1,0,0,1,1,0,0,0,1,0,0,0,0,0,0,   1,1,1,0,0,1,0,0,0,0,0,0,0,0,0,0,   1,0,0,0,1,1,0,0,1,0,0,0,0,0,0,0,   0,1,0,0,1,1,1,0,0,0,0,0,0,0,0,0,

   //'ㄱ'모양
   1,1,0,0,0,1,0,0,0,1,0,0,0,0,0,0,   1,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,   1,0,0,0,1,0,0,0,1,1,0,0,0,0,0,0,   0,0,1,0,1,1,1,0,0,0,0,0,0,0,0,0,

   //'ㄴ' 모양
   1,1,0,0,1,0,0,0,1,0,0,0,0,0,0,0,   1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,   0,1,0,0,0,1,0,0,1,1,0,0,0,0,0,0,   1,1,1,0,0,0,1,0,0,0,0,0,0,0,0,0,

   //'Z' 모양
   1,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,   0,1,0,0,1,1,0,0,1,0,0,0,0,0,0,0,   1,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,   0,1,0,0,1,1,0,0,1,0,0,0,0,0,0,0,

   //'S' 모양
   0,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0,   1,0,0,0,1,1,0,0,0,1,0,0,0,0,0,0,   0,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0,   1,0,0,0,1,1,0,0,0,1,0,0,0,0,0,0

};


void Block::init_total()
{
	for (int i = TOP; i < BOTTOM; i++)//y좌표
	{
		for (int j = LEFTSIDE; j <= RIGHTSIDE; j++) //x좌표
		{
			if ((j == LEFTSIDE) || (j == RIGHTSIDE)) //x좌표가 0또는 13일때 - 왼쪽 오른쪽 벽 블록 설정
			{
				total_block[i][j] = 1; //블록 
			}
			else {
				total_block[i][j] = 0;   //아니면 빈블록
			}
		}
	}

	for (int j = LEFTSIDE; j <= RIGHTSIDE; j++)         //화면의 제일 밑의 줄은 1로 채운다. 맨밑줄
		total_block[BOTTOM][j] = 1;

}

void Block::show_total_block(const int& level)
{
	SetColor(DARK_GRAY);// 전체 블록, 색 설정 다크그레이
	for (int i = TOP; i <= BOTTOM; i++) //y축
	{
		for (int j = LEFTSIDE; j <= RIGHTSIDE; j++)//x축
		{
			if (j == LEFTSIDE || j == RIGHTSIDE || i == BOTTOM)      //레벨에 따라 외벽 색이 변함
			{
				SetColor((level % 6) + 1); //레벨에 따른 외벽색

			}
			else {
				SetColor(DARK_GRAY); //외벽이 아니면 그냥 다그색으로 
			}
			gotoxy((j * 2) + ab_x, i + ab_y); //해당 블록 
			if (total_block[i][j] == 1)//빈칸이 아니면 네모 출력, 
			{
				printf("■");
			}
			else {
				printf("  ");
			}

		}
	}
	SetColor(BLACK);// 출력하는 글자 색 초기화- 
	gotoxy(77, 23);//커서 위치 재설정
	return;
}

int Block::check_full_line(GameManager& game)
{
	for (int i = TOP; i < BOTTOM; i++) //전체 모든 줄 체크
	{
		int j;
		for (j = LEFTSIDE + 1; j < RIGHTSIDE; j++) //i 줄의 모든 칸을 체크
		{
			if (total_block[i][j] == 0)//중간에 빈 곳이 있으면 break
				break;
		}
		if (j == 13)   //한줄이 다 채워졌음- j=13 break 없이 반복이 13번 수행된 
		{


			//출력-동작
			show_total_block(game.getStagelevel()); //토탈블록 출력
			SetColor(BLUE); // 블루로 출력
			gotoxy(1 * 2 + ab_x, i + ab_y); // 이 줄 위치로 가서
			for (j = 1; j < 13; j++)
			{
				printf("□"); //블루색으로 한번 출력 해주고
				Sleep(10); //0.01초마다 출력
			}
			gotoxy(1 * 2 + ab_x, i + ab_y); //다시 줄의 시작으로 가서
			for (j = 1; j < 13; j++)
			{
				printf("  ");// 쭉 지워줌
				Sleep(10);
			}

			//데이터 수정부
			for (int k = i; k > 0; k--)//지금 줄 i부터 그 윗줄 반복
			{
				for (j = 1; j < RIGHTSIDE; j++) //x축
					total_block[k][j] = total_block[k - 1][j];//바로 위에 줄의 정보를 가져옴
			}

			for (j = 1; j < 13; j++) //맨 위의 줄 0으로 초기화 해줌
				total_block[0][j] = 0;
			game.fullLine();

		}
	}
	show_total_block(game.getStagelevel());
	return 0;
}




Block::Block()
{
}

Block::Block(int shape, int angle, POINT pos) :block_shape(shape), block_angle(angle), pos(pos)
{
}

Block::~Block()
{
}

int Block::getBShape()
{
	return block_shape;
}

void Block::setBshape(int shape)
{
	this->block_shape = shape;
}

int& Block::getangle()
{
	return block_angle;
}



POINT& Block::getPos()
{
	return pos;
}

void Block::moveX(const int& x)
{
	pos.x += x;
}

void Block::moveY(const int& y)
{
	pos.y += y;
}

bool Block::rotate_Right()
{
	block_angle = (block_angle + 1) % 4; //angle을 하나 올리고
	if (strike_check()) { //충돌하면
		block_angle = (block_angle - 1) % 4; //복귀
		return false; //성공 실패리턴이나 결국 사용하지 않음
	}
	else
		return true; //
}



Block  Block::make_new_block(const int stick_rate)
{
	// i= 확률
	int i;
	i = rand() % 100;
	if (i <= stick_rate)      //막대기 나올확률 계산
		return Block(0);                //막대기 모양으로 리턴
	else
		return Block((rand() % 6) + 1);

}

void Block::show_cur_block()
{
	//정의 해둔 SetColor함수를 이용하여 모양에 따른 색 출력 구현
	switch (block_shape)
	{
	case 0:
		SetColor(RED);
		break;
	case 1:
		SetColor(BLUE);
		break;
	case 2:
		SetColor(SKY_BLUE);
		break;
	case 3:
		SetColor(WHITE);
		break;
	case 4:
		SetColor(YELLOW);
		break;
	case 5:
		SetColor(VOILET);
		break;
	case 6:
		SetColor(GREEN);//greenjoa!
		break;
	default:
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if ((j + pos.y) < 0)// 출력되는 y좌표가 0이하 콘솔 창밖을 벗어날때는 출력하지 않음
				continue;

			if (block[block_shape][block_angle][j][i] == 1) //해당하는 도형의 j,i위치가 빈블록이 아닐 때
			{
				gotoxy((i + pos.x) * 2 + ab_x, j + pos.y + ab_y); //(i+x)*2 + ab_x,j+y+ab_y 위치에 출력 저 사각형의 출력이 2칸 차지하므로 x는 두배
				printf("■");

			}
		}
	}

	SetColor(BLACK);// 출력하는 글자 색 초기화- 
	gotoxy(77, 23);//커서 위치 재설정
	return;
}

//네비블록 출력 함수
void Block::show_naviblock(const Block& origin)
{
	this->erase_cur_block(); //이전 네비 블록을 지우고
	*this = origin; 
	//origin으로 받아온 현재 이동블록으로 자기자신초기화

	switch (block_shape)
	{//shape에 따라서 ..색 출력
	case 0:
		SetColor(DARK_RED);
		break;
	case 1:
		SetColor(DARK_BLUE);
		break;
	case 2:
		SetColor(DARK_SKY_BLUE);
		break;
	case 3:
		SetColor(GRAY);
		break;
	case 4:
		SetColor(DARK_YELLOW);
		break;
	case 5:
		SetColor(DARK_VOILET);
		break;
	case 6:
		SetColor(DARK_GREEN);
		break;
	}


	while (strike_check() != true) //충돌 할때까지 
		moveY(1); //내려감
	moveY(-1);

	//출력부
	for (int i = 0; i < 4; i++)//y축
	{
		for (int j = 0; j < 4; j++) //x축
		{
			if ((j + pos.y) < 0) //0보다 작을때에는 출력x
				continue;

			if (block[block_shape][block_angle][j][i] == 1)
			{
				gotoxy((i + pos.x) * 2 + ab_x, (j + pos.y) + ab_y);
				printf("■");

			}
		}
	}

	//출력 후 초기화
	SetColor(BLACK);
	gotoxy(77, 23);
	return;
}

//블록 지우기 함수
int Block::erase_cur_block()
{

	if (block_shape <= 6 && block_shape >= 0)
		for (int i = 0; i < 4; i++) //y축
		{
			for (int j = 0; j < 4; j++) //x축
			{
				if (block[block_shape][block_angle][j][i] == 1)//해당하는 블록위치가 빈 블록이 아닐 때
				{
					if (total_block[j + pos.y][i + pos.x] == 1) break; //이동블록이 끝까지 이동한후 다음블록이 끝까지 이동할때까지 출력되지 않는 문제가 있어 토탈블록의 부분일때는 안지워주게 추가
					gotoxy((i + pos.x) * 2 + ab_x, j + pos.y + ab_y);//이 위치에 빈블록으로 지움
					printf("  ");
					//break;

				}
			}
		}

	return 0;
}

//충돌 체크
bool Block::strike_check()
{
	int block_dat;

	if (block_shape <= 6 && block_shape >= 0) {
		for (int i = 0; i < 4; i++)//y
		{
			for (int j = 0; j < 4; j++)//x
			{
				if ((pos.x + j) == LEFTSIDE || (pos.x + j) == RIGHTSIDE)
					block_dat = 1;   //이 블록이 지금 토탈 블록의 외곽부 이면 -1
				else if (pos.y + i < 0) //이경우 total_block  에는 이부분이 없기에 추가  수정--
					block_dat = 0;
				else
					block_dat = total_block[pos.y + i][pos.x + j];  //이블록이 토탈블록에 빈블록인지,찬 블록인지


				if ((block_dat != 0) && (block[block_shape][block_angle][i][j] == 1))  
				{ //좌측벽의 좌표를 빼기위함? -- 이블록이 빈블록이 아니고 도형의 이 블록 부분도 1이면 충돌 !
					return true;
				}
			}
		}
		return 0;
	}
	return 1;

}

//블록 병합
void Block::merge_block()
{
	for (int i = 0; i < 4; i++)//y축
	{
		for (int j = 0; j < 4; j++)//x축
		{ //토탈 블록에 현재블록 부분을 1로 바꿔줌
			total_block[pos.y + i][pos.x + j] |= block[block_shape][block_angle][i][j];
		}
	}
	return;

}

void Block::show_next_block(const int& level)
{

	SetColor((level + 1) % 6 + 1); //다음블록이 표기되는 테두리는 레벨따라 색이 다름
	for (int i = 1; i < 7; i++) //다음에 무슨 블록이 나올지 알려주는 네모난 공간을 만듦
	{
		gotoxy(33, i);
		for (int j = 0; j < 6; j++)
		{
			// 첫 행과 마지막 행만 색칠된 네모칸을 쭉 출력함. 나머지는 첫 번째 열과 마지막 줄 열에만 네모 출력.
			if (i == 1 || i == 6 || j == 0 || j == 5)
			{
				printf("■");
			}
			else {
				printf("  ");
			}

		}
	}
	Block temp(block_shape, 0, { 15, 1 });
	temp.show_cur_block(); // 15*2+ab_x하면 35,  다음블록 안에다가 도형 출력
}

void Block::block_start()
{
	pos = { 5,-3 };
	block_angle = 0;
}

bool Block::check_in_Total()
{
	if (block_shape <= 6 && block_shape >= 0) {
		for (int i = 0; i < 4; i++)//y for문 순서상 가장 위에잇는 칸부터 
		{
			for (int j = 0; j < 4; j++)//x
			{
				if (block[block_shape][block_angle][i][j] == 1) { //가장위에 있는 블록
					if (pos.y + i < 0) //블록의 가장위쪽 위치가 0보다 작으면 밖에 있음!
						return false;
					else
						return true;//아니면 안에
				}
			}
		}
	}
}

