#include "Application.h"
#include "Canvas.h"
#include <iostream>

namespace app {
	int width;
	int height;

	Canvas* canvas;
}

void app::init(int argc, char* argv[]) {
	if (!glfwInit()) {
		std::cout << "Error!" << std::endl;
		exit(EXIT_FAILURE);
	}

	app::width = 480;
	app::height = 320;
	GLFWwindow* window = glfwCreateWindow(app::width, app::height, "Ceramic Pixel", NULL, NULL);

	glfwSetWindowSizeCallback(window, app::resize);

	glfwMakeContextCurrent(window);
	app::updateViewport();

	canvas = new Canvas(1024, 1024);

	while (!glfwWindowShouldClose(window)) {
		display();
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	
	/*glutInitWindowSize(480, 320);
	glutInitDisplayMode(GLUT_RGB);
	glutCreateWindow("Ceramic Pixel");

	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	glutDisplayFunc(app::display);
	glutReshapeFunc(app::reshape);*/
}

void app::run() {
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