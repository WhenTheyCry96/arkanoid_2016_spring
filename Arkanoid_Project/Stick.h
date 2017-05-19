#ifndef _STICK_H_
#define _STICK_H_

#include "header.h"
#include "Vec3.h"
#include "Shape.h"

#define stickV 0.02
class Stick : public Shape, public Color {
public:
	Stick();
	Stick(Stick& st) :Shape(st), Color(st){
		this->cornerPoint = st.cornerPoint;
		this->length = st.length;
	}
	~Stick(){}
	virtual void draw();
	virtual void move();
	void oscillation(int gl);
	void setPosition(float x, float y, float z){
		cornerPoint.x = x; // 36~270
		cornerPoint.y = y;
		cornerPoint.z = z;
	}
	Vec3 cornerPoint;
	Vec3 length;
	int lftrgt; // To determine stick's velocity; right = 1, left = -1
};

#endif