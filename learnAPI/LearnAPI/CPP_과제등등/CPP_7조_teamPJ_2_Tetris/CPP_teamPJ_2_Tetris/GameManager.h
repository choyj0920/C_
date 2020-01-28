#pragma once
#include "mainheader.h"
#include "STAGE.h"
#ifndef DEFGAME
#define DEFGAME 0
class GameManager
{
private:
	//현재 스테이지 레벨
	int stagelevel;
	//현재 점수
	int score;
	//현재 클리어한 라인
	int clearline;
	
	//현재 이동하는 블록
	Block MoveBlock;
	//다음 블록
	Block NextBlock;
	//그림자 블록
	Block naviBlock;

public:
	GameManager();
	~GameManager();
	//정의된 check_full_line함수  토탈블록이 변화 했으니 줄이 완성 되었으면 지워주기 위해
	void initData();
	//게임 점수판 출력 함수 -해당 위치에 스테이지,점수 라인 정보 출력
	void show_gamestat();
	//게임 주 실행함수
	void GameRun();
	//한 줄이 다찼으면 , 점수,clearline, 점수창 수정
	void fullLine();
	// 현재 스테이지 리턴 함수
	int getStagelevel() const;

	//현재 이동블록을 움직여주는 함수
	// 리턴 값- 0은 정상 한칸 이동, 1이 리턴 게임 오버, 
	//2가 리턴 내려올 수 있는 곳까지 내려왔음(게임오버x)-이 경우 지금블록 병합처리 ,다음블록 처리
	int move_block();
	//게임 시작시 - 도움말표기, 스테이지 선택 함수
	void input_data();

	//객체에 따라 다른 특성이 없는 함수는 정적으로
	static void Logo(); //게임 로고출력함수
	static void showGameover();
};
#endif // !DEFGAME

