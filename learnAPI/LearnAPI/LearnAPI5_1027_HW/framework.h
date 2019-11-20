
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
#include "DrawImage.h"

#pragma comment(lib, "Msimg32.lib")

//파일 경로 가져오기 api
#include <Shlwapi.h>
#pragma comment(lib, "shlwapi.lib")

#define ID_CON_BUTTON_1 1000
#define ID_CON_BUTTON_2 1001
#define ID_CON_BUTTON_3 1003
#define ID_CON_BUTTON_4 1004
#define ID_CON_BUTTON_5 1005
#define ID_CON_BUTTON_6 1006
#define ID_CON_BUTTON_7 1007
#define ID_CON_CHECKBOX_1 1101
#define ID_CON_CHECKBOX_2 1102
#define ID_CON_EDIT_1 1201
#define ID_CON_EDIT_2 1202
#define ID_CON_LIST_1 1301
#define ID_CON_LIST_2 1302
#define ID_CON_COMBO_1 1401
#define ID_CON_SCROLL_1 1501
#define ID_CON_SCROLL_2 1502