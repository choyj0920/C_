#include<stdio.h>
#include<Windows.h>

enum eScoreType {
	D���� = 6,
	C���� ,
	B����,
	A����,
	AA����
	
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
	
	printf("�̸�, ����,Ű�� �Է��ϼ���(## ## ##) : ");
	scanf_s(" %s %d %f", name, sizeof(name), &num, &fnum);
	printf("�̸�: %s \n���� : %d \n Ű : %1.1f\n", name, num, fnum);*/

	/*int number = 0;
	printf("������ �Է��ϼ���: ");
	scanf_s(" %d", &number);
	if (number == 0) printf("�Է��Ͻ� ���� [%d]�� 0�Դϴ�.\n", number);
	else if (number % 2 == 1) {
		printf("�Է��Ͻ� ���� [%d]�� Ȧ�� �Դϴ�.\n", number);
	}
	else
		printf("�Է��Ͻ� ���� [%d]�� Ȧ���� �ƴմϴ�.\n", number);
*/

	//char c;
	//printf("���ڸ� �Է��ϼ���:");
	//scanf_s(" %c", &c,sizeof(c));
	//if (c <= 'z'&&c >= 'a') 
	//	printf("�ҹ��� �Դϴ�\n");
	//else if (c <= 'Z'&&c >= 'A') 
	//	printf("�빮�� �Դϴ�\n");
	//else if (c <= '9' && c >= '0') 
	//	printf("���� �Դϴ�\n");
	//else  
	//	printf("Ư�� �����Դϴ�\n");
	//
	// ����ġ��
	/*int score = 0;
	printf("������ �Է��ϼ���(1~100) : ");
	scanf_s(" %d", &score);
	switch (score / 10) {
	case 10:
	case 9:
		printf("A�����Դϴ� \n");
		break;
	case 8:
		printf("B�����Դϴ� \n");
		break;
	case 7:
		printf("C�����Դϴ� \n");
		break; 
	case 6:
		printf("D�����Դϴ� \n");
		break;
	default :
		printf("F���� �Դϴ�");
		break;
	}*/

	//�������� ����ġ��
	/*int score = 0;
	printf("������ �Է��ϼ���(1~100) : ");
	scanf_s(" %d", &score);
	switch (score / 10) {
	case AA����:
	case A����:
		printf("A�����Դϴ� \n");
		break;
	case B����:
		printf("B�����Դϴ� \n");
		break;
	case C����:
		printf("C�����Դϴ� \n");
		break;
	case D����:
		printf("D�����Դϴ� \n");
		break;
	default :
		printf("F���� �Դϴ�");
		break;
	}*/

	//for��
	/*int n_start , n_final ,total = 0;
	printf("���� ���ڸ� �Է��ϼ���: ");
	scanf_s(" %d", &n_start);
	printf("�� ���ڸ� �Է��ϼ���: ");
	scanf_s(" %d", &n_final);

	for (; n_start <= n_final; n_start++) {
		total += n_start;
	}
	printf("%d���� %d������ ��ü ���� [%d]�Դϴ�\n", n_start, n_final, total);*/

	//while�� ������ �ʹ� �߿���ˤ� ���߿�
	/*int n = 5;

	while (n > 0) {
		n--;
		printf("COUNT DOWN: %d!!\n", n);
		
		
	}
	printf("ǡ�̾�~~~~!!!\n");*/

	system("pause");
	return 0;
}