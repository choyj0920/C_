#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
int main() {
	
	/*int n = 5;
	do
		printf("countdown %d !!!\n", n);
	while (n-- > 0);
	printf("ǡ�̾�~~\n");*/
	//goto ��
	/*goto A;
	B:
	printf("���� 1\n");
	printf("���� 2\n");
	printf("���� 3\n");
	printf("���� 4\n");
	printf("���� 5\n");
	printf("���� 6\n");
	goto C;
	A:
	printf("���� 7\n");
	goto B;
	C:*/
	//break���
	/*int breakNumber = 0;
	int n = 0;
	printf("1~100�� ��ȣ �߿� �ϳ��� ������ :");
	scanf_s(" %d", &breakNumber);
	for (n = 1; n <= 100; n++) {
		if (n == breakNumber)
			break;

		printf("%d��\n",n);
	}*/
	//continue
	/*int checknumber = 0;
	int n = 0;
	int isOdd = 0;
	printf("������ ���� �Է��ϼ��� : ");
	scanf_s(" %d", &checknumber);
	isOdd = checknumber % 2 == 1;
	for (n = 1; n < 100; n++) {
		if (n % 2 == isOdd)
			continue;
		printf("%d��\n", n);
	}*/
	//����
	/*int start_num, final_num;
	printf("���� ��ȣ�� �Է��ϼ��� : ");
	scanf_s(" %d", &start_num);
	printf("�� ��ȣ�� �Է��ϼ��� : ");
	scanf_s(" %d", &final_num);
	while (++start_num < final_num) 
		printf("%d\n", start_num);*/
	
	//�ݺ���
	/*int loopnum,num,i,j,k;
	printf("�ݺ� Ƚ���� �Է��ϼ��� : ");
	scanf_s(" %d", &loopnum);
	printf("���ڸ� �Է��ϼ��� : ");
	scanf_s(" %d", &num);
	
	for (i = 0; i < loopnum; i++) {
		j = (num % 2) ? -i : i - loopnum+1;
		for (; j <= 0; j++)			
			printf("��");
		printf("\n");

	}
	for (i = 0; i < loopnum; i++) {
		if (num % 2)
			for (j = 0; j < i+1; j++)
				printf("��");
		else
			for(j=0;j<loopnum-i;j++)
				printf("��");
		putchar('\n');
	}
	*/
	
	//�迭 
	/*int n = 0;
	int numbers[10] = { 0,1,2,3,4,5,6,7,8 };

	printf("numbers addr = %u\n", numbers);
	printf("numbers[0] addr = %u\n", &numbers[0]);
	for (n = 0; n < 10; n++) {

		printf("numbers[%d] addr = %u\n", n,&numbers[n]);
		printf("numbers[%d] = %d\n", n, numbers[n]);


	}*/

	//�迭 ����
	int numbers[10];
	int n,m,number;
	printf("���ڸ� �Է� �ϼ��� : ");
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