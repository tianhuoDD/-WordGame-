#include "函数声明.h" //函数声明

//3.2玩法设置按钮
void BottonMode1(int x, int y, int w, int h)
{
	settextstyle(50, 0, "Zpix");//字体设置

	char text[50] = "模式选择";
	int tx = x + (w - textwidth(text)) / 2;//居中按钮
	int ty = y + (h - textheight(text)) / 2;//居中按钮
	outtextxy(tx, ty, text);
}
void BottonMode2(int x, int y, int w, int h)
{
	settextstyle(30, 0, "Zpix");//字体设置

	char text[50] = "简单模式";
	int tx = x + (w - textwidth(text)) / 2;//居中按钮
	int ty = y + (h - textheight(text)) / 2;//居中按钮
	outtextxy(tx, ty, text);
}
void BottonMode3(int x, int y, int w, int h)
{
	settextstyle(30, 0, "Zpix");//字体设置

	char text[50] = "困难模式";
	int tx = x + (w - textwidth(text)) / 2;//居中按钮
	int ty = y + (h - textheight(text)) / 2;//居中按钮
	outtextxy(tx, ty, text);
}
void BottonMode4(int x, int y, int w, int h)
{
	settextstyle(25, 0, "Zpix");//字体设置

	char text[50] = "返回菜单";
	int tx = x + (w - textwidth(text)) / 2;//居中按钮
	int ty = y + (h - textheight(text)) / 2;//居中按钮
	outtextxy(tx, ty, text);
}

//二、游戏介绍 按钮
void ButtonIntro1(int x, int y, int w, int h)
{

	settextstyle(25, 0, "Zpix");//字体设置

	char text[50] = "攻略";
	int tx = x + (w - textwidth(text)) / 2;//居中按钮
	int ty = y + (h - textheight(text)) / 2;//居中按钮
	outtextxy(tx, ty, text);
}
void ButtonIntro2(int x, int y, int w, int h)
{
	settextstyle(25, 0, "Zpix");//字体设置

	char text[50] = "制作组";
	int tx = x + (w - textwidth(text)) / 2;//居中按钮
	int ty = y + (h - textheight(text)) / 2;//居中按钮
	outtextxy(tx, ty, text);
}
void ButtonIntro3(int x, int y, int w, int h)
{
	settextstyle(25, 0, "Zpix");//字体设置

	char text[50] = "返回菜单";
	int tx = x + (w - textwidth(text)) / 2;//居中按钮
	int ty = y + (h - textheight(text)) / 2;//居中按钮
	outtextxy(tx, ty, text);
}
void ButtonIntro4(int x, int y, int w, int h)
{
	settextstyle(50, 0, "Zpix");//字体设置

	char text[50] = "游戏介绍";
	int tx = x + (w - textwidth(text)) / 2;//居中按钮
	int ty = y + (h - textheight(text)) / 2;//居中按钮
	outtextxy(tx, ty, text);
}

//2.1 游戏攻略 按钮
void ButtonStrategy1(int x, int y, int w, int h)
{
	settextstyle(25, 0, "Zpix");//字体设置

	char text[50] = "返回菜单";
	int tx = x + (w - textwidth(text)) / 2;//居中按钮
	int ty = y + (h - textheight(text)) / 2;//居中按钮
	outtextxy(tx, ty, text);
}
void ButtonStrategy2(int x, int y, int w, int h)
{

	settextstyle(25, 0, "Zpix");//字体设置

	char text[50] = "彩蛋攻略";
	int tx = x + (w - textwidth(text)) / 2;//居中按钮
	int ty = y + (h - textheight(text)) / 2;//居中按钮
	outtextxy(tx, ty, text);
}

//2.2 彩蛋攻略 按钮
void ButtonEgg1(int x, int y, int w, int h)
{
	settextstyle(25, 0, "Zpix");//字体设置

	char text[50] = "返回菜单";
	int tx = x + (w - textwidth(text)) / 2;//居中按钮
	int ty = y + (h - textheight(text)) / 2;//居中按钮
	outtextxy(tx, ty, text);
}
void ButtonEgg2(int x, int y, int w, int h)
{
	settextstyle(25, 0, "Zpix");//字体设置

	char text[50] = "返回";
	int tx = x + (w - textwidth(text)) / 2;//居中按钮
	int ty = y + (h - textheight(text)) / 2;//居中按钮
	outtextxy(tx, ty, text);
}
// 2.3 成员介绍
void ButtonMade1(int x, int y, int w, int h)
{
	settextstyle(50, 0, "Zpix");//字体设置

	char text[50] = "制作人员";
	int tx = x + (w - textwidth(text)) / 2;//居中按钮
	int ty = y + (h - textheight(text)) / 2;//居中按钮
	outtextxy(tx, ty, text);
}
void ButtonMade2(int x, int y, int w, int h)
{
	settextstyle(20, 0, "Zpix");//字体设置

	char text[50] = "Rom";
	int tx = x + (w - textwidth(text)) / 2;//居中按钮
	int ty = y + (h - textheight(text)) / 2;//居中按钮
	outtextxy(tx, ty, text);
}
void ButtonMade3(int x, int y, int w, int h)
{
	settextstyle(20, 0, "Zpix");//字体设置

	char text[50] = "阿鸟";
	int tx = x + (w - textwidth(text)) / 2;//居中按钮
	int ty = y + (h - textheight(text)) / 2;//居中按钮
	outtextxy(tx, ty, text);
}
void ButtonMade4(int x, int y, int w, int h)
{
	settextstyle(20, 0, "Zpix");//字体设置

	char text[50] = "指环王";
	int tx = x + (w - textwidth(text)) / 2;//居中按钮
	int ty = y + (h - textheight(text)) / 2;//居中按钮
	outtextxy(tx, ty, text);
}
void ButtonMade5(int x, int y, int w, int h)
{
	settextstyle(20, 0, "Zpix");//字体设置

	char text[50] = "修";
	int tx = x + (w - textwidth(text)) / 2;//居中按钮
	int ty = y + (h - textheight(text)) / 2;//居中按钮
	outtextxy(tx, ty, text);
}
void ButtonMade6(int x, int y, int w, int h)
{
	settextstyle(20, 0, "Zpix");//字体设置

	char text[50] = "抱米花";
	int tx = x + (w - textwidth(text)) / 2;//居中按钮
	int ty = y + (h - textheight(text)) / 2;//居中按钮
	outtextxy(tx, ty, text);
}
void ButtonMade7(int x, int y, int w, int h)
{
	settextstyle(20, 0, "Zpix");//字体设置

	char text[50] = "小鹿";
	int tx = x + (w - textwidth(text)) / 2;//居中按钮
	int ty = y + (h - textheight(text)) / 2;//居中按钮
	outtextxy(tx, ty, text);
}
void ButtonMade8(int x, int y, int w, int h)
{
	settextstyle(20, 0, "Zpix");//字体设置

	char text[50] = "冉";
	int tx = x + (w - textwidth(text)) / 2;//居中按钮
	int ty = y + (h - textheight(text)) / 2;//居中按钮
	outtextxy(tx, ty, text);
}
void ButtonMade9(int x, int y, int w, int h)
{
	settextstyle(20, 0, "Zpix");//字体设置

	char text[50] = "半个月亮";
	int tx = x + (w - textwidth(text)) / 2;//居中按钮
	int ty = y + (h - textheight(text)) / 2;//居中按钮
	outtextxy(tx, ty, text);

}
void ButtonMade10(int x, int y, int w, int h)
{
	settextstyle(35, 0, "Zpix");//字体设置

	char text[50] = "返回菜单";
	int tx = x + (w - textwidth(text)) / 2;//居中按钮
	int ty = y + (h - textheight(text)) / 2;//居中按钮
	outtextxy(tx, ty, text);
}
void ButtonMade11(int x, int y, int w, int h)
{
	settextstyle(25, 0, "Zpix");//字体设置

	char text[50] = "——地上的十便士";
	int tx = x + (w - textwidth(text)) / 2;//居中按钮
	int ty = y + (h - textheight(text)) / 2;//居中按钮
	outtextxy(tx, ty, text);
}

// 3.1 基础设置界面 按钮
void button1(int x, int y, int w, int h)
{
	settextstyle(50, 0, "Zpix");//字体设置

	char text[50] = "游戏设置";
	int tx = x + (w - textwidth(text)) / 2;//居中按钮
	int ty = y + (h - textheight(text)) / 2;//居中按钮
	outtextxy(tx, ty, text);
}
void button2(int x, int y, int w, int h)
{
	settextstyle(25, 0, "Zpix");//字体设置

	char text[50] = "基础设置";
	int tx = x + (w - textwidth(text)) / 2;//居中按钮
	int ty = y + (h - textheight(text)) / 2;//居中按钮
	outtextxy(tx, ty, text);
}
void button3(int x, int y, int w, int h)
{
	settextstyle(25, 0, "Zpix");//字体设置

	char text[50] = "玩法设置";
	int tx = x + (w - textwidth(text)) / 2;//居中按钮
	int ty = y + (h - textheight(text)) / 2;//居中按钮
	outtextxy(tx, ty, text);
}
void button4(int x, int y, int w, int h)
{
	settextstyle(25, 0, "Zpix");//字体设置

	char text[50] = "返回菜单";
	int tx = x + (w - textwidth(text)) / 2;//居中按钮
	int ty = y + (h - textheight(text)) / 2;//居中按钮
	outtextxy(tx, ty, text);
}

//一、开始游戏界面
//1.2进度界面 按钮
void ButtonProcess1(int x, int y, int w, int h)
{
	settextstyle(25, 0, "Zpix");//字体设置

	char text[50] = "新的游戏";
	int tx = x + (w - textwidth(text)) / 2;//居中按钮
	int ty = y + (h - textheight(text)) / 2;//居中按钮
	outtextxy(tx, ty, text);
}
void ButtonProcess2(int x, int y, int w, int h)
{
	settextstyle(25, 0, "Zpix");//字体设置

	char text[50] = "继续游戏";
	int tx = x + (w - textwidth(text)) / 2;//居中按钮
	int ty = y + (h - textheight(text)) / 2;//居中按钮
	outtextxy(tx, ty, text);
}
void ButtonProcess3(int x, int y, int w, int h)
{
	settextstyle(50, 0, "Zpix");//字体设置

	char text[50] = "选择你的进度";
	int tx = x + (w - textwidth(text)) / 2;//居中按钮
	int ty = y + (h - textheight(text)) / 2;//居中按钮
	outtextxy(tx, ty, text);
}

//跳转到菜单界面
void ButtonSkip1(int x, int y, int w, int h)
{
	roundrect(x, y, x + w, y + h, 10, 10);
	setbkmode(TRANSPARENT);
	settextstyle(25, 0, "Zpix");//字体设置

	char text[50] = "进入彩蛋关卡";
	int tx = x + (w - textwidth(text)) / 2;//居中按钮
	int ty = y + (h - textheight(text)) / 2;//居中按钮
	outtextxy(tx, ty, text);
}
void ButtonSkip2(int x, int y, int w, int h)
{
	roundrect(x, y, x + w, y + h, 10, 10);
	setbkmode(TRANSPARENT);
	settextstyle(25, 0, "Zpix");//字体设置

	char text[50] = "返回第一关";
	int tx = x + (w - textwidth(text)) / 2;//居中按钮
	int ty = y + (h - textheight(text)) / 2;//居中按钮
	outtextxy(tx, ty, text);
}

void ButtonSkip3(int x, int y, int w, int h)
{
	roundrect(x, y, x + w, y + h, 10, 10);
	setbkmode(TRANSPARENT);
	settextstyle(25, 0, "Zpix");//字体设置

	char text[50] = "返回第二关";
	int tx = x + (w - textwidth(text)) / 2;//居中按钮
	int ty = y + (h - textheight(text)) / 2;//居中按钮
	outtextxy(tx, ty, text);
}
void ButtonSkip4(int x, int y, int w, int h)
{
	roundrect(x, y, x + w, y + h, 10, 10);
	setbkmode(TRANSPARENT);
	settextstyle(25, 0, "Zpix");//字体设置

	char text[50] = "返回菜单";
	int tx = x + (w - textwidth(text)) / 2;//居中按钮
	int ty = y + (h - textheight(text)) / 2;//居中按钮
	outtextxy(tx, ty, text);
}
// 暂停界面 按钮
void ButtonPause1(int x, int y, int w, int h)
{
	settextstyle(25, 0, "Zpix");//字体设置

	char text[50] = "继续游戏";
	int tx = x + (w - textwidth(text)) / 2;//居中按钮
	int ty = y + (h - textheight(text)) / 2;//居中按钮
	outtextxy(tx, ty, text);
}
void ButtonPause2(int x, int y, int w, int h)
{
	settextstyle(25, 0, "Zpix");//字体设置

	char text[50] = "保存游戏";
	int tx = x + (w - textwidth(text)) / 2;//居中按钮
	int ty = y + (h - textheight(text)) / 2;//居中按钮
	outtextxy(tx, ty, text);
}
void ButtonPause3(int x, int y, int w, int h)
{
	settextstyle(25, 0, "Zpix");//字体设置

	char text[50] = "读取游戏";
	int tx = x + (w - textwidth(text)) / 2;//居中按钮
	int ty = y + (h - textheight(text)) / 2;//居中按钮
	outtextxy(tx, ty, text);
}
void ButtonPause4(int x, int y, int w, int h)
{
	settextstyle(25, 0, "Zpix");//字体设置

	char text[50] = "返回菜单";
	int tx = x + (w - textwidth(text)) / 2;//居中按钮
	int ty = y + (h - textheight(text)) / 2;//居中按钮
	outtextxy(tx, ty, text);
}
void ButtonPause5(int x, int y, int w, int h)
{
	settextstyle(50, 0, "Zpix");//字体设置

	char text[50] = "暂停";
	int tx = x + (w - textwidth(text)) / 2;//居中按钮
	int ty = y + (h - textheight(text)) / 2;//居中按钮
	outtextxy(tx, ty, text);
}

//通关界面
void button(int x, int y, int w, int h)//绘制圆角矩形框
{
	setbkmode(TRANSPARENT);
	roundrect(x, y, x + w, y + h, 10, 10);

	settextstyle(25, 0, "Zpix");

	char text[] = "返回主菜单";
	int tx = x + (w - textwidth(text)) / 2;
	int ty = y + (h - textheight(text)) / 2;

	outtextxy(tx, ty, text);
}

//1.2.1 读档界面 按钮
void BottonLoad1(int x, int y, int w, int h)
{
	settextstyle(50, 0, "Zpix");//字体设置

	char text[50] = "选择存档文件";
	int tx = x + (w - textwidth(text)) / 2;//居中按钮
	int ty = y + (h - textheight(text)) / 2;//居中按钮
	outtextxy(tx, ty, text);
}
void BottonLoad2(int x, int y, int w, int h)
{
	settextstyle(30, 0, "Zpix");//字体设置

	char text[50] = "(正在开发)";
	int tx = x + (w - textwidth(text)) / 2;//居中按钮
	int ty = y + (h - textheight(text)) / 2;//居中按钮
	outtextxy(tx, ty, text);
}
void BottonLoad3(int x, int y, int w, int h)
{
	settextstyle(25, 0, "Zpix");//字体设置

	char text[50] = "暂无存档";
	int tx = x + (w - textwidth(text)) / 2;//居中按钮
	int ty = y + (h - textheight(text)) / 2;//居中按钮
	outtextxy(tx, ty, text);
}
void BottonLoad4(int x, int y, int w, int h)
{
	settextstyle(25, 0, "Zpix");//字体设置

	char text[50] = "暂无存档";
	int tx = x + (w - textwidth(text)) / 2;//居中按钮
	int ty = y + (h - textheight(text)) / 2;//居中按钮
	outtextxy(tx, ty, text);
}
void BottonLoad5(int x, int y, int w, int h)
{
	settextstyle(25, 0, "Zpix");//字体设置

	char text[50] = "暂无存档";
	int tx = x + (w - textwidth(text)) / 2;//居中按钮
	int ty = y + (h - textheight(text)) / 2;//居中按钮
	outtextxy(tx, ty, text);
}
void BottonLoad6(int x, int y, int w, int h)
{
	settextstyle(25, 0, "Zpix");//字体设置

	char text[50] = "返回暂停";
	int tx = x + (w - textwidth(text)) / 2;//居中按钮
	int ty = y + (h - textheight(text)) / 2;//居中按钮
	outtextxy(tx, ty, text);
}
void BottonLoad7(int x, int y, int w, int h)
{
	settextstyle(25, 0, "Zpix");//字体设置

	char text[50] = "返回";
	int tx = x + (w - textwidth(text)) / 2;//居中按钮
	int ty = y + (h - textheight(text)) / 2;//居中按钮
	outtextxy(tx, ty, text);
}


// 保存存档 界面 按钮
void BottonArchive1(int x, int y, int w, int h)
{
	settextstyle(50, 0, "Zpix");//字体设置

	char text[50] = "保存存档";
	int tx = x + (w - textwidth(text)) / 2;//居中按钮
	int ty = y + (h - textheight(text)) / 2;//居中按钮
	outtextxy(tx, ty, text);
}
void BottonArchive2(int x, int y, int w, int h)
{
	settextstyle(30, 0, "Zpix");//字体设置

	char text[50] = "(正在开发)";
	int tx = x + (w - textwidth(text)) / 2;//居中按钮
	int ty = y + (h - textheight(text)) / 2;//居中按钮
	outtextxy(tx, ty, text);
}
void BottonArchive3(int x, int y, int w, int h)
{
	settextstyle(25, 0, "Zpix");//字体设置

	char text[50] = "暂无存档";
	int tx = x + (w - textwidth(text)) / 2;//居中按钮
	int ty = y + (h - textheight(text)) / 2;//居中按钮
	outtextxy(tx, ty, text);
}
void BottonArchive4(int x, int y, int w, int h)
{
	settextstyle(25, 0, "Zpix");//字体设置

	char text[50] = "暂无存档";
	int tx = x + (w - textwidth(text)) / 2;//居中按钮
	int ty = y + (h - textheight(text)) / 2;//居中按钮
	outtextxy(tx, ty, text);
}
void BottonArchive5(int x, int y, int w, int h)
{
	settextstyle(25, 0, "Zpix");//字体设置

	char text[50] = "暂无存档";
	int tx = x + (w - textwidth(text)) / 2;//居中按钮
	int ty = y + (h - textheight(text)) / 2;//居中按钮
	outtextxy(tx, ty, text);
}
void BottonArchive6(int x, int y, int w, int h)
{
	settextstyle(25, 0, "Zpix");//字体设置

	char text[50] = "返回暂停";
	int tx = x + (w - textwidth(text)) / 2;//居中按钮
	int ty = y + (h - textheight(text)) / 2;//居中按钮
	outtextxy(tx, ty, text);
}

//菜单界面按钮
void button_menu_1(int x, int y, int w, int h)
{
	settextstyle(25, 0, "Zpix");//字体设置

	char text[50] = "开始游戏";
	int tx = x + (w - textwidth(text)) / 2;//居中按钮
	int ty = y + (h - textheight(text)) / 2;//居中按钮
	outtextxy(tx, ty, text);
}
void button_menu_2(int x, int y, int w, int h)
{
	settextstyle(25, 0, "Zpix");//字体设置

	char text[50] = "游戏介绍";
	int tx = x + (w - textwidth(text)) / 2;//居中按钮
	int ty = y + (h - textheight(text)) / 2;//居中按钮
	outtextxy(tx, ty, text);
}
void button_menu_3(int x, int y, int w, int h)
{
	settextstyle(25, 0, "Zpix");//字体设置

	char text[50] = "游戏设置";
	int tx = x + (w - textwidth(text)) / 2;//居中按钮
	int ty = y + (h - textheight(text)) / 2;//居中按钮
	outtextxy(tx, ty, text);
}
void button_menu_4(int x, int y, int w, int h)
{
	settextstyle(25, 0, "Zpix");//字体设置

	char text[50] = "退出游戏";
	int tx = x + (w - textwidth(text)) / 2;//居中按钮
	int ty = y + (h - textheight(text)) / 2;//居中按钮
	outtextxy(tx, ty, text);
}
void button_menu_5(int x, int y, int w, int h)
{
	settextstyle(50, 0, "Zpix");//字体设置

	char text[50] = "文字游戏";
	int tx = x + (w - textwidth(text)) / 2;//居中按钮
	int ty = y + (h - textheight(text)) / 2;//居中按钮
	outtextxy(tx, ty, text);
}

//零、账号界面
//0.1账号登录按钮
void ButtonLogin1(int x, int y, int w, int h)
{
	settextstyle(50, 0, "Zpix");//字体设置

	char text[50] = "文字游戏";
	int tx = x + (w - textwidth(text)) / 2;//居中按钮
	int ty = y + (h - textheight(text)) / 2;//居中按钮
	outtextxy(tx, ty, text);
}
void ButtonLogin2(int x, int y, int w, int h)
{
	settextstyle(25, 0, "Zpix");//字体设置

	char text[50] = "账号";
	int tx = x + (w - textwidth(text)) / 2;//居中按钮
	int ty = y + (h - textheight(text)) / 2;//居中按钮
	outtextxy(tx, ty, text);
}
void ButtonLogin3(int x, int y, int w, int h)
{
	settextstyle(25, 0, "Zpix");//字体设置

	char text[50] = "密码";
	int tx = x + (w - textwidth(text)) / 2;//居中按钮
	int ty = y + (h - textheight(text)) / 2;//居中按钮
	outtextxy(tx, ty, text);
}
void ButtonLogin4(int x, int y, int w, int h)
{
	roundrect(x, y, x + w, y + h, 10, 10);


	settextstyle(23, 0, "Zpix");//字体设置
	char text[50] = "忘记密码";
	int tx = x + (w - textwidth(text)) / 2;//居中按钮
	int ty = y + (h - textheight(text)) / 2;//居中按钮
	outtextxy(tx, ty, text);
}
void ButtonLogin5(int x, int y, int w, int h)
{
	roundrect(x, y, x + w, y + h, 10, 10);


	settextstyle(30, 0, "Zpix");//字体设置
	char text[50] = "登录";
	int tx = x + (w - textwidth(text)) / 2;//居中按钮
	int ty = y + (h - textheight(text)) / 2;//居中按钮
	outtextxy(tx, ty, text);
}
void ButtonLogin6(int x, int y, int w, int h)
{
	roundrect(x, y, x + w, y + h, 10, 10);


	settextstyle(30, 0, "Zpix");//字体设置
	char text[50] = "注册";
	int tx = x + (w - textwidth(text)) / 2;//居中按钮
	int ty = y + (h - textheight(text)) / 2;//居中按钮
	outtextxy(tx, ty, text);
}
void ButtonLogin7(int x, int y, int w, int h)
{
	setfillcolor(BLACK);
	fillroundrect(x, y, x + w, y + h, 10, 10);

	settextstyle(30, 0, "Zpix");
	outtextxy(x, y, "");
}
void ButtonLogin8(int x, int y, int w, int h)
{
	setfillcolor(BLACK);
	fillroundrect(x, y, x + w, y + h, 10, 10);

	settextstyle(30, 0, "Zpix");
	outtextxy(x, y, "");
}
//0.2注册界面按钮
void ButtonReg1(int x, int y, int w, int h)
{
	roundrect(x, y, x + w, y + h, 10, 10);//绘制圆角矩形框
//绘制圆角矩形框

	settextstyle(30, 0, "Zpix");//框内文本字体

	char text1[] = "确认";
	int tx = x + (w - textwidth(text1)) / 2;//文本居中按钮
	int ty = y + (h - textheight(text1)) / 2;//文本居中按钮

	outtextxy(tx, ty, text1);

}

void ButtonReg2(int x, int y, int w, int h)
{
	roundrect(x, y, x + w, y + h, 10, 10);//绘制圆角矩形框

	settextstyle(26, 0, "Zpix");//框内文本字体


	char text2[] = "";
	int tx = x + 1;//文本居中按钮
	int ty = y + 5;//文本居中按钮

	outtextxy(tx, ty, text2);

}
//0.3找回密码按钮
void ButtonBack1(int x, int y, int w, int h)
{
	roundrect(x, y, x + w, y + h, 10, 10);//绘制圆角矩形框

	settextstyle(30, 0, "Zpix");//框内文本字体

	char text1[] = "确认";
	int tx = x + (w - textwidth(text1)) / 2;//文本居中按钮
	int ty = y + (h - textheight(text1)) / 2;//文本居中按钮

	outtextxy(tx, ty, text1);
}
void ButtonBack2(int x, int y, int w, int h)
{
	roundrect(x, y, x + w, y + h, 10, 10);//绘制圆角矩形框

	settextstyle(26, 0, "Zpix");//框内文本字体


	char text2[] = "";
	int tx = x + 15;//文本在框中的位置
	int ty = y + 5;//文本在框中的位置

	outtextxy(tx, ty, text2);
}
//0.4找回成功按钮
void ButtonSuccess1(int x, int y, int w, int h)
{
	roundrect(x, y, x + w, y + h, 10, 10);//绘制圆角矩形框

	settextstyle(30, 0, "Zpix");//框内文本字体

	char text1[] = "确认";
	int tx = x + (w - textwidth(text1)) / 2;//文本居中按钮
	int ty = y + (h - textheight(text1)) / 2;//文本居中按钮

	outtextxy(tx, ty, text1);

}
void ButtonSuccess2(int x, int y, int w, int h)//绘制圆角矩形框
{
	roundrect(x, y, x + w, y + h, 10, 10);

	settextstyle(26, 0, "Zpix");//框内文本字体


	char text2[] = "";
	int tx = x + 15;//文本在框中的位置
	int ty = y + 5;//文本在框中的位置

	outtextxy(tx, ty, text2);
}
