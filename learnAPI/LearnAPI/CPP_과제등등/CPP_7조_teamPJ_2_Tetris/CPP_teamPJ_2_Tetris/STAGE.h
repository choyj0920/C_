#pragma once
class STAGE
{
private:
	int speed; //���������� ��϶������� �ӵ� ���� ����
	int stick_rate; //���������� ����� ��ƽ�� �� Ȯ���� ���� ����
	int clear_line; //�������� �Ϸ� ������ ���� ����
	STAGE(int speed, int stick_rate, int clear_line) :speed(speed), stick_rate(stick_rate), clear_line(clear_line) {

	}//�����ڸ� privateȭ�ؼ� �ܺο��� stage��ü�� �������� ���ϰ���
	~STAGE() {}
public:
	//����� ���� ���ѵ� stage�� ���� 10��
	const static STAGE stage[10];
	
	int getSpeed()const { return speed; }
	int getStick_rate()const { return stick_rate; }
	int getclear_line()const { return clear_line; }

};
