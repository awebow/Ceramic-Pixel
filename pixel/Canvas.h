#include <GL/glew.h>

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

public:
	Canvas(int width, int height);
	
	void draw();

	int getLeft();
	int getRight();
	int getBottom();
	int getTop();

	float getZoom();
	void setZoom(float zoom);

	GLubyte* getImage();

	int getWidth();
	int getHeight();

	int getPaddedWidth();
	void updateTexture();

	void translate(int x, int y);
	void addZoom(float amount);
};