#pragma once
#pragma comment(lib, "d3d11.lib")//이거안넣음녀 오류
#pragma comment(lib, "d3dcompiler.lib")//이거안넣음녀 오류
#pragma comment(lib, "DirectXTex.lib")//이거안넣음녀 오류

// 제공 디파인을 위한...
#define WIN32_LEAN_AND_MEAN
// 필요 생성 디파인들.
#define MAX_KEYS		256



// 헤더들 include.
#include <Pdh.h>
#include <stdio.h>
#include <Windows.h>
#include <tchar.h>
#include <iostream>
#include <fstream>
#include <d3dcommon.h>
#include "DirectXTex.h"
#include <d3d11.h>
#include <DirectXMath.h>

#include <DirectXPackedVector.h>
#include<d3dcompiler.h>

#include <vector>
#include <list>
// 필요 네임스페이스 using들.
using namespace std;
using namespace DirectX;
#include "CPUClass.h"

#include "ObjectEnumHelper.h"
#include "ModelFileInfoClass.h"


#include "ModelAxis.h"
#include "TextureClass.h"

#include "TimeClass.h"
#include "fontdata/FontClass.h"

#include "ModelCube.h"

#include "D3D/ModelTraingle.h" 
#include "D3D/ModelRect.h"
#include "SpriteClass.h"

#include "fontdata/FontShader.h"

#include "TextObjectClass.h"

#include "TextureShader.h"
#include "SpriteObjectClass.h"

#include "enermyObject.h"
#include "Model_mal.h"
#include "Model_Mal_anis.h"
#include "D3D/ColorShader.h" 
#include "D3D/Camera.h"
#include "D3D/D3DClass.h"

#include "Mal_with_text.h"



#include "GraphicsClass.h"
#include "InputClass.h"


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

