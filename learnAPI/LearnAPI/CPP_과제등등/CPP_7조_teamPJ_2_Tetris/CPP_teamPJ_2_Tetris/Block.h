#pragma once
class GameManager;
#include "mainheader.h"

#ifndef DEFBLOCK
#define DEFBLOCK 0
class Block
{
private:
	//블록 모양,각도 저장 변수
	int block_shape, block_angle;
	POINT pos; //블록 위치 저장 변수

	//블록 절대 위치 - 이곳을 기준으로 블록위치 지정
	static const int ab_x = 5, ab_y = 1;

public:
	Block(); //블록 생성자
	Block(int shape, int angle = 0, POINT pos = { 0, 0 });
	~Block();
	//멤버 변수 겟 함수
	int getBShape();
	void setBshape(int shape);
	int& getangle();
	POINT& getPos();
	//x축방향으로 x 만큼  이동해주는 함수
	void moveX(const int& x);
	//y축 방향으로 y만큼 이동해주는 함수
	void moveY(const int& y);
	//회전할수 있을 때에만 angle+1 해주는 함수
	bool rotate_Right();
	

	//블록 표시 모양과,각도 ,x,y를 받아서  블록 출력
	void show_cur_block();
	// 네비블록 표시
	void show_naviblock(const Block& origin);
	//블록의 모양 각도 위치를 받아 출력 되었었던 블록을 빈 칸으로 그대로 덮어 씌워 지워줌
	int erase_cur_block();
	//충돌 체크 함수 -매개 x
	bool strike_check();
	//자기자신블록과 토탈 블록을 토탈블록에 병합한다. 매개x
	void merge_block();
	//다음 블록 출력함수-다음블록 칸에 출력하기
	void show_next_block(const int& level);
	//블록 이동 시작전 위치 초기화 함수
	void block_start();
	//지금 블록이 게임 화면상에 있는지 확인해주는 함수
	bool check_in_Total();

	//새로운 블록 생성 새로운 블록의 모양 설정 ,- 레벨에따른 스틱 확률에 따른..
	static Block make_new_block(const int stick_rate);

	//shape,각도별 블록모양-
	static const char block[7][4][4][4];
	
	//전체 블록
	static char total_block[BOTTOM+1][RIGHTSIDE+1];
	//전체 블록 초기화
	static void init_total();
	//전체 블록 출력
	static void show_total_block(const int& level);
	//토탈블록의 줄 전체가 가득 찬 부분이 있으면- 제거하고 토탈 블록 데이터 수정 
	static int check_full_line(GameManager &game);

	
};
#endif // !DEFBLOCK