#include "pch.h"
#include "Score.h"





Score::Score(int kor_s, int eng_s) :kor_s(kor_s),eng_s(eng_s)
{
	ave_s = (eng_s + kor_s) / 2.0;
}

Score::~Score()
{
}
