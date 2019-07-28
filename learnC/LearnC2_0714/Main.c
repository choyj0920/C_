#include<stdio.h>
#include<Windows.h>

enum 성격 {
	모난 = 0,
	근면한,
	둥근,
	추움,
};


int main() {
	/*int amugerna = 0 ;
	printf("int = %d\n", sizeof(int));
	unsigned int number = 0;
	printf("int = %d\n", sizeof(int));
	printf("amugerna= %d\n", amugerna);
	amugerna = 10;
	printf("amugerna + 70= %d\n", amugerna+70);
	
	printf("short = %d\n", sizeof(short));
	printf("int = %d\n", sizeof(int));
	printf("long = %d\n", sizeof(long));
	printf("float = %d\n", sizeof(float));
	printf("double = %d\n", sizeof(double));

	printf("number = %u\n", number-1);

	float a1 = 1000000000+9;
	double a2 = 1.22;
	printf("a1 = %f\n", a1);
	printf("a2 = %f\n", a2);
	char ch = 'g';
	char* str1 = "오늘도 수고했어!";
	char str2[] = "자료형 헷갈리죠!";
	printf("%c \n%s \n%s\n", ch, str1, str2);

	printf("%d", 모난);
	enum 성격 charac[4];
	charac[0] = 모난;
	if (charac[0] == 모난) {
		puts("성격이 모난 녀석 입니다");
	}
	else if (charac[0] == 근면한) {
		puts("성격이 근면한 녀석입니다.");
	}
	else
		puts("성격이 둥근 녀석입니다");

	printf("213 %% 6 = %d\n", 213 % 6);
	int val = 10;
	printf("val =%d \n", val);
	val++;
	printf("val =%d \n",val);
	++val;;
	printf("val =%d \n",val);
	printf("val =%d \n", val++);
	printf("val =%d \n", val);

	printf("val =%d \n", ++val);*/

	/*int val = 500000001;
	float fval = 500000001.f;

	printf("val >fval = %d \n", val > fval);
	printf("val < fval = %d \n", val < fval);
	printf("val == fval = %d \n", val == fval);
	val = 90;
	printf("val = %d\n", val);

	val = val < 100 ? 0: 10000;
	printf("val =%d \n", val);*/

	int num = 0;
	printf("숫자를 입력하세요:");
	scanf_s(" %d", &num);
	
	printf("num != 0 && num %%2 ==0   = %d\n", num != 0 && num % 2 == 0);
	printf("%d", 19 >> 2);
	//수업용 코드.
	system("pause");
	return 0;
}