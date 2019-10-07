#include "Application.h"
#include "PixelPainter.h"
#include <algorithm>
#include <cmath>

PixelPainter::PixelPainter() {
	drawing = false;
}

void PixelPainter::onMouseButton(int button, int action, int x, int y) {
	x = app::getCanvasX(x);
	y = app::getCanvasY(y);

	if (button == GLFW_MOUSE_BUTTON_LEFT) {
		if (action == GLFW_PRESS) {
			lastX = x;
			lastY = y;

			paint(x, y);
			app::canvas->updateTexture();
			drawing = true;
		}
		else if (action == GLFW_RELEASE) {
			drawing = false;
		}
	}
}

void PixelPainter::onMouseMove(int x, int y) {
	x = app::getCanvasX(x);
	y = app::getCanvasY(y);

	if (drawing) {
		float dx = x - lastX;
		float dy = y - lastY;
		float longer = std::max(std::fabs(dx), std::fabs(dy));

		dx /= longer;
		dy /= longer;

		float px = lastX;
		float py = lastY;
		for (int n = 0; n <= longer; n++) {
			paint((int) px, (int) py);

			px += dx;
			py += dy;
		}

		app::canvas->updateTexture();

		lastX = x;
		lastY = y;
	}
}

void PixelPainter::paint(int x, int y) {
	if (x >= 0 && x < app::canvas->getWidth() && y >= 0 && y < app::canvas->getHeight()) {
		GLubyte* image = app::canvas->getImage();

		int offset = (y * app::canvas->getPaddedWidth() + x * 3);
		image[offset] = 0;
		image[offset + 1] = 0;
		image[offset + 2] = 0;
	}
}
