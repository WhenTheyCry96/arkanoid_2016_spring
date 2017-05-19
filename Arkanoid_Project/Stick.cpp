#include "Stick.h"

Stick::Stick(){
	length[0] = 0.25;
	length[1] = 0.01;

	rgb[0] = rand() % 10 / double(10);
	rgb[1] = rand() % 10 / double(10);
	rgb[2] = rand() % 10 / double(10);

	velocity[0] = 0.03; velocity[1] = 0; velocity[2] = 0;
}

void Stick::draw(){

	glColor3f(rgb[0], rgb[1], rgb[2]);
	glBegin(GL_QUADS);
	glVertex3f(cornerPoint[0], cornerPoint[1], 0);
	glVertex3f(cornerPoint[0] + length[0], cornerPoint[1], 0);
	glVertex3f(cornerPoint[0] + length[0], cornerPoint[1] + length[1], 0);
	glVertex3f(cornerPoint[0], cornerPoint[1] + length[1], 0);

	glEnd();
}

void Stick::move() {
	if (lftrgt == 1)
		cornerPoint += velocity;
	else if (lftrgt == -1)
		cornerPoint -= velocity;
}

void Stick::oscillation(int gl) { // if gamelv is 3 == inferno 
	if (gl == 3) {
		length[0] += 0.0005*sin(pow(time(NULL), 1.3) / 0.5);
	}
}