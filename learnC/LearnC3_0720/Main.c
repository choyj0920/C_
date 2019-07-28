#include<stdio.h>
#include<Windows.h>

enum eScoreType {
	D학점 = 6,
	C학점 ,
	B학점,
	A학점,
	AA학점
	
};

int main() {
	
	/*char ch = getchar();

	putchar(ch);

	printf("ch = %c\n", ch);
	*/
	/*char str[100] = { 0, };
	gets_s(str, sizeof(str));
	printf("%s", str);*/
	/*int num = 0;
	float fnum = 0.0f;
	char name[50] = { 0, };
	
	printf("이름, 나이,키를 입력하세요(## ## ##) : ");
	scanf_s(" %s %d %f", name, sizeof(name), &num, &fnum);
	printf("이름: %s \n나이 : %d \n 키 : %1.1f\n", name, num, fnum);*/

	/*int number = 0;
	printf("정수를 입력하세요: ");
	scanf_s(" %d", &number);
	if (number == 0) printf("입력하신 정수 [%d]는 0입니다.\n", number);
	else if (number % 2 == 1) {
		printf("입력하신 정수 [%d]는 홀수 입니다.\n", number);
	}
	else
		printf("입력하신 정수 [%d]는 홀수가 아닙니다.\n", number);
*/

	//char c;
	//printf("문자를 입력하세요:");
	//scanf_s(" %c", &c,sizeof(c));
	//if (c <= 'z'&&c >= 'a') 
	//	printf("소문자 입니다\n");
	//else if (c <= 'Z'&&c >= 'A') 
	//	printf("대문자 입니다\n");
	//else if (c <= '9' && c >= '0') 
	//	printf("숫자 입니다\n");
	//else  
	//	printf("특수 문자입니다\n");
	//
	// 스위치문
	/*int score = 0;
	printf("점수를 입력하세요(1~100) : ");
	scanf_s(" %d", &score);
	switch (score / 10) {
	case 10:
	case 9:
		printf("A학점입니다 \n");
		break;
	case 8:
		printf("B학점입니다 \n");
		break;
	case 7:
		printf("C학점입니다 \n");
		break; 
	case 6:
		printf("D학점입니다 \n");
		break;
	default :
		printf("F학점 입니다");
		break;
	}*/

	//열거형과 스위치문
	/*int score = 0;
	printf("점수를 입력하세요(1~100) : ");
	scanf_s(" %d", &score);
	switch (score / 10) {
	case AA학점:
	case A학점:
		printf("A학점입니다 \n");
		break;
	case B학점:
		printf("B학점입니다 \n");
		break;
	case C학점:
		printf("C학점입니다 \n");
		break;
	case D학점:
		printf("D학점입니다 \n");
		break;
	default :
		printf("F학점 입니다");
		break;
	}*/

	//for문
	/*int n_start , n_final ,total = 0;
	printf("시작 숫자를 입력하세요: ");
	scanf_s(" %d", &n_start);
	printf("끝 숫자를 입력하세요: ");
	scanf_s(" %d", &n_final);

	for (; n_start <= n_final; n_start++) {
		total += n_start;
	}
	printf("%d에서 %d까지의 전체 합은 [%d]입니다\n", n_start, n_final, total);*/

	//while문 ㅁㅁㅁ 너무 추워요ㅛㅛ 제발여
	/*int n = 5;

	while (n > 0) {
		n--;
		printf("COUNT DOWN: %d!!\n", n);
		
		
	}
	printf("퐈이아~~~~!!!\n");*/

	system("pause");
	return 0;
}