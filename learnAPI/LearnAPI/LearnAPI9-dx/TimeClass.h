#pragma once
class TimeClass
{
	INT64 _Frequency;
	float _TicksPerMs;
	INT64 _startTime;
	float _FrameTime;
	double _GameStartTime;
	
	int _FPS;
	int _Count;
	double _CheckTime;

public:
	TimeClass();
	TimeClass(const TimeClass& copy);
	~TimeClass();

	bool Initialize();
	void Frame();
	float GetdeltaTime();
	double GetdelTime();
	int GetFps();

};

