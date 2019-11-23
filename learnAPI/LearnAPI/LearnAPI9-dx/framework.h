
#pragma once

//#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.
// Windows 헤더 파일
#include <windows.h>
// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <tchar.h>
#include "LearnAPI9-dx.h"
#define MAX_LOADSTRING 100



#define IDM_START_PRINT 1000
#define ID_CON_BUTTON_1 10001
#define ID_CON_BUTTON_2 10002
#define ID_CON_BUTTON_3 10003
#define ID_CON_BUTTON_4 10004
#define RAND_SPEED_TIMER 2000
#define RUN_TIMER 2001
#define DELETE_TIMER 2002

// 싱클톤 클래스
template < typename T >
class Singleton
{
protected:
	Singleton() {}
	virtual ~Singleton() {}
public:
	static T* GetInstance()
	{
		if (_Instance == NULL)
			_Instance = new T;
		return _Instance;
	};

	static void DestroyInstance()
	{
		if (_Instance)
		{
			delete _Instance;
			_Instance = NULL;
		}
	};
private:
	static T* _Instance;
};
template <typename T> T* Singleton<T>::_Instance = NULL;

#include "./FrameWork/GraphicsClass.h"
#include ".\FrameWork\InputClass.h"

#include "./FrameWork/System.h"

