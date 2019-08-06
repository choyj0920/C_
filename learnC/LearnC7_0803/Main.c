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
	// 포인터 문자열 길이 
	/*int n;
	char * explan = "Hello ~ He's been working his head since the morning~";
	printf("explan의 문자 수는 [%d]입니다\n",strlen(explan));
	printf("explan의 문자 수는 [%d]입니다\n",user_strlen(explan));
	char* pc = explan;
	for (n = 0; n < 5; n++) {
		putchar(*(pc));
		pc++;
	}*/
	// 
	/*char * explan = "Hello ~ He's been working his head since the morning~";
	char find[100] = { 0, };

	printf("%s\n 시작할 문자열을 입력하세요",explan);
	scanf_s(" %s", find, sizeof(find));
	printf("%s\n", user_strstr(explan, find));*/
	//const 변수  자료형 const  (const 자료형 *주소변수)  주소안에 있는 변수 값을 바꿀수 없다  주소는 가능  자료형* const 변수 이름은 주소를 바꿀수없음 하지만 주소가 가르키는 변수 바꾸기 가능 
	/*const int n = 100;
	int num1 = 10;
	int num2 = 100;
	char s1[100] = "안녕";
	char s2[100] = "반가워";
	const int* pnumber = &num1;
	printf("*pnumber = %d \n", *pnumber);
	pnumber = &num2;
	printf("*pnumber = %d \n", *pnumber);
	int* const pnum = &num1;*/
	
	//구조체 시작  크기 관련
	/*struct Monster mon;
	printf("mon's name size= %d\n", sizeof(mon.name));
	printf("mon's att size= %d\n", sizeof(mon.att));
	printf("mon's def size= %d\n", sizeof(mon.def));

	printf("mon's men size = %d\n", sizeof(struct Monster));*/
	
	//구조체 사용~
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
		printf("%d번째 몬스터의 이름은 [%s]입니다.\n", n + 1, pMon->name);
		printf("%d번째 몬스터의 공격력은 [%d]입니다.\n", n + 1, pMon->att);
		printf("%d번째 몬스터의 방어력은 [%d]입니다.\n", n + 1, pMon->def);
	}*/
	//자기참조 구조체
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
	//다중 구조체 
	/*int n;
	struct Monster mons[3] = { 0, };
	struct Monster* pMon = 0;
	struct Item weapons[2];
	strcpy_s(weapons[0].name, sizeof(weapons[0].name), "전투망치");
	weapons[0].addstat.att = 3;
	weapons[0].addstat.def = 0;
	weapons[0].addstat.hp = 10;
	strcpy_s(weapons[1].name, sizeof(weapons[1].name), "대검");
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
		printf("%d번째 몬스터의 이름은 [%s]입니다.\n", n + 1, pMon->name);
		printf("%d번째 몬스터의 공격력은 [%d]입니다.\n", n + 1, pMon->status.att);
		printf("%d번째 몬스터의 방어력은 [%d]입니다.\n", n + 1, pMon->status.def);
		printf("%d번째 몬스터의 체력은 [%d]입니다.\n", n + 1, pMon->status.hp);
		if (pMon->weapon != 0) {
			ShowItemInfo(pMon->weapon, "무기");
		}
		else
			printf("%d 번째 몬스터는 무기를 들지 않았습니다.\n",n+1);
		if (pMon->armor != 0) {
			ShowItemInfo(pMon->armor, "방어구");

		}
		else
			printf("%d 번째 몬스터는 방어구를 를 들지 않았습니다.\n", n + 1);
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



	//수업용코드
	system("pause");
}
// strlen만들어 보기 
void user_strlen(const char* words) {
	int i;
	
	for (i = 0; ; i++) {
		if (*(words + i) == '\0')
			return i;
	}
}
//strstr만들어보기
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

//아이템 정보 출력함수
void ShowItemInfo(struct Item* pitem, const char* type) {
	printf("현재 %s의 이름은 [%s]입니다.\n", type, pitem->name);
	printf("현재 %s의 공격력은 [%d]입니다.\n", type, pitem->addstat.att);
	printf("현재 %s의 방어력은 [%d]입니다.\n", type, pitem->addstat.def);
	printf("현재 %s의 생명력은 [%d]입니다.\n", type, pitem->addstat.hp);
}