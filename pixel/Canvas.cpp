#include "Canvas.h"
#include "Application.h"

Canvas::Canvas(int width, int height) : width(width), height(height) {
	int paddedWidth = getPaddedWidth();
	offsetX = 0;
	offsetY = 0;
	zoom = 1.0;

	image = new GLubyte[paddedWidth * height * 3];
	int offset;
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < height; x++) {
			offset = (y * paddedWidth + x) * 3;
			image[offset] = 255;
			image[offset + 1] = 255;
			image[offset + 2] = 255;
		}
	}
}

void Canvas::draw() {
	int centerX = app::width / 2 - offsetX;
	int centerY = app::height / 2 - offsetY;

	int left = centerX - width / 2;
	int right = centerX + width / 2;
	int bottom = centerY - height / 2;
	int top = centerY + height / 2;

	/*glBindTexture(GL_TEXTURE_2D, textureId);
	glEnable(GL_TEXTURE_2D);*/
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glTexCoord2f(0, 0);
	glVertex2f(left, bottom);
	glTexCoord2f(1, 0);
	glVertex2f(right, bottom);
	glTexCoord2f(1, 1);
	glVertex2f(right, top);
	glTexCoord2f(0, 1);
	glVertex2f(left, top);
	glEnd();
	/*glDisable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 0);*/
}

void Canvas::generateTexture() {
	glGenTextures(1, &textureId);
	glBindTexture(GL_TEXTURE_2D, textureId);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 16, 16, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	glBindTexture(GL_TEXTURE_2D, 0);
}

void Canvas::updateTexture() {
	glBindTexture(GL_TEXTURE_2D, textureId);
	glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, 16, 16, GL_RGB, GL_UNSIGNED_BYTE, image);
	glBindTexture(GL_TEXTURE_2D, 0);
}

int Canvas::getPaddedWidth() {
	int mod = width % 4;
	return width + (mod > 0 ? 4 - mod : 0);
}