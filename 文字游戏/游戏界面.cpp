#include "��������.h" //��������

//���˵����� 
int MenuView() {
	cleardevice();
	button_menu_1(440, 200, 120, 40);//��ť��x y w h
	button_menu_2(440, 260, 120, 40);
	button_menu_3(440, 320, 120, 40);
	button_menu_4(440, 380, 120, 40);
	button_menu_5(440, 100, 120, 40);
	ExMessage msg;
	while (true)
	{
		if (peekmessage(&msg, EM_MOUSE))//����������Ϣ���򷵻��棬��֮���
		{
			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				if (msg.x >= 440 && msg.x <= 440 + 120 && msg.y >= 200 && msg.y <= 200 + 40)
				{
					//�ź��� PrintGameOption();
					ProcessView();
					break;
				}

				if (msg.x >= 440 && msg.x <= 440 + 120 && msg.y >= 260 && msg.y <= 260 + 40)
				{
					//�ź��� PrintGameIntro();
					IntroView();
					break;
				}

				if (msg.x >= 440 && msg.x <= 440 + 120 && msg.y >= 320 && msg.y <= 320 + 40)
				{
					//�ź��� PrintGameSettings();
					SetView();
					break;
				}

				if (msg.x >= 440 && msg.x <= 440 + 120 && msg.y >= 380 && msg.y <= 380 + 40)
				{
					ExitView();//�ź��� 
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

//�ġ��˳�����
void ExitView() {

	cleardevice();
	settextstyle(25, 0, "Zpix");
	char restarttext[50] = "nonono����һ���";
	outtextxy(370, 390, restarttext);//���־���
	roundrect(360, 380, 580, 420, 15, 15);
	settextstyle(25, 0, "Zpix");
	char quittext[50] = "�����˳����´μ�";
	outtextxy(370, 320, quittext);//���־���
	roundrect(360, 310, 580, 350, 15, 15);

	settextstyle(50, 0, "Zpix");
	char xintengtext[50] = "��...�����Ҫ�뿪��";
	outtextxy(220, 130, xintengtext);//���־���

	ExMessage m;
	while (1)
	{
		if (peekmessage(&m, EM_MOUSE))
		{
			if (m.message == WM_LBUTTONDOWN && m.x >= 360 && m.x <= 580 && m.y >= 310 && m.y <= 350)

			{
				_exit(0);
				break;

			}

			if (m.message == WM_LBUTTONDOWN && m.x >= 360 && m.x <= 580 && m.y >= 380 && m.y <= 420)
			{
				MenuView();
				break;
			}
		}
	}
	getchar();
}

//1.x ��������
void DeathView() {

	cleardevice();
	settextstyle(20, 0, "Zpix");
	char deathtext[50] = " ��....�����˺ڰ���ʱ����ݣ��������������λ�á�";
	outtextxy(250, 290, deathtext);//���־���

	Sleep(1000);
	extern int sign_barrier_number;
	if ( sign_barrier_number == 1) {
		settextstyle(25, 0, "Zpix");
		FirstGameService();
	}

	else if (sign_barrier_number == 2) {
		settextstyle(25, 0, "Zpix");
		SecondBarrierView();
	}

	getchar();
}

//�㡢��¼����
int login()
{
	//mciSendString("open ����.mp3", 0, 0, 0);
	//mciSendString("play ����.mp3", 0, 0, 0);

	cleardevice();
	ButtonLogin1(440, 100, 120, 40);//��ť��x y w h
	ButtonLogin2(250, 220, 120, 40);
	ButtonLogin3(250, 290, 120, 40);
	ButtonLogin4(650, 290, 100, 40);
	ButtonLogin5(340, 410, 120, 40);
	ButtonLogin6(550, 410, 120, 40);
	ButtonLogin7(360, 220, 280, 40);
	ButtonLogin8(360, 290, 280, 40);
	ExMessage msg;
	while (true)
	{
		if (peekmessage(&msg, EM_MOUSE))//����������Ϣ���򷵻��棬��֮���
		{
			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				//if (msg.x >= 440 && msg.x <= 440 + 120 && msg.y >= 100 && msg.y <= 100 + 40)
				//{
				//	//�������
				//}
				//break;
				//if (msg.x >= 250 && msg.x <= 250 + 120 && msg.y >= 220 && msg.y <= 220 + 40)
				//{
				//	//�������
				//}
				//break;
				//if (msg.x >= 250 && msg.x <= 250 + 120 && msg.y >= 290 && msg.y <= 290 + 40)
				//{
				//	//�������
				//}
				//break;
				if (msg.x >= 630 && msg.x <= 630 + 120 && msg.y >= 290 && msg.y <= 290 + 40)
				{
					find_password();
					break;
				}

				if (msg.x >= 340 && msg.x <= 340 + 120 && msg.y >= 410 && msg.y <= 410 + 40)
				{
					MenuView();//����������ת���˵����棩
					break;
				}

				if (msg.x >= 550 && msg.x <= 550 + 120 && msg.y >= 410 && msg.y <= 410 + 40)
				{
					rigster();
					break;
				}

				if (msg.x >= 360 && msg.x <= 360 + 280 && msg.y >= 220 && msg.y <= 220 + 40)
				{
					//�����ı�
					break;
				}

				if (msg.x >= 360 && msg.x <= 360 + 280 && msg.y >= 290 && msg.y <= 290 + 40)
				{
					//�����ı�
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
//ע�����
int rigster()
{
	cleardevice();
	//���ΰ�ťλ��
	ButtonReg1(400, 450, 150, 50);
	ButtonReg2(410, 145, 250, 40);
	ButtonReg2(410, 220, 250, 40);
	ButtonReg2(410, 295, 250, 40);
	ButtonReg2(410, 370, 250, 40);
	//ҳ����������
	settextcolor(WHITE);
	settextstyle(40, 0, "Zpix");

	outtextxy(420, 50, "ע��ҳ��");
	//
	settextstyle(30, 0, "Zpix");
	outtextxy(300, 150, "�û���:");
	outtextxy(329, 225, "�˺�:");
	outtextxy(329, 300, "����:");
	outtextxy(270, 375, "ȷ������:");

	setlinecolor(WHITE);
	setlinestyle(PS_SOLID, 1);
	/*circle(705,165, 20);*/

	//����ͼƬ
	IMAGE img;
	loadimage(&img, "С���.png", 95, 65);
	putimage(680, 132, &img);
	putimage(680, 207, &img);
	putimage(680, 282, &img);
	putimage(680, 357, &img);

	ExMessage msg;
	while (true)
	{
		if (peekmessage(&msg, EM_MOUSE))//����������Ϣ���򷵻��棬��֮���
		{
			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				if (msg.x >= 400 && msg.x <= 400 + 150 && msg.y >= 450 && msg.y <= 450 + 50)
				{
					login();
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
//�һ��������
int find_password()
{
	cleardevice();
	//���ΰ�ťλ��
	ButtonBack1(430, 420, 150, 50);//��ȷ������ť��λ��
	ButtonBack2(480, 222, 250, 40);//���������롱��ťλ��
	ButtonBack2(480, 320, 250, 40);//���������롱��ťλ��


	//ҳ����������
//���ñ���Ϊ͸��ģʽ
	settextstyle(50, 0, "Zpix");
	outtextxy(410, 100, "�һ�����");

	settextstyle(25, 0, "Zpix");
	char text1[50] = "ע����û���:";
	char text2[50] = "ע����˺�:";
	outtextxy(260, 225, text1);
	outtextxy(260, 325, text2);

	ExMessage msg;
	while (true)
	{
		if (peekmessage(&msg, EM_MOUSE))//����������Ϣ���򷵻��棬��֮���
		{
			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				if (msg.x >= 430 && msg.x <= 430 + 150 && msg.y >= 420 && msg.y <= 420 + 50)
				{
					success_find();
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

//�һسɹ�����
int success_find()
{
	cleardevice();
	//���ΰ�ťλ��
	ButtonSuccess1(430, 420, 150, 50);//��ȷ������ť��λ��x,y,w,h
	ButtonSuccess2(480, 222, 250, 40);//���������롱��ťλ��x,y,w,h
	ButtonSuccess2(480, 320, 250, 40);//���������롱��ťλ����x,y,w,h
	//ҳ����������

	settextstyle(50, 0, "Zpix");
	outtextxy(405, 100, "�һسɹ���");
	//
	settextstyle(25, 0, "Zpix");
	char text3[50] = "������:";
	char text4[50] = "ȷ��������:";
	outtextxy(317, 225, text3);
	outtextxy(260, 325, text4);

	ExMessage msg;
	while (true)
	{
		if (peekmessage(&msg, EM_MOUSE))//����������Ϣ���򷵻��棬��֮���
		{
			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				if (msg.x >= 430 && msg.x <= 430 + 150 && msg.y >= 420 && msg.y <= 420 + 50)
				{
					login();
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