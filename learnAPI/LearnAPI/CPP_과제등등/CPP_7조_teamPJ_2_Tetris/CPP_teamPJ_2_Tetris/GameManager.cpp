#include "mainheader.h"

GameManager::GameManager()
{
	initData();
}

GameManager::~GameManager()
{

}

//������ �ʱ�ȭ �Լ� 
void GameManager::initData()
{
	//����� ��Ż ��� �ʱ�ȭ�Լ� ����
	Block::init_total();
	//���� ������������, ���μ�,���� �ʱ�ȭ
	stagelevel = 0;
	clearline = 0;
	score = 0;
}

void GameManager::show_gamestat()
{
	//ó���� �ѹ��� ����ѵ� �������� ���ھ� ���� �۾��� �ٽ� ��� ���Ϸ� �� �κ��ΰ� ������ 
//printed_text�� 0�� �ƴ� ���� ���ϴ� �κ��� ���� ���� �ǹ̰� ���µ�? -�ϴ� �׳� ����
	static int printed_text = 0; // �ؿ��ִ� ���ǹ��� ���ǿ� ���� ���� ���ǹ��� ��������

	SetColor(GRAY);
	if (printed_text == 0)
	{ //���� ���
		gotoxy(35, 7);
		printf("STAGE");

		gotoxy(35, 9);
		printf("SCORE");

		gotoxy(35, 12);
		printf("LINES");


	}
	gotoxy(41, 7);
	printf("%d", stagelevel + 1);
	gotoxy(35, 10);
	printf("%10d", score);
	gotoxy(35, 13);
	printf("%10d", STAGE::stage[stagelevel].getclear_line() - clearline);
}

void GameManager::GameRun()
{
	//���� ���� ���� ���� ����
	SetCursorvisible(false); //���۽� Ŀ����
	int is_gameover = 0;
	initData(); //�ʱ�ȭ �Լ� ����
	Logo(); //�ΰ� ����
	while (true) //
	{
		SetCursorvisible(true);//�������� ���ý� Ŀ�� ������
		input_data(); //�������� ���� �Լ�
		SetCursorvisible(false); //�������� ������ Ŀ�� ��
		Block::show_total_block(stagelevel); //��Ż ��� ��� - ��ó�� ������ ���
		
		//���� ��� ����
		MoveBlock = Block::make_new_block(STAGE::stage[stagelevel].getStick_rate()); //��� ����
		MoveBlock.block_start(); //���� ��� �ʱ�ȭ
		
		NextBlock = Block::make_new_block(STAGE::stage[stagelevel].getStick_rate()); //���� ��� ����
		
		naviBlock.show_naviblock(MoveBlock); //�׺� ��Ϻ��̱�
		MoveBlock.show_cur_block(); // �̵���� ���-�׺񺸴� ���� �ϸ� �׺񿡼������������
		NextBlock.show_next_block(stagelevel); //���� ��� ĭ ǥ��
		show_gamestat();

		for (int i = 0; true;  i++) { //���� ����
			if (_kbhit()) { //Ű�Է��� ������
				char keytemp = _getch(); 
				if (keytemp == KEY_ESC) {		//esc�Է��� ������-����
					initData(); //������ �ʱ�ȭ
					system("cls"); //��ü �ʱ�ȭ
					MoveBlock.block_start(); //
					break;
				}
				if (keytemp == EXT_KEY) {//Ȯ��Ű- ����Ű�Է½�
					keytemp = _getch();//Ȯ��Ű ����
					switch (keytemp)
					{
					case KEY_UP: { //��Ű- ȸ�� Ű
						MoveBlock.erase_cur_block(); //�̵���� �ϴ� �����
						MoveBlock.rotate_Right(); //ȸ�� ��ų�� ���� ������ ȸ�����ִ� �Լ�
						naviBlock.show_naviblock(MoveBlock); //�׺� ��Ϻ��̱�
						MoveBlock.show_cur_block(); // �̵���� ���
						break;
					}
					case KEY_LEFT: {//����Ű -�����̵�Ű
						if (MoveBlock.getPos().x > LEFTSIDE) { //�̵������ ���� ������ ���� ������
							MoveBlock.erase_cur_block(); //�̵� ��� �ϴ������
							MoveBlock.moveX(-1); //��ĭ �̵���
							if (MoveBlock.strike_check()) { //�浹�ϸ� 
								MoveBlock.moveX(1); //�ٽ� �� ��ġ��
							}
							naviBlock.show_naviblock(MoveBlock); //�׺� ��Ϻ��̱�
							MoveBlock.show_cur_block(); // �̵���� ���
						}
						break;
					}
					case KEY_RIGHT: {//����Ű ������ �̵�Ű
						if (MoveBlock.getPos().x < RIGHTSIDE) {//�̵� ����� ���� ������ ���� ������ -�̰Ŵ� �����ǹ̰� ���µ�
							MoveBlock.erase_cur_block(); //�̵� ��� �ϴ� �����
							MoveBlock.moveX(1); //�� ĭ �̵���
							if (MoveBlock.strike_check()) {//�浹�ϸ�
								MoveBlock.moveX(-1); //�ٽ� ����ġ��
							}
							naviBlock.show_naviblock(MoveBlock); //�׺� ��Ϻ��̱�
							MoveBlock.show_cur_block(); // �̵���� ���
						}
						break;
					}
					case KEY_DOWN: { //�Ʒ�Ű - ���������ϴ� Ű
						is_gameover = move_block(); //����� ��ĭ �Ʒ��� �̵��Լ�
						if(is_gameover==0)  //0���� ��� �Ǿ����� 
							naviBlock.show_naviblock(MoveBlock); //�׺� ��Ϻ��̱�
						//is_gameover ==2�� �Ʒ��� ������������ ��¼�� �׺�� ��ġ�� ���� ���x
						MoveBlock.show_cur_block(); // �̵���� ���
						
						break;
					}
					default:
						break;
					}
					continue;
				}
				if (keytemp == SPACEBAR) { //�����̽��ٸ� ������
					while (is_gameover == 0) {
						is_gameover = move_block();// ����� �Ʒ��� ������ ������ ����
					}//�̵���� ���  �̺κп����� �׺��ϰ� ��ġ�� ���� �ϱ⿡..
					MoveBlock.show_cur_block();
				}
				
			}
			if (is_gameover == 1) { //���� �����Ǹ�
				showGameover(); //���ӿ��� ���
				SetColor(GRAY); //
				initData(); //������ �ʱ�ȭ
				MoveBlock.block_start();
				is_gameover = 0;
				break;
			}
			if (STAGE::stage[stagelevel].getclear_line() <=clearline) //�� ���μ��� Ŭ���� ������ ������ 
			{
				clearline -= STAGE::stage[stagelevel].getclear_line(); //���μ� �ʱ�ȭ
				Block::show_total_block(++stagelevel);  //�� �ʱ�ȭ -����
				show_gamestat(); 
				
			}
			if ((i % STAGE::stage[stagelevel].getSpeed()) == 0) {
				if (is_gameover != 1) {
					is_gameover = move_block();
					naviBlock.show_naviblock(MoveBlock); //�׺� ��Ϻ��̱�
					MoveBlock.show_cur_block(); // �̵���� ���
				}
				
			}
			//��º� �ʱ�ȭ
			gotoxy(77, 23);
			Sleep(15);
 			gotoxy(77, 23);
		}
		//�Լ� �ʱ�ȭ
		initData();
	}

}

void GameManager::fullLine()
{
	clearline += 1; //���� Ŭ���� �Ǹ� ���� ��+1
	score += 100 + (stagelevel * 10) + (rand() % 10); //���� ���������� ���
	show_gamestat(); //���� ������ ����
}

int GameManager::getStagelevel() const
{
	return stagelevel;
}
//��Ͽ����� �ִ� �Լ�
int GameManager::move_block()
{
	MoveBlock.erase_cur_block(); //���� ��ġ�� ��� �����

	MoveBlock.moveY(1); //�Ʒ��� �� ĭ �̵�
	if (MoveBlock.strike_check()) {// ���� �̺���� ��Ż ��ϰ� �浹 ������
		MoveBlock.moveY(-1);
		if (MoveBlock.check_in_Total()) {//��� �� ������

			MoveBlock.merge_block();
			Block::check_full_line(*this);
			Block::show_total_block(stagelevel);
			show_gamestat(); //���� ������ ����
			MoveBlock = NextBlock; //��� ���Ӱ� �ٲٱ�
			MoveBlock.block_start(); //
			NextBlock = Block::make_new_block(STAGE::stage[stagelevel].getStick_rate());
			NextBlock.show_next_block(stagelevel);
			return 2;
		}
		else {
			return 1;
		}

	}
	return 0;
}

//�ΰ� ��� �Լ�
void GameManager::Logo()
{
	int i, j;// �ݺ������� ���Ǵ� ����
	//�� ��ºε� ����
	gotoxy(13, 3);
	printf("������������������������������������������������������������������������������������������������"); //���� 
	Sleep(100);
	gotoxy(13, 4);
	printf("���ߡߡ�  �ߡߡ�  �ߡߡ�   �ߡ�     ��   ��  �� ��");
	Sleep(100);
	gotoxy(13, 5);
	printf("��  ��    ��        ��     �� ��    ��    �ߡ�  ��");
	Sleep(100);
	gotoxy(13, 6);
	printf("��  ��    �ߡߡ�    ��     �ߡ�     ��     ��   ��");
	Sleep(100);
	gotoxy(13, 7);
	printf("��  ��    ��        ��     �� ��    ��    �ߡ�  ��");
	Sleep(100);
	gotoxy(13, 8);
	printf("��  ��    �ߡߡ�    ��     ��  ��   ��   ��  �� ��");
	Sleep(100);
	gotoxy(13, 9);
	printf("������������������������������������������������������������������������������������������������"); //����

	gotoxy(28, 20);
	printf("Please Press Any Key~!");
	// Ű�� �Է� ������ ���� ��� �ݺ��ؼ� ��ϵ� ����� 
	for (i = 0; i >= 0; i++)
	{
		if (i % 40 == 0)
		{ 
			

			for (int i = 14; i < 19; i++) {
				gotoxy(6, i); printf("%95s", ""); //����-�ܻ����������
			}
			Block(rand() % 7, rand() % 4, {6,14}).show_cur_block();
			Block(rand() % 7, rand() % 4, { 12,14 }).show_cur_block();
			Block(rand() % 7, rand() % 4, { 19,14 }).show_cur_block();
			Block(rand() % 7, rand() % 4, { 24,14 }).show_cur_block();
			
		}
		if (kbhit())
			break;
		Sleep(30);
	}

	getche();
	system("cls");

	return;
}

//�������� ���� �Լ�
void GameManager::input_data()
{
	int i = 0; // �Է¹޴� ���� ������ ����
	SetColor(GRAY);
	gotoxy(10, 7);
	printf("���������������� < GAME KEY > ��������������"); //����
	Sleep(10);
	gotoxy(10, 8);
	printf("�� UP   : Rotate Block       ��");
	Sleep(10);
	gotoxy(10, 9);
	printf("�� DOWN : Move One-Step Down ��");
	Sleep(10);
	gotoxy(10, 10);
	printf("�� SPACE: Move Bottom Down   ��");
	Sleep(10);
	gotoxy(10, 11);
	printf("�� LEFT : Move Left          ��");
	Sleep(10);
	gotoxy(10, 12);
	printf("�� RIGHT: Move Right         ��");
	Sleep(10);
	gotoxy(10, 13);
	printf("����������������������������������������������������������"); //����


	while (i < 1 || i>8)// 1�̸� 8�ʰ��μ��϶� �ٽ� �Է¹���
	{
		gotoxy(10, 3);
		printf("Select Start level[1-8]:              \b\b\b\b\b\b\b\b\b\b\b\b\b\b");
		scanf("%d", &i);
		while (getchar() != '\n'); //���۸� ���:scanf�� ��� ���Ͱ� ���ۿ� ���� ���� �ִٰ� �νĵǾ� ���ѹݺ��ǹǷ� 
		/*
		if (scanf("%d", &i) == 0) { ���� �κ��� �̷� ������ �ٲ㵵 ����
		   rewind(stdin);
		}
		*/

	}


	stagelevel = i - 1;
	system("cls");
	return;
}

//���ӿ��� ���
void GameManager::showGameover()
{
	//���� ���� ���
	SetColor(RED);
	gotoxy(15, 8);
	printf("��������������������������������������������������������");
	gotoxy(15, 9);
	printf("��**************************��");
	gotoxy(15, 10);
	printf("��*        GAME OVER       *��");
	gotoxy(15, 11);
	printf("��**************************��");
	gotoxy(15, 12);
	printf("��������������������������������������������������������");
	fflush(stdin); //���ݱ��� �׿��ִ� �Է� ���۸� �� ������
	Sleep(1000); //1�� ������

	getche();
	system("cls");

	return;
}

