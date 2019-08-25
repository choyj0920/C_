#include "pch.h"
#include "Class.h"

void A::over()
{
	cout << "A클래스의 over 함수 호출!" << endl;
}

void B::over()
{
	A::over();
	cout << "B클래스의 over 함수 호출!" << endl;

}
