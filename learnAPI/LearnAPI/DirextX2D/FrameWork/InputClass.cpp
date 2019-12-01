#include "../Stdafx.h"
#include "InputClass.h"



InputClass::InputClass()
{
}


InputClass::InputClass(const InputClass& other)
{
}


InputClass::~InputClass()
{
}


void InputClass::Initialize()
{
	for (int n = 0; n < MAX_KEYS; n++)
	{
		_Keys[n] = false;
	}
}


void InputClass::KeyDown(unsigned int input)
{
	// 키가 눌려진 경우 해당 상태를 키 배열에 저장하십시오.
	_Keys[input] = true;
}


void InputClass::KeyUp(unsigned int input)
{
	// 키가 해제 된 경우 키 배열에서 해당 상태를 지웁니다.
	_Keys[input] = false;
}


bool InputClass::IsKeyDown(unsigned int key)
{
	// 키가 어느 상태에 있는지를 리턴합니다 (눌렀다가 밀리지 않은 상태).
	return _Keys[key];
}

