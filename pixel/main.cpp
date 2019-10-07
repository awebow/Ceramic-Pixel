#include <iostream>
#include "Application.h"

using namespace std;

void display();
void onMouse(int button, int state, int x, int y);

int main(int argc, char* argv[]) {
	app::init(argc, argv);
	app::run();
}
/*
void display() {
	glBindTexture(GL_TEXTURE_2D, texId);
	glEnable(GL_TEXTURE_2D);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex2f(0, 0);
	glTexCoord2f(1, 0);
	glVertex2f(1, 0);
	glTexCoord2f(1, 1);
	glVertex2f(1, 1);
	glTexCoord2f(0, 1);
	glVertex2f(0, 1);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 0);
	glFlush();
}

void onMouse(int button, int state, int x, int y) {
	cout << x << " " << y << endl;
	if (button == GLUT_LEFT && state == GLUT_DOWN) {
		int px = 16 * (x - 240) / 240;
		int py = 16 * (320 - y - 160) / 160;

		if (px >= 0 && px < 1024 && py >= 0 && py < 1024) {
			texture[py][px][0] = 255;
			texture[py][px][1] = 255;
			texture[py][px][2] = 255;

			glBindTexture(GL_TEXTURE_2D, texId);
			glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, 16, 16, GL_RGB, GL_UNSIGNED_BYTE, texture);
			glBindTexture(GL_TEXTURE_2D, 0);

			cout << "Update!" << endl;
		}
	}
}*/