#include "Application.h"

#pragma once
class Canvas {
private:
	int width;
	int height;

	int offsetX;
	int offsetY;
	float zoom;

	GLubyte* image;
	GLuint textureId;

	void generateTexture();
	void updateTexture();
	int getPaddedWidth();

public:
	Canvas(int width, int height);
	
	void draw();
};