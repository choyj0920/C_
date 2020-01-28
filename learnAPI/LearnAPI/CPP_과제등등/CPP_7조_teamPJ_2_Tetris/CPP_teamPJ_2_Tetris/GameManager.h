#pragma once
#include "mainheader.h"
#include "STAGE.h"
#ifndef DEFGAME
#define DEFGAME 0
class GameManager
{
private:
	//���� �������� ����
	int stagelevel;
	//���� ����
	int score;
	//���� Ŭ������ ����
	int clearline;
	
	//���� �̵��ϴ� ���
	Block MoveBlock;
	//���� ���
	Block NextBlock;
	//�׸��� ���
	Block naviBlock;

public:
	GameManager();
	~GameManager();
	//���ǵ� check_full_line�Լ�  ��Ż����� ��ȭ ������ ���� �ϼ� �Ǿ����� �����ֱ� ����
	void initData();
	//���� ������ ��� �Լ� -�ش� ��ġ�� ��������,���� ���� ���� ���
	void show_gamestat();
	//���� �� �����Լ�
	void GameRun();
	//�� ���� ��á���� , ����,clearline, ����â ����
	void fullLine();
	// ���� �������� ���� �Լ�
	int getStagelevel() const;

	//���� �̵������ �������ִ� �Լ�
	// ���� ��- 0�� ���� ��ĭ �̵�, 1�� ���� ���� ����, 
	//2�� ���� ������ �� �ִ� ������ ��������(���ӿ���x)-�� ��� ���ݺ�� ����ó�� ,������� ó��
	int move_block();
	//���� ���۽� - ����ǥ��, �������� ���� �Լ�
	void input_data();

	//��ü�� ���� �ٸ� Ư���� ���� �Լ��� ��������
	static void Logo(); //���� �ΰ�����Լ�
	static void showGameover();
};
#endif // !DEFGAME

