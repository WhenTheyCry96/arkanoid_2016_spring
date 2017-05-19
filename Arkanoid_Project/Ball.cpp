#include "Ball.h"

int moksum = -1;

Ball::Ball() {
	radius = bRadius;
	life = 1;
	velocity.x = 0, velocity.y = 0, velocity.z = 0;
	ballSpeed = 0.001;// 0.001;
	rgb.x = bR; rgb.y = bG; rgb.z = bB;
}
void Ball::draw() { // ball is based on spherical coordinate system
	float dx = 15, dy = 15;
	for (float x = -90.0f; x < 90.0f; x += dx) {
		for (float y = 0.0f; y < 360.0f; y += dy) {
			glBegin(GL_TRIANGLES);
			glColor3f(rgb.x, rgb.y, rgb.z);
			glVertex3f(center.x + radius*sin(x)*cos(y), center.y + radius*sin(x)*sin(y), center.z + radius*cos(x));
			glVertex3f(center.x + radius*sin(x+dx)*cos(y), center.y + radius*sin(x+dx)*sin(y), center.z + radius*cos(x+dx));
			glVertex3f(center.x + radius*sin(x+dx)*cos(y+dy), center.y + radius*sin(x)*sin(y+dy), center.z + radius*cos(x+dx));
			glEnd();
		}
	}
}
void Ball::move() { 
	center += velocity;
}
bool Ball::collisionSideBoundary(Boundary* bo) {
	if (bo->whereBo == 2 && center[0] > rgtboundx - radius){
		center[0] = rgtboundx - radius;
		return true;
	}
	else if (bo->whereBo == 0 && center[0] < lftboundx + xlength/2 + radius){
		center[0] = lftboundx + xlength/2 + radius;
		return true;
	}
	else return false;
}
bool Ball::collisionUpperBoundary(Boundary* bo) {
	if (bo->whereBo == 1 && center[1] > uppboundy - radius){
		center[1] = uppboundy - radius;
		return true;
	}
	else if (center[1] < -1.2 - radius){ // When the ball falls
		moksum -= 1;
		center[0] = -0.4;
		center[1] = -0.8;
		velocity.x = 0, velocity.y = 0;
		return false;
	}
	else return false;
}
bool Ball::collisionBrickLeftRight(Brick* b) {
	float left = b->corner[0];
	float right = b->corner[0] + b->blong[0];
	float up = b->corner[1] + b->blong[1];
	float down = b->corner[1];

	if ((0 < left - center[0] && left - center[0] < radius) || (0 < center[0] - right && center[0] - right < radius)) {
		if (down < center[1] && center[1] < up) {
			b->alive = false;
			return true;
		}
		else return false;
	}
	else return false;
}

bool Ball::collisionBrickUpDown(Brick* b) {
	float left = b->corner[0];
	float right = b->corner[0] + b->blong[0];
	float up = b->corner[1] + b->blong[1];
	float down = b->corner[1];

	if ((0 < down - center[1] && down - center[1] < radius) || (0 < center[1] - up && center[1] - up < radius)) {
		if (left < center[0] && center[0] < right) {
			b->alive = false;
			return true;
		}
		else return false;
	}
	else return false;
}

bool Ball::collisionBrickCorner(Brick* b){
	Vec3 bottomLeft(b->corner[0], b->corner[1], b->corner[2]);
	Vec3 bottomRight(b->corner[0] + b->blong[0], b->corner[1], b->corner[2]);
	Vec3 upperLeft(b->corner[0], b->corner[1] + b->blong[1], b->corner[2]);
	Vec3 upperRight(b->corner[0] + b->blong[0], b->corner[1] + b->blong[1], b->corner[2]);


	if ((bottomLeft - center)*(bottomLeft - center) < radius*radius){
		nullVector = (center - bottomLeft);
		b->alive = false;
		return true;
	}

	else if ((bottomRight - center)*(bottomRight - center) < radius*radius){
		nullVector = (center - bottomRight);
		b->alive = false;
		return true;
	}

	else if ((upperLeft - center)*(upperLeft - center) < radius*radius){
		nullVector = (center - upperLeft);
		b->alive = false;
		return true;
	}

	else if ((upperRight - center)*(upperRight - center) < radius*radius){
		nullVector = (center - upperRight);
		b->alive = false;
		return true;
	}

	else return false;
}

bool Ball::collisionStick(Stick* st) {
		if (center[1] < st->cornerPoint[1] + st->length[1] + radius && center[1] > st->cornerPoint[1] - radius){
			Vec3 distanceCorner1 = center - st->cornerPoint;
			Vec3 distanceCorner2 = distanceCorner1;
			distanceCorner2[0] -= st->length[0];
			float distance1 = sqrt(distanceCorner1*distanceCorner1);
			float distance2 = sqrt(distanceCorner2*distanceCorner2);
			if (center[0]  > st->cornerPoint[0] && center[0] < st->cornerPoint[0] + st->length[0]){
				center[1] = st->cornerPoint[1] + st->length[1] + radius;
				return true;
			}
			else if (distance1 < radius || distance2 < radius){
				center[1] = st->cornerPoint[1] + st->length[1] + radius;
				return true;
			}
			else return false;
		}
		else return false;
}
bool Ball::collisionBall(Ball *ba) {
	Vec3 distance = center - ba->center;
	float distf = sqrt(distance*distance);
	if (radius + ba->radius > distf)
		return true;
	else
		return false;
}
void Ball::normalizeVelocity(){
	if (velocity.x != 0 && velocity.y != 0) {
		velocity = (ballSpeed / sqrt(velocity*velocity))*velocity;
	}
	else
		velocity.x = velocity.y = bBallSpeed/2*sqrt(2);
}

void Ball::gameDead() {
	if (life == 0) {			
		setPosition(-20, -20, -20);
	// Think what after to do 
	}
}
