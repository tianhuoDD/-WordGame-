/*
����ṹ��
	1.�������� 2.ȫ�ֱ��� 3.��ť���� 4���������� 5.������
*/

/*
����֮����
	��ת�������������ת
	��ά���飺��ͼ�Ļ���
	�໥������
		if��Ƕ�ף�̽����˳��
		��־������̽����˳������
	�ƶ���
		easyx���ƶ�������������������ƶ�
		�������ꡢʵ�����꣨�¡������꣩�����������ƶ�
*/
#include "��������.h" //��������


//�궨��
#define WIN_WIDTH    1000
#define WIN_HEIGHT   600

//-------------------------------------------������------------------------------------------------//
int main(void) {

	initgraph(WIN_WIDTH, WIN_HEIGHT, 0);//�����С
	mciSendString("open ./music/��ȼ.mp3 ", 0, 0, 0);
	mciSendString("play ./music/��ȼ.mp3 from 0", 0, 0, 0);
	
	//Sleep(1000);
	//mciSendString("pause music/����.mp3 ", 0, 0, 0);
	//mciSendString("close music/��ȼ.mp3 ", 0, 0, 0);

	/*mciSendString("open music/����.mp3 ", 0, 0, 0);
	mciSendString("play music/����.mp3 ", 0, 0, 0);*/
	
	login();

	return 0;
}