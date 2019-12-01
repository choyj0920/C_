#include "Stdafx.h"

#include "./FrameWork/ApplicationClass.h"


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR pScmdline, int iCmdshow)
{
	int nMsg = 0;
	if (ApplicationClass::GetInstance()->Initialize(hInstance))
	{
		nMsg = ApplicationClass::GetInstance()->Run();
	}

	ApplicationClass::GetInstance()->Shutdown();
	ApplicationClass::GetInstance()->DestroyInstance();

	return nMsg;
}

