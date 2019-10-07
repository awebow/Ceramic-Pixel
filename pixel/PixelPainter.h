#pragma once
#include "Tool.h"

class PixelPainter : public Tool {
private:
	bool drawing;
	int lastX;
	int lastY;

public:
	PixelPainter();

	virtual void onMouseButton(int button, int action, int x, int y);
	virtual void onMouseMove(int x, int y);

	void paint(int x, int y);
};

