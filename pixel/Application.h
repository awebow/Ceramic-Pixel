#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Tool.h"
#include "Canvas.h"

#pragma once
namespace app {
	extern int width;
	extern int height;

	extern GLFWwindow* window;

	extern Tool* clickTool;
	extern Tool* scrollTool;
	extern Canvas* canvas;

	void init(int argc, char* argv[]);
	void run();
	void display();
	void resize(GLFWwindow* window, int width, int height);
	void updateViewport();

	void onMouseButton(GLFWwindow* window, int button, int action, int mods);
	void onMouseMove(GLFWwindow* window, double x, double y);
	void onScroll(GLFWwindow* window, double x, double y);
	void onKey(GLFWwindow* window, int key, int scancode, int action, int mods);

	int getCanvasX(int x);
	int getCanvasY(int y);
}