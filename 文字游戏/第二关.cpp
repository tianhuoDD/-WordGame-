#include "函数声明.h" //函数声明

//第二关——————————————————————————————
//标志变量
int sign_secondbarrier = 0; //第一次进入下水道时显示对白
int sign_begintext = 0; //标志：如果为1则打印第一次进入第二关时开始游戏的文本
//int sign_rect = 0;
int sign_information = 0; //如果为1，代表正式开启第一关
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
//第二关主页面
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
		outtextxy(wo_x, wo_y, "我");

		EndBatchDraw();

		Move2();
	}
}

//-------------------------------4.函数定义-----------------------------------------//
//第二关 信息交互
void InformationOfSecondBarrier()
{

	settextstyle(25, 0, "Zpix");

	//第一次进入第二关的对白
	if (sign_secondbarrier == 0)
	{
		sign_begintext = 1; //打印开始游戏的文本
		sign_secondbarrier = 1; //从第二次进入第二关就不会显示这个文本了
		Sleep(500);
		PrintSecondGame();
	}

	if (wo_x == 550 &&		//如果走到了开始游戏文本空缺位置按下空格
		wo_y == 380 &&
		GetAsyncKeyState(VK_SPACE))
	{

		mciSendString("open 字意3.mp3 ", 0, 0, 0);
		mciSendString("play 字意3.mp3 ", 0, 0, 0);

		rectangle(158, 378, 608, 438); //出现方框

		//sign_rect = 1;
		sign_begintext = 0; //走到语句空缺位置按下空格后就不再打印第一次进入第二关的对白
		sign_information = 1;
		PrintSecondGame();
	}

	//锁
	if (sign_information == 1 &&
		wo_x == left_distance + 12 * space &&
		wo_y == top_distance + 2 * space &&
		GetAsyncKeyState(VK_SPACE))
	{
		if (tool_key == 0) { outtextxy(10, 10, "这把锁好像是用来挡风的..."); }
		if (tool_key == 1) //如果获得了钥匙
		{
			//成功
			mciSendString("open 吹散毒气.mp3 ", 0, 0, 0);
			mciSendString("play 吹散毒气.mp3 ", 0, 0, 0);

			sign_openlock = 1; //打开了 锁 的标志
			map_second[1][12] = 0; //开了锁后，删除毒字
			map_second[5][16] = 0; //开了锁后，删除锁字

			cleardevice();
			outtextxy(10, 10, "细口里的风透过门缝把毒气吹到门外面去了...");
			outtextxy(wo_x, wo_y, "我");
			PrintSecondGame();
			Sleep(300);

		}
	}

	//毒
	if (sign_information == 1 && sign_openlock != 1 &&
		wo_x >= left_distance + 13 * space && wo_x <= left_distance + 15 * space &&
		wo_y == top_distance + 5 * space)
	{
		BeginBatchDraw();
		outtextxy(10, 10, "好刺鼻难闻的毒气，直接碰上去可能会中毒身亡吧...");
		EndBatchDraw();
	}

	//如果没有打开锁就走到 毒 的位置
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
		outtextxy(290, 100, "进入下一关");
	}

	//返回第一关
	if (
		wo_x == left_distance + 0 * space
		&& wo_y == top_distance + 5 * space)
	{
		FirstGameService();
	}

	//通关跳转界面
	if (
		wo_x == left_distance + 20 * space
		&& wo_y == top_distance + 5 * space)
	{
		SuccessSkipView();
	}

}

//第二关 移动
void Move2() {

	InformationOfSecondBarrier();

	char key = _getch();

	switch (key) {
	case 72:  //↑：ASCII
	case 'w':
	case 'W':
		//判断"我"新坐标所在数组元素的值(用现在坐标表示)：如果是0，则可移动；否则不动
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

//图像——打印第二关地图
void PrintSecondGame(void)
{
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 21; j++) {

			int word_x = left_distance + j * space;
			int word_y = top_distance + i * space;

			switch (map_second[i][j])
			{
			case 1: outtextxy(word_x, word_y, "墙"); break;
			case 2: outtextxy(word_x, word_y, "我"); break;
			case 3: outtextxy(word_x, word_y, "管"); break;
			case 4: outtextxy(word_x, word_y, "锁");	break;
			case 5: outtextxy(word_x, word_y, "水");	break;
			case 93: outtextxy(word_x, word_y, "门"); break;
			case 91: outtextxy(word_x, word_y, "洞"); break;
			case 94: outtextxy(word_x, word_y, "毒");	break;
			case 9: outtextxy(word_x, word_y, "刀"); break;
			case 10: outtextxy(word_x, word_y, "风"); break;
			default:break;
			}
		}
	}

	if (tool_wood == 1) { outtextxy(bag_x + 90 - textwidth("木棒") / 2, bag_y + 60, "木棒"); }
	if (tool_knife == 1) { outtextxy(bag_x + 90 - textwidth("石尖刀") / 2, bag_y + 100, "石尖刀"); }
	if (tool_torch == 1) { outtextxy(bag_x + 90 - textwidth("火把") / 2, bag_y + 140, "火把"); }
	if (tool_key == 1) { outtextxy(bag_x + 90 - textwidth("钥匙") / 2, bag_y + 180, "钥匙"); }
	if (sign_begintext == 1)
	{

		outtextxy(left_distance + 4 * space, top_distance + 7 * space, "终于来到下水道，迎面一股臭气,     要");
		outtextxy(left_distance + 4 * space, top_distance + 8 * space, "快点离开这儿");
	}

	ESC();
	Bag();
}