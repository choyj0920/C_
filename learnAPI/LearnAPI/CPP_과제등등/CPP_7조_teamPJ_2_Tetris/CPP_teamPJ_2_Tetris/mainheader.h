#pragma once
#include <cstdio> //c��� stdio���̺귯��
#include <time.h> //���� ������ �õ带 �ð����� ���ֱ� ���� 
#include <conio.h>
#include <iostream> 
#include "ConsoleControl.h"
#pragma warning(disable: 4996) //scanf���� ����
//��� ����
//*********************************

#define EXT_KEY         0xffffffe0   //Ȯ��Ű �νİ� 
#define KEY_LEFT      0x4b
#define KEY_RIGHT      0x4d
#define KEY_UP         0x48
#define KEY_DOWN      0x50
#define KEY_ESC			 0x1b   //ESC�� �νİ� -esc�� ���Ḧ ���� �߰����� ����
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


