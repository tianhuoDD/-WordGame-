#include "��������.h" //��������
//��һ�ء�����������������������������������������������������������
int space = 30;//���ּ��
int left_distance;//��ͼ�봰�����߾�//����һ���ֵ�x����
int top_distance;//��ͼ�봰�ڶ��˱߾�//����һ���ֵ�y����
int wo_y, wo_x;//"��"����������
int wo_X, wo_Y;//����ֵ����������������=��������
int pause_graph_x = 760, pause_graph_y = 35;
int bag_x = 720, bag_y = 250;
//�����Ƿ��������һ�أ�ɾ������
int delete_temp = 1;
//�ؿ���־
int sign_barrier_number;
//��һ�� ̽��˳��ı�־
int sign_case = 0;
int sign_light = 0;
int sign_text = 0;
int sign_painting = 0;
//��һ�� ��ӡ���ߵı�־
int tool_wood = 0,
tool_knife = 0,
tool_key = 0,
tool_torch = 0;
//��һ�� �����־
int sign_rectangle = 0;
int sign_get = 0;
//��һ�� ��ͼ��ȫ�֣�
int map[13][21] = {
	{0,0,0,0,0,		0,0,0,10,11,	0,0,0,0,0,	0,0,0,0,0},
	{1,1,1,1,1,		1,1,1,1,1,		1,1,1,1,1,	1,1,1,1,1,	1},
	{1,1,0,0,0,		0,0,0,0,7,		0,0,0,0,0,	0,0,0,0,1,	1},
	{1,1,0,0,0,		0,0,0,0,0,		0,0,0,0,0,	0,0,0,0,1,	1},
	{1,1,0,0,0,		0,0,0,0,0,		0,0,0,0,0,	0,0,0,0,1,	1},
	{1,1,0,0,0,		0,0,0,0,0,		0,0,0,0,0,	0,0,0,0,1,	1},
	{8,8,5,0,0,		0,0,0,0,0,		0,0,0,0,0,	0,0,0,3,90,	91},
	{8,8,5,0,0,		0,0,0,0,0,		0,0,0,0,0,	0,0,0,0,1,	1},
	{1,1,0,0,0,		0,0,0,0,0,		0,0,0,0,0,	0,0,0,0,1,	1},
	{1,1,0,0,0,		0,0,0,0,0,		0,0,0,0,0,	0,0,4,4,1,	1},
	{1,1,0,0,0,		0,0,0,0,0,		0,0,0,6,6,	0,0,4,4,1,	1},
	{1,1,0,0,0,		0,0,0,0,0,		0,0,0,6,6,	0,0,4,4,1,	1},
	{1,1,1,1,1,		1,1,1,1,1,		1,1,1,1,1,	1,1,1,1,1,	1},
};

//��һ����ҳ��
void FirstGameService() {

	sign_barrier_number = 1;
	left_distance = 40;
	top_distance = 170;
	wo_x = left_distance + space * 16;
	wo_y = top_distance + space * 9;
	wo_X = wo_x;
	wo_Y = wo_y;

	while (1)
	{
		cleardevice();

		BeginBatchDraw();//������ͼ�����濨��

		PrintFirstMap(); //3 ��ӡ��һ�ص�ͼ
		outtextxy(wo_x, wo_y, "��");

		EndBatchDraw();

		Move1();
	}
}

//--------------------------------4.��������----------------------------------------//

//ͼ�񡪡���ӡ��ͣ��ť
void ESC() {
	settextstyle(25, 0, "Zpix");
	char text[50] = "ESC";
	outtextxy(pause_graph_x + 80 / 2 - textwidth(text) / 2, pause_graph_y + 40 / 2 - textheight(text) / 2, text);//���־���
	roundrect(pause_graph_x, pause_graph_y, pause_graph_x + 80, pause_graph_y + 40, 15, 15);
}

//ͼ�񡪡���ӡ����
void Bag() {
	settextstyle(25, 0, "Zpix");
	char text[50] = "������";
	outtextxy(bag_x + 90 - textwidth(text) / 2, bag_y + 10, text);//���־���
	roundrect(bag_x, bag_y, bag_x + 180/*ֱ�Ӽ��Ϸ���Ŀ��*/, bag_y + 250, 20, 20);
}

//�ı�����
void InformationOfFirstBarrier()
{
	settextstyle(25, 0, "Zpix");

	//�ж�"��"���ڵ�λ�ã�����������Χ���Ұ�ĳ�������ض�λ������ı�

	//��
	if (wo_x >= left_distance + space * 8 && wo_x <= left_distance + space * 10 &&
		wo_y >= top_distance + space * 2 && wo_y <= top_distance + space * 3 &&
		GetAsyncKeyState(VK_SPACE))
	{
		if (sign_case == 0) { outtextxy(10, 10, "ҡҷ�ĵƻ���������Ʈ������..."); } //û��̽��������
		else if (sign_case == 1)																//̽��������
		{



			outtextxy(10, 10, "��С�İ�Сľ�������ƻ�����ػ��һ�����...");

			sign_case = 2;
			sign_light = 1;		//��û��
			tool_torch = 1;		//������ʾ���
			tool_wood = 0;		//����ȡ����ʾľͷ

			//cleardevice();
			PrintFirstMap;
			outtextxy(wo_x, wo_y, "��");
		}
		else if (sign_light == 1) { outtextxy(10, 10, "�õ���Ѻ󣬵ƻ��ƺ�������..."); } //̽�������ӣ�̽�����ƻ�
	}

	//��
	else if (wo_x >= left_distance + space * 17 && wo_x <= left_distance + space * 18 &&
		wo_y >= top_distance + space * 5 && wo_y <= top_distance + space * 7 &&
		GetAsyncKeyState(VK_SPACE)) {
		if (sign_painting == 0)
		{
			outtextxy(10, 10, "�ƺ�ûʲô�ر�֮���Ļ�����������Ĭ���ҹ������...");
		}
		else;
	}

	//��
	else if (wo_x >= left_distance + space * 16 && wo_x <= left_distance + space * 18 &&
		wo_y >= top_distance + space * 8 && wo_y <= top_distance + space * 11 &&
		GetAsyncKeyState(VK_SPACE)
		) {
		outtextxy(10, 10, "ÿ���ڼ�Ӳ�Ĵ�������˯�����Ҽᶨ�˸���֮��...");
	}

	//��
	else if (wo_x >= left_distance + space * 2 && wo_x <= left_distance + space * 3 &&
		wo_y >= top_distance + space * 5 && wo_y <= top_distance + space * 8 &&
		GetAsyncKeyState(VK_SPACE)
		) {
		outtextxy(10, 10, "�ű�������ס���޷���...");
	}

	//��
	else if (wo_x == left_distance + space * 19 &&
		wo_y == top_distance + space * 8 &&
		GetAsyncKeyState(VK_SPACE) && map[6][20] == 0)
	{
		outtextxy(10, 10, "���ĺ�����ˮ��...");
	}

	//ɾ�� ��
	else if (GetAsyncKeyState(VK_BACK) && wo_x == 370 && wo_y == 440)
	{
		//�ɹ�
		mciSendString("open ɾ.mp3 ", 0, 0, 0);
		mciSendString("play ɾ.mp3 ", 0, 0, 0);

		map[8][11] = 0;
		cleardevice();
		outtextxy(wo_x, wo_y, "��");
		PrintFirstMap();
	}

	//��
	else if (wo_x >= left_distance + space * 12 && wo_x <= left_distance + space * 15 &&
		wo_y >= top_distance + space * 9 && wo_y <= top_distance + space * 11 &&
		GetAsyncKeyState(VK_SPACE)
		)
	{
		if (sign_case == 0) //���û̽��������
		{
			outtextxy(10, 10, "���һ��'ʯ�⵶'��һС��ľ����ʯ��������ҹ��ĥ����...");
			tool_wood = 1;
			tool_knife = 1;
			sign_case = 1;
			PrintFirstMap();
		}
		else if (sign_case == 1 && sign_light == 0) //̽�������ӣ�û̽���ƻ�
		{
			outtextxy(10, 10, "�ղ���������һ��'ʯ�⵶'��һС��ľ��������ûʲô������...");

		}
		else if (sign_light == 1 && sign_rectangle == 0) //̽�����ƻ�û�д���������
		{
			//�ɹ�
			mciSendString("open ��ȼ.mp3 ", 0, 0, 0);
			mciSendString("play ��ȼ.mp3 ", 0, 0, 0);
			//mciSendString(" ��ȼ.mp3 ", 0, 0, 0);

			Sleep(1000);

			outtextxy(10, 10, "�㲻С���û��ȼһ����ǣ�����������������");
			settextstyle(25, 0, "Zpix");

			map[10][3] = 20; // ���ֳ���
			//��������������ʱ��˵�ĶԻ��ı�
			map[8][3] = 21;
			map[8][4] = 37;
			map[8][5] = 24;
			map[8][6] = 25;
			map[8][7] = 26;
			map[8][8] = 27;
			map[8][9] = 28;
			map[8][10] = 29;
			map[8][11] = 30;
			map[8][12] = 31;
			map[8][13] = 32;
			map[8][14] = 33;
			map[8][15] = 34;
			map[8][16] = 35;
			map[8][17] = 36;

			tool_torch = 0;

			sign_rectangle = 1; //��if���ֻ����һ��
			PrintFirstMap(); //�����ﰴ��һ�οո�����������ı��ͳ�����
		}

		else if (sign_case == 2) //̽�������ӣ�û̽���ƻ�
		{
			outtextxy(10, 10, "��ª�Ĺ������Ѿ�ʲôҲû����...");
		}
	}

	//���ַ���
	else if (wo_x == 370 && wo_y == 410 && GetAsyncKeyState(VK_SPACE) && sign_rectangle == 1)
	{
		sign_rectangle = 2; //��ʱ���ܴ���"�㲻С���û��ȼһ����ǣ�����������������"
		sign_get = 1;
		rectangle(120, 400, 580, 440);

		//ʧ��
		mciSendString("open ɱ��2.mp3 ", 0, 0, 0);
		mciSendString("play ɱ��2.mp3 ", 0, 0, 0);

		outtextxy(10, 10, "������ɱ���������������Ϻ������һ��Կ��...");
		//Sleep(500);

		map[8][3] = 0;
		map[8][4] = 0;
		map[8][5] = 0;
		map[8][6] = 0;
		map[8][7] = 0;
		map[8][8] = 0;
		map[8][9] = 0;
		map[8][10] = 0;
		map[8][11] = 0;
		map[8][12] = 0;
		map[8][13] = 0;
		map[8][14] = 0;
		map[8][15] = 0;
		map[8][16] = 0;
		map[8][17] = 0;

		map[10][3] = 38;
		PrintFirstMap();

	}

	else if (GetAsyncKeyState(VK_SPACE) && wo_x == 160 && wo_y == 470 && sign_get == 1)
	{

		//ʧ��
		mciSendString("open �����Ʒ.mp3 ", 0, 0, 0);
		mciSendString("play �����Ʒ.mp3 ", 0, 0, 0);

		sign_get = 0;
		tool_key = 1;
		map[10][3] = 0;
		cleardevice();
		//outtextxy(10, 10, "���һ��Կ�ף�������ͳ�ͨ������...");
		outtextxy(10, 10, "���һ��Կ�ף�������ͳ�ͨ������...");
		outtextxy(wo_x, wo_y, "��");
		PrintFirstMap();
	}

	else if (wo_x == 640 && wo_y == 350)
	{

		cleardevice();
		outtextxy(wo_x, wo_y, "��");
		MainSecondBarrier();

	}
}
//�ƶ�����
void Move1() {

	InformationOfFirstBarrier();

	char key = _getch();

	switch (key) {
	case 72:  //����ASCII
	case 'w':
	case 'W':
		//�ж�"��"��������������Ԫ�ص�ֵ(�����������ʾ)�������0������ƶ������򲻶�
		if (map[(wo_y - space - top_distance) / space][(wo_x - left_distance) / space] == 0 ||
			map[(wo_y - space - top_distance) / space][(wo_x - left_distance) / space] == 90 ||
			map[(wo_y - space - top_distance) / space][(wo_x - left_distance) / space] == 91)
		{
			wo_Y -= space;
			wo_y = wo_Y;
		}
		else;
		break;

	case 80:
	case 's':
	case 'S':
		if (map[(wo_y + space - top_distance) / space][(wo_x - left_distance) / space] == 0 ||
			map[(wo_y + space - top_distance) / space][(wo_x - left_distance) / space] == 90 ||
			map[(wo_y + space - top_distance) / space][(wo_x - left_distance) / space] == 91)
		{
			wo_Y += space;
			wo_y = wo_Y;
		}
		else;
		break;

	case 77:
	case 'd':
	case 'D':
		if (map[(wo_y - top_distance) / space][(wo_x + space - left_distance) / space] == 0 ||
			map[(wo_y - top_distance) / space][(wo_x + space - left_distance) / space] == 90 ||
			map[(wo_y - top_distance) / space][(wo_x + space - left_distance) / space] == 91)
		{
			wo_X += space;
			wo_x = wo_X;
		}
		else;
		break;

	case 75:
	case 'a':
	case 'A':
		if (map[(wo_y - top_distance) / space][(wo_x - space - left_distance) / space] == 0 ||
			map[(wo_y - top_distance) / space][(wo_x - space - left_distance) / space] == 90 ||
			map[(wo_y - top_distance) / space][(wo_x - space - left_distance) / space] == 91)
		{
			wo_X -= space;
			wo_x = wo_X;
		}
		else;
		break;

	case VK_ESCAPE:
		//delete_temp = 1;
		PauseView();
		break;
	}


}

//��ӡ��һ�ص�ͼ
void PrintFirstMap()
{
	for (int i = 0; i < 13; ++i) {
		for (int j = 0; j < 21; ++j) {

			int word_x = left_distance + j * space;
			int word_y = top_distance + i * space;

			switch (map[i][j]) {
			case 1:outtextxy(word_x, word_y, "ǽ"); break;

			case 3:
				if (wo_x >= left_distance + space * 17 && wo_x <= left_distance + space * 18 &&
					wo_y >= top_distance + space * 5 && wo_y <= top_distance + space * 7 &&
					GetAsyncKeyState(VK_BACK))		//ɾ�� ��
				{
					mciSendString("open ɱ��1.mp3 ", 0, 0, 0);
					mciSendString("play ɱ��1.mp3 ", 0, 0, 0);
					delete_temp = 2;
					sign_painting = 1;
					map[6][18] = 0;//���ٵ�·
				}

				if (delete_temp == 1)
				{
					outtextxy(word_x, word_y, "��");
				}
				else;
				break;
			case 4:outtextxy(word_x, word_y, "��"); break;
			case 5:outtextxy(word_x, word_y, "��"); break;
			case 6:outtextxy(word_x, word_y, "��"); break;
			case 7:outtextxy(word_x, word_y, "��"); break;
			case 8:outtextxy(word_x, word_y, "��"); break;
			case 9:outtextxy(word_x, word_y, "��"); break;
			case 10:outtextxy(word_x, word_y, "��"); break;
			case 11:outtextxy(word_x, word_y, "��"); break;
			case 91:outtextxy(word_x, word_y, "��"); break;
			case 20:outtextxy(word_x, word_y, "��"); break;
			case 21:outtextxy(word_x, word_y, "��"); break;
			case 22:outtextxy(word_x, word_y, "ʲ"); break;
			case 23:outtextxy(word_x, word_y, "ô"); break;
			case 24:outtextxy(word_x, word_y, "��"); break;
			case 25:outtextxy(word_x, word_y, "��"); break;
			case 26:outtextxy(word_x, word_y, "��"); break;
			case 27:outtextxy(word_x, word_y, "��"); break;
			case 28:outtextxy(word_x, word_y, "��"); break;
			case 29:outtextxy(word_x, word_y, "��"); break;
			case 30:outtextxy(word_x, word_y, "��"); break;
			case 31:outtextxy(word_x, word_y, "��"); break;
			case 32:outtextxy(word_x, word_y, "��"); break;
			case 33:outtextxy(word_x, word_y, "��"); break;
			case 34:outtextxy(word_x, word_y, "��"); break;
			case 35:outtextxy(word_x, word_y, "֮"); break;
			case 36:outtextxy(word_x, word_y, "��"); break;
			case 37:outtextxy(word_x, word_y, "��"); break;
			case 38:outtextxy(word_x, word_y, "Կ��"); break;
			case 90:outtextxy(word_x, word_y, "ǽ"); break;
				//case 40:outtextxy(word_x, word_y, "ǽ"); break;
				//case 39:outtextxy(word_x, word_y, "��"); break;
			default:
				break;
			}
		}
	}

	//4  ���밴ť
	ESC();//��ͣ��ť������

	//5  ���������  
	Bag();//�˴�ע���Ȼ���ͼ��д���ܣ�������ܵ��µ�ͼ����ȫ��ʾ

	// ��ӡ����
	if (tool_wood == 1) {
		mciSendString("open ./music/����.mp3 ", 0, 0, 0);
		mciSendString("play ./music/����.mp3 ", 0, 0, 0);
		outtextxy(bag_x + 90 - textwidth("ľ��") / 2, bag_y + 60, "ľ��");
	}

	if (tool_knife == 1) {
		//mciSendString("open ����.mp3 ", 0, 0, 0);
		//mciSendString("play ����.mp3 ", 0, 0, 0); 
		outtextxy(bag_x + 90 - textwidth("ʯ�⵶") / 2, bag_y + 100, "ʯ�⵶");
	}

	if (tool_torch == 1) {
		mciSendString("open ./music/����.mp3", 0, 0, 0);
		mciSendString("play ./music/����.mp3 from 0", 0, 0, 0);
		outtextxy(bag_x + 90 - textwidth("���") / 2, bag_y + 140, "���");
	}

	if (tool_key == 1) {
		
		mciSendString("open ./music/����2.mp3 ", 0, 0, 0);
		mciSendString("play ./music/����2.mp3 ", 0, 0, 0);
		outtextxy(bag_x + 90 - textwidth("Կ��") / 2, bag_y + 180, "Կ��");
	}
}
//--------3.��һ�� ��Ҫ���� ��Ϸ����---------//
int FirstBarrierView() {

	settextstyle(25, 0, "Zpix");

	FirstGameService();//2 �����һ��

	getchar();//��ֹ��������
	return 0;
}


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