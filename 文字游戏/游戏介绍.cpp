#include "��������.h" //��������

//��������Ϸ���ܡ�����
int IntroView() {
	cleardevice();
	ButtonIntro1(320, 480, 120, 40);//��ť��x y w h
	ButtonIntro2(440, 480, 120, 40);
	ButtonIntro3(585, 480, 120, 40);
	ButtonIntro4(440, 80, 120, 40);
	settextstyle(20, 0, "Zpix");
	char text1[50] = "��ҿ��ơ��ҡ�����һϵ�еľ���̽����";
	char text2[50] = "��̽�������п��Ի��������������ǿ�Լ���";
	char text3[50] = "�Ӷ�����Լ��ƽ�����������ÿ�����鶼";
	char text4[50] = "�в�һ���Ĳʵ�Ŷ��Ŭ��ȥ̽���ɣ���";
	char text5[50] = "�ƶ����� wasd�����";
	char text6[50] = "���顢��NPC�������� �����ո񡱼�";
	char text7[50] = "ɾ/���֡��� ����Backspace����";
	char text8[50] = "���� �������";
	char text9[50] = "��ͣ���� Esc";
	char text10[50] = "����ʹ�ú��л����� �����ո񡱼�";
	char text11[50] = "����������������������������������������";

	outtextxy(340, 150, text1);
	outtextxy(300, 175, text2);
	outtextxy(300, 200, text3);
	outtextxy(300, 225, text4);
	outtextxy(300, 275, text5);
	outtextxy(300, 300, text6);
	outtextxy(300, 325, text7);
	outtextxy(300, 350, text8);
	outtextxy(300, 375, text9);
	outtextxy(300, 400, text10);
	outtextxy(300, 250, text11);
	ExMessage msg;
	while (true)
	{
		if (peekmessage(&msg, EM_MOUSE))//����������Ϣ���򷵻��棬��֮���
		{
			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				if (msg.x >= 320 && msg.x <= 320 + 120 && msg.y >= 480 && msg.y <= 480 + 40)
				{
					//�ź��� void PrintGameTips();
					StrategyView();
					break;
				}

				if (msg.x >= 440 && msg.x <= 440 + 120 && msg.y >= 480 && msg.y <= 480 + 40)
				{
					//�ź��� void PrintTeamDetails();
					MadeView();
					break;
				}

				if (msg.x >= 585 && msg.x <= 585 + 120 && msg.y >= 480 && msg.y <= 480 + 40)
				{
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
//2.1��Ϸ���� ����
int StrategyView() {
	cleardevice();
	ButtonStrategy1(440, 480, 120, 40);//��ť��x y w h
	ButtonStrategy2(850, 480, 120, 40);
	settextstyle(25, 0, "Zpix");
	outtextxy(200, 225, "��");
	outtextxy(200, 250, "��");
	outtextxy(200, 275, "��");
	outtextxy(200, 300, "��");
	settextstyle(20, 0, "Zpix");
	//��K����񽻻������ʯ������ƽ��������Ʊ�Ϊ���û��ȼ���񡱣��ÿ��ؽ�����
	//�ڳ��ֵĶԻ��а�J��ɾ�����㡱�֣����롰�ҡ���K������ʯ��ɱ�����أ�
	//�����ص�Կ�ף���J�����ƻ����ٲ�ǽ�֣��䴩��������ˮ����
	char text1[70] = "��һ�أ������ո񡱼���񽻻������ʯ������ƽ�����";
	char text2[60] = "�û��ȼ���񡱣��ÿ��ؽ������ڳ��ֵĶԻ��а�";
	char text3[80] = "��Backspace������ɾ�����㡱�֣����롰�ҡ������ո񡱼���";
	char text4[60] = "�����ص�Կ�ף���Backspace�����ƻ����ٲ�ǽ�֣�";
	char text5[50] = "�䴩����������ˮ����";
	//�ڶ��أ��ڿ�ʼ�Ķ԰��У��ѡ��ҡ����ڶ԰׿մ���K������ʼ��Ϸ��
	//��K������������Կ�״�ͨ�磬�ڶ԰�2�а�J��ɾ����û���֣�
	//��ɢ�������������а�K���ɹ��ӳ���
	char text6[70] = "�ڶ��أ��ڿ�ʼ�Ķ԰��У��ѡ��ҡ����ڶ԰׿մ������ո񡱼���ʼ";
	char text7[70] = "��Ϸ�������ո�����������Կ�״�ͨ�磬��ɢ������";
	char text8[50] = "�������гɹ��ӳ���";
	char text11[70] = "������������������������������������������������";

	outtextxy(300, 150, text1);
	outtextxy(380, 175, text2);
	outtextxy(380, 200, text3);
	outtextxy(380, 225, text4);
	outtextxy(380, 250, text5);
	outtextxy(300, 300, text6);
	outtextxy(380, 325, text7);
	outtextxy(380, 350, text8);
	outtextxy(380, 275, text11);
	ExMessage msg;
	while (true)
	{
		if (peekmessage(&msg, EM_MOUSE))//����������Ϣ���򷵻��棬��֮���
		{
			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				if (msg.x >= 440 && msg.x <= 440 + 120 && msg.y >= 480 && msg.y <= 480 + 40)
				{
					MenuView();
					break;
				}

				if (msg.x >= 850 && msg.x <= 850 + 120 && msg.y >= 480 && msg.y <= 480 + 40)
				{
					//�ź��� void PrintHiddenTips();
					EggStrategyView();
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
//2.2 �ʵ�����
int EggStrategyView() {
	cleardevice();
	ButtonEgg1(530, 480, 120, 40);//��ť��x y w h
	ButtonEgg2(350, 480, 120, 40);
	settextstyle(25, 0, "Zpix");
	outtextxy(200, 225, "��");
	outtextxy(200, 250, "��");
	outtextxy(200, 275, "��");
	outtextxy(200, 300, "��");
	settextstyle(20, 0, "Zpix");
	//���ҡ�������ߵġ����������뱳�����š��T����
	//�������ɡ��ˣ��ӡ��ɡ��˵Ļ��в�⡾�롿�֣���ɡ������͡�����
	//���������Ƶ���ˮ���ߣ���ϳɡ��������ý�������������ִﱦ�����ؼ���
	//�ӡ����ܳ��������������ɾ���������ֻ�����������ϡ���������һ�ߵġ��T���뿪��

	char text1[50] = "���ҡ�������ߵġ����������뱳�����š��T������";
	char text2[60] = "�����ɡ��ˣ��ӡ��ɡ��˵Ļ��в�⡾�롿�֣���ɡ�����";
	char text3[60] = "�͡��������������Ƶ���ˮ���ߣ���ϳɡ��������ý���";
	char text4[60] = "����������ִﱦ�����ؼ����ӡ����ܳ��������������";
	char text5[60] = "ɾ���������ֻ�����������ϡ���������һ�ߵġ��T����";
	char text6[50] = "����";
	char text7[50] = "";
	char text8[50] = "";
	char text9[50] = "";


	outtextxy(340, 180, text1);
	outtextxy(300, 210, text2);
	outtextxy(300, 240, text3);
	outtextxy(300, 270, text4);
	outtextxy(300, 300, text5);
	outtextxy(300, 330, text6);
	outtextxy(300, 360, text7);
	outtextxy(300, 390, text8);
	outtextxy(300, 420, text9);

	ExMessage msg;
	while (true)
	{
		if (peekmessage(&msg, EM_MOUSE))//����������Ϣ���򷵻��棬��֮���
		{
			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				if (msg.x >= 530 && msg.x <= 530 + 120 && msg.y >= 480 && msg.y <= 480 + 40)
				{
					//�ź��� PrintMenu();
					MenuView();
					break;
				}

				if (msg.x >= 350 && msg.x <= 350 + 120 && msg.y >= 480 && msg.y <= 480 + 40)
				{
					//�ź��� void PrintGameTips();
					StrategyView();
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
//2.3 ������Ա ����
int MadeView() {
	cleardevice();
	ButtonMade1(440, 100, 120, 40);//��ť��x y w h
	ButtonMade2(440, 160, 120, 40);
	ButtonMade3(440, 190, 120, 40);
	ButtonMade4(440, 220, 120, 40);
	ButtonMade5(440, 250, 120, 40);
	ButtonMade6(440, 280, 120, 40);
	ButtonMade7(440, 310, 120, 40);
	ButtonMade8(440, 340, 120, 40);
	ButtonMade9(440, 370, 120, 40);
	ButtonMade10(440, 450, 120, 40);
	ButtonMade11(700, 400, 120, 40);
	ExMessage msg;
	while (true)
	{
		if (peekmessage(&msg, EM_MOUSE))//����������Ϣ���򷵻��棬��֮���
		{
			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				if (msg.x >= 440 && msg.x <= 440 + 120 && msg.y >= 100 && msg.y <= 100 + 40)
				{
					//�������
				}

				if (msg.x >= 440 && msg.x <= 440 + 120 && msg.y >= 160 && msg.y <= 120 + 40)
				{
					//�������
				}

				if (msg.x >= 440 && msg.x <= 440 + 120 && msg.y >= 190 && msg.y <= 190 + 40)
				{
					//�������
				}

				if (msg.x >= 440 && msg.x <= 440 + 120 && msg.y >= 220 && msg.y <= 220 + 40)
				{
					//�������
				}

				if (msg.x >= 440 && msg.x <= 440 + 120 && msg.y >= 250 && msg.y <= 250 + 40)
				{
					//�������
				}

				if (msg.x >= 440 && msg.x <= 440 + 120 && msg.y >= 280 && msg.y <= 280 + 40)
				{
					//�������
				}

				if (msg.x >= 440 && msg.x <= 440 + 120 && msg.y >= 310 && msg.y <= 310 + 40)
				{
					//�������
				}

				if (msg.x >= 440 && msg.x <= 440 + 120 && msg.y >= 340 && msg.y <= 340 + 40)
				{
					//�������
				}

				if (msg.x >= 440 && msg.x <= 440 + 120 && msg.y >= 370 && msg.y <= 370 + 40)
				{
					//�������
				}

				if (msg.x >= 440 && msg.x <= 440 + 120 && msg.y >= 450 && msg.y <= 450 + 40)
				{
					//��Ӻ��������ز˵���
					MenuView();

				}

				if (msg.x >= 700 && msg.x <= 700 + 120 && msg.y >= 400 && msg.y <= 400 + 40)
				{
					//�������
				}
			}
		}


	}

	getchar();
	return 0;
}