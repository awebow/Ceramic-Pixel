#include "Application.h"
#include <iostream>
#include "PixelPainter.h"
#include "Scroller.h"
#include "Zoom.h"

namespace app {
	int width;
	int height;

	GLFWwindow* window;
	Tool* clickTool;
	Tool* scrollTool;

	PixelPainter pixelPainter;
	Scroller scroller;

	Canvas* canvas;
}

void app::init(int argc, char* argv[]) {
	if (!glfwInit()) {
		std::cout << "Error!" << std::endl;
		exit(EXIT_FAILURE);
	}

	width = 480;
	height = 320;
	clickTool = &pixelPainter;
	scrollTool = new Zoom();
	window = glfwCreateWindow(app::width, app::height, "Ceramic Pixel", NULL, NULL);

	glfwSetWindowSizeCallback(window, resize);
	glfwSetMouseButtonCallback(window, onMouseButton);
	glfwSetCursorPosCallback(window, onMouseMove);
	glfwSetScrollCallback(window, onScroll);
	glfwSetKeyCallback(window, onKey);

	glfwMakeContextCurrent(window);
	app::updateViewport();

	canvas = new Canvas(1024, 1024);
	
	/*glutInitWindowSize(480, 320);
	glutInitDisplayMode(GLUT_RGB);
	glutCreateWindow("Ceramic Pixel");

	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	glutDisplayFunc(app::display);
	glutReshapeFunc(app::reshape);*/
}

void app::run() {
	glfwSwapInterval(1);
	while (!glfwWindowShouldClose(window)) {
		display();
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}

void app::display() {
	glClearColor(0.29, 0.29, 0.29, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1);

	canvas->draw();
}

void app::resize(GLFWwindow* window, int width, int height) {
	app::width = width;
	app::height = height;

	updateViewport();
}

void app::updateViewport() {
	glViewport(0, 0, width, height);
}

void app::onMouseButton(GLFWwindow* window, int button, int action, int mods) {
	double x, y;
	glfwGetCursorPos(window, &x, &y);

	clickTool->onMouseButton(button, action, (int) x, height - (int) y);
}

void app::onMouseMove(GLFWwindow* window, double x, double y) {
	clickTool->onMouseMove((int) x, height - (int) y);
}

void app::onScroll(GLFWwindow* window, double x, double y) {
	scrollTool->onScroll(x, y);
}

void app::onKey(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (key == GLFW_KEY_SPACE) {
		if (action == GLFW_PRESS && glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) != GLFW_PRESS) {
			clickTool = &scroller;
		}
		else if (action == GLFW_RELEASE) {
			clickTool = &pixelPainter;
		}
	}
}

int app::getCanvasX(int x) {
	return (x - canvas->getLeft()) / canvas->getZoom();
}

int app::getCanvasY(int y) {
	return (y - canvas->getBottom()) / canvas->getZoom();
}
