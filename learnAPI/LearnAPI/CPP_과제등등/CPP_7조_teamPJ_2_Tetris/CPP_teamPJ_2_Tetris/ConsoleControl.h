#pragma once
#include <Windows.h> //윈도우 api제공 헤더
enum { //열거형 SetColor 함수에서 사용을 위한 - 특정 컬러의 번호 0~15에 대한 열거형 정의
	BLACK,      /*  0 : 까망 */
	DARK_BLUE,    /*  1 : 어두운 파랑 */
	DARK_GREEN,    /*  2 : 어두운 초록 */
	DARK_SKY_BLUE,  /*  3 : 어두운 하늘 */
	DARK_RED,    /*  4 : 어두운 빨강 */
	DARK_VOILET,  /*  5 : 어두운 보라 */
	DARK_YELLOW,  /*  6 : 어두운 노랑 */
	GRAY,      /*  7 : 회색 */
	DARK_GRAY,    /*  8 : 어두운 회색 */
	BLUE,      /*  9 : 파랑 */
	GREEN,      /* 10 : 초록 */
	SKY_BLUE,    /* 11 : 하늘 */
	RED,      /* 12 : 빨강 */
	VOILET,      /* 13 : 보라 */
	YELLOW,      /* 14 : 노랑 */
	WHITE,      /* 15 : 하양 */
};
//커서 위치 변경
void gotoxy(int x, int y);
//출력글씨 색 설정
void SetColor(int color);
// 커서 안보이게
void SetCursorvisible(bool visible);
