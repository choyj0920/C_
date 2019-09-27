
#ifndef PCH_H
#define PCH_H
#include<stdio.h>
#include<iostream>
#include<Windows.h>
#include <string.h>  
#include<cstdlib>
#include<ctime>
#include <string>
#include <conio.h>
#include "DrawGraphics.h"


using namespace std; //이걸 쓰면 std:: 안써도 ㄱㅊ

//확장키 
#define UPKEY 72
#define DOWNKEY 80
#define LEFTKEY 75
#define RIGHTKEY 77
//기본 키
#define ESCKEY 27
#define SPACEBARKEY 32

// 스크린 정보
#define SCREEN_WIDTH  80
#define SCREEN_HEIGHT 23
#define GAME_SCREEN_W 60
#define MAX_BUFFSIZE 1000

enum eObjectType {
	OBJ_item,
	OBJ_player
};


#endif //PCH_Ha
