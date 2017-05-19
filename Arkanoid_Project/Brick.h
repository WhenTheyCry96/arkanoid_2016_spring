#ifndef BRICK_H_
#define BRICK_H_

#include "header.h"
#include "Vec3.h"
#include "Shape.h"

#define xcorner -0.87
#define ycorner 0.68
#define xlong 0.08
#define ylong 0.12
#define zlong 0
#define gap 0.01
#define BrickNum 50

class Brick : public Shape, public Color {
public:
	Brick() {
		blong.x = xlong; blong.y = ylong; blong.z = zlong;
		center.x = -1, center.y = 1, center.z = 0;
		brickLife = 0;
		velocity.y = 0.00002;
		alive = true;
	}
	Brick(Brick& a) {
		corner[0] = a.corner[0], corner[1] = a.corner[1], corner[2] = a.corner[2];
		row_num = a.row_num, col_num = a.col_num;
	}
	~Brick() {
	}
	virtual void draw();
	virtual void move(); // brick's move is just breaking animation; not real moving
	void initBrick(int num, int gl);
	bool alive;
	Vec3 blong;
	Vec3 corner;
	int brickLife;
	int row_num, col_num, num;
};

#endif