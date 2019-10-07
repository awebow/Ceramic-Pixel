#include "Canvas.h"
#include "Application.h"

Canvas::Canvas(int width, int height) : width(width), height(height) {
	int paddedWidth = getPaddedWidth();
	offsetX = 0;
	offsetY = 0;
	zoom = 1.0;

	image = new GLubyte[paddedWidth * height];
	int offset;
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			offset = (y * paddedWidth + x * 3);
			image[offset] = 255;
			image[offset + 1] = 255;
			image[offset + 2] = 255;
		}
	}

	generateTexture();
}

void Canvas::draw() {
	int left = getLeft();
	int right = getRight();
	int bottom = getBottom();
	int top = getTop();

	glBindTexture(GL_TEXTURE_2D, textureId);
	glEnable(GL_TEXTURE_2D);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);
	glVertex2f(left, bottom);
	glTexCoord2f(1, 0);
	glVertex2f(right, bottom);
	glTexCoord2f(1, 1);
	glVertex2f(right, top);
	glTexCoord2f(0, 1);
	glVertex2f(left, top);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 0);
}

int Canvas::getLeft() {
	return app::width / 2 + (-offsetX - width / 2) * zoom;
}

int Canvas::getRight() {
	return app::width / 2 + (-offsetX + width / 2) * zoom;
}

int Canvas::getBottom() {
	return app::height / 2 + (-offsetY - height / 2) * zoom;
}

int Canvas::getTop() {
	return app::height / 2 + (-offsetY + height / 2) * zoom;
}

float Canvas::getZoom() {
	return zoom;
}

void Canvas::setZoom(float zoom) {
	this->zoom = zoom;
}

void Canvas::generateTexture() {
	glGenTextures(1, &textureId);
	glBindTexture(GL_TEXTURE_2D, textureId);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	glBindTexture(GL_TEXTURE_2D, 0);
}

void Canvas::updateTexture() {
	glBindTexture(GL_TEXTURE_2D, textureId);
	glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, width, height, GL_RGB, GL_UNSIGNED_BYTE, image);
	glBindTexture(GL_TEXTURE_2D, 0);
}

void Canvas::translate(int x, int y) {
	offsetX += x;
	offsetY += y;
}

void Canvas::addZoom(float amount) {
	zoom += amount;
}

GLubyte* Canvas::getImage() {
	return image;
}

int Canvas::getWidth() {
	return width;
}

int Canvas::getHeight() {
	return height;
}

int Canvas::getPaddedWidth() {
	int row = width * 3;
	int mod = row % 4;
	return row + (mod > 0 ? 4 - mod : 0);
}