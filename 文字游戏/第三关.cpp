#include "��������.h" //��������

//�����ء�����������������������������������������������������������
//��־����
int sign_ice = 0; //����ˮ��ʹ�� ����ˮ ��ʱ�򣬱�Ϊ1
int sign_begintext3 = 0;
int sign_twowater = 0; // ̽����
int sign_keytext = 0;
int sign_1 = 0; //Ϊ��ʹ��printsecond�������sleepʹ��һ��
int sign_keytext2 = 0;
int map_3[33][33] = {
	{0,0,0,0,0,		0,0,0,0,0,		0,0,0,0,0,	0,0,0,0,0,	0,0,0,0,0,		0,0,0,0,0,	0,0,0},
	{0,0,0,0,1,		1,0,0,0,0,		0,0,0,0,1,	1,0,0,0,0,	0,0,0,0,0,		0,0,1,1,0,	0,0,0},
	{0,0,0,1,1,		1,1,0,0,2,		0,0,0,1,1,	1,1,0,0,0,	0,0,2,0,0,		0,1,1,1,1,	0,0,0},
	{0,0,0,0,1,		1,0,0,0,0,		0,0,0,0,1,	1,0,0,0,0,	0,2,0,0,0,		0,0,1,1,0,	0,0,0},
	{0,3,0,0,5,		0,0,3,0,0,		0,5,0,0,0,	3,0,0,0,5,	0,0,0,0,3,		0,0,0,0,0,	3,0,0},
	{3,3,3,5,16,	5,3,3,3,0,		5,17,5,0,3,	3,3,0,5,18, 5,0,0,3,3,		3,0,0,0,3,	3,3,0},
	{0,4,5,5,0,		5,5,4,0,5,		5,5,5,5,0,	4,0,5,5,5,	5,5,0,0,4,		0,0,0,0,0,	4,0,0},
	{0,3,5,5,7,		5,5,3,0,5,		5,7,5,5,0,	0,0,5,5,7,	5,5,0,0,0,		0,0,0,0,0,	0,0,0},
	{3,3,3,0,0,		0,3,3,3,0,		0,0,0,0,6,	6,6,0,0,0,	0,0,9,9,9,		9,9,0,0,0,	0,0,0},
	{0,0,0,6,6,		6,0,0,0,6,		6,6,0,0,6,	6,0,0,0,0,	9,9,9,9,9,		9,9,9,0,0,	0,0,0},
	{8,8,8,8,8,		8,8,8,8,8,		8,8,8,8,8,	0,0,0,0,9,	9,9,9,9,9,		9,9,9,9,0,	0,0,0},
	{0,0,0,13,0,	0,0,0,0,0,		0,0,0,0,0,	0,0,0,9,9,	9,9,9,9,9,		9,9,9,9,9,	0,0,0},
	{0,0,0,13,0,	0,0,0,0,0,		0,0,0,0,0,	0,0,9,9,9,	9,9,9,9,9,		9,9,9,9,9,	9,0,0},
	{0,14,0,13,0,	0,0,0,0,0,		0,0,12,0,0, 0,9,9,9,9,	9,9,9,9,10,		9,9,9,9,9,	9,9,0},
	{0,0,0,7,0,		0,0,0,0,0,		0,0,0,0,0 ,	9,9,9,9,9,	9,9,9,10,11,	10,9,9,9,9,	9,9,7},
	{0,0,0,13,0,	0,0,0,0,0,		0,0,0,0,0,	0,9,9,9,9,	9,9,9,9,10,		9,9,9,9,9,	9,9,0},
	{0,0,0,13,0,	0,0,0,0,0,		0,0,0,0,0,	0,0,9,9,9,	9,9,9,9,9,		9,9,9,9,9,	9,0,0},
	{0,0,0,13,0,	0,0,0,0,0,		0,0,0,0,0,	0,0,0,9,9,	9,9,9,9,9,		9,9,9,9,9,	0,0,0},
	{8,8,8,8,8,		8,8,8,8,8,		8,8,8,8,8,	0,0,0,0,9,	9,9,9,9,9,		9,9,9,9,0,	0,0,0},
	{0,3,0,0,5,		0,0,3,0,0,		0,5,0,0,0,	3,0,0,0,5,	0,0,0,0,3,		0,0,0,0,0,	3,0,0},
	{3,3,3,5,5,		5,3,3,3,0,		5,5,5,0,3,	3,3,0,5,5,	5,0,0,3,3,		3,0,0,0,3,	3,3,0},
	{0,4,5,5,5,		5,5,4,0,5,		5,5,5,5,0,	4,0,5,5,5,	5,5,0,0,4,		0,0,0,0,0,	4,0,0},
	{0,0,5,5,7,		5,5,0,0,5,		5,7,5,5,0,	0,0,5,5,7,	5,5,0,0,0,		0,0,0,0,0,	0,0,0},
	{0,0,0,0,0,		0,0,0,0,0,		0,0,0,0,0,	0,0,0,0,0,	0,0,0,0,0,		0,0,0,0,0,	0,0,0}

};
int map_3_temp[33][33] = {
	{0,0,0,0,0,		0,0,0,0,0,		0,0,0,0,0,	0,0,0,0,0,		0,0,0,0,0,			0,0,0,0,0,		0,0,0},
	{0,0,0,0,1,		1,0,0,0,0,		0,0,0,0,1,	1,0,0,0,0,		0,0,0,0,0,			0,0,1,1,0,		0,0,0},
	{0,0,0,1,1,		1,1,0,0,2,		0,0,0,1,1,	1,1,0,0,0,		0,0,2,0,0,			0,1,1,1,1,		0,0,0},
	{0,0,0,0,1,		1,0,0,0,0,		0,0,0,0,1,	1,0,0,0,0,		0,2,0,0,0,			0,0,1,1,0,		0,0,0},
	{0,3,0,0,5,		0,0,3,0,0,		0,5,0,0,0,	3,0,0,0,5,		0,0,0,0,3,			0,0,0,0,0,		3,0,0},
	{3,3,3,5,16,	5,3,3,3,0,		5,17,5,0,3,	3,3,0,5,18,		5,0,0,3,3,			3,0,0,0,3,		3,3,0},
	{0,4,5,5,0,		5,5,4,0,5,		5,5,5,5,0,	4,0,5,5,5,		5,5,0,0,4,			0,0,0,0,0,		4,0,0},
	{0,3,5,5,7,		5,5,3,0,5,		5,7,5,5,0,	0,0,5,5,7,		5,5,0,0,0,			0,0,0,0,0,		0,0,0},
	{3,3,3,0,0,		0,3,3,3,0,		0,0,0,0,6,	6,6,0,0,0,		0,0,19,19,19,		19,19,0,0,0,	0,0,0},
	{0,0,0,6,6,		6,0,0,0,6,		6,6,0,0,6,	6,0,0,0,0,		19,19,19,19,19,		19,19,19,0,0,	0,0,0},
	{8,8,8,8,8,		8,8,8,8,8,		8,8,8,8,8,	0,0,0,0,19,		19,19,19,19,19,		19,19,19,19,0,	0,0,0},
	{0,0,0,13,0,	0,0,0,0,0,		0,0,0,0,0,	0,0,0,19,19,	19,19,19,19,19,		19,19,19,19,19,	0,0,0},
	{0,0,0,13,0,	0,0,0,0,0,		0,0,0,0,0,	0,0,19,19,19,	19,19,19,19,19,		19,19,19,19,19,	19,0,0},
	{0,14,0,13,0,	0,0,0,0,0,		0,0,12,0,0,	0,19,19,19,19,	19,19,19,19,10,		19,19,19,19,19,	19,19,0},
	{0,0,0,7,0,		0,0,0,0,0,		0,0,0,0,0,	19,19,19,19,19,	19,19,19,10,11,		10,19,19,19,19,	19,19,7},
	{0,0,0,13,0,	0,0,0,0,0,		0,0,0,0,0,	0,19,19,19,19,	19,19,19,19,10,		19,19,19,19,19,	19,19,0},
	{0,0,0,13,0,	0,0,0,0,0,		0,0,0,0,0,	0,0,19,19,19,	19,19,19,19,19,		19,19,19,19,19,	19,0,0},
	{0,0,0,13,0,	0,0,0,0,0,		0,0,0,0,0,	0,0,0,19,19,	19,19,19,19,19,		19,19,19,19,19,	0,0,0},
	{8,8,8,8,8,		8,8,8,8,8,		8,8,8,8,8,	0,0,0,0,19,		19,19,19,19,19,		19,19,19,19,0,	0,0,0},
	{0,3,0,0,5,		0,0,3,0,0,		0,5,0,0,0,	3,0,0,0,5,		0,0,0,0,3,			0,0,0,0,0,		3,0,0},
	{3,3,3,5,5,		5,3,3,3,0,		5,5,5,0,3,	3,3,0,5,5,		5,0,0,3,3,			3,0,0,0,3,		3,3,0},
	{0,4,5,5,5,		5,5,4,0,5,		5,5,5,5,0,	4,0,5,5,5,		5,5,0,0,4,			0,0,0,0,0,		4,0,0},
	{0,0,5,5,7,		5,5,0,0,5,		5,7,5,5,0,	0,0,5,5,7,		5,5,0,0,0,			0,0,0,0,0,		0,0,0},
	{0,0,0,0,0,		0,0,0,0,0,		0,0,0,0,0,	0,0,0,0,0,		0,0,0,0,0,			0,0,0,0,0,		0,0,0}

};
int jianqimap[3][3] = {
	{0,2,0},
	{2,1,2},
	{0,2,0}
};
int MainGodGame(void) {

	settextstyle(0, 0, "����");

	cleardevice();
	wo_y = 380;//"��"����������
	wo_x = 190;
	wo_X = wo_x;
	wo_Y = wo_y;



	GodBarrierView();

	getchar();
	return 0;
}

//�ɽ�����ҳ��
void GodBarrierView() {

	space = 20;
	left_distance = 170;
	top_distance = 100;

	if (sign_begintext3 == 0) {
		PrintGodGame();
		outtextxy(wo_x, wo_y, "��");
		outtextxy(10, 10, "��һ�X�с��l�F�Լ���̎����.....");
		Sleep(1000);
		cleardevice();
		PrintGodGame();
		outtextxy(wo_x, wo_y, "��");
		outtextxy(10, 10, "��߅��һ�ф�......        ���� [ �ո� ] ʰȡ");
		Sleep(1000);
		sign_begintext3 = 1;
	}



	while (1)
	{
		cleardevice();

		BeginBatchDraw();//������ͼ�����濨��

		if (sign_ice == 0)
		{
			PrintGodGame();
		}

		else if (sign_ice == 1)
		{
			PrintSecondGodGame();
		}
		outtextxy(wo_x, wo_y, "��");

		EndBatchDraw();

		if (sign_ice == 0)
		{
			Move_3();
		}

		else if (sign_ice == 1)
		{
			Move_3_ice();
		}

	}
}

//-----------------------------------------------------------��������-------------------------------------------------------------//

void InformationOfGodBarrier() {

	//��
	if (GetAsyncKeyState(VK_SPACE) && wo_x == 190 && wo_y == 380)
	{
		mciSendString("open ����5.mp3 ", 0, 0, 0);
		mciSendString("play ����5.mp3 ", 0, 0, 0);
		outtextxy(10, 10, "�ң�������� �� ");
		map_3[13][1] = 0;
		map_3_temp[13][1] = 0;
		PrintGodGame();
	}

	//��
	if (GetAsyncKeyState(VK_SPACE) && wo_x == 410 && wo_y == 380)
	{
		outtextxy(10, 10, "�ɣ����ӣ���K춁������ҵ���þ���... ");
		Sleep(800);
		outtextxy(10, 30, "�@�e�ǡ��T���f�������ֺ�������Ŷ... ");
		Sleep(800);
		outtextxy(10, 50, "ȥ�ɣ�������������Ҫ�Ė|��... ");
		Sleep(1500);
		cleardevice();
		PrintGodGame();
		outtextxy(wo_x, wo_y, "��");
		outtextxy(10, 10, "��:�е����ɻ�......��߀�ǛQ��ȥ���� ");
		Sleep(1000);
	}

	//ʯͷ
	if (GetAsyncKeyState(VK_SPACE) &&
		wo_x >= 210 && wo_y >= 320 &&
		wo_x <= 250 && wo_y <= 360)
	{
		outtextxy(10, 10, "�@����ͨ��ʯ�^...... ");

		PrintGodGame();
	}
	if (GetAsyncKeyState(VK_SPACE) &&
		wo_x >= 210 && wo_y >= 400 &&
		wo_x <= 250 && wo_y <= 440)
	{
		outtextxy(10, 10, "�@����ͨ��ʯ�^...... ");

		PrintGodGame();
	}

	//��
	if (GetAsyncKeyState(VK_SPACE) && wo_x == 250 && wo_y == 220)
	{
		mciSendString("open ����6.mp3 ", 0, 0, 0);
		mciSendString("play ����6.mp3 ", 0, 0, 0);
		outtextxy(10, 10, "������� ��");
		map_3[5][4] = 0;
		map_3_temp[5][4] = 0;
		PrintGodGame();
		sign_twowater = 1;
	}

	//���
	if (sign_twowater == 1 &&
		GetAsyncKeyState(VK_SPACE) &&
		wo_x >= 450 && wo_y <= 460 &&
		wo_x <= 590 && wo_y >= 260)
	{
		sign_ice = 1;
		printf("����������");
		PrintSecondGodGame();
		outtextxy(wo_x, wo_y, "��");
		Sleep(800);
		outtextxy(10, 10, "�ң��øղŻ�õġ�������ǰ��ġ�ˮ����ϣ���Ȼ��ˮ����˱���������ɽ��� ");
		PrintSecondGodGame();
	}

	//����
	if (GetAsyncKeyState(VK_SPACE) &&
		wo_x >= 610 && wo_y <= 420 &&
		wo_x <= 690 && wo_y >= 340)
	{
		sign_keytext = 1;
		PrintSecondGodGame();
		outtextxy(wo_x, wo_y, "��");
	}

	//ɾ �� ��
	if (GetAsyncKeyState(VK_BACK) &&
		wo_x == 370 && wo_y == 60)
	{
		mciSendString("open ɾ2.mp3 ", 0, 0, 0); //�Ų�����
		mciSendString("play ɾ2.mp3 ", 0, 0, 0);
		sign_keytext2 = 1; //����ɾ����������ʧ

		cleardevice();
		PrintSecondGodGame();
		outtextxy(wo_x, wo_y, "��");
		rectangle(12, 44, 552, 67); //����
		mciSendString("open ����4.mp3 ", 0, 0, 0);
		mciSendString("play ����4.mp3 ", 0, 0, 0);
		Sleep(1000);


		sign_keytext = 0;
		cleardevice();
		PrintSecondGodGame();
		outtextxy(10, 10, "�ɣ����p�ˣ���ϲ���������g�� ");
		Sleep(1000);
		outtextxy(10, 30, "�F�����ħ�M�У��������`�T̿��������...... ");
		Sleep(1000);
		outtextxy(10, 50, "���x������ħ�����n����������[��ɽ��֮�У���������...");
		Sleep(1000);
		outtextxy(10, 70, "һ���x��K��ȡ�Q���...���ӣ��ۂ��о��ٕ�...");
		outtextxy(810, 380, "��");
		outtextxy(850, 380, "��ϲ�㴳�سɹ���");
		Sleep(2000);


		CommonPassView();

	}



}

//�ƶ�����
void Move_3()
{

	InformationOfGodBarrier();

	char key = _getch();

	switch (key)
	{
	case 72:  //����ASCII
	case 'w':
	case 'W':
		//�ж�"��"��������������Ԫ�ص�ֵ(�����������ʾ)�������0������ƶ������򲻶�
		if (map_3[(wo_y - space - top_distance) / space][(wo_x - left_distance) / space] == 0 ||
			map_3[(wo_y - space - top_distance) / space][(wo_x - left_distance) / space] == 7 ||
			map_3[(wo_y - space - top_distance) / space][(wo_x - left_distance) / space] == 19 ||
			map_3[(wo_y - space - top_distance) / space][(wo_x - left_distance) / space] == 6)
		{
			wo_Y -= space;
			wo_y = wo_Y;
		}
		else;
		break;

	case 80:
	case 's':
	case 'S':
		if (map_3[(wo_y + space - top_distance) / space][(wo_x - left_distance) / space] == 0 ||
			map_3[(wo_y + space - top_distance) / space][(wo_x - left_distance) / space] == 7 ||
			map_3[(wo_y + space - top_distance) / space][(wo_x - left_distance) / space] == 19 ||
			map_3[(wo_y + space - top_distance) / space][(wo_x - left_distance) / space] == 6)
		{
			wo_Y += space;
			wo_y = wo_Y;
		}
		else;
		break;

	case 77:
	case 'd':
	case 'D':
		if (map_3[(wo_y - top_distance) / space][(wo_x + space - left_distance) / space] == 0 ||
			map_3[(wo_y - top_distance) / space][(wo_x + space - left_distance) / space] == 7 ||
			map_3[(wo_y - top_distance) / space][(wo_x + space - left_distance) / space] == 19 ||
			map_3[(wo_y - top_distance) / space][(wo_x + space - left_distance) / space] == 6)
		{
			wo_X += space;
			wo_x = wo_X;
		}
		else;
		break;

	case 75:
	case 'a':
	case 'A':
		if (map_3[(wo_y - top_distance) / space][(wo_x - space - left_distance) / space] == 0 ||
			map_3[(wo_y - top_distance) / space][(wo_x - space - left_distance) / space] == 7 ||
			map_3[(wo_y - top_distance) / space][(wo_x - space - left_distance) / space] == 19 ||
			map_3[(wo_y - top_distance) / space][(wo_x - space - left_distance) / space] == 6)
		{
			wo_X -= space;
			wo_x = wo_X;
		}
		else;
		break;
	}
}

void Move_3_ice() {

	InformationOfGodBarrier();

	char key = _getch();

	switch (key)
	{
	case 72:  //����ASCII
	case 'w':
	case 'W':
		//�ж�"��"��������������Ԫ�ص�ֵ(�����������ʾ)�������0������ƶ������򲻶�
		if (map_3_temp[(wo_y - space - top_distance) / space][(wo_x - left_distance) / space] == 0 ||
			map_3_temp[(wo_y - space - top_distance) / space][(wo_x - left_distance) / space] == 7 ||
			map_3_temp[(wo_y - space - top_distance) / space][(wo_x - left_distance) / space] == 19 ||
			map_3_temp[(wo_y - space - top_distance) / space][(wo_x - left_distance) / space] == 6)
		{
			wo_Y -= space;
			wo_y = wo_Y;
		}
		else;
		break;

	case 80:
	case 's':
	case 'S':
		if (map_3_temp[(wo_y + space - top_distance) / space][(wo_x - left_distance) / space] == 0 ||
			map_3_temp[(wo_y + space - top_distance) / space][(wo_x - left_distance) / space] == 7 ||
			map_3_temp[(wo_y + space - top_distance) / space][(wo_x - left_distance) / space] == 19 ||
			map_3_temp[(wo_y + space - top_distance) / space][(wo_x - left_distance) / space] == 6)
		{
			wo_Y += space;
			wo_y = wo_Y;
		}
		else;
		break;

	case 77:
	case 'd':
	case 'D':
		if (map_3_temp[(wo_y - top_distance) / space][(wo_x + space - left_distance) / space] == 0 ||
			map_3_temp[(wo_y - top_distance) / space][(wo_x + space - left_distance) / space] == 7 ||
			map_3_temp[(wo_y - top_distance) / space][(wo_x + space - left_distance) / space] == 19 ||
			map_3_temp[(wo_y - top_distance) / space][(wo_x + space - left_distance) / space] == 6)
		{
			wo_X += space;
			wo_x = wo_X;
		}
		else;
		break;

	case 75:
	case 'a':
	case 'A':
		if (map_3_temp[(wo_y - top_distance) / space][(wo_x - space - left_distance) / space] == 0 ||
			map_3_temp[(wo_y - top_distance) / space][(wo_x - space - left_distance) / space] == 7 ||
			map_3_temp[(wo_y - top_distance) / space][(wo_x - space - left_distance) / space] == 19 ||
			map_3_temp[(wo_y - top_distance) / space][(wo_x - space - left_distance) / space] == 6)
		{
			wo_X -= space;
			wo_x = wo_X;
		}
		else;
		break;
	}
}

void PrintGodGame()
{
	for (int i = 0; i < 33; i++)
	{
		for (int j = 0; j < 33; j++)
		{
			int word_x = left_distance + j * space;
			int word_y = top_distance + i * space;

			switch (map_3[i][j])

			{
			case 1:outtextxy(word_x, word_y, "��"); break;
			case 2:outtextxy(word_x, word_y, "��"); break;
			case 3:outtextxy(word_x, word_y, "��"); break;
			case 4:outtextxy(word_x, word_y, "ľ"); break;
			case 5:outtextxy(word_x, word_y, "��"); break;
			case 6:outtextxy(word_x, word_y, "��"); break;
			case 7:outtextxy(word_x, word_y, "��"); break;
			case 8:outtextxy(word_x, word_y, "·"); break;
			case 9:outtextxy(word_x, word_y, "ˮ"); break;
			case 10:outtextxy(word_x, word_y, "��"); break;
			case 11:outtextxy(word_x, word_y, "��"); break;
			case 12:outtextxy(word_x, word_y, "��"); break;
			case 13:outtextxy(word_x, word_y, "ʯ"); break;
			case 14:outtextxy(word_x, word_y, "��"); break;
			case 16:outtextxy(word_x, word_y, "��"); break;
			case 17:outtextxy(word_x, word_y, "��"); break;
			case 18:outtextxy(word_x, word_y, "׳"); break;
			case 19:outtextxy(word_x, word_y, "��"); break;
			}
		}
	}
}

void PrintSecondGodGame() {
	for (int i = 0; i < 33; i++) {
		for (int j = 0; j < 33; j++) {

			int word_x = left_distance + j * space;
			int word_y = top_distance + i * space;

			switch (map_3_temp[i][j]) {
			case 0:outtextxy(word_x, word_y, '\0'); break;
			case 1:outtextxy(word_x, word_y, "��"); break;
			case 2:outtextxy(word_x, word_y, "��"); break;
			case 3:outtextxy(word_x, word_y, "��"); break;
			case 4:outtextxy(word_x, word_y, "ľ"); break;
			case 5:outtextxy(word_x, word_y, "��");	break;
			case 6:outtextxy(word_x, word_y, "��"); break;
			case 7:outtextxy(word_x, word_y, "��"); break;
			case 8:outtextxy(word_x, word_y, "·"); break;
			case 9:outtextxy(word_x, word_y, "ˮ"); break;
			case 10:outtextxy(word_x, word_y, "��"); break;
			case 11:outtextxy(word_x, word_y, "��"); break;
			case 12:outtextxy(word_x, word_y, "��"); break;
			case 13:outtextxy(word_x, word_y, "ʯ"); break;
			case 14:outtextxy(word_x, word_y, "��"); break;
			case 16:outtextxy(word_x, word_y, "��");	break;
			case 17:outtextxy(word_x, word_y, "��"); break;
			case 18:outtextxy(word_x, word_y, "׳"); break;
			case 19:outtextxy(word_x, word_y, "��"); break;
			}
		}
	}

	if (sign_keytext == 1)
	{
		outtextxy(10, 3, "�@��һ�����书�ؼ���������ӛ�d��һ�ׄ���......");
		if (sign_1 == 0) { Sleep(1000); }
		outtextxy(10, 23, "�ڴ��_�ؼ���ͬ�r�������ҵ����ܱP���������M�����ҵ��w��...... ");
		if (sign_1 == 0) { Sleep(1000); }
		outtextxy(10, 43, "ͬ�r�е�һ�ɏ�����������w�����ӣ���  ���������@������...... ");

		if (sign_keytext2 == 0) //����ɾ����֮��Ͳ�����ʾ �� ��
		{
			outtextxy(298, 43, "��");
		}
		else /*{ Sleep(1000); cleardevice(); }*/;

		sign_1 = 1;
	}
}

void SwordView() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			switch (jianqimap[j][i]) {
			case 0:outtextxy(400 + j * 30, 30 + i * 30, "\0");
				break;
			case 2:outtextxy(400 + j * 30, 300 + i * 30, "��");
				break;
			case 1:outtextxy(400 + j * 30, 300 + i * 30, "��");
				break;
			}
		}
	}
}