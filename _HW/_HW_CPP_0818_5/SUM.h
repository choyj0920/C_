#pragma once
class SUM
{
public:
	/*
	inline�Լ��� '�����Ϸ�'�� �״�� �� ������ ���� �ؿ��� ������
	main�Լ��� ���� �� �����ϰ� �Ǵ� ��� �κп��� ���� �Ǿ�� ��!,
	������� �ʾƵ� ����Ǳ� ������ ���� ª�� �Լ��� inline���� ���
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

