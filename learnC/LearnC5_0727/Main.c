#include<stdio.h>
#include<Windows.h>

int main() {
	
	//������
	/*int a = 10;
	char b = 'Z';
	float c = 3.14f;
	int *pa = &a;
	char* pb = &b;
	float* pc = &c;

	*pa = 100;
	printf("a = %d, pa = %u \n", a,pa);
	printf("b = %c, pb = %u \n",b, pb);
	printf("c= %f, pc = %u \n",c, pc);
	printf("pc = %u, pc addr = %u\n",pc,&pc);	*/
	//����
	/*int a = 3;
	int *ap;
	printf("%d\n", a);
	printf("%u\n", &a);
	printf("%d\n", *&a);
	ap = &a;
	printf("%d\n", *ap);
	*ap = 20;
	printf("%d \n", a);*/

	/*int* a = 0;
	char* b = 0;
	float* c = 0;
	printf("a size = %d\n",sizeof(a));
	printf("b size = %d\n",sizeof(b));
	printf("c size = %d\n",sizeof(c));*/
	
	/*int aa[5] = { 0, };
	char bb[5] = { 0, };
	int* paa = &aa;
	char *caa = &bb;
	
	printf("aa[0] addr = %u\n", &aa[0]);
	printf("aa[1] addr = %u\n", &aa[1]);
	printf("aa[2] addr = %u\n", &aa[2]);
	printf("paa +2 = %u\n", paa + 2);
	printf("caa +0 = %u\n", caa );
	printf("caa +1 = %u\n", caa+1 );
	printf("caa +2 = %u\n", caa+2);*/
	
	//�����Ҵ�
	/*int n;
	int* pnum = (int *)malloc(sizeof(int) * 3);
	int nums[3] = { 0, };
	
	printf("nums size =%d\n", sizeof(nums));
	printf("pnums size =%d\n", sizeof(pnum));

	for (n = 0; n < 3; n++) {
		pnum[n] = (n + 1) * 2;
		nums[n] = (n + 1) * 2;
	}
	for (n = 0; n < 3; n++) {
		printf("pnum[%d] = %d\n", n, pnum[n]); 
		printf("nums[%d] = %d\n", n, nums[n]); 
	}
	free(pnum);*/

	//�����Ҵ� ����
	/*int count, i = 0, total = 0;
	int* pnum;

	printf("��� ���ڸ� �Է��Ͻðڽ��ϱ�? : ");
	scanf_s(" %d", &count);
	pnum = (int*)malloc(sizeof(int)*count);
	while (i < count) {
		int* p = pnum + i;
		printf("%d ��° ���� : ", i + 1);
		scanf_s(" %d", p);
		total += *p;
		i++;
	}
	printf("��ü �� : %d\n", total);*/

	//2���� �迭
	/*int n, m;
	int array2R[2][3] = { 0, };
	for (n = 0; n < 3*2; n++) {
		int line = n / 3;
		int row = n % 3;
		printf("array2R[%d][%d] addr = %u\n", line, row, array2R[line][row]);
	}*/

	//����������
	/*int n, m;
	int** pparray = 0;
	if (pparray == 0) {
		pparray = (int**)malloc(sizeof(int*) * 3);   //malloc ������ ù��° �ּ� ����  - int*�ڷ���¥�� 3ĭ ����� �����ּ� ����
		for (n = 0; n < 3; n++) {
			pparray[n] = (int*)malloc(sizeof(int) * 2); //- int �ڷ��� 2ĭ ����� ù��° �����ּ� ����
		}
	}

	printf("pparray=%u\n", pparray);
	printf("&pparray=%u\n", &pparray);
	printf("pparray[%d]=%u\n", 0, pparray[0]);
	printf("&pparray[%d]=%u\n", 0, &pparray[0]);
	printf("&pparray[%d][%d]=%u\n", 0,0, &pparray[0][0]);
	printf("&pparray[%d][%d]=%u\n", 0,1, &pparray[0][1]);
	printf("pparray[%d]=%u\n", 1, pparray[1]);
	printf("&pparray[%d]=%u\n", 1, &pparray[1]);
	printf("&pparray[%d][%d]=%u\n", 1,0, &pparray[1][0]);
	printf("&pparray[%d][%d]=%u\n", 1,1, &pparray[1][1]);
	printf("pparray[%d]=%u\n", 2, pparray[2]);
	printf("&pparray[%d]=%u\n", 2, &pparray[2]);
	printf("&pparray[%d][%d]=%u\n", 2,0, &pparray[2][0]);
	printf("&pparray[%d][%d]=%u\n", 2,1, &pparray[2][1]);

	for (n = 0; n < 3; n++) {
		printf("pparray[%d] addr =%u\n", n, &pparray[n]);
		for (m = 0;  m < 2; m++) {
			printf("pparray[%d][%d] addr = %u\n", n, m, &pparray[n][m]);
		}
	}

	//�Ҵ� ����
	if(pparray != 0) {
		for (n = 0; n < 3; n++) {
			free(pparray[n]);
			pparray[n] = 0;

		}
		free(pparray);
		pparray = 0;
	} */


	system("pause");
	return 0;
}