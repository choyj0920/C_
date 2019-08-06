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
	printf("array에 담을 숫자의 개수를 입력하세요 : ");
	scanf_s(" %d", &count); 
	array_space(&array, count); //array는 배열의 시작 주소가 담겨있는 변수, 그것의 주소= &array
	
	array_space(&array,count);
	array_insert(array, count);
	array_print(array, count);

	printf("배열의 합 : %d\n",array_calculate(array, count, &average));
	printf("배열 의 평균 :%.1f \n",average);
	

	free(array);
	system("pause");
}

//array의 공간을 동적 할당하는 함수 
void array_space(int** array_addr, int count) {
	*array_addr = (int*)malloc(sizeof(int)* count);
}
//array 안에 값을 넣는 함수
void array_insert(int* array, int count) {
	int start_num ,i;
	printf("배열 array의 처음 숫자를 입력하세요 : ");
	scanf_s(" %d", &start_num);
	for (i = 0; i < count; i++) {
		array[i] = start_num + i;
	}
}

//array의 값들을 출력하는 함수
void array_print(int* array, int count) {
	int i;
	printf("배열에 값 출력함수! \n");

	printf("시작 숫자 : %d , 배열 갯수 : %d\n", array[0], count);

	for (i = 0; i < count; i++) {
		printf("array[%d] = %d\n", i, array[i]);
	}
}

//array의 전체 합과 평균 계산 함수
int array_calculate(int * array, int count, float* average) {
	int total = 0, i;
	for (i = 0; i < count; i++)
		total += array[i];
	*average = total / (float)count;
	return total;

}
*/