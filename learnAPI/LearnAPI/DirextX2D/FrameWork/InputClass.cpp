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
	// Ű�� ������ ��� �ش� ���¸� Ű �迭�� �����Ͻʽÿ�.
	_Keys[input] = true;
}


void InputClass::KeyUp(unsigned int input)
{
	// Ű�� ���� �� ��� Ű �迭���� �ش� ���¸� ����ϴ�.
	_Keys[input] = false;
}


bool InputClass::IsKeyDown(unsigned int key)
{
	// Ű�� ��� ���¿� �ִ����� �����մϴ� (�����ٰ� �и��� ���� ����).
	return _Keys[key];
}

