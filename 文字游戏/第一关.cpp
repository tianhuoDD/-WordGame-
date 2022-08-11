#include "函数声明.h" //函数声明
#include "全局变量.h"
//第一关——————————————————————————————
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
		else if (sign_case == 1)																//探索过柜子
		{



			outtextxy(10, 10, "不小心把小木棒碰到灯火，意外地获得一个火把...");

			sign_case = 2;
			sign_light = 1;		//获得火把
			tool_torch = 1;		//背包显示火把
			tool_wood = 0;		//背包取消显示木头

			//cleardevice();
			PrintFirstMap;
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
		mciSendString("open 删.mp3 ", 0, 0, 0);
		mciSendString("play 删.mp3 ", 0, 0, 0);

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
			outtextxy(10, 10, "获得一把'石尖刀'和一小根木棒，石刀是我日夜打磨而成...");
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
			mciSendString("open 点燃.mp3 ", 0, 0, 0);
			mciSendString("play 点燃.mp3 ", 0, 0, 0);
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
		mciSendString("open 杀人2.mp3 ", 0, 0, 0);
		mciSendString("play 杀人2.mp3 ", 0, 0, 0);

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

		//失败
		mciSendString("open 获得物品.mp3 ", 0, 0, 0);
		mciSendString("play 获得物品.mp3 ", 0, 0, 0);

		sign_get = 0;
		tool_key = 1;
		map[10][3] = 0;
		cleardevice();
		//outtextxy(10, 10, "获得一把钥匙，监狱里就畅通无阻了...");
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
//移动功能
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
					mciSendString("open 杀人1.mp3 ", 0, 0, 0);
					mciSendString("play 杀人1.mp3 ", 0, 0, 0);
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
		mciSendString("open 字意.mp3 ", 0, 0, 0);
		mciSendString("play 字意.mp3 ", 0, 0, 0);
		outtextxy(bag_x + 90 - textwidth("木棒") / 2, bag_y + 60, "木棒");
	}

	if (tool_knife == 1) {
		//mciSendString("open 字意.mp3 ", 0, 0, 0);
		//mciSendString("play 字意.mp3 ", 0, 0, 0); 
		outtextxy(bag_x + 90 - textwidth("石尖刀") / 2, bag_y + 100, "石尖刀");
	}

	if (tool_torch == 1) {
		mciSendString("open 字意2.mp3 ", 0, 0, 0);
		mciSendString("play 字意2.mp3 ", 0, 0, 0);
		outtextxy(bag_x + 90 - textwidth("火把") / 2, bag_y + 140, "火把");
	}

	if (tool_key == 1) {
		mciSendString("open 字意.mp3 ", 0, 0, 0);
		mciSendString("play 字意.mp3 ", 0, 0, 0);
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