/*
#include<stdio.h>
#include<Windows.h>

void array_space(int** array_addr, int count);
void array_insert(int* array, int count);
void array_print(int* array, int count);
int array_calculate(int * array, int count, float* average);

int main() {

	int* array = 0;
	int count , total;
	float average = 0;
	printf("array�� ���� ������ ������ �Է��ϼ��� : ");
	scanf_s(" %d", &count); 
	array_space(&array, count); //array�� �迭�� ���� �ּҰ� ����ִ� ����, �װ��� �ּ�= &array
	
	array_space(&array,count);
	array_insert(array, count);
	array_print(array, count);

	printf("�迭�� �� : %d\n",array_calculate(array, count, &average));
	printf("�迭 �� ��� :%.1f \n",average);
	

	free(array);
	system("pause");
}

//array�� ������ ���� �Ҵ��ϴ� �Լ� 
void array_space(int** array_addr, int count) {
	*array_addr = (int*)malloc(sizeof(int)* count);
}
//array �ȿ� ���� �ִ� �Լ�
void array_insert(int* array, int count) {
	int start_num ,i;
	printf("�迭 array�� ó�� ���ڸ� �Է��ϼ��� : ");
	scanf_s(" %d", &start_num);
	for (i = 0; i < count; i++) {
		array[i] = start_num + i;
	}
}

//array�� ������ ����ϴ� �Լ�
void array_print(int* array, int count) {
	int i;
	printf("�迭�� �� ����Լ�! \n");

	printf("���� ���� : %d , �迭 ���� : %d\n", array[0], count);

	for (i = 0; i < count; i++) {
		printf("array[%d] = %d\n", i, array[i]);
	}
}

//array�� ��ü �հ� ��� ��� �Լ�
int array_calculate(int * array, int count, float* average) {
	int total = 0, i;
	for (i = 0; i < count; i++)
		total += array[i];
	*average = total / (float)count;
	return total;

}
*/