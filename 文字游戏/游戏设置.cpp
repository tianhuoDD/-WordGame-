#include "��������.h" //��������

//��������Ϸ���á�����
int SetView() {
	cleardevice();
	button1(440, 150, 120, 40);//��ť��x y w h
	button2(440, 250, 120, 40);
	button3(440, 320, 120, 40);
	button4(440, 400, 120, 40);
	ExMessage msg;
	while (true)
	{
		if (peekmessage(&msg, EM_MOUSE))//����������Ϣ���򷵻��棬��֮���
		{
			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				if (msg.x >= 440 && msg.x <= 440 + 120 && msg.y >= 150 && msg.y <= 150 + 40)
				{
					//�������
					break;
				}

				if (msg.x >= 440 && msg.x <= 440 + 120 && msg.y >= 250 && msg.y <= 250 + 40)
				{
					//�ź��� ������������ý��棩
					BasicSetView2();
					break;
				}

				if (msg.x >= 440 && msg.x <= 440 + 120 && msg.y >= 320 && msg.y <= 320 + 40)
				{
					//�ź��� (�����淨���ý���);
					ModeSetView();
					break;
				}

				if (msg.x >= 440 && msg.x <= 440 + 120 && msg.y >= 400 && msg.y <= 400 + 40)
				{
					//�ź��� (���ز˵�);
					MenuView();
					break;
				}

			default:
				break;
			}
		}


	}

	getchar();
	return 0;
}

//3.2�淨����!!(break��if���桪����
int ModeSetView() {
	cleardevice();
	BottonMode1(440, 150, 120, 40);//��ť��x y w h
	BottonMode2(300, 280, 120, 40);
	BottonMode3(600, 280, 120, 40);
	BottonMode4(440, 400, 120, 40);
	ExMessage msg;
	while (true)
	{
		if (peekmessage(&msg, EM_MOUSE))//����������Ϣ���򷵻��棬��֮���
		{
			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				if (msg.x >= 440 && msg.x <= 440 + 120 && msg.y >= 150 && msg.y <= 150 + 40)
				{
					//�޽�����ת

					break;
				}

				if (msg.x >= 440 && msg.x <= 440 + 120 && msg.y >= 250 && msg.y <= 250 + 40)
				{
					//�ź��� ��//service��Ҫ�������ܣ�������Ϸ��ͼΪ��һ�ؽ��棨Ĭ�ϣ���

					break;
				}

				if (msg.x >= 440 && msg.x <= 440 + 120 && msg.y >= 320 && msg.y <= 320 + 40)
				{
					//�ź��� (//service��Ҫ�������ܣ�������Ϸ��ͼΪ�ɽ���Ե����);
					break;
				}

				if (msg.x >= 440 && msg.x <= 440 + 120 && msg.y >= 390 && msg.y <= 390 + 40)
				{
					//�ź��� (������Ϸ����);
					MenuView();
					break;
				}

			default:
				break;
			}
		}


	}

	getchar();
	return 0;
}

// �������ý���
void BasicSetView1(void) //�½�һ��ֻ��ӡ����ѡ��ĺ���
{

	settextcolor(WHITE);//�������������ɫ
	settextstyle(25, 0, "Zpix");//�������������ʽ

	outtextxy(400, 50, "��Ϸ����");
	//���Ľ�������
	outtextxy(200, 150, "��������:");
	outtextxy(400, 150, "Zpix");
	outtextxy(500, 150, "����");
	outtextxy(600, 150, "�����п�");
	outtextxy(750, 150, "LiSu");

	outtextxy(200, 250, "������С:");
	outtextxy(400, 250, "+    -");

	outtextxy(200, 350, "��������:");
	outtextxy(400, 350, "1.��     2.��");

	outtextxy(900, 500, "����");
}

//3.1��������
int BasicSetView2()
{
	cleardevice();

	BasicSetView1(); //�������涨��Ľ��溯��

	ExMessage m; //����mΪ ExMessage ���ͣ� 
	//��m������Ϻ�׺�Ϳ��Ա�ʾ��������Ϣ��
		//m.x �� m.y ��ʾ��������
		//m.message ��ʾ���� ��� �� �Ҽ� �� �м�

	while (1) //��ʾ���ϴ�������
	{
		if (peekmessage(&m, EM_MOUSE))
		{
			if (m.message == WM_LBUTTONDOWN && m.x >= 150 && m.x <= 250 && m.y >= 90 && m.y <= 100)
				//.message��ʾ������Ϣ��WM_LBUTTONDOWN��ʾ �������
			{
				cleardevice(); //Ϊ�����������º��ߣ�������Ȼ���ٵ��ý��溯������ʵ�ֵ��һ��ѡ���ʾһ��ѡ��
				SetView();
				outtextxy(200, 100, "____"); //���ߵ��������Zpix������
				settextstyle(50, 0, "Zpix");//�ڿ���̨����ʾ

			}

			if (m.message == WM_LBUTTONDOWN && m.x >= 250 && m.x <= 350 && m.y >= 90 && m.y <= 100)
			{
				cleardevice(); //Ϊ�����������º��ߣ�������Ȼ���ٵ��ý��溯������ʵ�ֵ��һ��ѡ���ʾһ��ѡ��

				outtextxy(300, 100, "____");
				SetView();
				settextstyle(50, 0, "����");
			}

			if (m.message == WM_LBUTTONDOWN && m.x >= 350 && m.x <= 450 && m.y >= 90 && m.y <= 100)
			{
				cleardevice(); //Ϊ�����������º��ߣ�������Ȼ���ٵ��ý��溯������ʵ�ֵ��һ��ѡ���ʾһ��ѡ��

				outtextxy(400, 100, "____");
				SetView();
				settextstyle(50, 0, "�����п�");
			}

			if (m.message == WM_LBUTTONDOWN && m.x >= 450 && m.x <= 550 && m.y >= 90 && m.y <= 100)
			{
				cleardevice(); //Ϊ�����������º��ߣ�������Ȼ���ٵ��ý��溯������ʵ�ֵ��һ��ѡ���ʾһ��ѡ��

				outtextxy(500, 100, "____");
				SetView();
				settextstyle(50, 0, "LiSu");
			}

			if (m.message == WM_LBUTTONDOWN && m.x >= 900 && m.x <= 950 && m.y >= 500 && m.y <= 530)
			{
				MenuView();
			}
		}
	}
	getchar();
	return 0;
}
