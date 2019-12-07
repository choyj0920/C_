#pragma once
#pragma comment(lib, "d3d11.lib")//이거안넣음녀 오류
#pragma comment(lib, "d3dcompiler.lib")//이거안넣음녀 오류

// 제공 디파인을 위한...
#define WIN32_LEAN_AND_MEAN
// 필요 생성 디파인들.
#define MAX_KEYS		256



// 헤더들 include.
#include <stdio.h>
#include <Windows.h>
#include <tchar.h>
#include <iostream>
#include <fstream>
#include <d3dcommon.h>
#include <d3d11.h>
#include <DirectXMath.h>

#include <DirectXPackedVector.h>
#include<d3dcompiler.h>


// 필요 네임스페이스 using들.
using namespace std;
using namespace DirectX;

#include "D3D/ModelTraingle.h" 
#include "D3D/ModelRect.h"
#include "D3D/ColorShader.h" 
#include "D3D/Camera.h"
#include "D3D/D3DClass.h"

#include "./FrameWork/GraphicsClass.h"
#include "./FrameWork/InputClass.h"

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

