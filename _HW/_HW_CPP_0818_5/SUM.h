#pragma once
class SUM
{
public:
	/*
	inline함수는 '컴파일러'가 그대로 그 내용을 복사 해오기 때문에
	main함수의 실행 전 실행하게 되는 헤더 부분에서 정의 되어야 함!,
	사용하지 않아도 실행되기 때문에 비교적 짧은 함수만 inline으로 사용
	*/

	inline int Hab(int a, int b)
	{

		return a + b;
	}

	inline float Hab(float a, float b)
	{
		return a + b;
	}

	inline int ToHab(int a)
	{
		int tot = 0;
		for (int n = 1; n <= a; tot += n++);
		return tot;
	}

	inline int ToHab(int a, int b)
	{
		int tot = 0;
		for (int n = a; n <= b; tot += n++);

		return tot;
	}
	SUM(){}
	~SUM(){}
};

