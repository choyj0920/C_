#pragma once
#include <Windows.h> //������ api���� ���
enum { //������ SetColor �Լ����� ����� ���� - Ư�� �÷��� ��ȣ 0~15�� ���� ������ ����
	BLACK,      /*  0 : ��� */
	DARK_BLUE,    /*  1 : ��ο� �Ķ� */
	DARK_GREEN,    /*  2 : ��ο� �ʷ� */
	DARK_SKY_BLUE,  /*  3 : ��ο� �ϴ� */
	DARK_RED,    /*  4 : ��ο� ���� */
	DARK_VOILET,  /*  5 : ��ο� ���� */
	DARK_YELLOW,  /*  6 : ��ο� ��� */
	GRAY,      /*  7 : ȸ�� */
	DARK_GRAY,    /*  8 : ��ο� ȸ�� */
	BLUE,      /*  9 : �Ķ� */
	GREEN,      /* 10 : �ʷ� */
	SKY_BLUE,    /* 11 : �ϴ� */
	RED,      /* 12 : ���� */
	VOILET,      /* 13 : ���� */
	YELLOW,      /* 14 : ��� */
	WHITE,      /* 15 : �Ͼ� */
};
//Ŀ�� ��ġ ����
void gotoxy(int x, int y);
//��±۾� �� ����
void SetColor(int color);
// Ŀ�� �Ⱥ��̰�
void SetCursorvisible(bool visible);
