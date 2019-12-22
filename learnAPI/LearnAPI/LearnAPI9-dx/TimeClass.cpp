#include "framework.h"

TimeClass::TimeClass()
{
}

TimeClass::TimeClass(const TimeClass& copy)
{
}

TimeClass::~TimeClass()
{
}

bool TimeClass::Initialize()
{
	//이 시스템이 고성능 타이머를 지원하는지 확인
	QueryPerformanceFrequency((LARGE_INTEGER*)&_Frequency);

	if (_Frequency == 0) {
		MessageBox(NULL, _T("하드 웨어가 고해상도 카운터를 지원하지 않습니다."), NULL, MB_OK);
		return false;
	}

	//주파수 카운터가 매 밀리 초마다 틱하는 수를 확인하십시오/
	_TicksPerMs = (float)_Frequency;

	QueryPerformanceCounter((LARGE_INTEGER*)&_startTime);
	_GameStartTime = 0;

	_FPS = 0;
	_Count = 0;
	_CheckTime = 0;

	return true;

}

void TimeClass::Frame()
{
	INT64 currentTime;
	float timeDifference;

	_Count++;

	QueryPerformanceCounter((LARGE_INTEGER*)&currentTime);
	timeDifference = (float)(currentTime - _startTime);
	_FrameTime = timeDifference / _TicksPerMs;
	_startTime = currentTime;
	_GameStartTime += _FrameTime;

	if (_GameStartTime >= (_CheckTime + 1)) {
		_FPS = _Count;
		_Count = 0;
		_CheckTime = _GameStartTime;
	}
}

float TimeClass::GetdeltaTime()
{
	return _FrameTime;
}

double TimeClass::GetdelTime()
{
	return _GameStartTime;
}

int TimeClass::GetFps()
{
	return _FPS;
}
