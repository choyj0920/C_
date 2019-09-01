#pragma once
class Score
{
protected:
	int kor_s;
	int eng_s;
	double ave_s;
public:
	Score(int kor_s,int eng_s);
	~Score();
	void set_score(int kor_s, int eng_s);
};