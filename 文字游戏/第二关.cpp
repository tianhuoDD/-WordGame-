#include "��������.h" //��������

//�ڶ��ء�����������������������������������������������������������
//��־����
int sign_secondbarrier = 0; //��һ�ν�����ˮ��ʱ��ʾ�԰�
int sign_begintext = 0; //��־�����Ϊ1���ӡ��һ�ν���ڶ���ʱ��ʼ��Ϸ���ı�
//int sign_rect = 0;
int sign_information = 0; //���Ϊ1��������ʽ������һ��
int sign_openlock = 0;
int  map_second[12][21] = {
	{1,1,1,1,1, 1,1,1,1,1, 1,1,10,1,1, 1,1,1,1,1 ,1},
	{1,1,0,0,0, 0,0,0,0,0, 0,3,4,3,0, 0,0,0,0,1, 1},
	{1,1,0,0,0, 0,0,0,0,0, 0,3,0,3,0, 0,0,0,0,1, 1},
	{1,1,0,0,0, 0,0,0,0,0, 0,3,0,3,0, 0,0,0,0,1, 1},
	{1,1,0,0,3, 3,3,3,3,3, 3,3,0,3,3, 3,3,3,3,3, 3},
	{91,91,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,94,0,0,0, 91},
	{1,1,0,0,3, 3,3,3,3,3, 3,3,0,3,3, 3,3,3,3,3, 3},
	{1,1,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,1, 1},
	{1,1,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,1, 1},
	{1,1,0,0,0, 0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,1, 1},
	{1,1,5,5,5, 5,5,5,5,5, 5,5,5,5,5, 5,5,5,5,1, 1},
	{1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1,1,1,1,1, 1},
};

int MainSecondBarrier()
{


	settextstyle(25, 0, "Zpix");

	SecondBarrierView();

	getchar();
	return 0;
}
//�ڶ�����ҳ��
void SecondBarrierView()
{

	sign_barrier_number = 2;
	left_distance = 40;
	top_distance = 170;
	wo_x = left_distance + space * 2;
	wo_y = top_distance + space * 5;
	wo_X = wo_x;
	wo_Y = wo_y;

	while (1)
	{
		cleardevice();

		BeginBatchDraw();

		PrintSecondGame();
		outtextxy(wo_x, wo_y, "��");

		EndBatchDraw();

		Move2();
	}
}

//-------------------------------4.��������-----------------------------------------//
//�ڶ��� ��Ϣ����
void InformationOfSecondBarrier()
{

	settextstyle(25, 0, "Zpix");

	//��һ�ν���ڶ��صĶ԰�
	if (sign_secondbarrier == 0)
	{
		sign_begintext = 1; //��ӡ��ʼ��Ϸ���ı�
		sign_secondbarrier = 1; //�ӵڶ��ν���ڶ��ؾͲ�����ʾ����ı���
		Sleep(500);
		PrintSecondGame();
	}

	if (wo_x == 550 &&		//����ߵ��˿�ʼ��Ϸ�ı���ȱλ�ð��¿ո�
		wo_y == 380 &&
		GetAsyncKeyState(VK_SPACE))
	{

		mciSendString("open ����3.mp3 ", 0, 0, 0);
		mciSendString("play ����3.mp3 ", 0, 0, 0);

		rectangle(158, 378, 608, 438); //���ַ���

		//sign_rect = 1;
		sign_begintext = 0; //�ߵ�����ȱλ�ð��¿ո��Ͳ��ٴ�ӡ��һ�ν���ڶ��صĶ԰�
		sign_information = 1;
		PrintSecondGame();
	}

	//��
	if (sign_information == 1 &&
		wo_x == left_distance + 12 * space &&
		wo_y == top_distance + 2 * space &&
		GetAsyncKeyState(VK_SPACE))
	{
		if (tool_key == 0) { outtextxy(10, 10, "��������������������..."); }
		if (tool_key == 1) //��������Կ��
		{
			//�ɹ�
			mciSendString("open ��ɢ����.mp3 ", 0, 0, 0);
			mciSendString("play ��ɢ����.mp3 ", 0, 0, 0);

			sign_openlock = 1; //���� �� �ı�־
			map_second[1][12] = 0; //��������ɾ������
			map_second[5][16] = 0; //��������ɾ������

			cleardevice();
			outtextxy(10, 10, "ϸ����ķ�͸���ŷ�Ѷ�������������ȥ��...");
			outtextxy(wo_x, wo_y, "��");
			PrintSecondGame();
			Sleep(300);

		}
	}

	//��
	if (sign_information == 1 && sign_openlock != 1 &&
		wo_x >= left_distance + 13 * space && wo_x <= left_distance + 15 * space &&
		wo_y == top_distance + 5 * space)
	{
		BeginBatchDraw();
		outtextxy(10, 10, "�ô̱����ŵĶ�����ֱ������ȥ���ܻ��ж�������...");
		EndBatchDraw();
	}

	//���û�д������ߵ� �� ��λ��
	if (sign_openlock == 0 &&
		wo_x == left_distance + 16 * space &&
		wo_y == top_distance + 5 * space)
	{
		DeathView();
	}

	if (sign_information == 1 &&
		wo_x == left_distance + 19 * space
		&& wo_y == top_distance + 5 * space
		&& GetAsyncKeyState(VK_SPACE))
	{
		outtextxy(290, 100, "������һ��");
	}

	//���ص�һ��
	if (
		wo_x == left_distance + 0 * space
		&& wo_y == top_distance + 5 * space)
	{
		FirstGameService();
	}

	//ͨ����ת����
	if (
		wo_x == left_distance + 20 * space
		&& wo_y == top_distance + 5 * space)
	{
		SuccessSkipView();
	}

}

//�ڶ��� �ƶ�
void Move2() {

	InformationOfSecondBarrier();

	char key = _getch();

	switch (key) {
	case 72:  //����ASCII
	case 'w':
	case 'W':
		//�ж�"��"��������������Ԫ�ص�ֵ(�����������ʾ)�������0������ƶ������򲻶�
		if (map_second[(wo_y - space - top_distance) / space][(wo_x - left_distance) / space] == 0 ||
			map_second[(wo_y - space - top_distance) / space][(wo_x - left_distance) / space] == 93 ||
			map_second[(wo_y - space - top_distance) / space][(wo_x - left_distance) / space] == 91 ||
			map_second[(wo_y - space - top_distance) / space][(wo_x - left_distance) / space] == 94)
		{

			wo_Y -= space;
			wo_y = wo_Y;
		}
		else;
		break;

	case 80:
	case 's':
	case 'S':
		if (map_second[(wo_y + space - top_distance) / space][(wo_x - left_distance) / space] == 0 ||
			map_second[(wo_y + space - top_distance) / space][(wo_x - left_distance) / space] == 93 ||
			map_second[(wo_y + space - top_distance) / space][(wo_x - left_distance) / space] == 91 ||
			map_second[(wo_y + space - top_distance) / space][(wo_x - left_distance) / space] == 94)
		{
			wo_Y += space;
			wo_y = wo_Y;
		}
		else;
		break;

	case 77:
	case 'd':
	case 'D':
		if (map_second[(wo_y - top_distance) / space][(wo_x + space - left_distance) / space] == 0 ||
			map_second[(wo_y - top_distance) / space][(wo_x + space - left_distance) / space] == 93 ||
			map_second[(wo_y - top_distance) / space][(wo_x + space - left_distance) / space] == 91 ||
			map_second[(wo_y - top_distance) / space][(wo_x + space - left_distance) / space] == 94)
		{
			wo_X += space;
			wo_x = wo_X;
		}
		else;
		break;

	case 75:
	case 'a':
	case 'A':
		if (map_second[(wo_y - top_distance) / space][(wo_x - space - left_distance) / space] == 0 ||
			map_second[(wo_y - top_distance) / space][(wo_x - space - left_distance) / space] == 93 ||
			map_second[(wo_y - top_distance) / space][(wo_x - space - left_distance) / space] == 91 ||
			map_second[(wo_y - top_distance) / space][(wo_x - space - left_distance) / space] == 94)
		{
			wo_X -= space;
			wo_x = wo_X;
		}
		else;
		break;

	case VK_ESCAPE:
		/*	delete_temp = 1;*/
		PauseView();
		break;
	}


}

//ͼ�񡪡���ӡ�ڶ��ص�ͼ
void PrintSecondGame(void)
{
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 21; j++) {

			int word_x = left_distance + j * space;
			int word_y = top_distance + i * space;

			switch (map_second[i][j])
			{
			case 1: outtextxy(word_x, word_y, "ǽ"); break;
			case 2: outtextxy(word_x, word_y, "��"); break;
			case 3: outtextxy(word_x, word_y, "��"); break;
			case 4: outtextxy(word_x, word_y, "��");	break;
			case 5: outtextxy(word_x, word_y, "ˮ");	break;
			case 93: outtextxy(word_x, word_y, "��"); break;
			case 91: outtextxy(word_x, word_y, "��"); break;
			case 94: outtextxy(word_x, word_y, "��");	break;
			case 9: outtextxy(word_x, word_y, "��"); break;
			case 10: outtextxy(word_x, word_y, "��"); break;
			default:break;
			}
		}
	}

	if (tool_wood == 1) { outtextxy(bag_x + 90 - textwidth("ľ��") / 2, bag_y + 60, "ľ��"); }
	if (tool_knife == 1) { outtextxy(bag_x + 90 - textwidth("ʯ�⵶") / 2, bag_y + 100, "ʯ�⵶"); }
	if (tool_torch == 1) { outtextxy(bag_x + 90 - textwidth("���") / 2, bag_y + 140, "���"); }
	if (tool_key == 1) { outtextxy(bag_x + 90 - textwidth("Կ��") / 2, bag_y + 180, "Կ��"); }
	if (sign_begintext == 1)
	{

		outtextxy(left_distance + 4 * space, top_distance + 7 * space, "����������ˮ����ӭ��һ�ɳ���,     Ҫ");
		outtextxy(left_distance + 4 * space, top_distance + 8 * space, "����뿪���");
	}

	ESC();
	Bag();
}