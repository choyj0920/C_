#include<stdio.h>
#include<Windows.h>

void OutputGreetings();
void showaboutme(int age, float height);

int AddInteger(int num1, int num2);
float average_num(int start_n, int final_n);
int AddintegerAddr(int * num1, int* num2);
void Change_num(int* num1, int* num2);

int main() {
	// �Լ� ���� 
	/*printf("[�达�� �������ϴ�]\n");
	printf("���� �λ縦 �ǳܴϴ�.\n");
	OutputGreetings();
	printf("[�̾��� �������ϴ�]\n");
	printf("���� �λ縦 �ǳܴϴ�.\n");
	OutputGreetings();*/
	//�ڱ� �Ұ�
	/*printf("���̸� ������");
	showaboutme(23, 177.3f);*/
	//�ܼ����ϱ�
	/*
	printf("%d +%d= %d\n", 23, 11, AddInteger(23, 11));*/

	//���� ���ϱ� ���
	/*int start, end;
	printf("���� ���� ������ �Է�(num1 num2): ");
	scanf_s(" %d %d", &start, &end);
	printf("%.2f",average_num(start, end));
*/

	//�����ͷ�  �Ű�����
	/*int a = 20, b = 15;
	printf("a= %d, b= %d\n", a, b);
	printf("a + b =%d\n", AddInteger(a, b));
	printf("a= %d, b= %d\n", a, b);
	printf("a + b =%d\n", AddintegerAddr(&a, &b));
	printf("a= %d, b= %d\n", a, b);*/

	//���� ���� �ٲٱ�
	int a, b;
	printf("�� ������ �Է��ϼ��� (num1 num2) : ");
	scanf_s(" %d %d", &a, &b);
	printf("a = %d, b = %d \n", a, b);
	Change_num(&a, &b);
	
	printf("a = %d, b = %d \n", a, b);


	//������ �ڵ�
	system("pause");
	return 0;
}


void Change_num(int* num1, int* num2) {
	printf("���� �ٲٱ� ����!\n");
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

void showaboutme(int age, float height) {
	printf("�� ���̴� %d�Դϴ� \n", age);
	printf("Ű�� %.1f�Դϴ� \n", height);
}
void OutputGreetings() {
	printf("�ȳ��ϼ��� ~~\n");
	printf("�ݰ����ϴ� ~~\n");
}
int AddInteger(int num1, int num2) {
	return num1 + num2;
}
float average_num(int start_n, int final_n) {
	int i, total = 0, count;
	count = final_n - start_n + 1;
	for (; start_n <= final_n; start_n++) {
		total += start_n;
	}
	return total / (float)count;
}
int AddintegerAddr(int * num1, int* num2) {
	return *(num1) += *(num2);
}