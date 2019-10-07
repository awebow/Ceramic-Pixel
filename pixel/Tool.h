#pragma once

class Tool {
public:
	virtual void onMouseButton(int button, int action, int x, int y) {};
	virtual void onMouseMove(int x, int y) {};
	virtual void onScroll(double x, double y) {};
};