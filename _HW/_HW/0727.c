
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
	printf("���� �Է� �Ϸ�\n");
	printf("�� ��° �л��� ������ Ȯ�� �ұ��?(1~3) : ");
	scanf_s(" %d", &choice_stu);
	while (choice_stu < 1 || choice_stu >3) {
		printf("�߸� �Է� �ϼ̽��ϴ�. \n");
		printf("�� ��° �л��� ������ Ȯ�� �ұ��?(1~3) : ");
		scanf_s(" %d", &choice_stu);
	}
	printf("1.���� \n2.����\n");
	printf("������ Ȯ�� �� ������ �����Ͻÿ� : ");
	scanf_s(" %d",&choice_sub);
	switch(choice_sub)
	{
	case 1:
		printf("%d�� ° �л��� ���� ���� : %d\n", choice_stu--, score[choice_stu][choice_sub-1]); break;
	case 2:
		printf("%d�� ° �л��� ���� ���� : %d\n", choice_stu--, score[choice_stu][choice_sub-1]); break;
	default:
		printf("�߸� �Է��ϼ̽��ϴ�\n");  break;
	}
	


	system("pause");
}

*/