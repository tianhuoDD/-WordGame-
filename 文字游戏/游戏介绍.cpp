#include "函数声明.h" //函数声明

//二、“游戏介绍”界面
int IntroView() {
	cleardevice();
	ButtonIntro1(320, 480, 120, 40);//按钮的x y w h
	ButtonIntro2(440, 480, 120, 40);
	ButtonIntro3(585, 480, 120, 40);
	ButtonIntro4(440, 80, 120, 40);
	settextstyle(20, 0, "Zpix");
	char text1[50] = "玩家控制“我”进行一系列的剧情探索，";
	char text2[50] = "在探索过程中可以获得特殊能力来增强自己，";
	char text3[50] = "从而提高自己破解剧情的能力。每个剧情都";
	char text4[50] = "有不一样的彩蛋哦！努力去探索吧！！";
	char text5[50] = "移动—— wasd方向键";
	char text6[50] = "调查、与NPC交互—— 按“空格”键";
	char text7[50] = "删/拆字—— 按“Backspace”键";
	char text8[50] = "复活 ——点击";
	char text9[50] = "暂停—— Esc";
	char text10[50] = "道具使用和切换—— 按“空格”键";
	char text11[50] = "————————————————————";

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
		if (peekmessage(&msg, EM_MOUSE))//如果有鼠标消息，则返回真，反之则假
		{
			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				if (msg.x >= 320 && msg.x <= 320 + 120 && msg.y >= 480 && msg.y <= 480 + 40)
				{
					//放函数 void PrintGameTips();
					StrategyView();
					break;
				}

				if (msg.x >= 440 && msg.x <= 440 + 120 && msg.y >= 480 && msg.y <= 480 + 40)
				{
					//放函数 void PrintTeamDetails();
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
//2.1游戏攻略 界面
int StrategyView() {
	cleardevice();
	ButtonStrategy1(440, 480, 120, 40);//按钮的x y w h
	ButtonStrategy2(850, 480, 120, 40);
	settextstyle(25, 0, "Zpix");
	outtextxy(200, 225, "主");
	outtextxy(200, 250, "线");
	outtextxy(200, 275, "攻");
	outtextxy(200, 300, "略");
	settextstyle(20, 0, "Zpix");
	//按K键与柜交互，获得石刀，与灯交互，（灯变为火）用火点燃“柜”，趁看守进来，
	//在出现的对话中按J键删掉“你”字，放入“我”按K键，用石刀杀掉看守，
	//拿起看守的钥匙，按J键划破画，再拆开墙字，凿穿土进入下水道。
	char text1[70] = "第一关：按“空格”键与柜交互，获得石刀，与灯交互，";
	char text2[60] = "用火点燃“柜”，趁看守进来，在出现的对话中按";
	char text3[80] = "“Backspace”键，删掉“你”字，放入“我”按“空格”键，";
	char text4[60] = "拿起看守的钥匙，按Backspace键划破画，再拆开墙字，";
	char text5[50] = "凿穿土，进入下水道。";
	//第二关：在开始的对白中，把“我”放在对白空处按K键处开始游戏，
	//按K键与锁交互用钥匙打开通风，在对白2中按J键删除“没”字，
	//吹散毒气，进入门中按K键成功逃出。
	char text6[70] = "第二关：在开始的对白中，把“我”放在对白空处按“空格”键开始";
	char text7[70] = "游戏，按“空格”与锁交互用钥匙打开通风，吹散毒气，";
	char text8[50] = "进入门中成功逃出。";
	char text11[70] = "————————————————————————";

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
		if (peekmessage(&msg, EM_MOUSE))//如果有鼠标消息，则返回真，反之则假
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
					//放函数 void PrintHiddenTips();
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
//2.2 彩蛋攻略
int EggStrategyView() {
	cleardevice();
	ButtonEgg1(530, 480, 120, 40);//按钮的x y w h
	ButtonEgg2(350, 480, 120, 40);
	settextstyle(25, 0, "Zpix");
	outtextxy(200, 225, "彩");
	outtextxy(200, 250, "蛋");
	outtextxy(200, 275, "攻");
	outtextxy(200, 300, "略");
	settextstyle(20, 0, "Zpix");
	//【我】捡起身边的【剑】，加入背包进门【門】；
	//碰见【仙】人，从【仙】人的话中拆解【冯】字，变成【冫】和【马】；
	//将【冫】推到【水】边，结合成【冰】，用剑将【冰】拆除抵达宝箱获得秘籍；
	//从“不能承受这股力量”中删除【不】字获得力量，骑上【马】池塘另一边的【門】离开。

	char text1[50] = "【我】捡起身边的【剑】，加入背包进门【門】；碰";
	char text2[60] = "见【仙】人，从【仙】人的话中拆解【冯】字，变成【冫】";
	char text3[60] = "和【马】；将【冫】推到【水】边，结合成【冰】，用剑将";
	char text4[60] = "【冰】拆除抵达宝箱获得秘籍；从“不能承受这股力量”中";
	char text5[60] = "删除【不】字获得力量，骑上【马】池塘另一边的【門】离";
	char text6[50] = "开。";
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
		if (peekmessage(&msg, EM_MOUSE))//如果有鼠标消息，则返回真，反之则假
		{
			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				if (msg.x >= 530 && msg.x <= 530 + 120 && msg.y >= 480 && msg.y <= 480 + 40)
				{
					//放函数 PrintMenu();
					MenuView();
					break;
				}

				if (msg.x >= 350 && msg.x <= 350 + 120 && msg.y >= 480 && msg.y <= 480 + 40)
				{
					//放函数 void PrintGameTips();
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
//2.3 制作成员 介绍
int MadeView() {
	cleardevice();
	ButtonMade1(440, 100, 120, 40);//按钮的x y w h
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
		if (peekmessage(&msg, EM_MOUSE))//如果有鼠标消息，则返回真，反之则假
		{
			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				if (msg.x >= 440 && msg.x <= 440 + 120 && msg.y >= 100 && msg.y <= 100 + 40)
				{
					//无需操作
				}

				if (msg.x >= 440 && msg.x <= 440 + 120 && msg.y >= 160 && msg.y <= 120 + 40)
				{
					//无需操作
				}

				if (msg.x >= 440 && msg.x <= 440 + 120 && msg.y >= 190 && msg.y <= 190 + 40)
				{
					//无需操作
				}

				if (msg.x >= 440 && msg.x <= 440 + 120 && msg.y >= 220 && msg.y <= 220 + 40)
				{
					//无需操作
				}

				if (msg.x >= 440 && msg.x <= 440 + 120 && msg.y >= 250 && msg.y <= 250 + 40)
				{
					//无需操作
				}

				if (msg.x >= 440 && msg.x <= 440 + 120 && msg.y >= 280 && msg.y <= 280 + 40)
				{
					//无需操作
				}

				if (msg.x >= 440 && msg.x <= 440 + 120 && msg.y >= 310 && msg.y <= 310 + 40)
				{
					//无需操作
				}

				if (msg.x >= 440 && msg.x <= 440 + 120 && msg.y >= 340 && msg.y <= 340 + 40)
				{
					//无需操作
				}

				if (msg.x >= 440 && msg.x <= 440 + 120 && msg.y >= 370 && msg.y <= 370 + 40)
				{
					//无需操作
				}

				if (msg.x >= 440 && msg.x <= 440 + 120 && msg.y >= 450 && msg.y <= 450 + 40)
				{
					//添加函数（返回菜单）
					MenuView();

				}

				if (msg.x >= 700 && msg.x <= 700 + 120 && msg.y >= 400 && msg.y <= 400 + 40)
				{
					//无需操作
				}
			}
		}


	}

	getchar();
	return 0;
}