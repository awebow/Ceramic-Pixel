#include "Scroller.h"
#include "Application.h"
#include <GLFW/glfw3.h>
#include <iostream>

Scroller::Scroller() {
	scrolling = false;
}

void Scroller::onMouseButton(int button, int action, int x, int y) {
	if (button == GLFW_MOUSE_BUTTON_LEFT) {
		scrolling = action == GLFW_PRESS;
		lastX = x;
		lastY = y;
	}
}

void Scroller::onMouseMove(int x, int y) {
	if (scrolling) {
		app::canvas->translate((lastX - x) / app::canvas->getZoom(), (lastY - y) / app::canvas->getZoom());

		lastX = x;
		lastY = y;
	}
}
