/*
整体结构：
	1.函数声明 2.全局变量 3.按钮函数 4。函数定义 5.主函数
*/

/*
巧妙之处：
	跳转函数：界面的跳转
	二维数组：地图的绘制
	相互辅助：
		if的嵌套：探索的顺序
		标志变量：探索的顺序、其他
	移动：
		easyx的移动函数：人物可以任意移动
		虚拟坐标、实际坐标（新、旧坐标）：限制人物移动
*/
#include "函数声明.h" //函数声明


//宏定义
#define WIN_WIDTH    1000
#define WIN_HEIGHT   600

//-------------------------------------------主函数------------------------------------------------//
int main(void) {

	initgraph(WIN_WIDTH, WIN_HEIGHT, 0);//界面大小
	mciSendString("open ./music/点燃.mp3 ", 0, 0, 0);
	mciSendString("play ./music/点燃.mp3 from 0", 0, 0, 0);
	
	//Sleep(1000);
	//mciSendString("pause music/安静.mp3 ", 0, 0, 0);
	//mciSendString("close music/点燃.mp3 ", 0, 0, 0);

	/*mciSendString("open music/安静.mp3 ", 0, 0, 0);
	mciSendString("play music/安静.mp3 ", 0, 0, 0);*/
	
	login();

	return 0;
}