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
	//�� �ý����� ���� Ÿ�̸Ӹ� �����ϴ��� Ȯ��
	QueryPerformanceFrequency((LARGE_INTEGER*)&_Frequency);

	if (_Frequency == 0) {
		MessageBox(NULL, _T("�ϵ� ��� ���ػ� ī���͸� �������� �ʽ��ϴ�."), NULL, MB_OK);
		return false;
	}

	//���ļ� ī���Ͱ� �� �и� �ʸ��� ƽ�ϴ� ���� Ȯ���Ͻʽÿ�/
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
