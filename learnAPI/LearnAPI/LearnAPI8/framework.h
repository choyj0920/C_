
#pragma once

#include "targetver.h"
//#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.
// Windows 헤더 파일
#include <windows.h>
// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <cstdlib>
#include <ctime>
#include <tchar.h>
#define MAX_LOADSTRING 100
#define CH_COU 7


#pragma comment(lib, "Msimg32.lib")
#include "LearnAPI8.h"
#include"ChildClass.h"
#include <Ole2.h> // 이거없으면 에러 폭탄
#include  <gdiplus.h>

#pragma comment(lib,"gdiplus")
#include "ImageDraw.h"

using namespace Gdiplus;
#include "DrawImage.h"
#include "Character.h"
#include "Ch_Manager.h"

#define firstline 100
#define finishline 800

#define IDM_START_PRINT 1000
#define ID_CON_BUTTON_1 10001
#define ID_CON_BUTTON_2 10002
#define ID_CON_BUTTON_3 10003
#define ID_CON_BUTTON_4 10004
#define RAND_SPEED_TIMER 2000
#define RUN_TIMER 2001
#define DELETE_TIMER 2002