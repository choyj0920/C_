#include "pch.h"
#include "Score.h"

Score::Score(int kor_s, int eng_s) :kor_s(kor_s),eng_s(eng_s)
{
	ave_s = (eng_s + kor_s) / 2.0;
}

Score::~Score()
{
}

void Score::set_score(int kor_s, int eng_s)
{
	this->kor_s = kor_s;
	this->eng_s = eng_s;
}
