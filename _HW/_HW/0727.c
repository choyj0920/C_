
/*
#include<stdio.h>
#include<Windows.h>
#include<time.h>

#define student 3
#define subject 2
int main() {
	srand((unsigned)time(0));
	int i, j, score[student][subject];
	int choice_stu,choice_sub;

	for (i = 0; i < student; i++) {
		for (j = 0; j < subject; j++)
			score[i][j] = rand()% 41 + 60;
	}
	printf("성적 입력 완료\n");
	printf("몇 번째 학생의 점수를 확인 할까요?(1~3) : ");
	scanf_s(" %d", &choice_stu);
	while (choice_stu < 1 || choice_stu >3) {
		printf("잘못 입력 하셨습니다. \n");
		printf("몇 번째 학생의 점수를 확인 할까요?(1~3) : ");
		scanf_s(" %d", &choice_stu);
	}
	printf("1.영어 \n2.수학\n");
	printf("점수를 확인 할 과목을 선택하시오 : ");
	scanf_s(" %d",&choice_sub);
	switch(choice_sub)
	{
	case 1:
		printf("%d번 째 학생의 영어 점수 : %d\n", choice_stu--, score[choice_stu][choice_sub-1]); break;
	case 2:
		printf("%d번 째 학생의 수학 점수 : %d\n", choice_stu--, score[choice_stu][choice_sub-1]); break;
	default:
		printf("잘못 입력하셨습니다\n");  break;
	}
	


	system("pause");
}

*/