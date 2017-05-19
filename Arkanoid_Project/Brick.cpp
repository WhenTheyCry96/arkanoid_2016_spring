#include "Brick.h"

extern vector<Brick*> bricks;

void Brick::draw() {
	Vec3 tcorner = corner;
	if (alive == true) {
		glBegin(GL_QUADS);                        // corner is ¸Ç ¿ÞÂÊ/À§ÂÊÁÂÇ¥ 
		glColor3f(rgb.x, rgb.y, rgb.z);
		glVertex3f(tcorner[0], tcorner[1], tcorner[2]);
		glVertex3f(tcorner[0] + blong.x, tcorner[1], tcorner[2]);
		glVertex3f(tcorner[0] + blong.x, tcorner[1] + blong.y, tcorner[2]);
		glVertex3f(tcorner[0], tcorner[1] + blong.y, tcorner[2]);
		glEnd();
	}
}
void Brick::move() {
	if (alive == true) {
		corner -= velocity;
	}
	if (alive == false) {
		brickLife = 1;
	}
}
void Brick::initBrick(int num, int gl) {
	float R1 = 0.05;
	float G1 = 0.05;
	float B1 = 0.05;
	float x = xcorner, y = ycorner;                 // center's point
	int col = num % 10;                          // ¿­
	int row = num / 10;                          // Çà 
	x += col*(xlong + gap);
	y -= row*(ylong + gap);
	R1 += row*0.1; G1 += row*0.1; B1 += row*0.1;
		corner[0] = x;
		corner[1] = y;
		corner[2] = 0;                          // still 2D
		setRGB(R1, G1, B1);
}

