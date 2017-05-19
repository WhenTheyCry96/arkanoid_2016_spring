//This is Real Project!!
#include <string>
#include <iostream>
#include "Ball.h"
#include "Boundary.h"
#include "Brick.h"
#include "Stick.h"
#pragma warning(disable : 4996) 

#define WINDOW_WIDTH 720
#define WINDOW_HEIGHT 720

vector<Ball*> balls;
vector<Brick*> bricks;
vector<Boundary *> boundarys;
Stick * sticks;
//기빈추가
bool gameon = false;
int score = 0;
int pastmoksum = -1;
int gameLv = 1;
int mousePosX;
void* glutFonts[7] = {
	GLUT_BITMAP_9_BY_15,
	GLUT_BITMAP_8_BY_13,
	GLUT_BITMAP_TIMES_ROMAN_10,
	GLUT_BITMAP_TIMES_ROMAN_24,
	GLUT_BITMAP_HELVETICA_10,
	GLUT_BITMAP_HELVETICA_12,
	GLUT_BITMAP_HELVETICA_18
};

void glutPrint(float x, float y, void* font, char* text, float r, float g, float b, float a)
{
	if (!text || !strlen(text)) return;
	bool blending = false;
	if (glIsEnabled(GL_BLEND)) blending = true;
	glEnable(GL_BLEND);
	glColor4f(r, g, b, a);
	glRasterPos2f(x, y);

	while (*text) {
		glutBitmapCharacter(font, *text);
		text++;
	}
	if (!blending) glDisable(GL_BLEND);
}

//기빈추가 끝
void initShapeBall(int gl) {
	for (int i = 0; i < gl; i++) {
		Ball* shape = new Ball();
		shape->gamelevel = gl;
		shape->setPosition(-0.6, -0.85, 0);
		shape->velocity.x *= float(rand() % 10 - 5) / (gl + 1), shape->velocity.y *= float(rand() % 10 - 5) / (gl + 1), shape->velocity.z *= (gl + 1);
		shape->normalizeVelocity();
		balls.push_back(shape);
	}
}
void initShapeBrick(int gl){
	for (int j = 0; j < BrickNum; j++) {
		Brick* Bshape = new Brick();
		Bshape->velocity * (gl-1);
		Bshape->initBrick(j, gl);
		bricks.push_back(Bshape);
	}
}
void initShapeBoundary(int gl){
	for (int k = 0; k < BoundaryNum; k++) {
		Boundary* Boshape = new Boundary();
		Boshape->initBoundary(k);
		boundarys.push_back(Boshape);
	}
}
void initShapeStick(int gl){
	sticks = new Stick;
	sticks->setPosition(0, -0.95, 0);
}
//추가
int CountBlock(std::vector<Brick*> b){
	int numblock = 0;
	for (std::size_t i = 0; i != BrickNum; ++i){
		
			if (bricks[i]->alive == true)
				numblock = numblock + 1;
	}
	return numblock;
}
//추가 끝
void renderScene()
{
	// Clear Color and Depth Buffers
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//추가
	char* a = new char;
	itoa(CountBlock(bricks), a, 10);
	char* b = new char;
	itoa(score, b, 10);
	char* c = new char;
	itoa(moksum, c, 10); 
	//추가 끝
	if (moksum == -1) {
		glutPrint(0, 0, glutFonts[3], "ARKANOID", 0, 0, 0, 1);
		glutPrint(-0.14, -0.3, glutFonts[3], "Press F1 to Start EASY MODE", 0, 0, 0, 1);
		glutPrint(-0.14, -0.4, glutFonts[3], "Press F2 to Start HARD MODE", 0, 0, 0, 1);
		glutPrint(-0.14, -0.5, glutFonts[3], "Press F3 to Start INFERNO MODE", 0, 0, 0, 1);
		balls[0]->velocity.x = balls[0]->velocity.y = 0;
	}
	if (moksum == 0){
		gameon = false;
		for (int i = 0; i < boundarys.size(); i++) {
			boundarys[i]->draw();
		}
		for (int i = 0; i < BrickNum; i++) {
			bricks[i]->initBrick(i, gameLv);
			bricks[i]->alive = true;

		}
		glutPrint(-0.6, 0.0, glutFonts[3], "GAME OVER", 0, 0, 0, 1);
		glutPrint(0.1, -0.1, glutFonts[3], "PRESS F4 to Get Back To Menu", 0, 0, 0, 1);
	}
	if (moksum >  0) {
		for (int i = 0; i < BrickNum; i++) {
			if (bricks[i]->alive == true)
				bricks[i]->draw();
		}
		for (int i = 0; i < balls.size(); i++) {
			balls[i]->draw(); // 0 should be changed to GameLevel Input
		}
		for (int i = 0; i < boundarys.size(); i++) {
			boundarys[i]->draw();
		}
		//추가
		switch (gameLv){
		case 1:
			score = (BrickNum - CountBlock(bricks)) * 100;
			break;
		case 2:
			score = (BrickNum - CountBlock(bricks)) * 200;
			break;
		case 3:
			score = (BrickNum - CountBlock(bricks)) * 500;
			break;
		}
		glutPrint(0.3, -0.3, glutFonts[3], a, 0, 0, 0, 1);
		glutPrint(0.3, -0.2, glutFonts[3], "Bricks Left : ", 0, 0, 0, 1);
		glutPrint(0.3, -0.6, glutFonts[3], "SCORE :", 0, 0, 0, 1);
		glutPrint(0.3, -0.7, glutFonts[3], b, 0, 0, 0, 1);
		glutPrint(0.3, 0, glutFonts[3], c, 0, 0, 0, 1);
		glutPrint(0.3, 0.1, glutFonts[3], "Life :", 0, 0, 0, 1);

		if (CountBlock(bricks) == 0){
			sticks->length[0] = 1;
			gameon == false;
			glutPrint(-0.6, 0.0, glutFonts[3], "WELL DONE", 0, 0, 0, 1);
			glutPrint(0.1, -0.1, glutFonts[3], "PRESS F4 to Get Back To Menu", 0, 0, 0, 1);
			balls[0]->setPosition(-0.6, -0.85, 0);
			moksum = 0;
		}
		//추가 끝
	}
	sticks->draw();
	glutSwapBuffers();
}

clock_t preTime;
void process() {
	clock_t current = clock();
	clock_t diff = current - preTime;
	int lifes = 0;
	if (diff > 1000.0 / Frame) {
		//cout << moksum << endl;
		//cout << bricks[41]->corner[1] << endl;
		sticks->oscillation(gameLv);
		for (int i = 0; i < balls.size(); i++) {
			balls[i]->move();
		}
		for (int i = 0; i < balls.size(); i++) {
			for (int j = i + 1; j < balls.size(); j++){
				if (balls[i]->collisionBall(balls[j])){
					Vec3 vel_differ = balls[i]->velocity - balls[j]->velocity;
					Vec3 pos_differ = balls[i]->center - balls[j]->center;
					float cal = (vel_differ*pos_differ) / (pos_differ*pos_differ);
					balls[i]->velocity -= cal*pos_differ;
					balls[j]->velocity += cal*pos_differ;
					float distbb = sqrt(pos_differ*pos_differ);
					float overlap = balls[i]->radius + balls[j]->radius - distbb;
					Vec3 normalize = pos_differ / distbb;
					balls[i]->center += normalize*overlap / 2.0;
					balls[j]->center -= normalize*overlap / 2.0;
					balls[i]->normalizeVelocity();
					balls[j]->normalizeVelocity();
				}
			}
		}
		
		for (int i = 0; i < balls.size(); i++) {
			for (int k = 0; k < BrickNum; k++) {
				if (gameLv != 1) bricks[k]->move();
				if (bricks[k]->alive) {
					if (balls[i]->collisionBrickLeftRight(bricks[k])) {
						balls[i]->velocity.x *= -1;
						balls[i]->normalizeVelocity();
						break;
					}
					if (balls[i]->collisionBrickUpDown(bricks[k])) {
						balls[i]->velocity.y *= -1;
						balls[i]->normalizeVelocity();
						break;
					}
					if (balls[i]->collisionBrickCorner(bricks[k])) {
						Vec3 v = balls[i]->velocity;
						Vec3 n = balls[i]->nullVector;
						balls[i]->velocity = v - 2*(((v*n)/(n*n))*n);
						balls[i]->normalizeVelocity();
						break;
					}
				}
				if (bricks[k]->corner[1] < -1.1) {
					sticks->length[0] = 1;
					gameon == false;
					moksum = 0;
				}
			}
		}
		for (int i = 0; i < balls.size(); i++) {
			if (balls[i]->collisionStick(sticks)) {
				balls[i]->velocity.x += 2 * balls[i]->ballSpeed * (balls[i]->center[0] - (2 * (float)(mousePosX) / WINDOW_WIDTH - 1)) / sticks->length[0];
				balls[i]->velocity.y *= -1;
				balls[i]->velocity.z *= -1;
				balls[i]->normalizeVelocity();
			}
			else {
				//cout << "collision doesn't occur" << endl;
			}
			if (balls[i]->collisionSideBoundary(boundarys[0]))  balls[i]->velocity[0] *= -1;
			if (balls[i]->collisionSideBoundary(boundarys[2]))  balls[i]->velocity[0] *= -1;
			if (balls[i]->collisionUpperBoundary(boundarys[1])) balls[i]->velocity[1] *= -1;

		}
	}
	//cout << gameLv << endl;
	glutPostRedisplay();
}


void passive(int x, int y){
	float left = WINDOW_WIDTH * (0.0625 + (sticks->length[0] / 4));
	float right = WINDOW_WIDTH * (0.5139 - (sticks->length[0] / 4));
	if (left < x && x < right) {
		sticks->setPosition(2 * (float)(x) / WINDOW_WIDTH - 1 - sticks->length[0] / 2, -0.95, 0);
	}
	else if (x <= left) {
		sticks->setPosition(2 * left / WINDOW_WIDTH - 1 - sticks->length[0] / 2, -0.95, 0);
	}
	else if (x >= right) {
		sticks->setPosition(2 * right / WINDOW_WIDTH - 1 - sticks->length[0] / 2, -0.95, 0);
	}
	mousePosX = x;
	glutPostRedisplay();
}


void processMouse(int button, int state, int x, int y)
{
	switch (button)
	{
	case GLUT_LEFT_BUTTON:
		if (pastmoksum != moksum) {
			pastmoksum = moksum;
			for (int i = 0; i < balls.size(); i++) {
				balls[i]->velocity.x = -bBallSpeed / 2 * sqrt(2);
				balls[i]->velocity.y = bBallSpeed/2*sqrt(2);
				balls[i]->normalizeVelocity();

			}
		}
	}
}

void SpecialKey(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_RIGHT:
		sticks->lftrgt = 1;
		sticks->move();
		break;
	case GLUT_KEY_LEFT:
		sticks->lftrgt = -1;
		sticks->move();
		break;
	case GLUT_KEY_F1:
		if (moksum == -1) {
			if (gameon == false){
				pastmoksum = moksum;
				moksum += 4;
				gameLv = 1;
				gameon = true;
				balls[0]->velocity.x = balls[0]->velocity.y = 0;
				sticks->length[0] = 0.25;
			}
		}
		break;
	case GLUT_KEY_F2:
		if (moksum == -1) {
			if (gameon == false){
				pastmoksum = moksum;
				moksum += 4;
				gameLv = 2;
				gameon = true;
				sticks->length[0] = 0.25;
			}
		}
		break;
	case GLUT_KEY_F3:
		if (moksum == -1) {
			if (gameon == false){
				pastmoksum = moksum;
				moksum += 4;
				gameLv = 3;
				gameon = true;
				sticks->length[0] = 0.25;
			}
		}
		break;
	case GLUT_KEY_F4:
		if (moksum == 0) {
			if (gameon == false){
				moksum = -1;
			}
			break;
	default:
		break;
		}
	}
	glutPostRedisplay();
}

void main(int argc, char **argv) {
	srand(time(NULL));
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(300, 300);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutCreateWindow("Arkanoid");
	initShapeBall(gameLv);
	initShapeBrick(gameLv);
	initShapeBoundary(gameLv);
	initShapeStick(gameLv);// number equals to the number of balls
	glutDisplayFunc(renderScene);
	preTime = clock();
	glutPassiveMotionFunc(passive);
	glutSpecialFunc(SpecialKey);
	glutMouseFunc(processMouse);
	glutIdleFunc(process);
	glutMainLoop();
	for (int i = 0; i<balls.size(); i++){
		delete balls[i];
	}
	for (int j = 0; j < bricks.size(); j++) {
		delete bricks[j];
	}
	delete sticks;
}
