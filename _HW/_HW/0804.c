#include<stdio.h>
#include<Windows.h>
#include <string.h> 

struct Stat {
	int att;
	int def;
	int hp;
};

typedef struct Item {
	
	char name[20];
	struct  Stat addstat;
}ITEM;

void insert_item() {
	FILE* pf = 0;
	int select,count,i;
	char item_type[20] = { 0, };
	char itemtype[20] = { 0, };
	ITEM item[5] = { 0, };
	printf("<아이템 정보를 입력하세요>\n");
	printf("1.무기 , 2.방어구\n");
	scanf_s(" %d",&select);
	
	if (select % 2)
	{
		strcpy_s(item_type,sizeof("weapon.txt"),"weapon.txt");
		strcpy_s(itemtype,sizeof("무기"),"무기");
	}
	else {
		strcpy_s(item_type, sizeof("armor.txt"), "armor.txt"); 
		strcpy_s(itemtype, sizeof("방어구"), "방어구");
	}
	printf("몇 개를 입력하시겠습니까? : ");
	scanf_s(" %d", &count);
	errno_t er = fopen_s(&pf, item_type, "w");
	if (pf != 0) {
		for (i = 0; i < count; i++) {

			printf("%d번째 %s의 이름 공격력, 방어력, 생명력을 입력하세요 : ", i + 1, itemtype);
			scanf_s(" %s %d %d %d", item[i].name, 20, &item[i].addstat.att, &item[i].addstat.def, &item[i].addstat.hp);
			fprintf(pf, "%s %d %d %d\n", item[i].name, item[i].addstat.att, item[i].addstat.def, item[i].addstat.hp);

		}
		fclose(pf);
	}
}

void print_item() {
	FILE* pf = 0;
	char item_type[20] = { 0, };
	char itemtype[20] = { 0, };
	int select,  i;
	ITEM item[5] = { 0, };
	printf("1.무기 , 2.방어구\n");
	printf("<열람하고 싶은 정보를 입력하세요>\n");
	scanf_s(" %d", &select);

	if (select % 2)
	{
		strcpy_s(item_type, sizeof("weapon.txt"), "weapon.txt");
		strcpy_s(itemtype, sizeof("무기"), "무기");
	}
	else {
		strcpy_s(item_type, sizeof("armor.txt"), "armor.txt");
		strcpy_s(itemtype, sizeof("방어구"), "방어구");
	}
	errno_t er = fopen_s(&pf, item_type, "r");
	if (pf != 0) {
		i = 0;
		while (!feof(pf)) {
			fscanf_s(pf, "%s %d %d %d \n", item[i].name, 20, &item[i].addstat.att, &item[i].addstat.def, &item[i].addstat.hp);
			
			printf("%d 번째 %s의 이름 : %s\n", i+1, itemtype, item[i].name);
			printf("%d 번째 %s의 공격력 : %d\n", i+1, itemtype, item[i].addstat.att);
			printf("%d 번째 %s의 방어력 : %d\n", i+1, itemtype, item[i].addstat.def);
			printf("%d 번째 %s의 체력 : %d\n", i+1, itemtype, item[i].addstat.hp);
			i++;
		}
		fclose(pf);

	}
}

int main() {
	int menu = 0;
	while (menu != 3) {
		while (menu < 1 || menu > 3) {
			printf("1.아이템 입력\n");
			printf("2.아이템 출력\n");
			printf("3.종료\n");
			printf("메뉴입력 : ");
			scanf_s(" %d", &menu);
		}

		switch(menu)
		{
			case 1: 
				insert_item();
				menu = 0;
				break;
			case 2:
				menu = 0;
				print_item();
				break;
			default:
				break;
		}

		


	}
	
	system("pause");

}

