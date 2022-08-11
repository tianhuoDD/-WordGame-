#include "函数声明.h" //函数声明

//主菜单界面 
int MenuView() {
	cleardevice();
	button_menu_1(440, 200, 120, 40);//按钮的x y w h
	button_menu_2(440, 260, 120, 40);
	button_menu_3(440, 320, 120, 40);
	button_menu_4(440, 380, 120, 40);
	button_menu_5(440, 100, 120, 40);
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
					//放函数 PrintGameOption();
					ProcessView();
					break;
				}

				if (msg.x >= 440 && msg.x <= 440 + 120 && msg.y >= 260 && msg.y <= 260 + 40)
				{
					//放函数 PrintGameIntro();
					IntroView();
					break;
				}

				if (msg.x >= 440 && msg.x <= 440 + 120 && msg.y >= 320 && msg.y <= 320 + 40)
				{
					//放函数 PrintGameSettings();
					SetView();
					break;
				}

				if (msg.x >= 440 && msg.x <= 440 + 120 && msg.y >= 380 && msg.y <= 380 + 40)
				{
					ExitView();//放函数 
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

//四、退出界面
void ExitView() {

	cleardevice();
	settextstyle(25, 0, "Zpix");
	char restarttext[50] = "nonono再玩一会儿";
	outtextxy(370, 390, restarttext);//文字居中
	roundrect(360, 380, 580, 420, 15, 15);
	settextstyle(25, 0, "Zpix");
	char quittext[50] = "狠心退出，下次见";
	outtextxy(370, 320, quittext);//文字居中
	roundrect(360, 310, 580, 350, 15, 15);

	settextstyle(50, 0, "Zpix");
	char xintengtext[50] = "你...你真的要离开吗？";
	outtextxy(220, 130, xintengtext);//文字居中

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

//1.x 死亡界面
void DeathView() {

	cleardevice();
	settextstyle(20, 0, "Zpix");
	char deathtext[50] = " 你....陷入了黑暗，时光回溯，你来到了最初的位置。";
	outtextxy(250, 290, deathtext);//文字居中

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

//零、登录界面
int login()
{
	//mciSendString("open 安静.mp3", 0, 0, 0);
	//mciSendString("play 安静.mp3", 0, 0, 0);

	cleardevice();
	ButtonLogin1(440, 100, 120, 40);//按钮的x y w h
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
		if (peekmessage(&msg, EM_MOUSE))//如果有鼠标消息，则返回真，反之则假
		{
			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				//if (msg.x >= 440 && msg.x <= 440 + 120 && msg.y >= 100 && msg.y <= 100 + 40)
				//{
				//	//无需操作
				//}
				//break;
				//if (msg.x >= 250 && msg.x <= 250 + 120 && msg.y >= 220 && msg.y <= 220 + 40)
				//{
				//	//无需操作
				//}
				//break;
				//if (msg.x >= 250 && msg.x <= 250 + 120 && msg.y >= 290 && msg.y <= 290 + 40)
				//{
				//	//无需操作
				//}
				//break;
				if (msg.x >= 630 && msg.x <= 630 + 120 && msg.y >= 290 && msg.y <= 290 + 40)
				{
					find_password();
					break;
				}

				if (msg.x >= 340 && msg.x <= 340 + 120 && msg.y >= 410 && msg.y <= 410 + 40)
				{
					MenuView();//调函数（跳转至菜单界面）
					break;
				}

				if (msg.x >= 550 && msg.x <= 550 + 120 && msg.y >= 410 && msg.y <= 410 + 40)
				{
					rigster();
					break;
				}

				if (msg.x >= 360 && msg.x <= 360 + 280 && msg.y >= 220 && msg.y <= 220 + 40)
				{
					//输入文本
					break;
				}

				if (msg.x >= 360 && msg.x <= 360 + 280 && msg.y >= 290 && msg.y <= 290 + 40)
				{
					//输入文本
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
//注册界面
int rigster()
{
	cleardevice();
	//矩形按钮位置
	ButtonReg1(400, 450, 150, 50);
	ButtonReg2(410, 145, 250, 40);
	ButtonReg2(410, 220, 250, 40);
	ButtonReg2(410, 295, 250, 40);
	ButtonReg2(410, 370, 250, 40);
	//页面文字设置
	settextcolor(WHITE);
	settextstyle(40, 0, "Zpix");

	outtextxy(420, 50, "注册页面");
	//
	settextstyle(30, 0, "Zpix");
	outtextxy(300, 150, "用户名:");
	outtextxy(329, 225, "账号:");
	outtextxy(329, 300, "密码:");
	outtextxy(270, 375, "确认密码:");

	setlinecolor(WHITE);
	setlinestyle(PS_SOLID, 1);
	/*circle(705,165, 20);*/

	//插入图片
	IMAGE img;
	loadimage(&img, "小组件.png", 95, 65);
	putimage(680, 132, &img);
	putimage(680, 207, &img);
	putimage(680, 282, &img);
	putimage(680, 357, &img);

	ExMessage msg;
	while (true)
	{
		if (peekmessage(&msg, EM_MOUSE))//如果有鼠标消息，则返回真，反之则假
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
//找回密码界面
int find_password()
{
	cleardevice();
	//矩形按钮位置
	ButtonBack1(430, 420, 150, 50);//“确定”按钮的位置
	ButtonBack2(480, 222, 250, 40);//“单行输入”按钮位置
	ButtonBack2(480, 320, 250, 40);//“单行输入”按钮位置


	//页面文字设置
//设置背景为透明模式
	settextstyle(50, 0, "Zpix");
	outtextxy(410, 100, "找回密码");

	settextstyle(25, 0, "Zpix");
	char text1[50] = "注册的用户名:";
	char text2[50] = "注册的账号:";
	outtextxy(260, 225, text1);
	outtextxy(260, 325, text2);

	ExMessage msg;
	while (true)
	{
		if (peekmessage(&msg, EM_MOUSE))//如果有鼠标消息，则返回真，反之则假
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

//找回成功界面
int success_find()
{
	cleardevice();
	//矩形按钮位置
	ButtonSuccess1(430, 420, 150, 50);//“确定”按钮的位置x,y,w,h
	ButtonSuccess2(480, 222, 250, 40);//“单行输入”按钮位置x,y,w,h
	ButtonSuccess2(480, 320, 250, 40);//“单行输入”按钮位置想x,y,w,h
	//页面文字设置

	settextstyle(50, 0, "Zpix");
	outtextxy(405, 100, "找回成功！");
	//
	settextstyle(25, 0, "Zpix");
	char text3[50] = "新密码:";
	char text4[50] = "确认新密码:";
	outtextxy(317, 225, text3);
	outtextxy(260, 325, text4);

	ExMessage msg;
	while (true)
	{
		if (peekmessage(&msg, EM_MOUSE))//如果有鼠标消息，则返回真，反之则假
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