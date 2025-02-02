#pragma once
#pragma comment(lib, "d3d11.lib")

// 제공 디파인을 위한...
#define WIN32_LEAN_AND_MEAN

// 필요 생성 디파인들.
#define MAX_KEYS		256



// 헤더들 include.
#include <stdio.h>
#include <Windows.h>
#include <tchar.h>
#include <iostream>

#include <d3dcommon.h>
#include <d3d11.h>
#include <DirectXMath.h>
#include <DirectXPackedVector.h>


// 필요 네임스페이스 using들.
using namespace std;
using namespace DirectX;


#include "FrameWork/InputClass.h"
#include "./FrameWork/Graphics.h"


// 싱클톤 클래스
template < typename T >
class Singleton
{
protected:
	Singleton() {}
	virtual ~Singleton() {}
public:
	static T * GetInstance()
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
	static T * _Instance;
};
template <typename T> T * Singleton<T>::_Instance = NULL;