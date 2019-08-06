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
	printf("<������ ������ �Է��ϼ���>\n");
	printf("1.���� , 2.��\n");
	scanf_s(" %d",&select);
	
	if (select % 2)
	{
		strcpy_s(item_type,sizeof("weapon.txt"),"weapon.txt");
		strcpy_s(itemtype,sizeof("����"),"����");
	}
	else {
		strcpy_s(item_type, sizeof("armor.txt"), "armor.txt"); 
		strcpy_s(itemtype, sizeof("��"), "��");
	}
	printf("�� ���� �Է��Ͻðڽ��ϱ�? : ");
	scanf_s(" %d", &count);
	errno_t er = fopen_s(&pf, item_type, "w");
	if (pf != 0) {
		for (i = 0; i < count; i++) {

			printf("%d��° %s�� �̸� ���ݷ�, ����, ������� �Է��ϼ��� : ", i + 1, itemtype);
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
	printf("1.���� , 2.��\n");
	printf("<�����ϰ� ���� ������ �Է��ϼ���>\n");
	scanf_s(" %d", &select);

	if (select % 2)
	{
		strcpy_s(item_type, sizeof("weapon.txt"), "weapon.txt");
		strcpy_s(itemtype, sizeof("����"), "����");
	}
	else {
		strcpy_s(item_type, sizeof("armor.txt"), "armor.txt");
		strcpy_s(itemtype, sizeof("��"), "��");
	}
	errno_t er = fopen_s(&pf, item_type, "r");
	if (pf != 0) {
		i = 0;
		while (!feof(pf)) {
			fscanf_s(pf, "%s %d %d %d \n", item[i].name, 20, &item[i].addstat.att, &item[i].addstat.def, &item[i].addstat.hp);
			
			printf("%d ��° %s�� �̸� : %s\n", i+1, itemtype, item[i].name);
			printf("%d ��° %s�� ���ݷ� : %d\n", i+1, itemtype, item[i].addstat.att);
			printf("%d ��° %s�� ���� : %d\n", i+1, itemtype, item[i].addstat.def);
			printf("%d ��° %s�� ü�� : %d\n", i+1, itemtype, item[i].addstat.hp);
			i++;
		}
		fclose(pf);

	}
}

int main() {
	int menu = 0;
	while (menu != 3) {
		while (menu < 1 || menu > 3) {
			printf("1.������ �Է�\n");
			printf("2.������ ���\n");
			printf("3.����\n");
			printf("�޴��Է� : ");
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

