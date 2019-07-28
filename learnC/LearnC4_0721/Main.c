#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
int main() {
	
	/*int n = 5;
	do
		printf("countdown %d !!!\n", n);
	while (n-- > 0);
	printf("퐈이아~~\n");*/
	//goto 문
	/*goto A;
	B:
	printf("숫자 1\n");
	printf("숫자 2\n");
	printf("숫자 3\n");
	printf("숫자 4\n");
	printf("숫자 5\n");
	printf("숫자 6\n");
	goto C;
	A:
	printf("숫자 7\n");
	goto B;
	C:*/
	//break사용
	/*int breakNumber = 0;
	int n = 0;
	printf("1~100의 번호 중에 하나를 고르세요 :");
	scanf_s(" %d", &breakNumber);
	for (n = 1; n <= 100; n++) {
		if (n == breakNumber)
			break;

		printf("%d번\n",n);
	}*/
	//continue
	/*int checknumber = 0;
	int n = 0;
	int isOdd = 0;
	printf("임의의 수를 입력하세요 : ");
	scanf_s(" %d", &checknumber);
	isOdd = checknumber % 2 == 1;
	for (n = 1; n < 100; n++) {
		if (n % 2 == isOdd)
			continue;
		printf("%d번\n", n);
	}*/
	//예제
	/*int start_num, final_num;
	printf("시작 번호를 입력하세요 : ");
	scanf_s(" %d", &start_num);
	printf("끝 번호를 입력하세요 : ");
	scanf_s(" %d", &final_num);
	while (++start_num < final_num) 
		printf("%d\n", start_num);*/
	
	//반복문
	/*int loopnum,num,i,j,k;
	printf("반복 횟수를 입력하세요 : ");
	scanf_s(" %d", &loopnum);
	printf("숫자를 입력하세요 : ");
	scanf_s(" %d", &num);
	
	for (i = 0; i < loopnum; i++) {
		j = (num % 2) ? -i : i - loopnum+1;
		for (; j <= 0; j++)			
			printf("아");
		printf("\n");

	}
	for (i = 0; i < loopnum; i++) {
		if (num % 2)
			for (j = 0; j < i+1; j++)
				printf("아");
		else
			for(j=0;j<loopnum-i;j++)
				printf("아");
		putchar('\n');
	}
	*/
	
	//배열 
	/*int n = 0;
	int numbers[10] = { 0,1,2,3,4,5,6,7,8 };

	printf("numbers addr = %u\n", numbers);
	printf("numbers[0] addr = %u\n", &numbers[0]);
	for (n = 0; n < 10; n++) {

		printf("numbers[%d] addr = %u\n", n,&numbers[n]);
		printf("numbers[%d] = %d\n", n, numbers[n]);


	}*/

	//배열 예제
	int numbers[10];
	int n,m,number;
	printf("숫자를 입력 하세요 : ");
	scanf_s(" %d", &number);
	m = (number % 2)? 1:2;

	for (n = 0; n < 10; n++) {
		numbers[n] = n * 2 + m;
		printf("%d\n", numbers[n]);
	}
	rand();
	system("pause");
	return 0;
}