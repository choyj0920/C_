// LearnAPI7.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR pScmdline, int iCmdshow)
{
	int nMsg = 0;
	if (System::GetInstance()->Initialize(hInstance))
	{
		nMsg = System::GetInstance()->Run();
	}

	System::GetInstance()->Shutdown();
	System::GetInstance()->DestroyInstance();

	return nMsg;
}


