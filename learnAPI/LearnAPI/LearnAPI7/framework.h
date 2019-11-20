
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


#pragma comment(lib, "Msimg32.lib")
#include "LearnAPI7.h"
#include"ChildClass.h"
#include <Ole2.h> // 이거없으면 에러 폭탄
#include  <gdiplus.h>

#pragma comment(lib,"gdiplus")

using namespace Gdiplus;
#include "ImageDraw.h"


