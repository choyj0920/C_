#include<stdio.h>
#include<Windows.h>
#include<time.h>

char* user_strstr(const char* word, const char* subword);

struct Stat {
	int att;
	int def;
	int hp;
};

struct Item {
	int isUse;
	char name[20];
	struct  Stat addstat;
};
struct Monster {
	char name[30];
	struct Stat status;
	struct Item *weapon;
	struct Item *armor;
};
void ShowItemInfo(struct Item* pitem, const char* type);

struct Train {
	int num;
	int inwon;
	struct Train* next;
};
struct _node {
	int Num;
	struct _node *Next;
};

int main() {
	srand(time(0));
	// ������ ���ڿ� ���� 
	/*int n;
	char * explan = "Hello ~ He's been working his head since the morning~";
	printf("explan�� ���� ���� [%d]�Դϴ�\n",strlen(explan));
	printf("explan�� ���� ���� [%d]�Դϴ�\n",user_strlen(explan));
	char* pc = explan;
	for (n = 0; n < 5; n++) {
		putchar(*(pc));
		pc++;
	}*/
	// 
	/*char * explan = "Hello ~ He's been working his head since the morning~";
	char find[100] = { 0, };

	printf("%s\n ������ ���ڿ��� �Է��ϼ���",explan);
	scanf_s(" %s", find, sizeof(find));
	printf("%s\n", user_strstr(explan, find));*/
	//const ����  �ڷ��� const  (const �ڷ��� *�ּҺ���)  �ּҾȿ� �ִ� ���� ���� �ٲܼ� ����  �ּҴ� ����  �ڷ���* const ���� �̸��� �ּҸ� �ٲܼ����� ������ �ּҰ� ����Ű�� ���� �ٲٱ� ���� 
	/*const int n = 100;
	int num1 = 10;
	int num2 = 100;
	char s1[100] = "�ȳ�";
	char s2[100] = "�ݰ���";
	const int* pnumber = &num1;
	printf("*pnumber = %d \n", *pnumber);
	pnumber = &num2;
	printf("*pnumber = %d \n", *pnumber);
	int* const pnum = &num1;*/
	
	//����ü ����  ũ�� ����
	/*struct Monster mon;
	printf("mon's name size= %d\n", sizeof(mon.name));
	printf("mon's att size= %d\n", sizeof(mon.att));
	printf("mon's def size= %d\n", sizeof(mon.def));

	printf("mon's men size = %d\n", sizeof(struct Monster));*/
	
	//����ü ���~
	/*int n;
	struct Monster mons[3] = { 0, };
	struct Monster* pMon = 0;

	for (n = 0; n < 3; n++) {
		sprintf_s(mons[n].name, sizeof(mons[n].name), "Mon%d", n + 1);
		mons[n].att = rand() % 6 + 5;
		mons[n].def = rand() % 4;
	}

	for (n = 0; n < 3; n++) {
		pMon = &mons[n];
		printf("%d��° ������ �̸��� [%s]�Դϴ�.\n", n + 1, pMon->name);
		printf("%d��° ������ ���ݷ��� [%d]�Դϴ�.\n", n + 1, pMon->att);
		printf("%d��° ������ ������ [%d]�Դϴ�.\n", n + 1, pMon->def);
	}*/
	//�ڱ����� ����ü
	/*
struct Train train1, train2, train3;
train1.num = 8;
train1.inwon = 5;
train1.next = 0;
train2.num = 2;
train2.inwon = 15;
train3.num = 6;
train3.inwon = 10;
train2.next= &train3;
train3.next = &train1;
*/
	//���� ����ü 
	/*int n;
	struct Monster mons[3] = { 0, };
	struct Monster* pMon = 0;
	struct Item weapons[2];
	strcpy_s(weapons[0].name, sizeof(weapons[0].name), "������ġ");
	weapons[0].addstat.att = 3;
	weapons[0].addstat.def = 0;
	weapons[0].addstat.hp = 10;
	strcpy_s(weapons[1].name, sizeof(weapons[1].name), "���");
	weapons[1].addstat.att = 3;
	weapons[1].addstat.def = 3;
	weapons[1].addstat.hp = 0;


	for (n = 0; n < 3; n++) {
		sprintf_s(mons[n].name, sizeof(mons[n].name), "Mon%d", n + 1);
		mons[n].status.att = rand() % 6 + 5;
		mons[n].status.def = rand() % 4;
		mons[n].status.hp = rand() % 31 + 20;
		mons[n].weapon = 0;
		mons[n].armor = 0;
	}
	mons[2].weapon = &weapons[1];

	for (n = 0; n < 3; n++) {
		pMon = &mons[n];
		printf("%d��° ������ �̸��� [%s]�Դϴ�.\n", n + 1, pMon->name);
		printf("%d��° ������ ���ݷ��� [%d]�Դϴ�.\n", n + 1, pMon->status.att);
		printf("%d��° ������ ������ [%d]�Դϴ�.\n", n + 1, pMon->status.def);
		printf("%d��° ������ ü���� [%d]�Դϴ�.\n", n + 1, pMon->status.hp);
		if (pMon->weapon != 0) {
			ShowItemInfo(pMon->weapon, "����");
		}
		else
			printf("%d ��° ���ʹ� ���⸦ ���� �ʾҽ��ϴ�.\n",n+1);
		if (pMon->armor != 0) {
			ShowItemInfo(pMon->armor, "��");

		}
		else
			printf("%d ��° ���ʹ� ���� �� ���� �ʾҽ��ϴ�.\n", n + 1);
		puts("==============================================================================");
	}*/

struct _node AA, BB, CC;
AA.Num = 1;
BB.Num = 2;
CC.Num = 3;

AA.Next = &BB;
BB.Next = &CC;
CC.Next = NULL;

printf("%d -> %d -> %d -> NULL\n", AA.Num, BB.Num, CC.Num);
printf("%d -> %d -> %d -> NULL\n", AA.Num, AA.Next -> Num, AA.Next->Next ->Num);



	//�������ڵ�
	system("pause");
}
// strlen����� ���� 
void user_strlen(const char* words) {
	int i;
	
	for (i = 0; ; i++) {
		if (*(words + i) == '\0')
			return i;
	}
}
//strstr������
char* user_strstr(const char* word, const char* subword) {
	int i ,m,j,k;
	int match = 0;
	k = strlen(subword);
	j = strlen(word);
	char* pword=word;
	char * psub= subword;
	for (i = 0; i < j; i++) {
		if (*(pword+i) != *subword) continue;
		for (m = 0; m < k-m; m++) {
			if (*(pword+i+m) != *(psub+m)) { match = 0; break;}
			match = 1;
		}
		if (match == 1) {
			return (word + i);
		}

	}
}

//������ ���� ����Լ�
void ShowItemInfo(struct Item* pitem, const char* type) {
	printf("���� %s�� �̸��� [%s]�Դϴ�.\n", type, pitem->name);
	printf("���� %s�� ���ݷ��� [%d]�Դϴ�.\n", type, pitem->addstat.att);
	printf("���� %s�� ������ [%d]�Դϴ�.\n", type, pitem->addstat.def);
	printf("���� %s�� ������� [%d]�Դϴ�.\n", type, pitem->addstat.hp);
}