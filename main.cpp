#include <iostream>
#include <stdio.h>
#include <graphics.h>
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")


#define LIMG 0
#define RIMG 80
#define NIMG 40
#define N 5//֡��8//ԽС����Խ��
#define PixSpend 1//�ٶ�  Խ����ͬʱ�����ߵ�ԽԶ
#define T 10//���� //Խ���ߵ�Խ��
int pximg = 0;
int Dtime = 0;
int imgNum = 318;
int imgL = 107;
static int lock = 0;
IMAGE  role;
IMAGE img;
enum DIR
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
};
struct Ship
{
	int x;
	int y;
	int img_x;
	int img_y;
	int img_ny;
	int dir;
}ship;
void PlayBGM()
{
	//������
	/*mciSendString("open ./res/Music0001.mp3 alias BGM", 0, 0, 0);
	mciSendString("play BGM", 0, 0, 0);
	Sleep(8000);
	mciSendString("close BGM", 0, 0, 0);*/
}
void GameInit()
{
	ship = { 0,350,0,104 * 4,104 * 4 + 107,RIGHT };
	initgraph(640, 480);
	//setbkcolor(YELLOW);
	//cleardevice();
	loadimage(&img, "./res/Img0001.jpg");
	putimage(0, 0, &img);
	PlayBGM();
}
void DrawBackIMG(int x, int y)
{
	putimage(x, y, 40, 40, &img, x, y);
}
void KeyControl()
{

	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	{
		if ((GetAsyncKeyState(VK_LEFT) & 0x8000) | GetAsyncKeyState(VK_RIGHT) & 0x8000)
		{
			ship.y += PixSpend;
		}
		else {
			if (ship.dir == LEFT)
			{
				ship.img_ny = 104 * 3;
				ship.img_y = 104 * 2;

				Dtime++;
				if (Dtime > N)
				{
					Dtime = 0;
					ship.img_x -= 53;
				}
				if (ship.img_x == 0)ship.img_x = 477;
				ship.y += PixSpend;
				imgNum = 477;
				imgL = 104;
			}
			else if (ship.dir == RIGHT) {
				ship.img_ny = 104;
				ship.img_y = 0;
				Dtime++;
				if (Dtime > N)
				{
					Dtime = 0;
					ship.img_x -= 53;
				}
				if (ship.img_x == 0)ship.img_x = 477;
				ship.y += PixSpend;
				imgNum = 477;
				imgL = 104;
			}
			else {
				ship.y += PixSpend;
			}
		}

	}
	/*����"�����" �� "�����"����
	//��һ���������������ͼ�뱳����ɫͼ������ɫ�����
	//����������ɫ1011������ͼ���ﲿ�֣���ɫ��0000���������ְ�ɫ��1111
	//�������
	//��ǰ���ﲿ�֣�1011&0000=0000��ɫ
	//��ǰ�������֣�1011&1111=1011��ɫ
	//��ǰͼ�񱳾�Ϊ��ɫ������Ϊ��ɫ
	//�ڶ�������������ͼ��ͼ�������ɫ�����
	//��������ͼ���ﲿ�֣�1001 ����ͼ�������ֺ�ɫ��0000
	//�������
	//��ǰ���ﲿ�֣�1001|0000=1001��ɫ
	//��ǰ�������֣�0000|1011=1011��ɫ
	//����������ǰͼ������ȷ��ʾ����ͱ���*/
	if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		if ((GetAsyncKeyState(VK_LEFT) & 0x8000) | GetAsyncKeyState(VK_RIGHT) & 0x8000)
		{
			ship.y -= PixSpend;
		}
		else {
			if (ship.dir == LEFT)
			{
				ship.img_ny = 104 * 3;
				ship.img_y = 104 * 2;

				Dtime++;
				if (Dtime > N)
				{
					Dtime = 0;
					ship.img_x -= 53;
				}
				if (ship.img_x == 0)ship.img_x = 477;
				ship.y -= PixSpend;
				imgNum = 477;
				imgL = 104;
			}
			else if (ship.dir == RIGHT) {
				ship.img_ny = 104;
				ship.img_y = 0;
				Dtime++;
				if (Dtime > N)
				{
					Dtime = 0;
					ship.img_x -= 53;
				}
				if (ship.img_x == 0)ship.img_x = 477;
				ship.y -= PixSpend;
				imgNum = 477;
				imgL = 104;
			}
			else {
				ship.y -= PixSpend;
			}
		}
	}
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		ship.dir = LEFT;
		ship.img_ny = 104 * 3;
		ship.img_y = 104 * 2;

		Dtime++;
		if (Dtime > N)
		{
			Dtime = 0;
			ship.img_x -= 53;
		}
		if (ship.img_x == 0)ship.img_x = 477;
		ship.x -= PixSpend;
		imgNum = 477;
		imgL = 104;
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		ship.dir = RIGHT;
		ship.img_ny = 104;
		ship.img_y = 0;
		Dtime++;
		if (Dtime > N)
		{
			Dtime = 0;
			ship.img_x -= 53;
		}
		if (ship.img_x == 0)ship.img_x = 477;
		ship.x += PixSpend;
		imgNum = 477;
		imgL = 104;
	}
	if (ship.dir == RIGHT && !(GetAsyncKeyState(VK_DOWN) & 0x8000) && !(GetAsyncKeyState(VK_UP) & 0x8000) && !(GetAsyncKeyState(VK_LEFT) & 0x8000) && !(GetAsyncKeyState(VK_RIGHT) & 0x8000)) {
		ship.img_ny = 104 * 4 + 107;
		ship.img_y = 104 * 4;

		Dtime++;
		if (Dtime > N * 4)
		{
			Dtime = 0;
			ship.img_x += 53;
		}
		imgNum = 318;
		imgL = 107;
	}
	if (ship.dir == LEFT && !(GetAsyncKeyState(VK_DOWN) & 0x8000) && !(GetAsyncKeyState(VK_UP) & 0x8000) && !(GetAsyncKeyState(VK_LEFT) & 0x8000) && !(GetAsyncKeyState(VK_RIGHT) & 0x8000)) {
		ship.img_ny = 104 * 4 + 107 * 3;
		ship.img_y = 104 * 4 + 107 * 2;

		Dtime++;
		if (Dtime > N * 4)
		{
			Dtime = 0;
			ship.img_x += 53;
		}
		imgNum = 318;
		imgL = 107;
	}


}
void GameDraw()
{
	BeginBatchDraw();//��̨��ͼ ��ֹ
	putimage(0, 0, &img);
	//cleardevice();
	putimage(ship.x, ship.y, 53, imgL, &role, ship.img_x % imgNum, ship.img_ny, SRCAND);
	putimage(ship.x, ship.y, 53, imgL, &role, ship.img_x % imgNum, ship.img_y, SRCPAINT);
	EndBatchDraw();
}
int main()
{

	loadimage(&role, "./res/0002.jpg");

	//initgraph(640, 480,SHOWCONSOLE);

	//fillcircle(320, 240, 50);
	//setbkcolor(YELLOW);
	//cleardevice();
	GameInit();
	while (1)
	{
		if (lock == 0)
		{

			KeyControl();
			lock = 1;
		}
		Sleep(T);
		lock = 0;
		GameDraw();
	}
	return 0;
}
