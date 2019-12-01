#pragma once
#pragma comment(lib, "d3d11.lib")

// ���� �������� ����...
#define WIN32_LEAN_AND_MEAN

// �ʿ� ���� �����ε�.
#define MAX_KEYS		256



// ����� include.
#include <stdio.h>
#include <Windows.h>
#include <tchar.h>
#include <iostream>

#include <d3dcommon.h>
#include <d3d11.h>
#include <DirectXMath.h>
#include <DirectXPackedVector.h>


// �ʿ� ���ӽ����̽� using��.
using namespace std;
using namespace DirectX;


#include "FrameWork/InputClass.h"
#include "./FrameWork/Graphics.h"


// ��Ŭ�� Ŭ����
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