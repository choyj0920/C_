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

	//�� ��ü�� �ý��� CPU����� ������ �ִ���  ���θ� ��Ÿ���� �÷��׸� �ʱ�ȭ�մϴ�.
	_CanReadCPU = true;

	//cpu����� �����ϴ� ���� ��ü �����
	status = PdhOpenQuery(NULL, 0, &_QueryHandle);

	if (status != ERROR_SUCCESS) {
		_CanReadCPU = false;
	}
	
	//�ý�����  ��� cpu�� �����ϵ��� ���� ��ü�� �����մϴ�.
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
