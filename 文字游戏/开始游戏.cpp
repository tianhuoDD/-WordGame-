#include "��������.h" //��������

//һ����ʼ��Ϸ�����Ƚ��棩
int ProcessView() {
	cleardevice();
	ButtonProcess1(440, 220, 120, 40);//��ť��x y w h
	ButtonProcess2(440, 300, 120, 40);
	ButtonProcess3(440, 100, 120, 40);
	ExMessage msg;
	while (true)
	{
		if (peekmessage(&msg, EM_MOUSE))//����������Ϣ���򷵻��棬��֮���
		{
			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				if (msg.x >= 440 && msg.x <= 440 + 120 && msg.y >= 220 && msg.y <= 220 + 40)
				{
					//�ź��� �������µ���Ϸ��
					FirstBarrierView();
					break;
				}

				if (msg.x >= 440 && msg.x <= 440 + 120 && msg.y >= 300 && msg.y <= 300 + 40)
				{
					//�ź��� void PrintMenuLoad();������浵���棩
					ChooseArchiveViewInMenu();
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

//1.2.1 ��������
int ChooseArchiveViewInGame() {
	cleardevice();
	BottonLoad1(440, 150, 120, 40);//��ť��x y w h
	BottonLoad2(670, 160, 120, 40);
	BottonLoad3(440, 250, 120, 40);
	BottonLoad4(440, 320, 120, 40);
	BottonLoad5(440, 390, 120, 40);
	BottonLoad6(440, 460, 120, 40);

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

				if (msg.x >= 620 && msg.x <= 670 + 120 && msg.y >= 160 && msg.y <= 160 + 40)
				{
					//�������
					break;
				}

				if (msg.x >= 440 && msg.x <= 440 + 120 && msg.y >= 250 && msg.y <= 250 + 40)
				{
					//�������
					break;
				}
				if (msg.x >= 440 && msg.x <= 440 + 120 && msg.y >= 320 && msg.y <= 320 + 40)
				{
					//�������
					break;
				}
				if (msg.x >= 440 && msg.x <= 440 + 120 && msg.y >= 390 && msg.y <= 390 + 40)
				{
					//�������
					break;
				}

				if (msg.x >= 440 && msg.x <= 440 + 120 && msg.y >= 460 && msg.y <= 460 + 40)
				{
					//�ź��� (������ͣ����);
					PauseView();
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

// ��������
int ChooseArchiveViewInMenu() {
	cleardevice();
	BottonLoad1(440, 150, 120, 40);//��ť��x y w h
	BottonLoad2(670, 160, 120, 40);
	BottonLoad3(440, 250, 120, 40);
	BottonLoad4(440, 320, 120, 40);
	BottonLoad5(440, 390, 120, 40);
	BottonLoad7(440, 460, 120, 40);

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

				if (msg.x >= 620 && msg.x <= 670 + 120 && msg.y >= 160 && msg.y <= 160 + 40)
				{
					//�������
					break;
				}

				if (msg.x >= 440 && msg.x <= 440 + 120 && msg.y >= 250 && msg.y <= 250 + 40)
				{
					//�������
					break;
				}
				if (msg.x >= 440 && msg.x <= 440 + 120 && msg.y >= 320 && msg.y <= 320 + 40)
				{
					//�������
					break;
				}
				if (msg.x >= 440 && msg.x <= 440 + 120 && msg.y >= 390 && msg.y <= 390 + 40)
				{
					//�������
					break;
				}

				if (msg.x >= 440 && msg.x <= 440 + 120 && msg.y >= 460 && msg.y <= 460 + 40)
				{
					//�ź��� (������ͣ����);
					ProcessView();
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

//�����ؿ�
int SuccessSkipView() {

	cleardevice();
	ButtonSkip1(420, 215, 160, 40);//��ť��x y w h
	ButtonSkip2(430, 290, 140, 40);
	ButtonSkip3(430, 365, 140, 40);
	ButtonSkip4(440, 440, 120, 40);

	settextstyle(40, 0, "Zpix");
	outtextxy(325, 75, "��ϲ��ͨ�����߹ؿ���");
	outtextxy(300, 140, "��ѡ���Ƿ�����ʵ��ؿ�");

	mciSendString("open ����2.mp3 ", 0, 0, 0);
	mciSendString("play ����2.mp3 ", 0, 0, 0);

	ExMessage msg;
	while (true)
	{
		if (peekmessage(&msg, EM_MOUSE))//����������Ϣ���򷵻��棬��֮���
		{
			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				if (msg.x >= 420 && msg.x <= 420 + 160 && msg.y >= 215 && msg.y <= 215 + 40)
				{
					//�ź��� ���������ؿ�
					MainGodGame();

				}
				if (msg.x >= 430 && msg.x <= 430 + 140 && msg.y >= 290 && msg.y <= 290 + 40)
				{
					//�ź��� ���ص�һ��
					FirstBarrierView();
				}
				if (msg.x >= 430 && msg.x <= 430 + 140 && msg.y >= 365 && msg.y <= 365 + 40)
				{
					//�ź��� ���صڶ���
					MainSecondBarrier();
				}
				if (msg.x >= 440 && msg.x <= 440 + 120 && msg.y >= 440 && msg.y <= 440 + 40)
				{
					//�ź��� ���ز˵�
					MenuView();
				}
			default:
				break;
			}
		}


	}

	getchar();
	return 0;
}

//��ͨ�ص�ͨ�ؽ���
int CommonPassView()
{
	//��ӡ���ý���
	cleardevice();

	button(408, 420, 150, 50);//���ΰ�ťλ��
	//����λ��
	settextcolor(WHITE);
	settextstyle(30, 0, "Zpix");
	setbkmode(TRANSPARENT);
	outtextxy(344, 130, "��ϷĿǰ����������");
	outtextxy(350, 180, "���Ѿ���ȫͨ������");
	settextcolor(RGB(214, 157, 133));
	settextstyle(50, 0, "Zpix");
	outtextxy(355, 230, "��л������棡");
	settextcolor(WHITE);
	settextstyle(30, 0, "Zpix");
	outtextxy(332, 300, "���κ��뷨�򱦹������");
	outtextxy(380, 350, "����ϵxxx������");

	mciSendString("open ����1.mp3 ", 0, 0, 0);
	mciSendString("play ����1.mp3 ", 0, 0, 0);

	//�������ť���н���
	ExMessage msg;
	while (1)
	{
		if (peekmessage(&msg, EM_MOUSE))
		{
			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				if (msg.x >= 410 && msg.x <= 562 && msg.y >= 420 && msg.y <= 473)
				{
					//�������˵�
					MenuView();
				}
				break;
			default:
				break;
			}
		}
	}



	getchar();
	return 0;
}

//��ͣ����
int PauseView() {
	cleardevice();
	ButtonPause1(440, 200, 120, 40);//��ť��x y w h
	ButtonPause2(440, 260, 120, 40);
	ButtonPause3(440, 320, 120, 40);
	ButtonPause4(440, 380, 120, 40);
	ButtonPause5(440, 100, 120, 40);
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
					//�ź��� �����ظոյ���Ϸ���棩
					FirstBarrierView();
					break;
				}

				if (msg.x >= 440 && msg.x <= 440 + 120 && msg.y >= 260 && msg.y <= 260 + 40)
				{
					//�ź��� void PrintArchive(); ���� ����浵 ����
					SaveArchiveView();
					break;
				}

				if (msg.x >= 440 && msg.x <= 440 + 120 && msg.y >= 320 && msg.y <= 320 + 40)
				{
					//�ź��� void PrintGameLoad();
					ChooseArchiveViewInGame();
					break;
				}

				if (msg.x >= 440 && msg.x <= 440 + 120 && msg.y >= 380 && msg.y <= 380 + 40)
				{
					//�ź��� rintMenu();
					int delete_temp = 1;
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

// ����ͣ���� ���� ����浵 ����
int SaveArchiveView() {
	cleardevice();
	BottonArchive1(440, 150, 120, 40);//��ť��x y w h
	BottonArchive2(620, 160, 120, 40);
	BottonArchive3(440, 250, 120, 40);
	BottonArchive4(440, 320, 120, 40);
	BottonArchive5(440, 390, 120, 40);
	BottonArchive6(440, 460, 120, 40);

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

				if (msg.x >= 620 && msg.x <= 620 + 120 && msg.y >= 160 && msg.y <= 160 + 40)
				{
					//�������
					break;
				}

				if (msg.x >= 440 && msg.x <= 440 + 120 && msg.y >= 250 && msg.y <= 250 + 40)
				{
					//�������
					break;
				}

				if (msg.x >= 440 && msg.x <= 440 + 120 && msg.y >= 320 && msg.y <= 320 + 40)
				{
					//�������
					break;
				}

				if (msg.x >= 440 && msg.x <= 440 + 120 && msg.y >= 390 && msg.y <= 390 + 40)
				{
					//�������
				}

				if (msg.x >= 440 && msg.x <= 440 + 120 && msg.y >= 460 && msg.y <= 460 + 40)
				{
					//�ź���  ������ͣ;
					PauseView();
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
