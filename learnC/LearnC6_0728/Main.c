#include<stdio.h>
#include<Windows.h>

void OutputGreetings();
void showaboutme(int age, float height);

int AddInteger(int num1, int num2);
float average_num(int start_n, int final_n);
int AddintegerAddr(int * num1, int* num2);
void Change_num(int* num1, int* num2);

int main() {
	// 함수 시작 
	/*printf("[김씨를 만났습니다]\n");
	printf("내가 인사를 건넵니다.\n");
	OutputGreetings();
	printf("[이씨를 만났습니다]\n");
	printf("내가 인사를 건넵니다.\n");
	OutputGreetings();*/
	//자기 소개
	/*printf("내이름 조윤직");
	showaboutme(23, 177.3f);*/
	//단순더하기
	/*
	printf("%d +%d= %d\n", 23, 11, AddInteger(23, 11));*/

	//숫자 더하기 평균
	/*int start, end;
	printf("시작 숫자 끝숫자 입력(num1 num2): ");
	scanf_s(" %d %d", &start, &end);
	printf("%.2f",average_num(start, end));
*/

	//포인터로  매개변수
	/*int a = 20, b = 15;
	printf("a= %d, b= %d\n", a, b);
	printf("a + b =%d\n", AddInteger(a, b));
	printf("a= %d, b= %d\n", a, b);
	printf("a + b =%d\n", AddintegerAddr(&a, &b));
	printf("a= %d, b= %d\n", a, b);*/

	//예제 숫자 바꾸기
	int a, b;
	printf("두 정수를 입력하세요 (num1 num2) : ");
	scanf_s(" %d %d", &a, &b);
	printf("a = %d, b = %d \n", a, b);
	Change_num(&a, &b);
	
	printf("a = %d, b = %d \n", a, b);


	//수업용 코드
	system("pause");
	return 0;
}


void Change_num(int* num1, int* num2) {
	printf("변수 바꾸기 실행!\n");
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

void showaboutme(int age, float height) {
	printf("내 나이는 %d입니다 \n", age);
	printf("키는 %.1f입니다 \n", height);
}
void OutputGreetings() {
	printf("안녕하세요 ~~\n");
	printf("반갑습니다 ~~\n");
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