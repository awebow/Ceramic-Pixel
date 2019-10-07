#include <GL/glew.h>
#include <GLFW/glfw3.h>

#pragma once
namespace app {
	extern int width;
	extern int height;

	void init(int argc, char* argv[]);
	void run();
	void display();
	void resize(GLFWwindow* window, int width, int height);
	void updateViewport();
}