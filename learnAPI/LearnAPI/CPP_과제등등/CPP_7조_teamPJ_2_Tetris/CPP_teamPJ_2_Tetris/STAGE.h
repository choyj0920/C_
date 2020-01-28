#pragma once
class STAGE
{
private:
	int speed; //스테이지의 블록떨어지는 속도 담을 변수
	int stick_rate; //스테이지의 블록이 스틱이 될 확률을 담을 변수
	int clear_line; //스테이지 완료 조건을 담을 변수
	STAGE(int speed, int stick_rate, int clear_line) :speed(speed), stick_rate(stick_rate), clear_line(clear_line) {

	}//생성자를 private화해서 외부에서 stage객체를 생성하지 못하게함
	~STAGE() {}
public:
	//상수로 선언 시켜둔 stage의 정보 10개
	const static STAGE stage[10];
	
	int getSpeed()const { return speed; }
	int getStick_rate()const { return stick_rate; }
	int getclear_line()const { return clear_line; }

};
