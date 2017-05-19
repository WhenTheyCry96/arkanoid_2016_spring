#ifndef _BOUNDARY_H_
#define _BOUNDARY_H_

#include "header.h"
#include "Shape.h"
#include "Vec3.h"

#define BoundaryNum 3
#define boR 0.3
#define boG 0.3
#define boB 0.3
#define xlength 0.1
#define ylength 0.1
#define zlength 0
#define lftboundx -0.945
#define lftboundy 0.8
#define rgtboundx 0.045
#define rgtboundy 0.8
#define uppboundx -0.945
#define uppboundy 0.8

class Boundary : public Shape, public Color {
public:
	Boundary() {
		velocity.x = velocity.y = velocity.z = 0;
		rgb.x = boR; rgb.y = boG; rgb.z = boB;
		boLong.x = xlength; boLong.y = ylength; boLong.z = zlength;
	};
	Boundary(int num) {
		velocity.x = velocity.y = velocity.z = 0;
		rgb.x = boR; rgb.y = boG; rgb.z = boB;
		boLong.x = xlength; boLong.y = ylength; boLong.z = zlength;
		whereBo = num;                                              // 0 is left-side, 1 is upper-side, 2 is right-side boundary
	}
	~Boundary() {};

	virtual void draw();
	virtual void move();
	void initBoundary(int num);
	Vec3 boLong;
	Vec3 corner;
	int whereBo;                                                    // 0 is left-side, 1 is upper-side, 2 is right-side boundary
};

#endif