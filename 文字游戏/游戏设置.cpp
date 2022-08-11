#include "函数声明.h" //函数声明

//三、“游戏设置”界面
int SetView() {
	cleardevice();
	button1(440, 150, 120, 40);//按钮的x y w h
	button2(440, 250, 120, 40);
	button3(440, 320, 120, 40);
	button4(440, 400, 120, 40);
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

				if (msg.x >= 440 && msg.x <= 440 + 120 && msg.y >= 250 && msg.y <= 250 + 40)
				{
					//放函数 （进入基础设置界面）
					BasicSetView2();
					break;
				}

				if (msg.x >= 440 && msg.x <= 440 + 120 && msg.y >= 320 && msg.y <= 320 + 40)
				{
					//放函数 (进入玩法设置界面);
					ModeSetView();
					break;
				}

				if (msg.x >= 440 && msg.x <= 440 + 120 && msg.y >= 400 && msg.y <= 400 + 40)
				{
					//放函数 (返回菜单);
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

//3.2玩法设置!!(break在if后面——）
int ModeSetView() {
	cleardevice();
	BottonMode1(440, 150, 120, 40);//按钮的x y w h
	BottonMode2(300, 280, 120, 40);
	BottonMode3(600, 280, 120, 40);
	BottonMode4(440, 400, 120, 40);
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
					//无界面跳转

					break;
				}

				if (msg.x >= 440 && msg.x <= 440 + 120 && msg.y >= 250 && msg.y <= 250 + 40)
				{
					//放函数 （//service需要函数功能：调整游戏地图为第一关界面（默认））

					break;
				}

				if (msg.x >= 440 && msg.x <= 440 + 120 && msg.y >= 320 && msg.y <= 320 + 40)
				{
					//放函数 (//service需要函数功能：调整游戏地图为仙剑奇缘界面);
					break;
				}

				if (msg.x >= 440 && msg.x <= 440 + 120 && msg.y >= 390 && msg.y <= 390 + 40)
				{
					//放函数 (返回游戏设置);
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

// 基础设置界面
void BasicSetView1(void) //新建一个只打印界面选项的函数
{

	settextcolor(WHITE);//整体界面字体颜色
	settextstyle(25, 0, "Zpix");//整体界面字体样式

	outtextxy(400, 50, "游戏设置");
	//更改界面字体
	outtextxy(200, 150, "字体设置:");
	outtextxy(400, 150, "Zpix");
	outtextxy(500, 150, "宋体");
	outtextxy(600, 150, "华文行楷");
	outtextxy(750, 150, "LiSu");

	outtextxy(200, 250, "音量大小:");
	outtextxy(400, 250, "+    -");

	outtextxy(200, 350, "背景音乐:");
	outtextxy(400, 350, "1.开     2.关");

	outtextxy(900, 500, "返回");
}

//3.1基础设置
int BasicSetView2()
{
	cleardevice();

	BasicSetView1(); //调用上面定义的界面函数

	ExMessage m; //定义m为 ExMessage 类型； 
	//在m后面加上后缀就可以表示鼠标相关信息了
		//m.x 和 m.y 表示鼠标的坐标
		//m.message 表示鼠标的 左键 或 右键 或 中键

	while (1) //表示不断处理事物
	{
		if (peekmessage(&m, EM_MOUSE))
		{
			if (m.message == WM_LBUTTONDOWN && m.x >= 150 && m.x <= 250 && m.y >= 90 && m.y <= 100)
				//.message表示鼠标的消息。WM_LBUTTONDOWN表示 按下左键
			{
				cleardevice(); //为了清楚楷体的下横线，清屏，然后再调用界面函数，就实现点击一个选项，显示一个选项
				SetView();
				outtextxy(200, 100, "____"); //横线的坐标就是Zpix的坐标
				settextstyle(50, 0, "Zpix");//在控制台中显示

			}

			if (m.message == WM_LBUTTONDOWN && m.x >= 250 && m.x <= 350 && m.y >= 90 && m.y <= 100)
			{
				cleardevice(); //为了清楚楷体的下横线，清屏，然后再调用界面函数，就实现点击一个选项，显示一个选项

				outtextxy(300, 100, "____");
				SetView();
				settextstyle(50, 0, "宋体");
			}

			if (m.message == WM_LBUTTONDOWN && m.x >= 350 && m.x <= 450 && m.y >= 90 && m.y <= 100)
			{
				cleardevice(); //为了清楚楷体的下横线，清屏，然后再调用界面函数，就实现点击一个选项，显示一个选项

				outtextxy(400, 100, "____");
				SetView();
				settextstyle(50, 0, "华文行楷");
			}

			if (m.message == WM_LBUTTONDOWN && m.x >= 450 && m.x <= 550 && m.y >= 90 && m.y <= 100)
			{
				cleardevice(); //为了清楚楷体的下横线，清屏，然后再调用界面函数，就实现点击一个选项，显示一个选项

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
