#include "函数声明.h" //函数声明

//第三关——————————————————————————————
//标志变量
int sign_ice = 0; //当在水旁使用 两点水 的时候，变为1
int sign_begintext3 = 0;
int sign_twowater = 0; // 探索冯
int sign_keytext = 0;
int sign_1 = 0; //为了使得printsecond函数里的sleep使用一次
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

	settextstyle(0, 0, "宋体");

	cleardevice();
	wo_y = 380;//"我"的现在坐标
	wo_x = 190;
	wo_X = wo_x;
	wo_Y = wo_y;



	GodBarrierView();

	getchar();
	return 0;
}

//仙剑关主页面
void GodBarrierView() {

	space = 20;
	left_distance = 170;
	top_distance = 100;

	if (sign_begintext3 == 0) {
		PrintGodGame();
		outtextxy(wo_x, wo_y, "我");
		outtextxy(10, 10, "我一覺醒來，發現自己深處異境.....");
		Sleep(1000);
		cleardevice();
		PrintGodGame();
		outtextxy(wo_x, wo_y, "我");
		outtextxy(10, 10, "旁邊有一把劍......        按下 [ 空格 ] 拾取");
		Sleep(1000);
		sign_begintext3 = 1;
	}



	while (1)
	{
		cleardevice();

		BeginBatchDraw();//批量绘图防画面卡顿

		if (sign_ice == 0)
		{
			PrintGodGame();
		}

		else if (sign_ice == 1)
		{
			PrintSecondGodGame();
		}
		outtextxy(wo_x, wo_y, "我");

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

//-----------------------------------------------------------函数定义-------------------------------------------------------------//

void InformationOfGodBarrier() {

	//剑
	if (GetAsyncKeyState(VK_SPACE) && wo_x == 190 && wo_y == 380)
	{
		mciSendString("open 字意5.mp3 ", 0, 0, 0);
		mciSendString("play 字意5.mp3 ", 0, 0, 0);
		outtextxy(10, 10, "我：获得武器 剑 ");
		map_3[13][1] = 0;
		map_3_temp[13][1] = 0;
		PrintGodGame();
	}

	//仙
	if (GetAsyncKeyState(VK_SPACE) && wo_x == 410 && wo_y == 380)
	{
		outtextxy(10, 10, "仙：孩子，你終於來啦，我等你好久了... ");
		Sleep(800);
		outtextxy(10, 30, "這裡是【馮家莊】，冯字很有深意哦... ");
		Sleep(800);
		outtextxy(10, 50, "去吧，池塘中有你想要的東西... ");
		Sleep(1500);
		cleardevice();
		PrintGodGame();
		outtextxy(wo_x, wo_y, "我");
		outtextxy(10, 10, "我:感到很疑惑......但還是決定去看看 ");
		Sleep(1000);
	}

	//石头
	if (GetAsyncKeyState(VK_SPACE) &&
		wo_x >= 210 && wo_y >= 320 &&
		wo_x <= 250 && wo_y <= 360)
	{
		outtextxy(10, 10, "這是普通的石頭...... ");

		PrintGodGame();
	}
	if (GetAsyncKeyState(VK_SPACE) &&
		wo_x >= 210 && wo_y >= 400 &&
		wo_x <= 250 && wo_y <= 440)
	{
		outtextxy(10, 10, "這是普通的石頭...... ");

		PrintGodGame();
	}

	//冯
	if (GetAsyncKeyState(VK_SPACE) && wo_x == 250 && wo_y == 220)
	{
		mciSendString("open 字意6.mp3 ", 0, 0, 0);
		mciSendString("play 字意6.mp3 ", 0, 0, 0);
		outtextxy(10, 10, "获得冫和 马");
		map_3[5][4] = 0;
		map_3_temp[5][4] = 0;
		PrintGodGame();
		sign_twowater = 1;
	}

	//结冰
	if (sign_twowater == 1 &&
		GetAsyncKeyState(VK_SPACE) &&
		wo_x >= 450 && wo_y <= 460 &&
		wo_x <= 590 && wo_y >= 260)
	{
		sign_ice = 1;
		printf("进入结冰函数");
		PrintSecondGodGame();
		outtextxy(wo_x, wo_y, "我");
		Sleep(800);
		outtextxy(10, 10, "我：用刚才获得的“冫”和前面的“水”结合，竟然让水变成了冰，这就是仙界吗？ ");
		PrintSecondGodGame();
	}

	//宝箱
	if (GetAsyncKeyState(VK_SPACE) &&
		wo_x >= 610 && wo_y <= 420 &&
		wo_x <= 690 && wo_y >= 340)
	{
		sign_keytext = 1;
		PrintSecondGodGame();
		outtextxy(wo_x, wo_y, "我");
	}

	//删 不 字
	if (GetAsyncKeyState(VK_BACK) &&
		wo_x == 370 && wo_y == 60)
	{
		mciSendString("open 删2.mp3 ", 0, 0, 0); //放不出来
		mciSendString("play 删2.mp3 ", 0, 0, 0);
		sign_keytext2 = 1; //按下删除键后不字消失

		cleardevice();
		PrintSecondGodGame();
		outtextxy(wo_x, wo_y, "我");
		rectangle(12, 44, 552, 67); //方框
		mciSendString("open 字意4.mp3 ", 0, 0, 0);
		mciSendString("play 字意4.mp3 ", 0, 0, 0);
		Sleep(1000);


		sign_keytext = 0;
		cleardevice();
		PrintSecondGodGame();
		outtextxy(10, 10, "仙：年輕人，恭喜你習得秘術。 ");
		Sleep(1000);
		outtextxy(10, 30, "現如今妖魔橫行，導致生靈塗炭、民不聊生...... ");
		Sleep(1000);
		outtextxy(10, 50, "是選擇降妖除魔拯救蒼生，亦或是隱匿山林之中，不問世事...");
		Sleep(1000);
		outtextxy(10, 70, "一切選擇終將取決於你...孩子，咱們有緣再會...");
		outtextxy(810, 380, "我");
		outtextxy(850, 380, "恭喜你闯关成功！");
		Sleep(2000);


		CommonPassView();

	}



}

//移动功能
void Move_3()
{

	InformationOfGodBarrier();

	char key = _getch();

	switch (key)
	{
	case 72:  //↑：ASCII
	case 'w':
	case 'W':
		//判断"我"新坐标所在数组元素的值(用现在坐标表示)：如果是0，则可移动；否则不动
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
	case 72:  //↑：ASCII
	case 'w':
	case 'W':
		//判断"我"新坐标所在数组元素的值(用现在坐标表示)：如果是0，则可移动；否则不动
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
			case 1:outtextxy(word_x, word_y, "云"); break;
			case 2:outtextxy(word_x, word_y, "鸟"); break;
			case 3:outtextxy(word_x, word_y, "树"); break;
			case 4:outtextxy(word_x, word_y, "木"); break;
			case 5:outtextxy(word_x, word_y, "房"); break;
			case 6:outtextxy(word_x, word_y, "草"); break;
			case 7:outtextxy(word_x, word_y, "门"); break;
			case 8:outtextxy(word_x, word_y, "路"); break;
			case 9:outtextxy(word_x, word_y, "水"); break;
			case 10:outtextxy(word_x, word_y, "箱"); break;
			case 11:outtextxy(word_x, word_y, "宝"); break;
			case 12:outtextxy(word_x, word_y, "仙"); break;
			case 13:outtextxy(word_x, word_y, "石"); break;
			case 14:outtextxy(word_x, word_y, "剑"); break;
			case 16:outtextxy(word_x, word_y, "冯"); break;
			case 17:outtextxy(word_x, word_y, "家"); break;
			case 18:outtextxy(word_x, word_y, "壮"); break;
			case 19:outtextxy(word_x, word_y, "冰"); break;
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
			case 1:outtextxy(word_x, word_y, "云"); break;
			case 2:outtextxy(word_x, word_y, "鸟"); break;
			case 3:outtextxy(word_x, word_y, "树"); break;
			case 4:outtextxy(word_x, word_y, "木"); break;
			case 5:outtextxy(word_x, word_y, "房");	break;
			case 6:outtextxy(word_x, word_y, "草"); break;
			case 7:outtextxy(word_x, word_y, "门"); break;
			case 8:outtextxy(word_x, word_y, "路"); break;
			case 9:outtextxy(word_x, word_y, "水"); break;
			case 10:outtextxy(word_x, word_y, "箱"); break;
			case 11:outtextxy(word_x, word_y, "宝"); break;
			case 12:outtextxy(word_x, word_y, "仙"); break;
			case 13:outtextxy(word_x, word_y, "石"); break;
			case 14:outtextxy(word_x, word_y, "剑"); break;
			case 16:outtextxy(word_x, word_y, "冯");	break;
			case 17:outtextxy(word_x, word_y, "家"); break;
			case 18:outtextxy(word_x, word_y, "壮"); break;
			case 19:outtextxy(word_x, word_y, "冰"); break;
			}
		}
	}

	if (sign_keytext == 1)
	{
		outtextxy(10, 3, "這是一本【武功秘籍】，上面記載了一套劍法......");
		if (sign_1 == 0) { Sleep(1000); }
		outtextxy(10, 23, "在打開秘籍的同時，劍在我的四周盤旋，最後進入了我的體內...... ");
		if (sign_1 == 0) { Sleep(1000); }
		outtextxy(10, 43, "同時感到一股強大的力量在體內流動，我  能忍受著這股力量...... ");

		if (sign_keytext2 == 0) //按下删除键之后就不会显示 不 字
		{
			outtextxy(298, 43, "不");
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
			case 2:outtextxy(400 + j * 30, 300 + i * 30, "剑");
				break;
			case 1:outtextxy(400 + j * 30, 300 + i * 30, "我");
				break;
			}
		}
	}
}