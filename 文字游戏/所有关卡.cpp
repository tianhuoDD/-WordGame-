#include "函数声明.h" //函数声明
//-----第一关----------第一关----------第一关----------第一关----------第一关----------第一关----------第一关-----
int space = 30;//文字间距
int left_distance;//地图与窗口左侧边距//即第一个字的x坐标
int top_distance;//地图与窗口顶端边距//即第一个字的y坐标
int wo_y, wo_x;//"我"的现在坐标
int wo_X, wo_Y;//赋初值：接下来的新坐标=现在坐标
int pause_graph_x = 760, pause_graph_y = 35;
int bag_x = 720, bag_y = 250;
//控制是否输出（第一关：删除画）
int delete_temp = 1;
//关卡标志
int sign_barrier_number;
//第一关 探索顺序的标志
int sign_case = 0;
int sign_light = 0;
int sign_text = 0;
int sign_painting = 0;
//第一关 打印工具的标志
int tool_wood = 0,
tool_knife = 0,
tool_key = 0,
tool_torch = 0;
//第一关 方框标志
int sign_rectangle = 0;
int sign_get = 0;
//第一关 地图（全局）
int map[13][21] = {
	{0,0,0,0,0,		0,0,0,10,11,	0,0,0,0,0,	0,0,0,0,0},
	{1,1,1,1,1,		1,1,1,1,1,		1,1,1,1,1,	1,1,1,1,1,	1},
	{1,1,0,0,0,		0,0,0,0,7,		0,0,0,0,0,	0,0,0,0,1,	1},
	{1,1,0,0,0,		0,0,0,0,0,		0,0,0,0,0,	0,0,0,0,1,	1},
	{1,1,0,0,0,		0,0,0,0,0,		0,0,0,0,0,	0,0,0,0,1,	1},
	{1,1,0,0,0,		0,0,0,0,0,		0,0,0,0,0,	0,0,0,0,1,	1},
	{8,8,5,0,0,		0,0,0,0,0,		0,0,0,0,0,	0,0,0,3,90,	91},
	{8,8,5,0,0,		0,0,0,0,0,		0,0,0,0,0,	0,0,0,0,1,	1},
	{1,1,0,0,0,		0,0,0,0,0,		0,0,0,0,0,	0,0,0,0,1,	1},
	{1,1,0,0,0,		0,0,0,0,0,		0,0,0,0,0,	0,0,4,4,1,	1},
	{1,1,0,0,0,		0,0,0,0,0,		0,0,0,6,6,	0,0,4,4,1,	1},
	{1,1,0,0,0,		0,0,0,0,0,		0,0,0,6,6,	0,0,4,4,1,	1},
	{1,1,1,1,1,		1,1,1,1,1,		1,1,1,1,1,	1,1,1,1,1,	1},
};

//第一关主页面
void FirstGameService() {

	sign_barrier_number = 1;
	left_distance = 40;
	top_distance = 170;
	wo_x = left_distance + space * 16;
	wo_y = top_distance + space * 9;
	wo_X = wo_x;
	wo_Y = wo_y;

	while (1)
	{
		cleardevice();

		BeginBatchDraw();//批量绘图防画面卡顿

		PrintFirstMap(); //3 打印第一关地图
		outtextxy(wo_x, wo_y, "我");

		EndBatchDraw();

		Move1();
	}
}

//--------------------------------4.函数定义----------------------------------------//

//图像——打印暂停按钮
void ESC() {
	settextstyle(25, 0, "Zpix");
	char text[50] = "ESC";
	outtextxy(pause_graph_x + 80 / 2 - textwidth(text) / 2, pause_graph_y + 40 / 2 - textheight(text) / 2, text);//文字居中
	roundrect(pause_graph_x, pause_graph_y, pause_graph_x + 80, pause_graph_y + 40, 15, 15);
}

//图像——打印背包
void Bag() {
	settextstyle(25, 0, "Zpix");
	char text[50] = "背包栏";
	outtextxy(bag_x + 90 - textwidth(text) / 2, bag_y + 10, text);//文字居中
	roundrect(bag_x, bag_y, bag_x + 180/*直接加上方框的宽度*/, bag_y + 250, 20, 20);
}

//文本互动
void InformationOfFirstBarrier()
{
	settextstyle(25, 0, "Zpix");

	//判断"我"现在的位置，如果在这个范围，且按某键，则特定位置输出文本

	//灯
	if (wo_x >= left_distance + space * 8 && wo_x <= left_distance + space * 10 &&
		wo_y >= top_distance + space * 2 && wo_y <= top_distance + space * 3 &&
		GetAsyncKeyState(VK_SPACE))
	{
		if (sign_case == 0) { outtextxy(10, 10, "摇曳的灯火似我人生飘忽不定..."); } //没有探索过柜子
		else if (sign_case == 1)	//探索过柜子
		{
			outtextxy(10, 10, "把木棒点燃获得一个火把...");
			mciSendString("open ./music/字意.mp3", 0, 0, 0);
			mciSendString("play ./music/字意.mp3 from 0", 0, 0, 0);

			sign_case = 2;
			sign_light = 1;		//获得火把
			tool_torch = 1;		//背包显示火把
			tool_wood = 0;		//背包取消显示木头

			cleardevice();
			PrintFirstMap();
			outtextxy(wo_x, wo_y, "我");
		}
		else if (sign_light == 1) { outtextxy(10, 10, "拿到火把后，灯火似乎更亮了..."); } //探索过柜子，探索过灯火
	}

	//画
	else if (wo_x >= left_distance + space * 17 && wo_x <= left_distance + space * 18 &&
		wo_y >= top_distance + space * 5 && wo_y <= top_distance + space * 7 &&
		GetAsyncKeyState(VK_SPACE)) {
		if (sign_painting == 0)
		{
			outtextxy(10, 10, "似乎没什么特别之处的画作，典狱长默许我挂在这儿...");
		}
		else;
	}

	//床
	else if (wo_x >= left_distance + space * 16 && wo_x <= left_distance + space * 18 &&
		wo_y >= top_distance + space * 8 && wo_y <= top_distance + space * 11 &&
		GetAsyncKeyState(VK_SPACE)
		) {
		outtextxy(10, 10, "每天在坚硬的床板上入睡，让我坚定了复仇之心...");
	}

	//锁
	else if (wo_x >= left_distance + space * 2 && wo_x <= left_distance + space * 3 &&
		wo_y >= top_distance + space * 5 && wo_y <= top_distance + space * 8 &&
		GetAsyncKeyState(VK_SPACE)
		) {
		outtextxy(10, 10, "门被铁锁锁住，无法打开...");
	}

	//洞
	else if (wo_x == left_distance + space * 19 &&
		wo_y == top_distance + space * 8 &&
		GetAsyncKeyState(VK_SPACE) && map[6][20] == 0)
	{
		outtextxy(10, 10, "洞的后面下水道...");
	}

	//删除 你
	else if (GetAsyncKeyState(VK_BACK) && wo_x == 370 && wo_y == 440)
	{
		//成功
		mciSendString("open ./music/删.mp3 ", 0, 0, 0);
		mciSendString("play ./music/删.mp3 from 0", 0, 0, 0);

		map[8][11] = 0;
		cleardevice();
		outtextxy(wo_x, wo_y, "我");
		PrintFirstMap();
	}

	//柜
	else if (wo_x >= left_distance + space * 12 && wo_x <= left_distance + space * 15 &&
		wo_y >= top_distance + space * 9 && wo_y <= top_distance + space * 11 &&
		GetAsyncKeyState(VK_SPACE)
		)
	{
		if (sign_case == 0) //如果没探索过柜子
		{
			outtextxy(10, 10, "获得一把 石尖刀 和一小根 木棒，石刀是我日夜打磨而成...");
			mciSendString("open ./music/字意.mp3 ", 0, 0, 0);
			mciSendString("play ./music/字意.mp3 ", 0, 0, 0);
			tool_wood = 1;
			tool_knife = 1;
			sign_case = 1;
			PrintFirstMap();
		}
		else if (sign_case == 1 && sign_light == 0) //探索过柜子，没探索灯火
		{
			outtextxy(10, 10, "刚才在这里获得一把'石尖刀'和一小根木棒，现在没什么东西了...");

		}
		else if (sign_light == 1 && sign_rectangle == 0) //探索过灯火，没有触发过守卫
		{
			//成功
			mciSendString("open ./music/点燃.mp3 ", 0, 0, 0);
			mciSendString("play ./music/点燃.mp3 from 0", 0, 0, 0);
			//mciSendString(" 点燃.mp3 ", 0, 0, 0);

			Sleep(1000);

			outtextxy(10, 10, "你不小心用火点燃一点火星，亮光吸引来了守卫");
			settextstyle(25, 0, "Zpix");

			map[10][3] = 20; // 守字出现
			//下面是守卫出现时所说的对话文本
			map[8][3] = 21;
			map[8][4] = 37;
			map[8][5] = 24;
			map[8][6] = 25;
			map[8][7] = 26;
			map[8][8] = 27;
			map[8][9] = 28;
			map[8][10] = 29;
			map[8][11] = 30;
			map[8][12] = 31;
			map[8][13] = 32;
			map[8][14] = 33;
			map[8][15] = 34;
			map[8][16] = 35;
			map[8][17] = 36;

			tool_torch = 0;

			sign_rectangle = 1; //此if语句只运行一次
			PrintFirstMap(); //在这里按下一次空格键，守卫和文本就出现了
		}

		else if (sign_case == 2) //探索过柜子，没探索灯火
		{
			outtextxy(10, 10, "简陋的柜子里已经什么也没有了...");
		}
	}

	//出现方框
	else if (wo_x == 370 && wo_y == 410 && GetAsyncKeyState(VK_SPACE) && sign_rectangle == 1)
	{
		sign_rectangle = 2; //此时不能触发"你不小心用火点燃一点火星，亮光吸引来了守卫"
		sign_get = 1;
		rectangle(120, 400, 580, 440);

		//失败
		mciSendString("open ./music/杀人.mp3 ", 0, 0, 0);
		mciSendString("play ./music/杀人.mp3 from 0", 0, 0, 0);

		outtextxy(10, 10, "用字意杀死了守卫，他身上好像掉了一串钥匙...");
		//Sleep(500);

		map[8][3] = 0;
		map[8][4] = 0;
		map[8][5] = 0;
		map[8][6] = 0;
		map[8][7] = 0;
		map[8][8] = 0;
		map[8][9] = 0;
		map[8][10] = 0;
		map[8][11] = 0;
		map[8][12] = 0;
		map[8][13] = 0;
		map[8][14] = 0;
		map[8][15] = 0;
		map[8][16] = 0;
		map[8][17] = 0;

		map[10][3] = 38;
		PrintFirstMap();

	}

	else if (GetAsyncKeyState(VK_SPACE) && wo_x == 160 && wo_y == 470 && sign_get == 1)
	{
		mciSendString("open ./music/获得物品.mp3 ", 0, 0, 0);
		mciSendString("play ./music/获得物品.mp3 ", 0, 0, 0);

		sign_get = 0;
		tool_key = 1;
		map[10][3] = 0;
		cleardevice();
		outtextxy(10, 10, "获得一把钥匙，监狱里就畅通无阻了...");
		outtextxy(wo_x, wo_y, "我");
		PrintFirstMap();
	}

	else if (wo_x == 640 && wo_y == 350)
	{

		cleardevice();
		outtextxy(wo_x, wo_y, "我");
		MainSecondBarrier();

	}
}

//第一关 移动功能
void Move1() {

	InformationOfFirstBarrier();

	char key = _getch();

	switch (key) {
	case 72:  //↑：ASCII
	case 'w':
	case 'W':
		//判断"我"新坐标所在数组元素的值(用现在坐标表示)：如果是0，则可移动；否则不动
		if (map[(wo_y - space - top_distance) / space][(wo_x - left_distance) / space] == 0 ||
			map[(wo_y - space - top_distance) / space][(wo_x - left_distance) / space] == 90 ||
			map[(wo_y - space - top_distance) / space][(wo_x - left_distance) / space] == 91)
		{
			wo_Y -= space;
			wo_y = wo_Y;
		}
		else;
		break;

	case 80:
	case 's':
	case 'S':
		if (map[(wo_y + space - top_distance) / space][(wo_x - left_distance) / space] == 0 ||
			map[(wo_y + space - top_distance) / space][(wo_x - left_distance) / space] == 90 ||
			map[(wo_y + space - top_distance) / space][(wo_x - left_distance) / space] == 91)
		{
			wo_Y += space;
			wo_y = wo_Y;
		}
		else;
		break;

	case 77:
	case 'd':
	case 'D':
		if (map[(wo_y - top_distance) / space][(wo_x + space - left_distance) / space] == 0 ||
			map[(wo_y - top_distance) / space][(wo_x + space - left_distance) / space] == 90 ||
			map[(wo_y - top_distance) / space][(wo_x + space - left_distance) / space] == 91)
		{
			wo_X += space;
			wo_x = wo_X;
		}
		else;
		break;

	case 75:
	case 'a':
	case 'A':
		if (map[(wo_y - top_distance) / space][(wo_x - space - left_distance) / space] == 0 ||
			map[(wo_y - top_distance) / space][(wo_x - space - left_distance) / space] == 90 ||
			map[(wo_y - top_distance) / space][(wo_x - space - left_distance) / space] == 91)
		{
			wo_X -= space;
			wo_x = wo_X;
		}
		else;
		break;

	case VK_ESCAPE:
		//delete_temp = 1;
		PauseView();
		break;
	}


}

//打印第一关地图
void PrintFirstMap()
{
	for (int i = 0; i < 13; ++i) {
		for (int j = 0; j < 21; ++j) {

			int word_x = left_distance + j * space;
			int word_y = top_distance + i * space;

			switch (map[i][j]) {
			case 1:outtextxy(word_x, word_y, "墙"); break;

			case 3:
				if (wo_x >= left_distance + space * 17 && wo_x <= left_distance + space * 18 &&
					wo_y >= top_distance + space * 5 && wo_y <= top_distance + space * 7 &&
					GetAsyncKeyState(VK_BACK))		//删除 画
				{
					mciSendString("open ./music/杀人.mp3 ", 0, 0, 0);
					mciSendString("play ./music/杀人.mp3 from 0", 0, 0, 0);
					delete_temp = 2;
					sign_painting = 1;
					map[6][18] = 0;//开辟道路
				}

				if (delete_temp == 1)
				{
					outtextxy(word_x, word_y, "画");
				}
				else;
				break;
			case 4:outtextxy(word_x, word_y, "床"); break;
			case 5:outtextxy(word_x, word_y, "锁"); break;
			case 6:outtextxy(word_x, word_y, "柜"); break;
			case 7:outtextxy(word_x, word_y, "灯"); break;
			case 8:outtextxy(word_x, word_y, "门"); break;
			case 9:outtextxy(word_x, word_y, "守"); break;
			case 10:outtextxy(word_x, word_y, "监"); break;
			case 11:outtextxy(word_x, word_y, "牢"); break;
			case 91:outtextxy(word_x, word_y, "洞"); break;
			case 20:outtextxy(word_x, word_y, "守"); break;
			case 21:outtextxy(word_x, word_y, "搞"); break;
			case 22:outtextxy(word_x, word_y, "什"); break;
			case 23:outtextxy(word_x, word_y, "么"); break;
			case 24:outtextxy(word_x, word_y, "幺"); break;
			case 25:outtextxy(word_x, word_y, "蛾"); break;
			case 26:outtextxy(word_x, word_y, "子"); break;
			case 27:outtextxy(word_x, word_y, "，"); break;
			case 28:outtextxy(word_x, word_y, "我"); break;
			case 29:outtextxy(word_x, word_y, "让"); break;
			case 30:outtextxy(word_x, word_y, "你"); break;
			case 31:outtextxy(word_x, word_y, "死"); break;
			case 32:outtextxy(word_x, word_y, "无"); break;
			case 33:outtextxy(word_x, word_y, "葬"); break;
			case 34:outtextxy(word_x, word_y, "身"); break;
			case 35:outtextxy(word_x, word_y, "之"); break;
			case 36:outtextxy(word_x, word_y, "地"); break;
			case 37:outtextxy(word_x, word_y, "鬼"); break;
			case 38:outtextxy(word_x, word_y, "钥匙"); break;
			case 90:outtextxy(word_x, word_y, "墙"); break;
				//case 40:outtextxy(word_x, word_y, "墙"); break;
				//case 39:outtextxy(word_x, word_y, "匙"); break;
			default:
				break;
			}
		}
	}

	//4  加入按钮
	ESC();//暂停按钮的坐标

	//5  加入道具栏  
	Bag();//此处注意先画地图在写功能，否则可能导致地图不完全显示

	// 打印道具
	if (tool_wood == 1) {
		outtextxy(bag_x + 90 - textwidth("木棒") / 2, bag_y + 60, "木棒");
	}

	if (tool_knife == 1) {
		outtextxy(bag_x + 90 - textwidth("石尖刀") / 2, bag_y + 100, "石尖刀");
	}

	if (tool_torch == 1) {
		outtextxy(bag_x + 90 - textwidth("火把") / 2, bag_y + 140, "火把");
	}

	if (tool_key == 1) {
		outtextxy(bag_x + 90 - textwidth("钥匙") / 2, bag_y + 180, "钥匙");
	}
}



//--------3.第一关 主要函数 游戏界面---------//
int FirstBarrierView() {

	settextstyle(25, 0, "Zpix");

	FirstGameService();//2 进入第一关

	getchar();//防止程序闪退
	return 0;
}

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

		mciSendString("open ./music/字意.mp3 ", 0, 0, 0);
		mciSendString("play ./music/字意.mp3 from 0", 0, 0, 0);

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
			mciSendString("open ./music/吹散毒气.mp3 ", 0, 0, 0);
			mciSendString("play ./music/吹散毒气.mp3 ", 0, 0, 0);

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
		mciSendString("open ./music/字意.mp3 ", 0, 0, 0);
		mciSendString("play ./music/字意.mp3 from 0", 0, 0, 0);
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
		mciSendString("open ./music/字意.mp3 ", 0, 0, 0);
		mciSendString("play ./music/字意.mp3 from 0", 0, 0, 0);
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
		mciSendString("open ./music/删.mp3 ", 0, 0, 0); //放不出来
		mciSendString("play ./music/删.mp3 from 0", 0, 0, 0);
		sign_keytext2 = 1; //按下删除键后不字消失

		cleardevice();
		PrintSecondGodGame();
		outtextxy(wo_x, wo_y, "我");
		rectangle(12, 44, 552, 67); //方框
		mciSendString("open ./music/字意.mp3 ", 0, 0, 0);
		mciSendString("play ./music/字意.mp3 from 0", 0, 0, 0);
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
