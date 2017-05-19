#ifndef BALL_H_
#define BALL_H_

#include "header.h"
#include "Vec3.h"
#include "Shape.h"
#include "Brick.h"
#include "Boundary.h"
#include "Stick.h"

#define bRadius 0.03
#define bR 1.0
#define bG 0.0
#define bB 0.0
#define bBallSpeed 0.001

extern int moksum;
class Ball : public Shape, public Color {
public:
	friend class Brick;
	friend class Boundary;
	Ball();
	Ball(Ball& ba) :Shape(ba), Color(ba){
		this->radius = ba.radius;
		this->center = ba.center;
		this->ballSpeed = ba.ballSpeed;
	}
	~Ball(){};
	void setPosition(float x, float y, float z){
	// if gamelevel is harder than easy, ball is randomly generated
		if (gamelevel > 0) {
			center = Vec3(x, y, z);
		}
	}
	virtual void draw();
	virtual void move();
	bool collisionSideBoundary(Boundary* bo);
	bool collisionUpperBoundary(Boundary* bo);
	bool collisionStick(Stick* s);	
	bool collisionBrickLeftRight(Brick* b);
	bool collisionBrickUpDown(Brick* b);
	bool collisionBrickCorner(Brick* b);
	Vec3 nullVector;
	bool collisionBall(Ball* ba);
	void normalizeVelocity();
	void gameDead();
	int life;
	int gamelevel;
	float radius;
	float ballSpeed;
};

#endif