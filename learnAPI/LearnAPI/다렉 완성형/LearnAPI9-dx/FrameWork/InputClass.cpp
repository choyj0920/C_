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
	//Ű�� ������ ��� �ش� ���¸� Ű�迭�� �����Ͻʽä���
	_Keys[input] = true;
}

void InputClass::KeyUp(unsigned int input)
{
	//Ű�� ������ ��� Ű�迭 �ٽ� ����
	_Keys[input] = false;

}

bool InputClass::IsKeyDown(unsigned int key)
{
	//Ű�� ���� ����
	return _Keys[key];
	
}

InputClass::InputClass(const InputClass& copy)
{
}

InputClass::~InputClass()
{
}
