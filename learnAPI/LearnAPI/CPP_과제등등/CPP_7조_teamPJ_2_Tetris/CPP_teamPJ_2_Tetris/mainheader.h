#pragma once
#include <cstdio> //c언어 stdio라이브러리
#include <time.h> //랜덤 변수의 시드를 시간으로 해주기 위해 
#include <conio.h>
#include <iostream> 
#include "ConsoleControl.h"
#pragma warning(disable: 4996) //scanf에러 방지
//상수 선언
//*********************************

#define EXT_KEY         0xffffffe0   //확장키 인식값 
#define KEY_LEFT      0x4b
#define KEY_RIGHT      0x4d
#define KEY_UP         0x48
#define KEY_DOWN      0x50
#define KEY_ESC			 0x1b   //ESC의 인식값 -esc의 종료를 위해 추가해준 정의
#define SPACEBAR 32

#define LEFTSIDE 0
#define RIGHTSIDE 13
#define TOP 0
#define BOTTOM 20

using namespace std;

#ifndef DEFBLOCK
#include "Block.h"
#endif // !DEFBLOCK

#ifndef DEFGAME
#include "GameManager.h"
#endif // !DEFGAME


