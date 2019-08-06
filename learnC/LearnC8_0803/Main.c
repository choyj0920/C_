#include<stdio.h>
#include<Windows.h>
//트으레인 그냥 구조체 정의 해보기
/*
typedef struct Train {
	int num;
	int inwon;
	struct Train* next;
}TRAIN, *LPTRAIN;

int main() {

	
	TRAIN train1, train2, train3;
	train1.num = 8;
	train1.inwon = 5;
	train1.next = 0;
	train2.num = 2;
	train2.inwon = 15;
	train3.num = 6;
	train3.inwon = 10;
	train2.next = &train3;
	train3.next = &train1;
	
}*/
void WriteFileTest(const char* filename);
void WriteBinFileTest(const char* filename);
void ReadFileTest(const char* fileName);

int main() {

	//WriteFileTest("test.txt");
	//ReadFileTest("test.txt");
	WriteBinFileTest("testb.dat");

	system("pause");
	return;
}
void ReadFileTest(const char* fileName) {
	char* tempStr[MAX_PATH] = { 0, };
	FILE* pf = 0;
	errno_t er = fopen_s(&pf, fileName, "r");
	if (pf != 0) {
		while (feof(pf) == 0) {
			memset(tempStr, 0, sizeof(tempStr)); 
			//printf("%c", fgetc(pf));
			fgets(tempStr, MAX_PATH, pf);
			printf(tempStr);
		}
		fclose(pf);
	}
	else printf("%s 파일은 존재 하지않습니다\n",fileName);
}
void WriteFileTest(const char* filename) {
	FILE* pf = 0;
	errno_t er = fopen_s(&pf, filename, "w");
	fputc('Z', pf);
	fputc('\n', pf);
	fputs("처음이라 당황하셨죠...\n", pf);
	fprintf(pf,"%s\t%d\t%1.1f\t%d\n","홍길동",19,177.38f,1);	
	fprintf(pf,"%s\t%d\t%1.1f\t%d\n","이영희",16,168.18f,0);

	fclose(pf);
}
void WriteBinFileTest(const char* filename) {
	FILE* pf = 0;
	errno_t er = fopen_s(&pf, filename, "wb");
	fputc('Z', pf);
	fputc('\n', pf);
	fputs("처음이라 당황하셨죠...\n", pf);
	fprintf(pf, "%s\t%d\t%1.1f\t%d\n", "홍길동", 19, 177.38f, 1);
	fprintf(pf, "%s\t%d\t%1.1f\t%d\n", "이영희", 16, 168.18f, 0);

	fclose(pf);
}