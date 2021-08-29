#include <stdio.h>
#include<easyx.h>
#include <mmsystem.h>
#include<ctime>
#pragma comment(lib, "winmm.lib")
#define WIDTH 900
#define HEIGHT 900
struct role {
	unsigned x;
	unsigned y;
}van1,van2,BL1,BL2,yw1,yw2,xjj1,xjj2;
short speed = 2;
IMAGE back;
IMAGE bl_1;
IMAGE bl_2;
IMAGE van_1;
IMAGE van_2;
IMAGE yw_1;
IMAGE xjj_1;
IMAGE xjj_2;
IMAGE  yw_2 ;
IMAGE first;
clock_t begin, end;
void ini() {
	initgraph(WIDTH,HEIGHT);

	mciSendString("open .\\resource\\wsglcm.mp3", 0, 0, 0);//加载音乐
	mciSendString("play .\\resource\\wsglcm.mp3 repeat", 0, 0, 0);//播放音乐

	loadimage(&back,".\\resource\\back.png");
	loadimage(&van_1, ".\\resource\\van_1.png");
	loadimage(&bl_1, ".\\resource\\bl_1.png");
	loadimage(&xjj_1, ".\\resource\\xjj_1.png");
	loadimage(&yw_1, ".\\resource\\yw_1.png");
	loadimage(&first, ".\\resource\\first.png");
	loadimage(&van_2, ".\\resource\\van_2.png");
	loadimage(&bl_2, ".\\resource\\bl_2.png");
	loadimage(&xjj_2, ".\\resource\\xjj_2.png");
	loadimage(&yw_2, ".\\resource\\yw_2.png");

	van1.x = 0;
	van1.y = 0;

	van2.x = WIDTH - 300;
	van2.y = HEIGHT - 600;

	BL1.x = WIDTH - 300;
	BL1.y = HEIGHT - 300;

	BL2.x = 0;
	BL2.y = HEIGHT - 600;

	xjj1.x = WIDTH - 300;
	xjj1.y = 0;

	xjj2.x = WIDTH - 600;
	xjj2.y = HEIGHT - 300;

	yw1.x = 0;
	yw1.y = HEIGHT - 300;

	yw2.x = WIDTH - 600;
	yw2.y = 0;
}
void van1_move() {
	if ((van1.y==0)&&(van1.x<=WIDTH-300))
		van1.x += speed;
	if ((van1.x == WIDTH - 300) && (van1.y <= HEIGHT - 300))
		van1.y += speed;
	if ((van1.y == HEIGHT - 300) && (van1.x >= 0))
		van1.x -= speed;
	if ((van1.x == 0) && (van1.y >= 0))
		van1.y -= speed;
}
void van2_move() {
	if ((van2.y == HEIGHT - 300) && (van2.x >= 0))
		van2.x -= speed;
	if ((van2.x == WIDTH - 300) && (van2.y <= HEIGHT - 300))
		van2.y += speed;
	if ((van2.y == 0) && (van2.x <= WIDTH - 300))
		van2.x += speed;
	if ((van2.x == 0) && (van2.y >= 0))
		van2.y -= speed;
}
void BL1_move() {
	if ((BL1.y == HEIGHT - 300) && (BL1.x >= 0))
		BL1.x -= speed;
	if ((BL1.x == WIDTH - 300) && (BL1.y <= HEIGHT - 300))
		BL1.y += speed;
	if ((BL1.y == 0) && (BL1.x <= WIDTH - 300))
		BL1.x += speed;
	if ((BL1.x == 0) && (BL1.y >= 0))
		BL1.y -= speed;
}
void BL2_move() {
	if ((BL2.x == 0) && (BL2.y >= 0))
		BL2.y -= speed;
	if ((BL2.y == 0) && (BL2.x <= WIDTH - 300))
		BL2.x += speed;
	if ((BL2.x == WIDTH - 300) && (BL2.y <= HEIGHT - 300))
		BL2.y += speed;
	if ((BL2.y == HEIGHT - 300) && (BL2.x >= 0))
		BL2.x -= speed;
}
void xjj1_move() {
	if ((xjj1.y == HEIGHT - 300) && (xjj1.x >= 0))
		xjj1.x -= speed;
	if ((xjj1.x == WIDTH - 300) && (xjj1.y <= HEIGHT - 300))
		xjj1.y += speed;
	if ((xjj1.y == 0) && (xjj1.x <= WIDTH - 300))
		xjj1.x += speed;
	if ((xjj1.x == 0) && (xjj1.y >= 0))
		xjj1.y -= speed;
}
void xjj2_move() {
	if ((xjj2.y == HEIGHT - 300) && (xjj2.x >= 0))
		xjj2.x -= speed;
	if ((xjj2.x == WIDTH - 300) && (xjj2.y <= HEIGHT - 300))
		xjj2.y += speed;
	if ((xjj2.y == 0) && (xjj2.x <= WIDTH - 300))
		xjj2.x += speed;
	if ((xjj2.x == 0) && (xjj2.y >= 0))
		xjj2.y -= speed;
}
void yw1_move() {
	if ((yw1.x == 0) && (yw1.y >= 0))
		yw1.y -= speed;
	if ((yw1.y == 0) && (yw1.x <= WIDTH - 300))
		yw1.x += speed;
	if ((yw1.x == WIDTH - 300) && (yw1.y <= HEIGHT - 300))
		yw1.y += speed;
	if ((yw1.y == HEIGHT - 300) && (yw1.x >= 0))
		yw1.x -= speed;
	
}
void yw2_move() {
	if ((yw2.y == 0) && (yw2.x <= WIDTH - 300))
		yw2.x += speed;
	if ((yw2.x == WIDTH - 300) && (yw2.y <= HEIGHT - 300))
		yw2.y += speed;
	if ((yw2.y == HEIGHT - 300) && (yw2.x >= 0))
		yw2.x -= speed;
	if ((yw2.x == 0) && (yw2.y >= 0))
		yw2.y -= speed;
}
void draw_1() {
	putimage(0, 0, &back);
	putimage(van1.x, van1.y, &van_1);
	putimage(BL1.x, BL1.y, &bl_1);
	putimage(xjj1.x, xjj1.y, &xjj_1);
	putimage(yw1.x, yw1.y, &yw_1);
	putimage(300, 300, &first);
	putimage(van2.x, van2.y, &van_2);
	putimage(BL2.x, BL2.y, &bl_2);
	putimage(xjj2.x, xjj2.y, &xjj_2);
	putimage(yw2.x, yw2.y, &yw_2);

}
void draw_2() {

}
void update() {
	van1_move();
	van2_move();
	BL1_move();
	BL2_move();
	xjj1_move();
	xjj2_move();
	yw1_move();
	yw2_move();
}
bool stop() {
	if (GetAsyncKeyState(VK_SPACE)) {
		return false;
	}
	else return true;
}
int main() {
	ini();
	BeginBatchDraw();
	while (stop()) {
		draw_1();
		update();
		FlushBatchDraw();
	}
	ini();
	while (stop()) {
		speed = 5;
		draw_1();
		update();
		FlushBatchDraw();
	}
	ini();
	while (stop()) {
		speed = 10;
		draw_1();
		update();
		FlushBatchDraw();
	}
	ini();
	while (stop()) {
		speed = 15;
		draw_1();
		update();
		FlushBatchDraw();
	}
	ini();
	while (stop()) {
		speed = 25;
		draw_1();
		update();
		FlushBatchDraw();
	}

	EndBatchDraw();
	return 0;
}