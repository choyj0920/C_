#include "framework.h"

CPUClass::CPUClass()
{
}

CPUClass::CPUClass(const CPUClass& copy)
{
}

CPUClass::~CPUClass()
{
}

bool CPUClass::Initialize()
{
	PDH_STATUS status;

	//이 객체가 시스템 CPU사용을 읽을수 있는지  여부를 나타내는 플래그를 초기화합니다.
	_CanReadCPU = true;

	//cpu사용을 폴링하는 쿼리 개체 만들기
	status = PdhOpenQuery(NULL, 0, &_QueryHandle);

	if (status != ERROR_SUCCESS) {
		_CanReadCPU = false;
	}
	
	//시스템의  모든 cpu를 폴링하도록 쿼리 개체를 설정합니다.
	status = PdhAddCounter(_QueryHandle, TEXT("\\Processor(_Total)\\% processor time"),
		0, &_CounterHandle);

	if (status != ERROR_SUCCESS) {
		_CanReadCPU = false;
	}
	_LastSapleTime = GetTickCount();
	_CPUUsage = 0;



	return true;
}

void CPUClass::Release()
{
	if (_CanReadCPU) {
		PdhCloseQuery(_QueryHandle);
	}
}

void CPUClass::Frame()
{
	PDH_FMT_COUNTERVALUE  value;
	
	if (_CanReadCPU) {
		if ((_LastSapleTime + 1000) < GetTickCount()) {
			_LastSapleTime = GetTickCount();
			PdhCollectQueryData(_QueryHandle);
			PdhGetFormattedCounterValue(_CounterHandle, PDH_FMT_LONG, NULL, &value);
			_CPUUsage = value.longValue;
		}
	}
}

int CPUClass::GetCpuPercentage()
{
	int usage;
	if (_CanReadCPU) {
		usage = (int)_CPUUsage;

	}
	else {
		usage = 0;

	}
	return usage;
}
