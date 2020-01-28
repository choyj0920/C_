#pragma once
class GameManager;
#include "mainheader.h"

#ifndef DEFBLOCK
#define DEFBLOCK 0
class Block
{
private:
	//��� ���,���� ���� ����
	int block_shape, block_angle;
	POINT pos; //��� ��ġ ���� ����

	//��� ���� ��ġ - �̰��� �������� �����ġ ����
	static const int ab_x = 5, ab_y = 1;

public:
	Block(); //��� ������
	Block(int shape, int angle = 0, POINT pos = { 0, 0 });
	~Block();
	//��� ���� �� �Լ�
	int getBShape();
	void setBshape(int shape);
	int& getangle();
	POINT& getPos();
	//x��������� x ��ŭ  �̵����ִ� �Լ�
	void moveX(const int& x);
	//y�� �������� y��ŭ �̵����ִ� �Լ�
	void moveY(const int& y);
	//ȸ���Ҽ� ���� ������ angle+1 ���ִ� �Լ�
	bool rotate_Right();
	

	//��� ǥ�� ����,���� ,x,y�� �޾Ƽ�  ��� ���
	void show_cur_block();
	// �׺��� ǥ��
	void show_naviblock(const Block& origin);
	//����� ��� ���� ��ġ�� �޾� ��� �Ǿ����� ����� �� ĭ���� �״�� ���� ���� ������
	int erase_cur_block();
	//�浹 üũ �Լ� -�Ű� x
	bool strike_check();
	//�ڱ��ڽź�ϰ� ��Ż ����� ��Ż��Ͽ� �����Ѵ�. �Ű�x
	void merge_block();
	//���� ��� ����Լ�-������� ĭ�� ����ϱ�
	void show_next_block(const int& level);
	//��� �̵� ������ ��ġ �ʱ�ȭ �Լ�
	void block_start();
	//���� ����� ���� ȭ��� �ִ��� Ȯ�����ִ� �Լ�
	bool check_in_Total();

	//���ο� ��� ���� ���ο� ����� ��� ���� ,- ���������� ��ƽ Ȯ���� ����..
	static Block make_new_block(const int stick_rate);

	//shape,������ ��ϸ��-
	static const char block[7][4][4][4];
	
	//��ü ���
	static char total_block[BOTTOM+1][RIGHTSIDE+1];
	//��ü ��� �ʱ�ȭ
	static void init_total();
	//��ü ��� ���
	static void show_total_block(const int& level);
	//��Ż����� �� ��ü�� ���� �� �κ��� ������- �����ϰ� ��Ż ��� ������ ���� 
	static int check_full_line(GameManager &game);

	
};
#endif // !DEFBLOCK