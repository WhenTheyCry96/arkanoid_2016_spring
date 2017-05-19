#include "Boundary.h"

void Boundary::move() {

}

void Boundary::draw() {
	if (whereBo == 0) {
		for (int i = 0; i < 20; i++) {
			glBegin(GL_QUADS);
			glColor3f(rgb.x, rgb.y, rgb.z);
			glVertex3f(corner[0], corner[1] - boLong.y*i, 0);
			glVertex3f(corner[0] + boLong.x/2, corner[1] - boLong.y*i, 0);
			glVertex3f(corner[0] + boLong.x/2, corner[1] + boLong.y - boLong.y*i, 0);
			glVertex3f(corner[0], corner[1] + boLong.y - boLong.y*i, 0);
			glEnd();
		}
		glBegin(GL_QUADS); // shading
		glColor3f(rgb.x - 0.1, rgb.y - 0.1, rgb.z - 0.1);
		glVertex3f(corner[0] + boLong.x / 2, corner[1], 0);
		glVertex3f(corner[0] + boLong.x / 2, corner[1] + boLong.x / 5 - 1.8, 0);
		glVertex3f(corner[0] + boLong.x / 2 + boLong.x / 5, corner[1] + boLong.x / 5 - 1.8, 0);
		glVertex3f(corner[0] + boLong.x / 2 + boLong.x / 5, corner[1], 0);
		glEnd();
		glBegin(GL_TRIANGLES);
		glColor3f(rgb.x - 0.1, rgb.y - 0.1, rgb.z - 0.1);
		glVertex3f(corner[0] + boLong.x / 2, corner[1]- 1.8, 0);
		glVertex3f(corner[0] + boLong.x / 2 + boLong.x / 5, corner[1] + boLong.x / 5 - 1.8, 0);
		glVertex3f(corner[0] + boLong.x / 2 , corner[1] + boLong.x * 2 / 5 - 1.8, 0);
		glEnd();
	}
	if (whereBo == 1) {
		for (int i = 0; i < 10; i++) {
			glBegin(GL_QUADS);
			glColor3f(rgb.x, rgb.y, rgb.z);
			glVertex3f(corner[0] + boLong.x*i, corner[1], 0);
			glVertex3f(corner[0] + boLong.x + boLong.x*i, corner[1], 0);
			glVertex3f(corner[0] + boLong.x + boLong.x*i, corner[1] + boLong.y, 0);
			glVertex3f(corner[0] + boLong.x*i, corner[1] + boLong.y, 0);
			glEnd();
		}
		glBegin(GL_QUADS); // shading
		glColor3f(rgb.x - 0.1, rgb.y - 0.1, rgb.z - 0.1);
		glVertex3f(corner[0] + boLong.x / 4, corner[1] + boLong.y, 0);
		glVertex3f(corner[0] + boLong.x / 4, corner[1] + boLong.y + boLong.y / 4, 0);
		glVertex3f(corner[0] + boLong.x * 10 + boLong.x / 5, corner[1] + boLong.y + boLong.y / 4, 0);
		glVertex3f(corner[0] + boLong.x * 10 + boLong.x / 5, corner[1] + boLong.y, 0);
		glEnd();
		glBegin(GL_TRIANGLES);
		glColor3f(rgb.x - 0.1, rgb.y - 0.1, rgb.z - 0.1);
		glVertex3f(corner[0], corner[1] + boLong.y, 0);
		glVertex3f(corner[0] + boLong.x / 4, corner[1] + boLong.y, 0);
		glVertex3f(corner[0] + boLong.x / 4, corner[1] + boLong.y + boLong.y / 4, 0);
		glEnd();
		glBegin(GL_TRIANGLES);
		glColor3f(rgb.x - 0.1, rgb.y - 0.1, rgb.z - 0.1);
		glVertex3f(corner[0] + boLong.x * 10 + boLong.x / 5, corner[1] + boLong.y, 0);
		glVertex3f(corner[0] + boLong.x * 10 + boLong.x / 5, corner[1] + boLong.y + boLong.y/4, 0);
		glVertex3f(corner[0] + boLong.x * 10 + boLong.x *2/5  , corner[1] + boLong.y, 0);
		glEnd();
	}
	if (whereBo == 2) {
		for (int i = 0; i < 20; i++) {
			glBegin(GL_QUADS);
			glColor3f(rgb.x, rgb.y, rgb.z);
			glVertex3f(corner[0], corner[1] - boLong.y*i, 0);
			glVertex3f(corner[0] + boLong.x/2, corner[1] - boLong.y*i, 0);
			glVertex3f(corner[0] + boLong.x/2, corner[1] + boLong.y - boLong.y*i, 0);
			glVertex3f(corner[0], corner[1] + boLong.y - boLong.y*i, 0);
			glEnd();
		}
		glBegin(GL_QUADS); // shading
		glColor3f(rgb.x - 0.1, rgb.y - 0.1, rgb.z - 0.1);
		glVertex3f(corner[0], corner[1], 0);
		glVertex3f(corner[0], corner[1] + boLong.x / 5 - 1.8, 0);
		glVertex3f(corner[0] - boLong.x / 5, corner[1] + boLong.x / 5 - 1.8, 0);
		glVertex3f(corner[0] - boLong.x / 5, corner[1], 0);
		glEnd();
		glBegin(GL_TRIANGLES);
		glColor3f(rgb.x - 0.1, rgb.y - 0.1, rgb.z - 0.1);
		glVertex3f(corner[0], corner[1] - 1.8, 0);
		glVertex3f(corner[0] - boLong.x / 5, corner[1] + boLong.x / 5 - 1.8, 0);
		glVertex3f(corner[0], corner[1] + boLong.x * 2 / 5 - 1.8, 0);
		glEnd();

	}
}

void Boundary::initBoundary(int num) {
	whereBo = num;
	if (whereBo == 0) {
		corner[0] = lftboundx; corner[1] = lftboundy; corner[2] = 0;
	}
	if (whereBo == 1) {
		corner[0] = uppboundx; corner[1] = uppboundy; corner[2] = 0;
	}
	if (whereBo == 2) {
		corner[0] = rgtboundx; corner[1] = rgtboundy; corner[2] = 0;
	}
}