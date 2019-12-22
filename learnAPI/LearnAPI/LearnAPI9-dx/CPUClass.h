#pragma once
class CPUClass
{
	bool _CanReadCPU;
	HQUERY _QueryHandle;
	HCOUNTER _CounterHandle;
	unsigned long _LastSapleTime;
	long _CPUUsage;

public:
	CPUClass();
	CPUClass(const CPUClass& copy);
	~CPUClass();
	
	bool Initialize();
	void Release();
	void Frame();
	int GetCpuPercentage();
};

