#include "InputClass.h"
InputClass::InputClass()
{
}

void InputClass::Initialize()
{
	for (int i = 0; i < MAX_KEYS; i++) {
		_Keys[i] = false;
	}
}

void InputClass::KeyDown(unsigned int input)
{
	//키가 눌러진 경우 해당 상태를 키배열에 저장하십시ㅇ오
	_Keys[input] = true;
}

void InputClass::KeyUp(unsigned int input)
{
	//키가 해제된 경우 키배열 다시 저장
	_Keys[input] = false;

}

bool InputClass::IsKeyDown(unsigned int key)
{
	//키의 지금 상태
	return _Keys[key];
	
}

InputClass::InputClass(const InputClass& copy)
{
}

InputClass::~InputClass()
{
}
