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

}
int Student::count = 0;

void Student::save_file(Student ** stus, int stu_count)
{
	count = stu_count;
	ofstream out("Data.txt");
	for (int i = 0; i < stu_count; i++) {
		out << stus[i]->name << '\t' << stus[i]->ban << '\t' << stus[i]->kor_s << '\t' << stus[i]->eng_s << endl;
	}
	cout << "파일 저장 완료!" << endl;
	out.close();
}

void Student::print_Info(Student ** stus)
{
	if (count == 0) {
		cout << "저장된 학생이 없습니다. 입력하거나 불러와 주세요\n";
	}
	for (int i = 0; i < count; i++) {
		printf("%d 번째 학생 : \n",i+1);
		printf("\t이름 : %s\n", stus[i]->name);
		printf("\t반 : %d반\n", stus[i]->ban);
		printf("\t국어 점수 : %d점\n", stus[i]->kor_s);
		printf("\t영어 점수 : %d점\n", stus[i]->eng_s);
		printf("\t평균 점수 : %.2f점\n", (stus[i]->kor_s+stus[i]->eng_s)/2.0f);
	}
	
}

void Student::set_count(int n)
{
	count = n;
}

void Student::setInfo(const char *name, int ban, int kon_s, int eng_s) 
{
	strcpy_s(this->name, strlen(name) + 1, name);
	this->ban = ban;
	set_score(kon_s, eng_s);
}

Student::~Student()
{
}
