#include "mainheader.h"

char Block::total_block[21][14] = { 0, };
const char Block::block[7][4][4][4] = { //[������ ��� 0~6][������ ���� 0~3][y][x]
   //������
   1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,   1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,   1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,   1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,

   //�׸���
   1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,   1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,   1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,   1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,

   //'��' ���
   0,1,0,0,1,1,0,0,0,1,0,0,0,0,0,0,   1,1,1,0,0,1,0,0,0,0,0,0,0,0,0,0,   1,0,0,0,1,1,0,0,1,0,0,0,0,0,0,0,   0,1,0,0,1,1,1,0,0,0,0,0,0,0,0,0,

   //'��'���
   1,1,0,0,0,1,0,0,0,1,0,0,0,0,0,0,   1,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,   1,0,0,0,1,0,0,0,1,1,0,0,0,0,0,0,   0,0,1,0,1,1,1,0,0,0,0,0,0,0,0,0,

   //'��' ���
   1,1,0,0,1,0,0,0,1,0,0,0,0,0,0,0,   1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,   0,1,0,0,0,1,0,0,1,1,0,0,0,0,0,0,   1,1,1,0,0,0,1,0,0,0,0,0,0,0,0,0,

   //'Z' ���
   1,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,   0,1,0,0,1,1,0,0,1,0,0,0,0,0,0,0,   1,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,   0,1,0,0,1,1,0,0,1,0,0,0,0,0,0,0,

   //'S' ���
   0,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0,   1,0,0,0,1,1,0,0,0,1,0,0,0,0,0,0,   0,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0,   1,0,0,0,1,1,0,0,0,1,0,0,0,0,0,0

};


void Block::init_total()
{
	for (int i = TOP; i < BOTTOM; i++)//y��ǥ
	{
		for (int j = LEFTSIDE; j <= RIGHTSIDE; j++) //x��ǥ
		{
			if ((j == LEFTSIDE) || (j == RIGHTSIDE)) //x��ǥ�� 0�Ǵ� 13�϶� - ���� ������ �� ��� ����
			{
				total_block[i][j] = 1; //��� 
			}
			else {
				total_block[i][j] = 0;   //�ƴϸ� ����
			}
		}
	}

	for (int j = LEFTSIDE; j <= RIGHTSIDE; j++)         //ȭ���� ���� ���� ���� 1�� ä���. �ǹ���
		total_block[BOTTOM][j] = 1;

}

void Block::show_total_block(const int& level)
{
	SetColor(DARK_GRAY);// ��ü ���, �� ���� ��ũ�׷���
	for (int i = TOP; i <= BOTTOM; i++) //y��
	{
		for (int j = LEFTSIDE; j <= RIGHTSIDE; j++)//x��
		{
			if (j == LEFTSIDE || j == RIGHTSIDE || i == BOTTOM)      //������ ���� �ܺ� ���� ����
			{
				SetColor((level % 6) + 1); //������ ���� �ܺ���

			}
			else {
				SetColor(DARK_GRAY); //�ܺ��� �ƴϸ� �׳� �ٱ׻����� 
			}
			gotoxy((j * 2) + ab_x, i + ab_y); //�ش� ��� 
			if (total_block[i][j] == 1)//��ĭ�� �ƴϸ� �׸� ���, 
			{
				printf("��");
			}
			else {
				printf("  ");
			}

		}
	}
	SetColor(BLACK);// ����ϴ� ���� �� �ʱ�ȭ- 
	gotoxy(77, 23);//Ŀ�� ��ġ �缳��
	return;
}

int Block::check_full_line(GameManager& game)
{
	for (int i = TOP; i < BOTTOM; i++) //��ü ��� �� üũ
	{
		int j;
		for (j = LEFTSIDE + 1; j < RIGHTSIDE; j++) //i ���� ��� ĭ�� üũ
		{
			if (total_block[i][j] == 0)//�߰��� �� ���� ������ break
				break;
		}
		if (j == 13)   //������ �� ä������- j=13 break ���� �ݺ��� 13�� ����� 
		{


			//���-����
			show_total_block(game.getStagelevel()); //��Ż��� ���
			SetColor(BLUE); // ���� ���
			gotoxy(1 * 2 + ab_x, i + ab_y); // �� �� ��ġ�� ����
			for (j = 1; j < 13; j++)
			{
				printf("��"); //�������� �ѹ� ��� ���ְ�
				Sleep(10); //0.01�ʸ��� ���
			}
			gotoxy(1 * 2 + ab_x, i + ab_y); //�ٽ� ���� �������� ����
			for (j = 1; j < 13; j++)
			{
				printf("  ");// �� ������
				Sleep(10);
			}

			//������ ������
			for (int k = i; k > 0; k--)//���� �� i���� �� ���� �ݺ�
			{
				for (j = 1; j < RIGHTSIDE; j++) //x��
					total_block[k][j] = total_block[k - 1][j];//�ٷ� ���� ���� ������ ������
			}

			for (j = 1; j < 13; j++) //�� ���� �� 0���� �ʱ�ȭ ����
				total_block[0][j] = 0;
			game.fullLine();

		}
	}
	show_total_block(game.getStagelevel());
	return 0;
}




Block::Block()
{
}

Block::Block(int shape, int angle, POINT pos) :block_shape(shape), block_angle(angle), pos(pos)
{
}

Block::~Block()
{
}

int Block::getBShape()
{
	return block_shape;
}

void Block::setBshape(int shape)
{
	this->block_shape = shape;
}

int& Block::getangle()
{
	return block_angle;
}



POINT& Block::getPos()
{
	return pos;
}

void Block::moveX(const int& x)
{
	pos.x += x;
}

void Block::moveY(const int& y)
{
	pos.y += y;
}

bool Block::rotate_Right()
{
	block_angle = (block_angle + 1) % 4; //angle�� �ϳ� �ø���
	if (strike_check()) { //�浹�ϸ�
		block_angle = (block_angle - 1) % 4; //����
		return false; //���� ���и����̳� �ᱹ ������� ����
	}
	else
		return true; //
}



Block  Block::make_new_block(const int stick_rate)
{
	// i= Ȯ��
	int i;
	i = rand() % 100;
	if (i <= stick_rate)      //����� ����Ȯ�� ���
		return Block(0);                //����� ������� ����
	else
		return Block((rand() % 6) + 1);

}

void Block::show_cur_block()
{
	//���� �ص� SetColor�Լ��� �̿��Ͽ� ��翡 ���� �� ��� ����
	switch (block_shape)
	{
	case 0:
		SetColor(RED);
		break;
	case 1:
		SetColor(BLUE);
		break;
	case 2:
		SetColor(SKY_BLUE);
		break;
	case 3:
		SetColor(WHITE);
		break;
	case 4:
		SetColor(YELLOW);
		break;
	case 5:
		SetColor(VOILET);
		break;
	case 6:
		SetColor(GREEN);//greenjoa!
		break;
	default:
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if ((j + pos.y) < 0)// ��µǴ� y��ǥ�� 0���� �ܼ� â���� ������� ������� ����
				continue;

			if (block[block_shape][block_angle][j][i] == 1) //�ش��ϴ� ������ j,i��ġ�� ������ �ƴ� ��
			{
				gotoxy((i + pos.x) * 2 + ab_x, j + pos.y + ab_y); //(i+x)*2 + ab_x,j+y+ab_y ��ġ�� ��� �� �簢���� ����� 2ĭ �����ϹǷ� x�� �ι�
				printf("��");

			}
		}
	}

	SetColor(BLACK);// ����ϴ� ���� �� �ʱ�ȭ- 
	gotoxy(77, 23);//Ŀ�� ��ġ �缳��
	return;
}

//�׺��� ��� �Լ�
void Block::show_naviblock(const Block& origin)
{
	this->erase_cur_block(); //���� �׺� ����� �����
	*this = origin; 
	//origin���� �޾ƿ� ���� �̵�������� �ڱ��ڽ��ʱ�ȭ

	switch (block_shape)
	{//shape�� ���� ..�� ���
	case 0:
		SetColor(DARK_RED);
		break;
	case 1:
		SetColor(DARK_BLUE);
		break;
	case 2:
		SetColor(DARK_SKY_BLUE);
		break;
	case 3:
		SetColor(GRAY);
		break;
	case 4:
		SetColor(DARK_YELLOW);
		break;
	case 5:
		SetColor(DARK_VOILET);
		break;
	case 6:
		SetColor(DARK_GREEN);
		break;
	}


	while (strike_check() != true) //�浹 �Ҷ����� 
		moveY(1); //������
	moveY(-1);

	//��º�
	for (int i = 0; i < 4; i++)//y��
	{
		for (int j = 0; j < 4; j++) //x��
		{
			if ((j + pos.y) < 0) //0���� ���������� ���x
				continue;

			if (block[block_shape][block_angle][j][i] == 1)
			{
				gotoxy((i + pos.x) * 2 + ab_x, (j + pos.y) + ab_y);
				printf("��");

			}
		}
	}

	//��� �� �ʱ�ȭ
	SetColor(BLACK);
	gotoxy(77, 23);
	return;
}

//��� ����� �Լ�
int Block::erase_cur_block()
{

	if (block_shape <= 6 && block_shape >= 0)
		for (int i = 0; i < 4; i++) //y��
		{
			for (int j = 0; j < 4; j++) //x��
			{
				if (block[block_shape][block_angle][j][i] == 1)//�ش��ϴ� �����ġ�� �� ����� �ƴ� ��
				{
					if (total_block[j + pos.y][i + pos.x] == 1) break; //�̵������ ������ �̵����� ��������� ������ �̵��Ҷ����� ��µ��� �ʴ� ������ �־� ��Ż����� �κ��϶��� �������ְ� �߰�
					gotoxy((i + pos.x) * 2 + ab_x, j + pos.y + ab_y);//�� ��ġ�� �������� ����
					printf("  ");
					//break;

				}
			}
		}

	return 0;
}

//�浹 üũ
bool Block::strike_check()
{
	int block_dat;

	if (block_shape <= 6 && block_shape >= 0) {
		for (int i = 0; i < 4; i++)//y
		{
			for (int j = 0; j < 4; j++)//x
			{
				if ((pos.x + j) == LEFTSIDE || (pos.x + j) == RIGHTSIDE)
					block_dat = 1;   //�� ����� ���� ��Ż ����� �ܰ��� �̸� -1
				else if (pos.y + i < 0) //�̰�� total_block  ���� �̺κ��� ���⿡ �߰�  ����--
					block_dat = 0;
				else
					block_dat = total_block[pos.y + i][pos.x + j];  //�̺���� ��Ż��Ͽ� ��������,�� �������


				if ((block_dat != 0) && (block[block_shape][block_angle][i][j] == 1))  
				{ //�������� ��ǥ�� ��������? -- �̺���� ������ �ƴϰ� ������ �� ��� �κе� 1�̸� �浹 !
					return true;
				}
			}
		}
		return 0;
	}
	return 1;

}

//��� ����
void Block::merge_block()
{
	for (int i = 0; i < 4; i++)//y��
	{
		for (int j = 0; j < 4; j++)//x��
		{ //��Ż ��Ͽ� ������ �κ��� 1�� �ٲ���
			total_block[pos.y + i][pos.x + j] |= block[block_shape][block_angle][i][j];
		}
	}
	return;

}

void Block::show_next_block(const int& level)
{

	SetColor((level + 1) % 6 + 1); //��������� ǥ��Ǵ� �׵θ��� �������� ���� �ٸ�
	for (int i = 1; i < 7; i++) //������ ���� ����� ������ �˷��ִ� �׸� ������ ����
	{
		gotoxy(33, i);
		for (int j = 0; j < 6; j++)
		{
			// ù ��� ������ �ุ ��ĥ�� �׸�ĭ�� �� �����. �������� ù ��° ���� ������ �� ������ �׸� ���.
			if (i == 1 || i == 6 || j == 0 || j == 5)
			{
				printf("��");
			}
			else {
				printf("  ");
			}

		}
	}
	Block temp(block_shape, 0, { 15, 1 });
	temp.show_cur_block(); // 15*2+ab_x�ϸ� 35,  ������� �ȿ��ٰ� ���� ���
}

void Block::block_start()
{
	pos = { 5,-3 };
	block_angle = 0;
}

bool Block::check_in_Total()
{
	if (block_shape <= 6 && block_shape >= 0) {
		for (int i = 0; i < 4; i++)//y for�� ������ ���� �����մ� ĭ���� 
		{
			for (int j = 0; j < 4; j++)//x
			{
				if (block[block_shape][block_angle][i][j] == 1) { //�������� �ִ� ���
					if (pos.y + i < 0) //����� �������� ��ġ�� 0���� ������ �ۿ� ����!
						return false;
					else
						return true;//�ƴϸ� �ȿ�
				}
			}
		}
	}
}

