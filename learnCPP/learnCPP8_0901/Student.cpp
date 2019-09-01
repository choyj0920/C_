#include "pch.h"
#include "Student.h"


char _name[MAX_BUFFSIZE];
char _ban[MAX_BUFFSIZE];
char kors[MAX_BUFFSIZE];
char engs[MAX_BUFFSIZE];
char aves[MAX_BUFFSIZE];



Student::Student(const char * name, int ban, int kon_s, int eng_s) :Score(kon_s, eng_s)
{
	strcpy_s(this->name, strlen(name) + 1, name);
	this->ban = ban;
	ofstream outFile("Data.txt");
	outFile << name << "	" << ban << "	" << this->kor_s << "	" << eng_s << "	" << ave_s << endl;
	outFile.close();

}

void Student::showInfo()
{
	ifstream inFile("output.txt");
	if (inFile.is_open()) {
		while (!inFile.eof()) {
			int n = 1;
			inFile.get(_name, 100,'\t'); //100바이트 까지 받아옴
			inFile.get(_ban, 100,'\t'); //100바이트 까지 받아옴
			inFile.get(kors, 100,'\t'); //100바이트 까지 받아옴
			inFile.get(engs, 100,'\t'); //100바이트 까지 받아옴
			inFile.get(aves, 100,'\n'); //100바이트 까지 받아옴
			printf("%d번째 학생\n이름 : %s\n반 : %s \n국어 : %s\n영어 : %s\n평균 : %s\n",n, _name, _ban, kors, engs, aves);
			n++;
			
		}
		inFile.close();
	}
}

Student::~Student()
{
}
