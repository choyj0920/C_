#include "pch.h"
#include "Beggar.h"
#include "apple.h"


Beggar::Beggar()
{
}


Beggar::~Beggar()
{
}

void Beggar::ddagi(apple* A)
{
	if (A->apple_count == 0) {
		cout << "더이상 사과를 딸수 없습니다 사과가 0개에요 ㅠ\n"; return ;
	}
	A->apple_count --;
	cout << "사과를 얻었습니다 !! \n";
	cout << "사과 나무에 사과 갯수 : " << A->apple_count << endl;
}
