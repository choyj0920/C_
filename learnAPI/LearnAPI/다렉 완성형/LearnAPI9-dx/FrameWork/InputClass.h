#pragma once
#include <Windows.h>
#define MAX_KEYS 256
class InputClass
{
	bool _Keys[MAX_KEYS];
public:
	InputClass();
	InputClass(const InputClass& copy);
	~InputClass();

	void Initialize();

	void KeyDown(unsigned int input);
	void KeyUp(unsigned int input);

	bool IsKeyDown(unsigned int);
};

