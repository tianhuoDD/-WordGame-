#include "函数声明.h" //函数声明

//一、开始游戏（进度界面）
int ProcessView() {
	cleardevice();
	ButtonProcess1(440, 220, 120, 40);//按钮的x y w h
	ButtonProcess2(440, 300, 120, 40);
	ButtonProcess3(440, 100, 120, 40);
	ExMessage msg;
	while (true)
	{
		if (peekmessage(&msg, EM_MOUSE))//如果有鼠标消息，则返回真，反之则假
		{
			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				if (msg.x >= 440 && msg.x <= 440 + 120 && msg.y >= 220 && msg.y <= 220 + 40)
				{
					//放函数 （进入新的游戏）
					FirstBarrierView();
					break;
				}

				if (msg.x >= 440 && msg.x <= 440 + 120 && msg.y >= 300 && msg.y <= 300 + 40)
				{
					//放函数 void PrintMenuLoad();（进入存档界面）
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

//1.2.1 读档界面
int ChooseArchiveViewInGame() {
	cleardevice();
	BottonLoad1(440, 150, 120, 40);//按钮的x y w h
	BottonLoad2(670, 160, 120, 40);
	BottonLoad3(440, 250, 120, 40);
	BottonLoad4(440, 320, 120, 40);
	BottonLoad5(440, 390, 120, 40);
	BottonLoad6(440, 460, 120, 40);

	ExMessage msg;
	while (true)
	{
		if (peekmessage(&msg, EM_MOUSE))//如果有鼠标消息，则返回真，反之则假
		{
			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				if (msg.x >= 440 && msg.x <= 440 + 120 && msg.y >= 150 && msg.y <= 150 + 40)
				{
					//无需操作
					break;
				}

				if (msg.x >= 620 && msg.x <= 670 + 120 && msg.y >= 160 && msg.y <= 160 + 40)
				{
					//无需操作
					break;
				}

				if (msg.x >= 440 && msg.x <= 440 + 120 && msg.y >= 250 && msg.y <= 250 + 40)
				{
					//无需操作
					break;
				}
				if (msg.x >= 440 && msg.x <= 440 + 120 && msg.y >= 320 && msg.y <= 320 + 40)
				{
					//无需操作
					break;
				}
				if (msg.x >= 440 && msg.x <= 440 + 120 && msg.y >= 390 && msg.y <= 390 + 40)
				{
					//无需操作
					break;
				}

				if (msg.x >= 440 && msg.x <= 440 + 120 && msg.y >= 460 && msg.y <= 460 + 40)
				{
					//放函数 (返回暂停界面);
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

// 读档界面
int ChooseArchiveViewInMenu() {
	cleardevice();
	BottonLoad1(440, 150, 120, 40);//按钮的x y w h
	BottonLoad2(670, 160, 120, 40);
	BottonLoad3(440, 250, 120, 40);
	BottonLoad4(440, 320, 120, 40);
	BottonLoad5(440, 390, 120, 40);
	BottonLoad7(440, 460, 120, 40);

	ExMessage msg;
	while (true)
	{
		if (peekmessage(&msg, EM_MOUSE))//如果有鼠标消息，则返回真，反之则假
		{
			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				if (msg.x >= 440 && msg.x <= 440 + 120 && msg.y >= 150 && msg.y <= 150 + 40)
				{
					//无需操作
					break;
				}

				if (msg.x >= 620 && msg.x <= 670 + 120 && msg.y >= 160 && msg.y <= 160 + 40)
				{
					//无需操作
					break;
				}

				if (msg.x >= 440 && msg.x <= 440 + 120 && msg.y >= 250 && msg.y <= 250 + 40)
				{
					//无需操作
					break;
				}
				if (msg.x >= 440 && msg.x <= 440 + 120 && msg.y >= 320 && msg.y <= 320 + 40)
				{
					//无需操作
					break;
				}
				if (msg.x >= 440 && msg.x <= 440 + 120 && msg.y >= 390 && msg.y <= 390 + 40)
				{
					//无需操作
					break;
				}

				if (msg.x >= 440 && msg.x <= 440 + 120 && msg.y >= 460 && msg.y <= 460 + 40)
				{
					//放函数 (返回暂停界面);
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

//仙侠关卡
int SuccessSkipView() {

	cleardevice();
	ButtonSkip1(420, 215, 160, 40);//按钮的x y w h
	ButtonSkip2(430, 290, 140, 40);
	ButtonSkip3(430, 365, 140, 40);
	ButtonSkip4(440, 440, 120, 40);

	settextstyle(40, 0, "Zpix");
	outtextxy(325, 75, "恭喜你通过主线关卡！");
	outtextxy(300, 140, "请选择是否游玩彩蛋关卡");

	mciSendString("open 过关2.mp3 ", 0, 0, 0);
	mciSendString("play 过关2.mp3 ", 0, 0, 0);

	ExMessage msg;
	while (true)
	{
		if (peekmessage(&msg, EM_MOUSE))//如果有鼠标消息，则返回真，反之则假
		{
			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				if (msg.x >= 420 && msg.x <= 420 + 160 && msg.y >= 215 && msg.y <= 215 + 40)
				{
					//放函数 进入仙侠关卡
					MainGodGame();

				}
				if (msg.x >= 430 && msg.x <= 430 + 140 && msg.y >= 290 && msg.y <= 290 + 40)
				{
					//放函数 返回第一关
					FirstBarrierView();
				}
				if (msg.x >= 430 && msg.x <= 430 + 140 && msg.y >= 365 && msg.y <= 365 + 40)
				{
					//放函数 返回第二关
					MainSecondBarrier();
				}
				if (msg.x >= 440 && msg.x <= 440 + 120 && msg.y >= 440 && msg.y <= 440 + 40)
				{
					//放函数 返回菜单
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

//普通关的通关界面
int CommonPassView()
{
	//打印设置界面
	cleardevice();

	button(408, 420, 150, 50);//矩形按钮位置
	//文字位置
	settextcolor(WHITE);
	settextstyle(30, 0, "Zpix");
	setbkmode(TRANSPARENT);
	outtextxy(344, 130, "游戏目前就做到这里");
	outtextxy(350, 180, "你已经完全通关啦！");
	settextcolor(RGB(214, 157, 133));
	settextstyle(50, 0, "Zpix");
	outtextxy(355, 230, "感谢你的游玩！");
	settextcolor(WHITE);
	settextstyle(30, 0, "Zpix");
	outtextxy(332, 300, "有任何想法或宝贵意见，");
	outtextxy(380, 350, "请联系xxx反馈。");

	mciSendString("open 过关1.mp3 ", 0, 0, 0);
	mciSendString("play 过关1.mp3 ", 0, 0, 0);

	//鼠标点击按钮进行交互
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
					//返回主菜单
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

//暂停界面
int PauseView() {
	cleardevice();
	ButtonPause1(440, 200, 120, 40);//按钮的x y w h
	ButtonPause2(440, 260, 120, 40);
	ButtonPause3(440, 320, 120, 40);
	ButtonPause4(440, 380, 120, 40);
	ButtonPause5(440, 100, 120, 40);
	ExMessage msg;
	while (true)
	{
		if (peekmessage(&msg, EM_MOUSE))//如果有鼠标消息，则返回真，反之则假
		{
			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				if (msg.x >= 440 && msg.x <= 440 + 120 && msg.y >= 200 && msg.y <= 200 + 40)
				{
					//放函数 （返回刚刚的游戏界面）
					FirstBarrierView();
					break;
				}

				if (msg.x >= 440 && msg.x <= 440 + 120 && msg.y >= 260 && msg.y <= 260 + 40)
				{
					//放函数 void PrintArchive(); 进入 保存存档 界面
					SaveArchiveView();
					break;
				}

				if (msg.x >= 440 && msg.x <= 440 + 120 && msg.y >= 320 && msg.y <= 320 + 40)
				{
					//放函数 void PrintGameLoad();
					ChooseArchiveViewInGame();
					break;
				}

				if (msg.x >= 440 && msg.x <= 440 + 120 && msg.y >= 380 && msg.y <= 380 + 40)
				{
					//放函数 rintMenu();
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

// 从暂停界面 进入 保存存档 界面
int SaveArchiveView() {
	cleardevice();
	BottonArchive1(440, 150, 120, 40);//按钮的x y w h
	BottonArchive2(620, 160, 120, 40);
	BottonArchive3(440, 250, 120, 40);
	BottonArchive4(440, 320, 120, 40);
	BottonArchive5(440, 390, 120, 40);
	BottonArchive6(440, 460, 120, 40);

	ExMessage msg;
	while (true)
	{
		if (peekmessage(&msg, EM_MOUSE))//如果有鼠标消息，则返回真，反之则假
		{
			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				if (msg.x >= 440 && msg.x <= 440 + 120 && msg.y >= 150 && msg.y <= 150 + 40)
				{
					//无需操作
					break;
				}

				if (msg.x >= 620 && msg.x <= 620 + 120 && msg.y >= 160 && msg.y <= 160 + 40)
				{
					//无需操作
					break;
				}

				if (msg.x >= 440 && msg.x <= 440 + 120 && msg.y >= 250 && msg.y <= 250 + 40)
				{
					//无需操作
					break;
				}

				if (msg.x >= 440 && msg.x <= 440 + 120 && msg.y >= 320 && msg.y <= 320 + 40)
				{
					//无需操作
					break;
				}

				if (msg.x >= 440 && msg.x <= 440 + 120 && msg.y >= 390 && msg.y <= 390 + 40)
				{
					//无需操作
				}

				if (msg.x >= 440 && msg.x <= 440 + 120 && msg.y >= 460 && msg.y <= 460 + 40)
				{
					//放函数  返回暂停;
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
